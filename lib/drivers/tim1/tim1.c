#include "tim1.h"

/**********************************************************************************/
/*                               TIM1 Core Functions                              */
/**********************************************************************************/

/**
 * @brief  Initialises TIM1 in counter mode
 * @param  cnt_config: Pointer to TIM1_CNT_Config structure containing counter settings
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_CNT_Init(TIM1_CNT_Config_t *cnt_config) {
    //validate config struct pointer
    if (!(cnt_config)) {
        return INVALID_PARAM;
    }

    //validate prescaler, auto-reload, repetition, and interrupt priority level
    if (Validate_uint16_t(cnt_config->prescaler)              == INVALID_PARAM 
        || Validate_uint16_t(cnt_config->auto_reload)         == INVALID_PARAM 
        || Validate_uint8_t(cnt_config->repetition)           == INVALID_PARAM
        || Validate_Priority(cnt_config->interrupt_priority)  == INVALID_PARAM) {
        return INVALID_PARAM;
    } else {
        cnt_config->prescaler   = (uint16_t) cnt_config->prescaler;
        cnt_config->auto_reload = (uint16_t) cnt_config->auto_reload;
        cnt_config->repetition  = (uint8_t) cnt_config->repetition;
    }

    //validate availability of interrupt priority level
    if (cnt_config->interrupt_enable) {
        if (priority_tracker[cnt_config->interrupt_priority]) {
            return INVALID_PARAM;
        }
    }

    //enable TIM1 clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    //configure the counter in edge-aligned or centre-aligned mode
    if (cnt_config->centre_aligned_mode) {
        TIM1->CR1 &= ~(TIM_CR1_CMS);
        switch (cnt_config->centre_aligned_mode) {
            case TIM1_CENTRE_MODE_UP: TIM1->CR1   |= TIM_CR1_CMS_UP; break;
            case TIM1_CENTRE_MODE_DOWN: TIM1->CR1 |= TIM_CR1_CMS_DOWN; break;
            case TIM1_CENTRE_MODE_BOTH: TIM1->CR1 |= TIM_CR1_CMS_BOTH; break;
            default: return INVALID_PARAM; 
        }
    } else {
        switch (cnt_config->direction) {
            case TIM1_DIR_UP: TIM1->CR1   &= ~(TIM_CR1_DIR); break;
            case TIM1_DIR_DOWN: TIM1->CR1 |= TIM_CR1_DIR; break;
            default: return INVALID_PARAM;
        }
    }

    //configure auto-reload, prescaler, and repetition
    if (cnt_config->auto_reload) {
        TIM1->CR1 |= TIM_CR1_ARPE;
        TIM1->ARR = (cnt_config->auto_reload - 1UL);
    }
    TIM1->PSC = (cnt_config->prescaler - 1UL);
    TIM1->RCR = cnt_config->repetition;

    //configure interrupts
    switch (cnt_config->interrupt_enable) {
        case TIM1_INTERRUPT_ENABLED: {
            TIM1->DIER |= TIM_DIER_UIE;
            DISABLE_IRQ();
            NVIC_Set_Priority(TIM1_UP_TIM10_IRQn, cnt_config->interrupt_priority);
            NVIC_Enable_IRQ(TIM1_UP_TIM10_IRQn);
            ENABLE_IRQ();
            break;
        }
        case TIM1_INTERRUPT_DISABLED: TIM1->DIER &= ~(TIM_DIER_UIE); break;
        default: return INVALID_PARAM;
    }

    //configure DMA
    switch (cnt_config->dma_enable) {
        case TIM1_DMA_ENABLED: TIM1->DIER  |= TIM_DIER_UDE; break;
        case TIM1_DMA_DISABLED: TIM1->DIER &= ~(TIM_DIER_UDE); break;
        default: return INVALID_PARAM;
    }

    //configure update event
    switch (cnt_config->update_event) {
        case TIM1_UPDATE_EVENT_ENABLED: TIM1->CR1  &= ~(TIM_CR1_UDIS); break;
        case TIM1_UPDATE_EVENT_DISABLED: TIM1->CR1 |= TIM_CR1_UDIS; break;
        default: return INVALID_PARAM; 
    }

    //configure update request
    switch (cnt_config->update_request) {
        case TIM1_UPDATE_REQ_ALL: TIM1->CR1  &= ~(TIM_CR1_URS); break;
        case TIM1_UPDATE_REQ_FLOW: TIM1->CR1 |= TIM_CR1_URS; break;
        default: return INVALID_PARAM;
    }

    //enable the counter
    TIM1->CR1 |= TIM_CR1_CEN;

    //record utilised interrupt priority level
    if (cnt_config->interrupt_enable) {
        priority_tracker[cnt_config->interrupt_priority] = 1U;
    }
    
    DSB();
    return SUCCESS;
}

/**
 * @brief  Initialises TIM1 as a time base in milli-seconds
 * @note   This function is called independent of counter initialisation via @ref TIM1_CNT_Init
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_MS_Base_Init(void) {
    //set global tim1 time to 0
    g_tim1_time = 0;

    //calculate appropriate prescaler value based on system clock frequency
    uint16_t prescaler_val = 0UL;
    if (g_sys_clk_source == HSI_CLOCK) {
        prescaler_val = 16UL;
    } else if (g_sys_clk_source == HSE_CLOCK) {
        prescaler_val = 25UL;
    }

    //configure settings for time base
    TIM1_CNT_Config_t base_config = {
        .auto_reload = (1000UL - 1UL),
        .prescaler   = prescaler_val,
        .interrupt_enable = TIM1_INTERRUPT_ENABLED
    };
    
    return TIM1_CNT_Init(&base_config);
}

/**
 * @brief  Delays program execution
 * @note   Assumes TIM1 has been configured as a time base unit via @ref TIM1_Base_Init
 * @param  time_delay: The desired time delay in milli-seconds
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_Delay(uint32_t time_delay) {
    //validate delay
    if (time_delay <= 0) {
        return INVALID_PARAM;
    }

    //save current tim1 time
    uint32_t prev_tim1_time = g_tim1_time;

    //wait for time delay to elapse
    while ((g_tim1_time - prev_tim1_time) < time_delay) {
        NOP();
    }

    return SUCCESS;
}

/**
 * @brief  Initialises TIM1 in input capture mode
 * @note   Can be called independent of counter initialisation via @ref TIM1_CNT_Init
 * @param  ic_config: Pointer to TIM1_IC_Config structure containing input capture settings
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_IC_Init(TIM1_IC_Config_t *ic_config) {
    //validate config struct pointer
    if (!ic_config) {
        return INVALID_PARAM;
    }

    //validate channel
    if (Validate_TIM1_Channel(ic_config->channel) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    //validate interrupt priority level and selection
    if (Validate_Priority(ic_config->interrupt_priority) == INVALID_PARAM
        || ic_config->selection                          == TIM1_CC_OUTPUT) {
        return INVALID_PARAM;
    }

    //validate availability of interrupt priority level
    if (ic_config->interrupt_enable) {
        if (priority_tracker[ic_config->interrupt_priority]) {
            return INVALID_PARAM;
        }
    }

    //enable TIM1 clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    //disable capture
    TIM1->CCER &= ~(SET_ONE << ((ic_config->channel - 1U) * 4U));

    //configure TIM1 channel as input
    uint8_t ccmr_shift = (ic_config->channel % 2) ? 0 : 8;
    uint8_t ccmr_reg   = (ic_config->channel <= 2) ? 0 : 1;
    if (ccmr_reg == 0) {
        //configure input mapping
        TIM1->CCMR1 &= ~(SET_THREE << ccmr_shift);
        TIM1->CCMR1 |= (((uint32_t) ic_config->selection) << ccmr_shift);
        //configure input prescaler
        TIM1->CCMR1 &= ~(SET_TWO << (ccmr_shift + 2U));
        TIM1->CCMR1 |= (((uint32_t) ic_config->prescaler) << (ccmr_shift + 2U));
        //configure input filter
        TIM1->CCMR1 &= ~(SET_FOUR << (ccmr_shift + 4U));
        TIM1->CCMR1 |= (((uint32_t) ic_config->filter) << (ccmr_shift + 4U));
    } else {
        //configure input mapping
        TIM1->CCMR2 &= ~(SET_THREE << ccmr_shift);
        TIM1->CCMR2 |= (((uint32_t) ic_config->selection) << ccmr_shift);
        //configure input prescaler
        TIM1->CCMR2 &= ~(SET_TWO << (ccmr_shift + 2U));
        TIM1->CCMR2 |= (((uint32_t) ic_config->prescaler) << (ccmr_shift + 2U));
        //configure input filter
        TIM1->CCMR2 &= ~(SET_FOUR << (ccmr_shift + 4U));
        TIM1->CCMR2 |= (((uint32_t) ic_config->filter) << (ccmr_shift + 4U));
    }

    //configure polarity
    TIM1->CCER |= (((uint32_t) ic_config->polarity) << (1U + ((ic_config->channel - 1) * 4U)));
    switch (ic_config->polarity) {
        case TIM1_CC_NON_INV_RISING: {
            TIM1->CCER &= ~(SET_ONE << (1U + ((ic_config->channel - 1) * 4U)));
            TIM1->CCER &= ~(SET_ONE << (3U + ((ic_config->channel - 1) * 4U)));
        }
        break;
        case TIM1_CC_INV_FALLING: {
            TIM1->CCER |= (SET_ONE << (1U + ((ic_config->channel - 1) * 4U)));
            TIM1->CCER &= ~(SET_ONE << (3U + ((ic_config->channel - 1) * 4U)));
        }
        break;
        case TIM1_CC_NON_INV_BOTH: {
            TIM1->CCER |= (SET_ONE << (1U + ((ic_config->channel - 1) * 4U)));
            TIM1->CCER |= (SET_ONE << (3U + ((ic_config->channel - 1) * 4U)));
        }
        break;
        default: return INVALID_PARAM;
    }
    
    //configure interrupts
    switch (ic_config->interrupt_enable) {
        case TIM1_CC_INTERRUPT_ENABLED: {
            TIM1->DIER |= (SET_ONE << ic_config->channel);
            DISABLE_IRQ();
            NVIC_Set_Priority(TIM1_CC_IRQn, ic_config->interrupt_priority);
            NVIC_Enable_IRQ(TIM1_CC_IRQn);
            ENABLE_IRQ();
            break;
        }
        case TIM1_CC_INTERRUPT_DISABLED: TIM1->DIER &= ~(SET_ONE << ic_config->channel); break;
        default: return INVALID_PARAM;
    }

    //configure DMA
    switch (ic_config->dma_enable) {
        case TIM1_CC_DMA_ENABLED: TIM1->DIER  |= (SET_ONE << (ic_config->channel + 8U)); break;
        case TIM1_CC_DMA_DISABLED: TIM1->DIER &= ~(SET_ONE << (ic_config->channel + 8U)); break;
        default: return INVALID_PARAM;
    }
        
    //enable capture
    TIM1->CCER |= (SET_ONE << ((ic_config->channel - 1U) * 4U));

    //enable counter
    if (!(TIM1->CR1 & TIM_CR1_CEN)) {
        TIM1->CR1 |= TIM_CR1_CEN;
    }

    //record utilised interrupt priority level
    if (ic_config->interrupt_enable) {
        priority_tracker[ic_config->interrupt_priority] = 1U;
    }

    DSB();
    return SUCCESS;
}

/**
 * @brief  Initialises TIM1 in PWM input mode
 * @note   Can be called independent of counter initialisation via @ref TIM1_CNT_Init
 * @param  pwm_input_config: Pointer to TIM1_PWM_Input_Config structure containing PWM input settings
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_PWM_Input_Init(TIM1_PWM_Input_Config_t *pwm_input_config) {
    //validate config struct pointer
    if (!pwm_input_config) {
        return INVALID_PARAM;
    }

    //validate channel pair
    if (!((pwm_input_config->channel_1  == TIM1_CHANNEL_1 && pwm_input_config->channel_2 == TIM1_CHANNEL_2)
        || (pwm_input_config->channel_1 == TIM1_CHANNEL_2 && pwm_input_config->channel_2 == TIM1_CHANNEL_1))) {
        return INVALID_PARAM;
    }

    //configure channel 1
    TIM1_IC_Config_t input_channel_1 = {
        .channel            = pwm_input_config->channel_1,
        .selection          = pwm_input_config->selection_1,
        .prescaler          = pwm_input_config->prescaler_1,
        .filter             = pwm_input_config->filter_1,
        .polarity           = pwm_input_config->polarity_1,
        .interrupt_enable   = pwm_input_config->interrupt_enable_1,
        .interrupt_priority = pwm_input_config->interrupt_priority_1,
        .dma_enable         = pwm_input_config->dma_enable_1
    };

    //configure channel 2
    TIM1_IC_Config_t input_channel_2 = {
        .channel            = pwm_input_config->channel_2,
        .selection          = pwm_input_config->selection_2,
        .prescaler          = pwm_input_config->prescaler_2,
        .filter             = pwm_input_config->filter_2,
        .polarity           = pwm_input_config->polarity_2,
        .interrupt_enable   = pwm_input_config->interrupt_enable_2,
        .interrupt_priority = pwm_input_config->interrupt_priority_2,
        .dma_enable         = pwm_input_config->dma_enable_2
    };

    //configure trigger input
    TIM1->SMCR &= ~(TIM_SMCR_TS);
    switch (pwm_input_config->trigger_selection) {
        case TIM1_FILTERED_TI1: TIM1->SMCR |= TIM_SMCR_TS_TI1FP1; break;
        case TIM1_FILTERED_TI2: TIM1->SMCR |= TIM_SMCR_TS_TI2FP2; break;
        default: return INVALID_PARAM;  
    }

    //configure slave mode controller in reset mode
    TIM1->SMCR &= ~(TIM_SMCR_SMS);
    TIM1->SMCR |= TIM_SMCR_SMS_RESET;

    //initialise channel 1 and 2
    if (TIM1_IC_Init(&input_channel_1) == INVALID_PARAM || TIM1_IC_Init(&input_channel_2) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    DSB();
    return SUCCESS;
}

/**
 * @brief  Initialises TIM1 in output compare mode
 * @note   Assumes TIM1 has been configured in counter mode via @ref TIM1_CNT_Init
 * @param  oc_config: Pointer to TIM1_OC_Config structure containing output compare settings
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_OC_Init(TIM1_OC_Config_t *oc_config) {
    //validate config struct pointer
    if (!oc_config) {
        return INVALID_PARAM;
    }

    //validate channel
    if (Validate_TIM1_Channel(oc_config->channel) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    //validate output compare mode
    if (oc_config->oc_mode    != TIM1_OCM_FROZEN         && oc_config->oc_mode != TIM1_OCM_ACTIVE 
        && oc_config->oc_mode != TIM1_OCM_INACTIVE       && oc_config->oc_mode != TIM1_OCM_TOGGLE 
        && oc_config->oc_mode != TIM1_OCM_FORCE_INACTIVE && oc_config->oc_mode != TIM1_OCM_FORCE_ACTIVE 
        && oc_config->oc_mode != TIM1_OCM_PWM_1          && oc_config->oc_mode != TIM1_OCM_PWM_2) {
            return INVALID_PARAM;
        }

    //validate availability of interrupt priority level
    if (oc_config->interrupt_enable) {
        if (priority_tracker[oc_config->interrupt_priority]) {
            return INVALID_PARAM;
        }
    }

    //validate auto reload and compare value
    if (Validate_uint16_t(oc_config->compare_value)   == INVALID_PARAM
        || Validate_uint16_t(oc_config->auto_reload)  == INVALID_PARAM
        || Validate_uint16_t(oc_config->prescaler)    == INVALID_PARAM) {
            return INVALID_PARAM;
    } else {
        oc_config->compare_value = (uint16_t) oc_config->compare_value;
        oc_config->auto_reload   = (uint16_t) oc_config->auto_reload;
        oc_config->prescaler     = (uint16_t) oc_config->prescaler;
    }

    //disable compare
    TIM1->CCER &= ~(SET_ONE << ((oc_config->channel - 1U) * 4U));

    //write values to ARR, PSC and CCRx
    TIM1->ARR = (oc_config->auto_reload - 1U);
    TIM1->PSC = (oc_config->prescaler - 1U);
    switch (oc_config->channel) {
        case TIM1_CHANNEL_1: TIM1->CCR1 = oc_config->compare_value; break;
        case TIM1_CHANNEL_2: TIM1->CCR2 = oc_config->compare_value; break;
        case TIM1_CHANNEL_3: TIM1->CCR3 = oc_config->compare_value; break;
        case TIM1_CHANNEL_4: TIM1->CCR4 = oc_config->compare_value; break;
        default: return INVALID_PARAM;
    }

    //configure TIM1 channel as output
    uint8_t ccmr_shift = (oc_config->channel % 2) ? 0 : 8;
    uint8_t ccmr_reg   = (oc_config->channel <= 2) ? 0 : 2;
    if (ccmr_reg == 0) {
        //configure channel as ouput
        TIM1->CCMR1 &= ~(SET_TWO << ccmr_shift);
        //configure output compare mode
        TIM1->CCMR1 &= ~(SET_THREE << (ccmr_shift + 4U));
        TIM1->CCMR1 |= (((uint32_t) oc_config->oc_mode) << (ccmr_shift + 4U));
        //configure preload
        TIM1->CCMR1 |= (((uint32_t) oc_config->preload) << (ccmr_shift + 3U));
        //configure fast enable
        TIM1->CCMR1 |= (((uint32_t) oc_config->fast_enable) << (ccmr_shift + 2U));
    } else {
        //configure channel as output
        TIM1->CCMR2 &= ~(SET_TWO << ccmr_shift);
        //configure output compare mode
        TIM1->CCMR2 &= ~(SET_THREE << (ccmr_shift + 4U));
        TIM1->CCMR2 |= (((uint32_t) oc_config->oc_mode) << (ccmr_shift + 4U));
        //configure preload
        TIM1->CCMR2 |= (((uint32_t) oc_config->preload) << (ccmr_shift + 3U));
        //configure fast enable
        TIM1->CCMR2 |= (((uint32_t) oc_config->fast_enable) << (ccmr_shift + 2U));
    }

    //configure polarity
    TIM1->CCER &= ~(SET_ONE << (1U + ((oc_config->channel - 1U) * 4U)));
    TIM1->CCER |= (((uint32_t) oc_config->polarity) << (1U + ((oc_config->channel - 1U) * 4U)));

    //configure interrupts
    switch (oc_config->interrupt_enable) {
        case TIM1_CC_INTERRUPT_ENABLED: {
            TIM1->DIER |= (SET_ONE << oc_config->channel);
            DISABLE_IRQ();
            NVIC_Set_Priority(TIM1_CC_IRQn, oc_config->interrupt_priority);
            NVIC_Enable_IRQ(TIM1_CC_IRQn);
            ENABLE_IRQ();
            break;
        }
        case TIM1_CC_INTERRUPT_DISABLED: TIM1->DIER &= ~(SET_ONE << oc_config->channel); break;
        default: return INVALID_PARAM;
    }

    //configure dma
    switch (oc_config->dma_enable) {
        case TIM1_CC_DMA_ENABLED: TIM1->DIER  |= (SET_ONE << (oc_config->channel + 8U)); break;
        case TIM1_CC_DMA_DISABLED: TIM1->DIER &= ~(SET_ONE << (oc_config->channel + 8U)); break;
        default: return INVALID_PARAM;
    }

    //enable compare
    TIM1->CCER |= (SET_ONE << ((oc_config->channel - 1U) * 4U));

    //enable main output
    TIM1->BDTR |= TIM_BDTR_MOE;

    //enable counter
    if (!(TIM1->CR1 & TIM_CR1_CEN)) {
        TIM1->CR1 |= TIM_CR1_CEN;
    }

    //record utilised interrupt priority level
    if (oc_config->interrupt_enable) {
        priority_tracker[oc_config->interrupt_priority] = 1U;
    }
    
    DSB();
    return SUCCESS;
}

/**
 * @brief  Initialises TIM1 in PWM output mode
 * @note   Assumes TIM1 has been configured in counter mode via @ref TIM1_CNT_Init
 * @param  pwm_output_config: Pointer to TIM1_PWM_Output_Config structure containing PWM output settings
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_PWM_Output_Init(TIM1_PWM_Output_Config_t *pwm_output_config) {
    //validate config struct pointer
    if (!pwm_output_config) {
        return INVALID_PARAM;
    }

    //validate channel
    if (Validate_TIM1_Channel(pwm_output_config->channel) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    //validate duty cycle
    if (pwm_output_config->duty_cycle < 0 || pwm_output_config->duty_cycle > 1) {
        return INVALID_PARAM;
    }

    //configure channel as PWM output
    TIM1_OC_Config_t pwm_channel = {
        .channel            = pwm_output_config->channel,
        .auto_reload        = pwm_output_config->auto_reload,
        .compare_value      = (uint16_t)(((float) pwm_output_config->auto_reload) 
                              * pwm_output_config->duty_cycle),
        .oc_mode            = pwm_output_config->oc_mode,
        .preload            = pwm_output_config->preload,
        .polarity           = pwm_output_config->polarity,
        .fast_enable        = pwm_output_config->fast_enable,
        .interrupt_enable   = pwm_output_config->interrupt_enable,
        .interrupt_priority = pwm_output_config->interrupt_priority,
        .dma_enable         = pwm_output_config->dma_enable
    };

    //intialise PWM channel
    if (TIM1_OC_Init(&pwm_channel) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    DSB();
    return SUCCESS;
}


/**
 * @brief  Sets the PWM duty cycle for a particular TIM1 channel
 * @note   Assumes TIM1 has been configured in PWM output mode via @ref TIM1_PWM_Output_Init
 * @param  channel:    TIM1 channel whose duty cycle will be set
 * @param  duty_cycle: Duty cycle as a decimal (0.0 - 1.0)
 * @retval Status indicating success or invalid parameters
 */
