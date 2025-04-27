/* This file contains functions common across STM32 Blackpill projects */

#include "utils.h"

/**********************************************************************************/
/*                                  RCC Functions                                 */
/**********************************************************************************/

void Peripheral_Reset(void) {
    RCC->AHB1RSTR = 0x00000000;
    RCC->AHB2RSTR = 0x00000000;
    RCC->APB1RSTR = 0x00000000;
    RCC->APB2RSTR = 0x00000000;
}

Status System_Clock_Init(System_Clock_Source clock_source) {
    switch(clock_source) {
        case HSI_CLOCK: {
            RCC->CR |= RCC_CR_HSION;
            do {} while (!(RCC->CR & RCC_CR_HSIRDY));
            RCC->CFGR &= ~(RCC_CFGR_SW);
            g_sys_clk_source = HSI_CLOCK;
            g_sys_clk_freq = HSI_FREQ_HZ;
            return SUCCESS;
        }
        case HSE_CLOCK: {
            RCC->CR |= RCC_CR_HSEON;
            do {} while (!(RCC->CR & RCC_CR_HSERDY));
            RCC->CFGR |= RCC_CFGR_SW_0;
            g_sys_clk_source = HSE_CLOCK;
            g_sys_clk_freq = HSE_FREQ_HZ;
            return SUCCESS;
        }
        default: return INVALID_PARAM;
    }

    return ERROR;
}


/**********************************************************************************/
/*                                 SYSTICK Functions                              */
/**********************************************************************************/

void Delay_Loop(uint32_t delay_ms) {
    if (delay_ms <= 0) {
        return;
    }
    uint32_t ticks_per_ms = (g_sys_clk_freq / SEC_TO_MILLI);
    uint32_t systick_reload_val = ((ticks_per_ms * delay_ms)  - 1UL);
    SYSTICK->CTRL &= ~(SYSTICK_CTRL_ENABLE);

    while (systick_reload_val > 0) {
        if (systick_reload_val <= SYSTICK_LOAD_RELOAD) {
            if (delay_ms <= 1000) {
                systick_reload_val = ((systick_reload_val * 55) / 100);
            }
            SYSTICK->LOAD = systick_reload_val;
            SYSTICK->VAL = CLEAR_REGISTER;
            SYSTICK->CTRL |= SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_ENABLE;
            while (!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG)) {
                NOP();
            }
            systick_reload_val = 0;
            return;
        } else {
            SYSTICK->LOAD = SYSTICK_LOAD_RELOAD;
            SYSTICK->VAL = CLEAR_REGISTER;
            SYSTICK->CTRL |= SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_ENABLE;
            while (!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG)) {
                NOP();
            }
            systick_reload_val -= SYSTICK_LOAD_RELOAD;
        }
        SYSTICK->CTRL &= ~(SYSTICK_CTRL_ENABLE);
    }
}

/**
 * @brief  Initialises Systick as a time base
 * @param  unit: Unit of time for the time base. Limited to seconds, milliseconds and microseconds
 * @retval Status indicating success or invalid parameters
 */
Status Systick_Init(Systick_Base_Unit unit) {
    //initialise global systick time base
    g_systick_time = 0;

    //validate unit measure of systick time base
    if (unit != SYSTICK_UNIT_SEC && unit != SYSTICK_UNIT_MILLI && unit != SYSTICK_UNIT_MICRO && unit) {
        return INVALID_PARAM;
    }

    //calculate reload value
    uint32_t ticks_per_unit;
    switch (unit) {
        case SYSTICK_UNIT_SEC:   ticks_per_unit = g_sys_clk_freq; break;
        case SYSTICK_UNIT_MILLI: ticks_per_unit = (g_sys_clk_freq / SEC_TO_MILLI); break;
        case SYSTICK_UNIT_MICRO: ticks_per_unit = (g_sys_clk_freq / SEC_TO_MICRO); break;
        default: return INVALID_PARAM;
    }
    uint32_t reload_val = (ticks_per_unit - 1UL);

    //validate reload value
    if (reload_val > 0xFFFFFF) {
        reload_val = 0xFFFFFF;
    }

    //configure systick
    SYSTICK->CTRL &= ~(SYSTICK_CTRL_ENABLE);
    SYSTICK->LOAD = reload_val;
    SYSTICK->VAL = CLEAR_REGISTER;
    SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_TICKINT;

    return SUCCESS;
}

