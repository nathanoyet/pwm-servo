/* This header file contains prototypes of functions and macros common across all STM32 Blackpill projects */

#ifndef __UTILS_H
#define __UTILS_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "../../include/ext_periph_layer.h"
#include "../../include/int_periph_layer.h"
#include <stdint.h>
#include <math.h>


/**********************************************************************************/
/*                                      Enums                                     */
/**********************************************************************************/

typedef enum {
    SUCCESS = 0,
    ERROR,
    INVALID_PARAM
} Status;

typedef enum {
    BIT_SET = 0,
    BIT_RESET,
    BIT_ERROR,
    BIT_INVALID_PARAM
} Bit_State;

typedef enum {
    HSI_CLOCK = 1,
    HSE_CLOCK = 2,
    PLL_CLOCK = 3
} System_Clock_Source;

typedef enum {
    SYSTICK_UNIT_SEC = 0,
    SYSTICK_UNIT_MILLI,
    SYSTICK_UNIT_MICRO
} Systick_Base_Unit;


/**********************************************************************************/
/*                                Global Constants                                */
/**********************************************************************************/

/********************************** System Clock **********************************/
const uint32_t HSI_FREQ_HZ          = 16000000U;
const uint32_t HSE_FREQ_HZ          = 25000000U;
const uint32_t LSI_FREQ_HZ          = 32000U;
const uint32_t LSE_FREQ_HZ          = 32768U;

/*********************************** System Time **********************************/
const uint32_t SEC_TO_MILLI         = 1000U;
const uint32_t SEC_TO_MICRO         = 1000000U;
const uint32_t SEC_TO_NANO          = 1000000000U;

/************************************* Timers *************************************/
const uint32_t TIM1_CNT_VAL_MAX     = (0xFFFFUL);

/*************************** Standard Bit Shift Divisors **************************/
const uint32_t DIV_BY_2             = 1U;
const uint32_t DIV_BY_4             = 2U;
const uint32_t DIV_BY_8             = 3U;
const uint32_t DIV_BY_16            = 4U;
const uint32_t DIV_BY_32            = 8U;


/**********************************************************************************/
/*                                 Constant Macros                                */
/**********************************************************************************/

/******************************* Standard Bit Masks *******************************/
#define SET_ONE                     (0x01UL)
#define SET_TWO                     (0x03UL)
#define SET_THREE                   (0x07UL)
#define SET_FOUR                    (0x0FUL)
#define SET_FIVE                    (0x1FUL)
#define SET_SIX                     (0x2FUL)
#define SET_SEVEN                   (0x3FUL)
#define SET_EIGHT                   (0x4FUL)


/**********************************************************************************/
/*                         Uninitialised Global Variables                         */
/**********************************************************************************/

/********************************** System Clock **********************************/
System_Clock_Source                 g_sys_clk_source;
uint32_t                            g_sys_clk_freq;
volatile uint32_t                   g_systick_time;

/************************************** TIM1 **************************************/
volatile uint32_t                   g_tim1_time;
volatile uint32_t                   g_tim1_subtime;
volatile uint32_t                   g_tim1_subticks_per_tick;
volatile float                      g_tim1_tick_time;
volatile uint32_t                   g_curr_cc1;
volatile uint32_t                   g_prev_cc1;
volatile float                      g_pwm_input_pulse_width;
volatile float                      g_pwm_input_period;
volatile float                      g_pwm_input_duty_cycle;


#define NVIC_PRIORITY_BITS          4U
#define CLEAR_REGISTER              0UL

uint8_t priority_tracker[256];


/**********************************************************************************/
/*                               Function Prototypes                              */
/**********************************************************************************/

/***************************** Reset and Clock Control ****************************/
void   Peripheral_Reset    (void);
Status System_Clock_Init   (System_Clock_Source clock_source);
Status Systick_Init        (Systick_Base_Unit unit);
Status Systick_Delay       (uint32_t time_delay);
void   Delay_Loop          (uint32_t delay_duration_ms);

/***************************** Integer Size Validation ****************************/
Status Validate_uint8_t  (int value);
Status Validate_uint16_t (int value);

/************************************** TIM1 **************************************/
Status TIM1_CC1_PWM_Output_Config      (float duty_cycle_input);
Status TIM1_CC1_PWM_Servo_Init         (void);
Status TIM1_CC1_PWM_Servo_Set_Position (float rotate_degrees);

/********************** Nested Vectored Interrupt Controller **********************/
Status   NVIC_Enable_IRQ        (IRQn_t IRQn);
Status   NVIC_Disable_IRQ       (IRQn_t IRQn);
uint32_t NVIC_Get_Enable_IRQ    (IRQn_t IRQn);
Status   NVIC_Set_Pending_IRQ   (IRQn_t IRQn);
Status   NVIC_Clear_Pending_IRQ (IRQn_t IRQn);
uint32_t NVIC_Get_Pending_IRQ   (IRQn_t IRQn);
uint32_t NVIC_Get_Active_IRQ    (IRQn_t IRQn);
Status   NVIC_Set_Priority      (IRQn_t IRQn, uint32_t priority);
uint32_t NVIC_Get_Priority      (IRQn_t IRQn);
Status   Validate_Priority      (uint32_t priority);


/**********************************************************************************/
/*                          Inline Assembly Instructions                          */
/**********************************************************************************/
__attribute__((always_inline)) static inline void NOP(void) {
    __asm__ volatile("nop");
}

__attribute__((always_inline)) static inline void WFI(void) {
    __asm__ volatile("wfi");
}

__attribute__((always_inline)) static inline void DSB(void) {
    __asm__ volatile("dsb":::"memory");
}

__attribute__((always_inline)) static inline void ENABLE_IRQ(void) {
    __asm__ volatile("cpsie i":::"memory");
}

__attribute__((always_inline)) static inline void DISABLE_IRQ(void) {
    __asm__ volatile("cpsid i":::"memory");
}



#ifdef __cplusplus
    }
#endif

#endif