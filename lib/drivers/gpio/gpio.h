#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "../../utils/utils.h"


/**********************************************************************************/
/*                                      Enums                                     */
/**********************************************************************************/

typedef enum {
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D
} GPIO_Port;

typedef enum {
    GPIO_PIN_0 = 0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
} GPIO_Pin;

typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG
} GPIO_Mode;

typedef enum {
    GPIO_OUTPUT_PUSH_PULL = 0,
    GPIO_OUTPUT_OPEN_DRAIN
} GPIO_Output_Type;

typedef enum {
    GPIO_OUTPUT_SPEED_LOW = 0,
    GPIO_OUTPUT_SPEED_MED,
    GPIO_OUTPUT_SPEED_FAST,
    GPIO_OUTPUT_SPEED_HIGH
} GPIO_Output_Speed;

typedef enum {
    GPIO_PUPD_NO = 0,
    GPIO_PUPD_PULLUP,
    GPIO_PUPD_PULLDOWN
} GPIO_PUPD;

typedef enum {
    GPIO_AF_0 = 0,
    GPIO_AF_1,
    GPIO_AF_2,
    GPIO_AF_3,
    GPIO_AF_4,
    GPIO_AF_5,
    GPIO_AF_6,
    GPIO_AF_7,
    GPIO_AF_8,
    GPIO_AF_9,
    GPIO_AF_10,
    GPIO_AF_11,
    GPIO_AF_12,
    GPIO_AF_13,
    GPIO_AF_14,
    GPIO_AF_15
} GPIO_AF;


/**********************************************************************************/
/*                              Configuration Structs                             */
/**********************************************************************************/

typedef struct {
/************************************ Required ************************************/
    GPIO_t           *port;
    GPIO_Pin          pin;
    GPIO_Mode         mode;
/************************************ Optional ************************************/
    GPIO_Output_Type  output_type;
    GPIO_Output_Speed output_speed;
    GPIO_PUPD         pupd;
    GPIO_AF           alt_function;
} GPIO_Config_t;


/**********************************************************************************/
/*                               Function Prototypes                              */
/**********************************************************************************/

Status    GPIO_Init       (GPIO_Config_t *gpio_config);
Bit_State GPIO_Read_Pin   (GPIO_t *port, GPIO_Pin pin);
Status    GPIO_Set_Pin    (GPIO_t *port, GPIO_Pin pin);
Status    GPIO_Reset_Pin  (GPIO_t *port, GPIO_Pin pin);
Status    GPIO_Toggle_Pin (GPIO_t *port, GPIO_Pin pin);
Status    GPIO_Lock_Pin   (GPIO_t *port, GPIO_Pin pin);
Status    GPIO_Deinit     (GPIO_t *port, GPIO_Pin pin);



#ifdef cplusplus
    }
#endif

#endif