/**
 * @brief  Delays program execution
 * @note   Assumes Systick has been configured as a time base unit via @ref Systick_Init
 * @param  time_delay: The desired time delay
 * @retval Status indicating success or invalid parameters
 */
Status Systick_Delay(uint32_t time_delay) {
    //validate time delay
    if (time_delay <= 0) {
        return INVALID_PARAM;
    }

    //wait for time delay to elapse
    uint32_t previous_sys_time = g_systick_time;
    while ((g_systick_time - previous_sys_time) < time_delay) {
        NOP();
    }

    return SUCCESS;
}


/**********************************************************************************/
/*                        Integer Size Validation Functions                       */
/**********************************************************************************/

Status Validate_uint8_t(int value) {
    if (value < 0 || value > 0xFF) {
        return INVALID_PARAM;
    } else {
        return SUCCESS;
    }
}

Status Validate_uint16_t(int value) {
    if (value < 0 || value > 0xFFFF) {
        return INVALID_PARAM;
    } else {
        return SUCCESS;
    }
}


/**********************************************************************************/
/*                                 TIM1 Functions                                 */
/**********************************************************************************/

Status TIM1_CC1_PWM_Output_Config(float duty_cycle_input) {
    if (duty_cycle_input > 1 || duty_cycle_input < 0) {
        return ERROR;
    }

    TIM1->CR1 &= ~(TIM_CR1_DIR);
    if (g_sys_clk_source == HSI_CLOCK) {
        TIM1->PSC = 16000UL;
        g_tim1_tick_time = (1 / (((float) g_sys_clk_freq) / ((float) TIM1->PSC)));
    } else if (g_sys_clk_source == HSE_CLOCK) {
        TIM1->PSC = 25000UL;
        g_tim1_tick_time = (1 / (((float) g_sys_clk_freq) / ((float) TIM1->PSC)));
    }
    TIM1->CR1 |= TIM_CR1_ARPE;
    TIM1->ARR = (1000UL - 1UL);

    TIM1->CCER &= ~(TIM_CCER_CC1E);

    TIM1->CCMR1 &= ~(TIM_CCMR1_CC1S);

    TIM1->CCR1 = (uint32_t)(((float) TIM1->ARR) * duty_cycle_input);

    TIM1->CCMR1 |= TIM_CCMR1_OC1PE;

    TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M);
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_PWM_TWO;

    TIM1->CCER &= ~(TIM_CCER_CC1P);

    TIM1->CCER |= TIM_CCER_CC1E;

    TIM1->BDTR |= TIM_BDTR_MOE;

    TIM1->CR1 |= TIM_CR1_CEN;

    return SUCCESS;
}

Status TIM1_CC1_PWM_Servo_Init(void) {
    TIM1->CR1 &= ~(TIM_CR1_DIR);
    if (g_sys_clk_source == HSI_CLOCK) {
        TIM1->PSC = 16UL;
    } else if (g_sys_clk_source == HSE_CLOCK) {
        TIM1->PSC = 25UL;
    }
    TIM1->CR1 |= TIM_CR1_ARPE;
    TIM1->ARR = (20000UL - 1UL);

    //TIM1->CCR1 = 1500UL;

    TIM1->CCER &= ~(TIM_CCER_CC1E);

    TIM1->CCMR1 &= ~(TIM_CCMR1_CC1S);

    TIM1->CCMR1 |= TIM_CCMR1_OC1PE;

    TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M);
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_PWM_ONE;

    TIM1->CCER &= ~(TIM_CCER_CC1P);

    TIM1->CCER |= TIM_CCER_CC1E;

    TIM1->BDTR |= TIM_BDTR_MOE;

    TIM1->CR1 |= TIM_CR1_CEN;

    return SUCCESS;
}

