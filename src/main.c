/* This program uses PWM output to control a servo motor */

/* Local .bin path --> ~/projects/pwm_servo/.pio/build/blackpill_f411ce/firmware.bin */

#include "main.h"

int main(void) {
    Peripheral_Reset();

    System_Clock_Init(HSI_CLOCK);

    GPIO_Config_t gpio_settings = {
        .port = GPIOA,
        .pin = GPIO_PIN_8,
        .mode = GPIO_MODE_AF,
        .alt_function = GPIO_AF_1,
        .output_type = GPIO_OUTPUT_PUSH_PULL,
        .output_speed = GPIO_OUTPUT_SPEED_HIGH,
    };

    GPIO_Init(&gpio_settings);

    TIM1_CNT_Config_t tim1_cnt_settings = {
        .auto_reload = 1000UL,
        .prescaler = 16UL      
    };

    TIM1_CNT_Init(&tim1_cnt_settings);
    TIM1_Servo_Init(TIM1_CHANNEL_1);

    while(1) {
        TIM1_Servo_Set_Position(TIM1_CHANNEL_1, 30);
        Delay_Loop(3000);
        TIM1_Servo_Set_Position(TIM1_CHANNEL_1, 90);
        Delay_Loop(3000);
        TIM1_Servo_Set_Position(TIM1_CHANNEL_1, 120);
        Delay_Loop(3000);
    }
}