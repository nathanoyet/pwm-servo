#ifndef __TIM1_H
#define __TIM1_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "../../utils/utils.h"

/**********************************************************************************/
/*                                      Enums                                     */
/**********************************************************************************/

typedef enum {
    TIM1_DIR_UP = 0,
    TIM1_DIR_DOWN
} TIM1_Direction;

typedef enum {
    TIM_CENTRE_MODE_EDGE = 0,
    TIM1_CENTRE_MODE_DOWN,
    TIM1_CENTRE_MODE_UP,
    TIM1_CENTRE_MODE_BOTH
} TIM1_Centre_Aligned;

typedef enum {
    TIM1_INTERRUPT_DISABLED = 0,
    TIM1_INTERRUPT_ENABLED
} TIM1_Interrupt;

typedef enum {
    TIM1_DMA_DISABLED = 0,
    TIM1_DMA_ENABLED
} TIM1_DMA;

typedef enum {
    TIM1_UPDATE_EVENT_ENABLED = 0,
    TIM1_UPDATE_EVENT_DISABLED
} TIM1_Update_Event;

typedef enum {
    TIM1_UPDATE_REQ_ALL = 0,
    TIM1_UPDATE_REQ_FLOW
} TIM1_Update_Request;

typedef enum {
    TIM1_CHANNEL_1 = 1,
    TIM1_CHANNEL_2,
    TIM1_CHANNEL_3,
    TIM1_CHANNEL_4
} TIM1_Channel;

typedef enum {
    CC_OUTPUT = 0,
    CC_INPUT_MAP_EQ,
    CC_INPUT_MAP_ALT,
    CC_INPUT_MAP_TRC
} TIM1_CC_Selection;

typedef enum {
    CC_PSC_0 = 0,
    CC_PSC_2,
    CC_PSC_4,
    CC_PSC_8
} TIM1_CC_Prescaler;

typedef enum {
    CC_FILTER_0 = 0,
    CC_FILTER_1,
    CC_FILTER_2,
    CC_FILTER_3,
    CC_FILTER_4,
    CC_FILTER_5,
    CC_FILTER_6,
    CC_FILTER_7,
    CC_FILTER_8,
    CC_FILTER_9,
    CC_FILTER_10,
    CC_FILTER_11,
    CC_FILTER_12,
    CC_FILTER_13,
    CC_FILTER_14,
    CC_FILTER_15
} TIM1_CC_Filter;

typedef enum {
    CC_ACTIVE_HIGH = 0,
    CC_ACTIVE_LOW
} TIM1_CC_Polarity;

typedef enum {
    CC_INTERRUPT_DISABLED = 0,
    CC_INTERRUPT_ENABLED
} TIM1_CC_Interrupt;

typedef enum {
    CC_DMA_DISABLED = 0,
    CC_DMA_ENABLED
} TIM1_CC_DMA;

typedef enum {
    INTERNAL_TRG_0 = 0,
    INTERNAL_TRG_1,
    INTERNAL_TRG_2,
    INTERNAL_TRG_3,
} TIM1_INT_TRG_Selection;

typedef enum {
    TI1_EDGE_DETECTOR = 0,
    FILTERED_TI1,
    FILTERED_TI2,
    EXTERNAL_TRG_INPUT
} TIM1_EXT_TRG_Selection;

typedef enum {
    OCM_FROZEN = 0,
    OCM_ACTIVE,
    OCM_INACTIVE,
    OCM_TOGGLE,
    OCM_FORCE_INACTIVE,
    OCM_FORCE_ACTIVE,
    OCM_PWM_1,
    OCM_PWM_2
} TIM1_OC_Mode;

typedef enum {
    OC_PRELOAD_DISABLED = 0,
    OC_PRELOAD_ENABLED
} TIM1_OC_Preload;

typedef enum {
    OC_FAST_ENABLE_OFF = 0,
    OC_FAST_ENABLE_ON
} TIM1_OC_Fast_Enable;


/**********************************************************************************/
/*                              Configuration Structs                             */
/**********************************************************************************/