Status TIM1_CC1_PWM_Servo_Set_Position(float rotate_degrees) {
    if (rotate_degrees < 0 || rotate_degrees > 180) {
        return ERROR;
    }
    float duty_cycle = (0.03 + ((rotate_degrees / 180.0) * 0.09));
    TIM1->CCR1 = (uint32_t)(((float) TIM1->ARR) * duty_cycle);
    TIM1->EGR |= TIM_EGR_UG;
    return SUCCESS;
}

/**********************************************************************************/
/*                                  NVIC Functions                                */
/**********************************************************************************/

Status NVIC_Enable_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        NVIC->ISER[((uint32_t) IRQn) >> DIV_BY_32] = ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        return SUCCESS;       
    }
    return ERROR;
}

Status NVIC_Disable_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        NVIC->ICER[((uint32_t) IRQn) >> DIV_BY_32] = ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        return SUCCESS;
    }
    return ERROR;
}

uint32_t NVIC_Get_Enable_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        uint32_t enable_status = (NVIC->ISER[((uint32_t) IRQn) >> DIV_BY_32]) & ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        if (enable_status == 0) {
            return ((uint32_t) 0U);
        } else {
            return ((uint32_t) 1U);
        }
    } else {
        return ((uint32_t) 0U);
    }
}

Status NVIC_Set_Pending_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        NVIC->ISPR[((uint32_t) IRQn) >> DIV_BY_32] = ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        return SUCCESS;
    }
    return ERROR;
}

Status NVIC_Clear_Pending_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        NVIC->ICPR[((uint32_t) IRQn) >> DIV_BY_32] = ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        return SUCCESS;
    }
    return ERROR;
}

uint32_t NVIC_Get_Pending_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        uint32_t pending_status = (NVIC->ISPR[((uint32_t) IRQn) >> DIV_BY_32]) & ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        if (pending_status == 0) {
            return ((uint32_t) 0U);
        } else {
            return ((uint32_t) 1U);
        }
    } else {
        return ((uint32_t) 0U);
    }
}

uint32_t NVIC_Get_Active_IRQ(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        uint32_t active_status = (NVIC->IABR[((uint32_t) IRQn) >> DIV_BY_32]) & ((uint32_t) (1UL << (((uint32_t) IRQn) & 0x1FUL)));
        if (active_status == 0) {
            return ((uint32_t) 0U);
        } else {
            return ((uint32_t) 1U);
        }
    } else {
        return ((uint32_t) 0U);
    }
}

Status NVIC_Set_Priority(IRQn_t IRQn, uint32_t priority) {
    if ((int32_t) IRQn >= 0) {
        NVIC->IPR[(uint32_t) IRQn] = ((uint8_t) ((priority << NVIC_PRIORITY_BITS) & 0xFFUL));
        return SUCCESS;
    } else {
        uint8_t shpr_array_position = ((uint8_t) IRQn) + ((uint8_t) 0xC);
        if (shpr_array_position < 0) {
            return ERROR;
        } else {
            SCB->SHPR[shpr_array_position] = ((uint8_t) ((priority << NVIC_PRIORITY_BITS) & 0xFFUL));
            return SUCCESS;
        }
    }      
}

uint32_t NVIC_Get_Priority(IRQn_t IRQn) {
    if ((int32_t) IRQn >= 0) {
        uint32_t priority_status = (NVIC->IPR[(uint32_t) IRQn] >> NVIC_PRIORITY_BITS);
        return priority_status;
    } else {
        uint8_t shpr_array_position = ((uint8_t) IRQn) + ((uint8_t) 0xC);
        if (shpr_array_position < 0) {
            return (uint32_t) ERROR;
        } else {
            uint32_t priority_status = (SCB->SHPR[shpr_array_position] >> NVIC_PRIORITY_BITS);
            return priority_status;
        }
    }
}

Status Validate_Priority(uint32_t priority) {
    if (priority < 0 || priority > 0xFF) {
        return INVALID_PARAM;
    } else {
        return SUCCESS;
    }
}

uint8_t priority_tracker[256];


/**********************************************************************************/
/*                               Interrupt Handlers                               */
/**********************************************************************************/
void SysTick_Handler(void) {
    g_systick_time++;
}




