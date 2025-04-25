#include "usart.h"


/**********************************************************************************/
/*                               USART Core Functions                             */
/**********************************************************************************/

//gpio pins should be configured prior to USART being initialised
Status USART_Init(USART_Init_Config *init_config) {
    //validate config struct pointer
    if (!(init_config)) {
        return INVALID_PARAM;
    }

    //validate instance
    if ((init_config->instance   != USART1) && (init_config->instance != USART2)
        && (init_config->instance != USART6)) {
        return INVALID_PARAM;
    }

    //validate word length, oversampling, stop bits, one bit, parity control and selection
    if (init_config->word_length         < 0 || init_config->word_length      > 1
        || init_config->oversampling     < 0 || init_config->oversampling     > 1
        || init_config->stop_bits        < 0 || init_config->stop_bits        > 2
        || init_config->one_bit          < 0 || init_config->one_bit          > 1
        || init_config->parity_control   < 0 || init_config->parity_control   > 1
        || init_config->parity_selection < 0 || init_config->parity_selection > 1) {
        return INVALID_PARAM;
    }

    //validate interrupt priority level
    if (Validate_Priority(init_config->interrupt_priority) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    //validate availability of interrupt priority level
    if (!(priority_tracker[init_config->interrupt_priority])) {
        return INVALID_PARAM;
    }

    //get USART index
    USART_Index usart_index;
    if (Get_USART_Index(init_config->instance) == USART_Index_Error) {
        return INVALID_PARAM;
    } else {
        usart_index = Get_USART_Index(init_config->instance);
    }

    //store init config in global usart state struct
    usart_states[usart_index].init_config = init_config;

    //enable USART clock
    if (init_config->instance == USART1) {
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    } else if (init_config->instance == USART2) {
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    } else if (init_config->instance == USART6) {
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    } else {
        return INVALID_PARAM;
    }

    //calculate and configure USART_DIV
    uint8_t over;
    if (init_config->oversampling) {
        over = 8U;
    } else {
        over = 16U;
    }
    float usart_div = (((float) g_sys_clk_freq) / ((float) (init_config->baud_rate * over)));
    uint16_t mantissa = ((uint16_t) usart_div);
    if (mantissa < 0x0UL || mantissa > 0xFFFUL) {
        return INVALID_PARAM;
    }
    uint8_t fraction = round((usart_div - mantissa) * over);
    mantissa = (mantissa << 4U);

    if (over == 8U && fraction == 8U) {
        mantissa += (0x1UL << 4U);
        fraction = 0UL;
    }

    uint16_t brr = (mantissa + fraction);
    init_config->instance->BRR = brr;

    //configure word length
    init_config->instance->CR1 &= ~(USART_CR1_M);
    init_config->instance->CR1 |= (((uint32_t) init_config->word_length) << 12U);

    //configure oversampling
    init_config->instance->CR1 &= ~(USART_CR1_OVER8);
    init_config->instance->CR1 |= (((uint32_t) init_config->oversampling) << 15U);

    //configure stop bits
    init_config->instance->CR2 &= ~(USART_CR2_STOP);
    init_config->instance->CR2 |= (((uint32_t) init_config->stop_bits) << 12U);

    //configure onebit
    init_config->instance->CR3 &= ~(USART_CR3_ONEBIT);
    init_config->instance->CR3 |= (((uint32_t) init_config->one_bit) << 11U);

    //configure parity
    init_config->instance->CR1 &= ~(USART_CR1_PCE);
    init_config->instance->CR1 |= (((uint32_t) init_config->parity_control) << 10U);
    init_config->instance->CR1 &= ~(USART_CR1_PS);
    init_config->instance->CR1 |= (((uint32_t) init_config->parity_selection) << 9U);

    //configure interrupts
    if (init_config->pe_interrupt_enable) {
        init_config->instance->CR1 |= USART_CR1_PEIE;
    }
    if (init_config->idle_interrupt_enable) {
        init_config->instance->CR1 |= USART_CR1_IDLEIE;
    }
    if (init_config->cts_interrupt_enable) {
        init_config->instance->CR3 |= USART_CR3_CTSIE;
    }
    if (init_config->error_interrupt_enable) {
        init_config->instance->CR3 |= USART_CR3_EIE;
    }
    if (init_config->lbd_interrupt_enable) {
        init_config->instance->CR2 |= USART_CR2_LBDIE;
    }

    //dummy comment

    DISABLE_IRQ();
    if (init_config->instance == USART1) {
        NVIC_Set_Priority(USART1_IRQn, init_config->interrupt_priority);
        NVIC_Enable_IRQ(USART1_IRQn);
    } else if (init_config->instance == USART2) {
        NVIC_Set_Priority(USART2_IRQn, init_config->interrupt_priority);
        NVIC_Enable_IRQ(USART2_IRQn);
    } else {
        NVIC_Set_Priority(USART6_IRQn, init_config->interrupt_priority);
        NVIC_Enable_IRQ(USART6_IRQn);
    }
    ENABLE_IRQ();
    
    //record utilised interrupt priority level
    priority_tracker[init_config->interrupt_priority] = 1U;

    //enable transmitter and receiver
    init_config->instance->CR1 |= (USART_CR1_TE | USART_CR1_RE);

    //enable USART
    init_config->instance->CR1 |= USART_CR1_UE;

    return SUCCESS;
}



Status USART_Transmit(USART_Init_Config *init_config, uint8_t *tx_data, uint16_t tx_length) {
    //validate config struct pointer and length
    if ((!(init_config)) || tx_length <= 0) {
        return INVALID_PARAM;
    }

    //get USART index
    USART_Index usart_index;
    if (Get_USART_Index(init_config->instance) == USART_Index_Error) {
        return INVALID_PARAM;
    } else {
        usart_index = Get_USART_Index(init_config->instance);
    }

    //check if USART is currently transmitting
    if (usart_states[usart_index].tx_status == USART_BUSY) {
        return ERROR;
    }

    //store and initialise transmitter parameters in global usart state struct
    usart_states[usart_index].tx_buffer = tx_data;
    usart_states[usart_index].tx_length = tx_length;
    usart_states[usart_index].tx_index  = 0;
    usart_states[usart_index].tx_status = USART_BUSY;

    //enable TXE interrupts
    init_config->instance->CR1 |= USART_CR1_TXEIE;

    //transmit the first byte
    init_config->instance->DR = usart_states[usart_index].tx_buffer[usart_states[usart_index].tx_index++];

    return SUCCESS;
}


Status USART_Receive(USART_Init_Config *init_config, uint8_t *rx_buffer, uint16_t rx_length) {
    //validate config struct pointer and length
    if ((!(init_config)) || rx_length <= 0) {
        return INVALID_PARAM;
    }

    //get usart index
    USART_Index usart_index;
    if (Get_USART_Index(init_config->instance) == USART_Index_Error) {
        return INVALID_PARAM;
    } else {
        usart_index = Get_USART_Index(init_config->instance);
    }

    //check if USART is currently receiving
    if (usart_states[usart_index].rx_status == USART_BUSY) {
        return ERROR;
    }

    //store and intitialise receiver parameters in global usart state struct
    usart_states[usart_index].rx_buffer = rx_buffer;
    usart_states[usart_index].rx_length = rx_length;
    usart_states[usart_index].rx_index  = 0;
    usart_states[usart_index].rx_status = USART_BUSY;

    //enable RXNE interrupts
    init_config->instance->CR1 |= USART_CR1_RXNEIE;

    return SUCCESS;
}


//write USART_Deinit()

//check TC=1 before disabling USART
//RE should not be reset while receiving data, RXNE=0



static USART_Index Get_USART_Index(USART_TypeDef *instance) {
    if (instance == USART1) {
        return USART1_Index;
    } else if (instance == USART2) {
        return USART2_Index;
    } else if (instance == USART6) {
        return USART6_Index;
    } else {
        return USART_Index_Error;
    }
}


/**********************************************************************************/
/*                            USART Interrupt Handlers                            */
/**********************************************************************************/

void USART_IRQHandler(USART_Index usart_index) {
    //alias usart state and usart state config
    USART_State_Config *usart_state = &usart_states[usart_index];
    USART_Init_Config *config       = usart_state->init_config;

    //handle TXE interrupt
    if (config->instance->SR & USART_SR_TXE) {
        if (usart_state->tx_index < usart_state->tx_length) {
            config->instance->DR = usart_state->tx_buffer[usart_state->tx_index++];
        } else {
            config->instance->CR1 &= ~(USART_CR1_TXEIE);
            config->instance->CR1 |= USART_CR1_TCIE;
        }        
    }

    //handle RXNE interrupt
    if (config->instance->SR & USART_SR_RXNE) {
        //check for errors
        USART_RX_Error error = USART_ERROR_NONE;
        if (config->instance->SR & USART_SR_ORE) {
            error = USART_ERROR_OVERRUN;
        } else if (config->instance->SR & USART_SR_FE) {
            error = USART_ERROR_FRAMING;
        } else if (config->instance->SR & USART_SR_NF) {
            error = USART_ERROR_NOISE;
        }

        //read data to clear RXNE and error flags
        uint8_t data = config->instance->DR;                            /* validate in docs */

        if (error == USART_ERROR_NONE && (usart_state->rx_status == USART_BUSY)) {
            //store byte in buffer
            usart_state->rx_buffer[usart_state->rx_index++] = data;
            
            //check for receiption of all bytes
            if (usart_state->rx_index >= usart_state->rx_length) {
                usart_state->rx_status = USART_IDLE;
            }
        } else if (error != USART_ERROR_NONE) {
            usart_state->rx_status = USART_IDLE;
        }
    }

    //handle TC interrupt
    if (config->instance->SR & USART_SR_TC) {
        config->instance->CR1 &= ~(USART_CR1_TCIE);
        usart_state->tx_status   = USART_IDLE;
    }
}

void USART1_IRQHandler(void) {
     USART_IRQHandler(USART1_Index);
}

void USART2_IRQHandler(void) {
     USART_IRQHandler(USART2_Index);
}

void USART6_IRQHandler(void) {
     USART_IRQHandler(USART6_Index);
}