typedef struct {
/************************************ Required ************************************/
    int                 prescaler;
    int                 auto_reload;
/************************************ Optional ************************************/
    TIM1_Direction      direction;
    TIM1_Centre_Aligned centre_aligned_mode;
    int                 repetition;
    TIM1_Interrupt      interrupt_enable;
    uint32_t            interrupt_priority;
    TIM1_DMA            dma_enable;
    TIM1_Update_Event   update_event;
    TIM1_Update_Request update_request;
} TIM1_CNT_Config;

typedef struct {
/************************************ Required ************************************/
    TIM1_Channel      channel;
    TIM1_CC_Selection selection;
/************************************ Optional ************************************/
    TIM1_CC_Prescaler prescaler;
    TIM1_CC_Filter    filter;
    TIM1_CC_Polarity  polarity;                //review IC polarity settings in CCER
    TIM1_CC_Interrupt interrupt_enable;
    uint32_t          interrupt_priority;     
    TIM1_CC_DMA       dma_enable;
} TIM1_IC_Config;

typedef struct {
/************************************ Required ************************************/
    TIM1_Channel           channel_1;
    TIM1_Channel           channel_2;
    TIM1_CC_Selection      selection_1;
    TIM1_CC_Selection      selection_2;
/************************************ Optional ************************************/
    TIM1_CC_Prescaler      prescaler_1;
    TIM1_CC_Prescaler      prescaler_2;
    TIM1_CC_Filter         filter_1;
    TIM1_CC_Filter         filter_2;
    TIM1_CC_Polarity       polarity_1;
    TIM1_CC_Polarity       polarity_2;
    TIM1_CC_Interrupt      interrupt_enable_1;
    TIM1_CC_Interrupt      interrupt_enable_2;
    uint32_t               interrupt_priority_1;
    uint32_t               interrupt_priority_2;
    TIM1_CC_DMA            dma_enable_1;
    TIM1_CC_DMA            dma_enable_2;
    TIM1_EXT_TRG_Selection trigger_selection;
} TIM1_PWM_Input_Config;

typedef struct {
/************************************ Required ************************************/
    TIM1_Channel        channel;
    int                 auto_reload;
    int                 prescaler;
    int                 compare_value;
    TIM1_OC_Mode        oc_mode;
/************************************ Optional ************************************/
    TIM1_OC_Preload     preload;
    TIM1_CC_Polarity    polarity;
    TIM1_OC_Fast_Enable fast_enable;
    TIM1_CC_Interrupt   interrupt_enable;
    uint32_t            interrupt_priority;
    TIM1_CC_DMA         dma_enable;
} TIM1_OC_Config;

typedef struct {
/************************************ Required ************************************/
    TIM1_Channel        channel;
    int                 auto_reload;
    float               duty_cycle;
    TIM1_OC_Mode        oc_mode;
/************************************ Optional ************************************/
    TIM1_OC_Preload     preload;
    TIM1_CC_Polarity    polarity;
    TIM1_OC_Fast_Enable fast_enable;
    TIM1_CC_Interrupt   interrupt_enable;
    uint32_t            interrupt_priority;
    TIM1_CC_DMA         dma_enable;
} TIM1_PWM_Output_Config;


/**********************************************************************************/
/*                               Function Prototypes                              */
/**********************************************************************************/

Status TIM1_CNT_Init             (TIM1_CNT_Config *cnt_config);
Status TIM1_MS_Base_Init         (TIM1_CNT_Config *cnt_config);
Status TIM1_Delay                (uint32_t delay_ms);
Status TIM1_IC_Init              (TIM1_IC_Config *ic_config);
Status TIM1_PWM_Input_Init       (TIM1_PWM_Input_Config *pwm_input_config);
Status TIM1_OC_Init              (TIM1_OC_Config *oc_config);
Status TIM1_PWM_Output_Init      (TIM1_PWM_Output_Config *pwm_output_config);
Status TIM1_PWM_Set_Duty_Cycle   (TIM1_Channel channel, float duty_cycle_input);
Status TIM1_Servo_Init           (TIM1_Channel channel);
Status TIM1_Servo_Set_Position   (TIM1_Channel channel, float degrees);
void   TIM1_UP_TIM10_IRQHandler  (void);


#ifdef __cplusplus
    }
#endif

#endif