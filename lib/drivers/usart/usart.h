#ifndef __USART_H
#define __USART_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "../../utils/utils.h"


/**********************************************************************************/
/*                                      Enums                                     */
/**********************************************************************************/

typedef enum {
    USART1_Index = 0,
    USART2_Index,
    USART6_Index,
    USART_Index_Error
} USART_Index;

typedef enum {
    USART_DATA_8 = 0,
    USART_DATA_9
} USART_Word_Length;

typedef enum {
    USART_OVER_16 = 0,
    USART_OVER_8
} USART_Oversampling;

typedef enum {
    USART_STOP_1 = 0,
    USART_STOP_0_5,
    USART_STOP_2,
} USART_Stop_Bits;

typedef enum {
    USART_ONEBIT_3 = 0,
    USART_ONEBIT_1
} USART_One_Bit;

typedef enum {
    USART_PARITY_DISABLED = 0,
    USART_PARITY_ENABLED
} USART_Parity_Control;

typedef enum {
    USART_EVEN_PARITY = 0,
    USART_ODD_PARITY
} USART_Parity_Selection;

typedef enum {
    USART_INTERRUPT_DISABLED = 0,
    USART_INTERRUPT_ENABLED
} USART_Interrupt;

typedef enum {
    USART_IDLE = 0,
    USART_BUSY
} USART_Status;

typedef enum {
    USART_ERROR_NONE = 0,
    USART_ERROR_OVERRUN,
    USART_ERROR_FRAMING,
    USART_ERROR_NOISE
} USART_RX_Error;


/**********************************************************************************/
/*                              Configuration Structs                             */
/**********************************************************************************/

typedef struct {
/************************************ Required ************************************/
    USART_t                *instance;
    uint32_t               baud_rate;
    uint32_t               interrupt_priority;
/************************************ Optional ************************************/
    USART_One_Bit          one_bit;
    USART_Word_Length      word_length;
    USART_Oversampling     oversampling;
    USART_Stop_Bits        stop_bits;
    USART_Parity_Control   parity_control;
    USART_Parity_Selection parity_selection;
    USART_Interrupt        pe_interrupt_enable;
    USART_Interrupt        idle_interrupt_enable;
    USART_Interrupt        cts_interrupt_enable;
    USART_Interrupt        error_interrupt_enable;
    USART_Interrupt        lbd_interrupt_enable;
} USART_Init_Config_t;


typedef struct {
/************************************ Required ************************************/
    uint8_t             *tx_buffer;
    uint16_t            tx_length;
    uint16_t            tx_index;
    USART_Status        tx_status;
    uint8_t             *rx_buffer;
    uint16_t            rx_length;
    uint16_t            rx_index;
    USART_Status        rx_status;
    USART_Init_Config_t *init_config;
} USART_State_Config_t;

static USART_State_Config_t usart_states[3] = {0};


/**********************************************************************************/
/*                               Function Prototypes                              */
/**********************************************************************************/

Status             USART_Init(USART_Init_Config_t *init_config);
static USART_Index Get_USART_Index(USART_t *instance);
void               USART_IRQHandler(USART_Index usart_index);
void               USART1_IRQHandler(void);
void               USART2_IRQHandler(void);
void               USART6_IRQHandler(void);


#ifdef __cplusplus
    }
#endif

#endif