Status TIM1_PWM_Set_Duty_Cycle(TIM1_Channel channel, float duty_cycle) {
    //validate duty cycle
    if (duty_cycle < 0 || duty_cycle > 1) {
        return INVALID_PARAM;
    }

    //calculate compare value
    uint16_t compare_value = (uint16_t)(((float) TIM1->ARR) * duty_cycle);

    //update compare value
    switch (channel) {
        case TIM1_CHANNEL_1: TIM1->CCR1 = compare_value; break;
        case TIM1_CHANNEL_2: TIM1->CCR2 = compare_value; break;
        case TIM1_CHANNEL_3: TIM1->CCR3 = compare_value; break;
        case TIM1_CHANNEL_4: TIM1->CCR4 = compare_value; break;
        default: return INVALID_PARAM;
    }

    DSB();
    return SUCCESS;
}

/**
 * @brief  Deinitialises TIM1
 * @retval Status indicating success
 */
Status TIM1_Deinit(void) {
    //disable tim1
    TIM1->CR1 &= ~(TIM_CR1_CEN);

    //disable interrupts and dma requests
    TIM1->DIER = CLEAR_REGISTER;

    //disable tim1 clock
    RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN);

    //reset tim1
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST;

    return SUCCESS;
}


/**********************************************************************************/
/*                              TIM1 Other Functions                              */
/**********************************************************************************/

