/* This program uses PWM output to control a servo motor */

#include "main.h"

// int main(void) {
//     Peripheral_Reset();

//     HSI_Clk_Config();
//     RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
//     RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

//     DSB();

//     GPIOA->MODER |= GPIO_MODER_MODER8_AF;
//     GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED8_HI;
//     GPIOA->AFR[1] |= GPIO_AFRH_AFSEL8_0;
//     GPIOA->OTYPER &= ~(GPIO_OTYPER_OT8);

//     TIM1_CC1_PWM_Servo_Init();

//     while(1) {
//         TIM1_CC1_PWM_Servo_Set_Position(50.0);
//         //Delay_Loop(10000);
//         //TIM1_CC1_PWM_Servo_Set_Position(0.0);
//         //Delay_Loop(10000);
//     }
// }

int main(void) {
    Peripheral_Reset();

    System_Clock_Init(HSI_CLOCK);

    //configure gpio in PWM output mode
    GPIO_Config_t gpio_settings = {
        .port = GPIOA,
        .pin = GPIO_PIN_8,
        .mode = GPIO_MODE_AF,
        .alt_function = GPIO_AF_1,
        .output_type = GPIO_OUTPUT_PUSH_PULL,
        .output_speed = GPIO_OUTPUT_SPEED_HIGH,
    };

    GPIO_Init(&gpio_settings);

    //initialise tim1
    TIM1_CNT_Config_t tim1_cnt_settings = {
        .direction = TIM1_DIR_UP,
        .auto_reload = 1000UL,
        .prescaler = 16UL,
        .repetition = 0U,
        .update_event = TIM1_UPDATE_EVENT_ENABLED        
    };

    TIM1_CNT_Init(&tim1_cnt_settings);

    //initialise tim1 for servo
    // TIM1_Servo_Init(TIM1_CHANNEL_1);
    // TIM1_Servo_Set_Position(TIM1_CHANNEL_1, 120);

    TIM1_CC1_PWM_Servo_Init();
    

    while(1) {
        TIM1_CC1_PWM_Servo_Set_Position(90);
    }
}