Status TIM1_Servo_Init(TIM1_Channel channel) {
    //configure PWM output
    TIM1_PWM_Output_Config_t config = {
        .channel = channel,
        .auto_reload = (20000UL - 1UL),
        .duty_cycle = 0.0,
        .oc_mode = TIM1_OCM_PWM_1,
        .polarity = TIM1_CC_ACTIVE_HIGH,
        .preload = TIM1_OC_PRELOAD_ENABLED
    };

    //initialise PWM output
    if (TIM1_PWM_Output_Init(&config) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    return SUCCESS;
}

Status TIM1_Servo_Set_Position(TIM1_Channel channel, float degrees) {
    //validate degrees
    if (degrees < 0 || degrees > 180) {
        return INVALID_PARAM;
    }

    //calculate duty cycle
    float duty_cycle = (0.03 + ((degrees / 180.0) * 0.09));

    //set duty cycle
    if (TIM1_PWM_Set_Duty_Cycle(channel, duty_cycle) == INVALID_PARAM) {
        return INVALID_PARAM;
    }

    return SUCCESS;
}

Status Validate_TIM1_Channel(TIM1_Channel channel) {
    if (channel != TIM1_CHANNEL_1 && channel != TIM1_CHANNEL_2 && channel != TIM1_CHANNEL_3 
        && channel != TIM1_CHANNEL_4) {
            return INVALID_PARAM;
        }
    
    return SUCCESS;
}


/**********************************************************************************/
/*                             TIM1 Interrupt Handlers                            */
/**********************************************************************************/

/** @brief  Handles TIM1 update and TIM10 global interrupts */
void TIM1_UP_TIM10_IRQHandler(void) {
    if (TIM1->SR & TIM_SR_UIF) {
        TIM1->SR &= ~(TIM_SR_UIF);
        g_tim1_time++;
    }
}

/** @brief  Handles TIM1 capture and compare interrupts */
void TIM1_CC_IRQHandler(void) {
    if (TIM1->SR & TIM_SR_CC1IF) {
        TIM1->SR &= ~(TIM_SR_CC1IF);
        g_prev_cc1 = g_curr_cc1;
        g_curr_cc1 = TIM1->CCR1;
        if (g_prev_cc1 > 0) {
            if (g_curr_cc1 > g_prev_cc1) {
                g_pwm_input_period = (g_curr_cc1 - g_prev_cc1) * g_tim1_tick_time;
                g_pwm_input_duty_cycle = (g_pwm_input_pulse_width / g_pwm_input_period);
            } else {
                g_pwm_input_period = ((TIM1_CNT_VAL_MAX + g_curr_cc1 + 1) - g_prev_cc1) * g_tim1_tick_time;
                g_pwm_input_duty_cycle = (g_pwm_input_pulse_width / g_pwm_input_period);
            }
        }          
    } else if (TIM1->SR & TIM_SR_CC2IF) {
        TIM1->SR &= ~(TIM_SR_CC2IF);
        uint32_t cc2_value = TIM1->CCR2;
        if (cc2_value > g_curr_cc1) {
            g_pwm_input_pulse_width = (cc2_value - g_curr_cc1) * g_tim1_tick_time;
        } else {
            g_pwm_input_pulse_width = ((TIM1_CNT_VAL_MAX + cc2_value + 1) - g_curr_cc1) * g_tim1_tick_time;
        }
    }
}

