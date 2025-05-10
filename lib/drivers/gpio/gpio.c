#include "gpio.h"

/**********************************************************************************/
/*                          GPIO Initialisation Functions                         */
/**********************************************************************************/

/**
 * @brief  Initialises the specified GPIO pin
 * @param  gpio_config: Pointer to GPIO_Config structure containing GPIO settings
 * @retval Status indicating success or invalid parameters
 */
Status GPIO_Init(GPIO_Config_t *gpio_config) {
    //validate config struct pointer
    if (!gpio_config) {
        return INVALID_PARAM;
    }

    //validate pin, mode, output type, output speed, alternate function and pull-up/pull-down
    if (gpio_config->pin < 0 || gpio_config->pin > 15 || gpio_config->mode < 0 || gpio_config->mode > 3 
        || gpio_config->output_type < 0 || gpio_config->output_type > 1 || gpio_config->output_speed < 0 
        || gpio_config->output_speed > 3 || gpio_config->alt_function < 0 || gpio_config->alt_function > 15 
        || gpio_config->pupd < 0 || gpio_config->pupd > 2 ) {
            return INVALID_PARAM;
        }

    //enable clock
    if (gpio_config->port == GPIOA) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    } else if (gpio_config->port == GPIOB) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    } else if (gpio_config->port == GPIOC) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    } else {
        return INVALID_PARAM;
    }

    //configure mode
    gpio_config->port->MODER &= ~(SET_TWO << (gpio_config->pin * 2U));
    gpio_config->port->MODER |= (((uint32_t) gpio_config->mode) << (gpio_config->pin * 2U));

    //configure alternate function
    if (gpio_config->mode == GPIO_MODE_AF) {
        uint8_t afr = (gpio_config->pin <= 7) ? 0 : 1;
        if (afr == 0) {
            gpio_config->port->AFR[0] &= ~(SET_FOUR << (gpio_config->pin * 4U));
            gpio_config->port->AFR[0] |= (((uint32_t) gpio_config->alt_function) << (gpio_config->pin * 4U));
        } else {
            gpio_config->port->AFR[1] &= ~(SET_FOUR << ((gpio_config->pin - 8U) * 4U));
            gpio_config->port->AFR[1] |= (((uint32_t) gpio_config->alt_function) << ((gpio_config->pin - 8U) * 4U));
        }
    }

    //configure output type and speed
    if (gpio_config->mode == GPIO_MODE_OUTPUT || gpio_config->mode == GPIO_MODE_AF) {
        gpio_config->port->OTYPER |= (((uint32_t) gpio_config->output_type) << gpio_config->pin);

        gpio_config->port->OSPEEDR &= ~(SET_TWO << (gpio_config->pin * 2));
        gpio_config->port->OSPEEDR |= (((uint32_t) gpio_config->output_speed) << (gpio_config->pin * 2));
    }

    //configure pull-up/pull-down resistors
    gpio_config->port->PUPDR &= ~(SET_TWO << (gpio_config->pin * 2U));
    gpio_config->port->PUPDR |= (((uint32_t) gpio_config->pupd) << (gpio_config->pin * 2U));

    return SUCCESS;
}

/**
* @brief  Deinitialises a GPIO pin
* @param  port: Pointer to GPIO_t structure containing the GPIO port
* @param  pin:  Number of the pin to be deinitialised
* @retval Status indicating success or invalid parameters
*/
Status GPIO_Deinit(GPIO_t *port, GPIO_Pin pin) {
    //validate port and pin
    if ((!port) || pin < 0 || pin > 15) {
        return INVALID_PARAM;
    }

    //reset mode
    port->MODER &= ~(SET_TWO << (pin * 2U));

    //reset output type and speed
    port->OTYPER  &= ~(SET_ONE << pin);
    port->OSPEEDR &= ~(SET_TWO << (pin * 2U));

    //reset pull-up/pull-down resistors
    port->PUPDR &= ~(SET_TWO << (pin * 2U));

    //reset alternate function
    uint8_t afr = (pin <= 7) ? 0 : 1;
    if (afr == 0) {
        port->AFR[0] &= ~(SET_FOUR << (pin * 4U));
    } else {
        port->AFR[1] &= ~(SET_FOUR << ((pin - 8U) * 4U));
    }

    return SUCCESS;
}


/**********************************************************************************/
/*                             TIM1 Modifier Functions                            */
/**********************************************************************************/

/**
 * @brief  Reads a GPIO pin to determine bit state
 * @param  port: Pointer to GPIO_t structure containing the GPIO port
 * @param  pin:  Number of the pin to be read
 * @retval Bit_State indicating whether a bit is set or reset
 */
Bit_State GPIO_Read_Pin(GPIO_t *port, GPIO_Pin pin) {
    //validate port and pin
    if ((!port) || pin < 0 || pin > 15) {
        return BIT_INVALID_PARAM;
    }

    //read the pin's input data register
    if (port->IDR & (SET_ONE << pin)) {
        return BIT_SET;
    } else {
        return BIT_RESET;
    }
}

/**
 * @brief  Sets a GPIO pin
 * @param  port: Pointer to GPIO_t structure containing the GPIO port
 * @param  pin:  Number of the pin to be set
 * @retval Status indicating success or invalid parameters
 */
Status GPIO_Set_Pin(GPIO_t *port, GPIO_Pin pin) {
    //validate port and pin
    if ((!port) || pin < 0 || pin > 15) {
        return INVALID_PARAM;
    }

    //set corresponding BSRR bit
    port->BSRR |= (SET_ONE << pin);

    return SUCCESS;
}

/**
 * @brief  Resets a GPIO pin
 * @param  port: Pointer to GPIO_t structure containing the GPIO port
 * @param  pin:  Number of the pin to be reset
 * @retval Status indicating success or invalid parameters
 */
Status GPIO_Reset_Pin(GPIO_t *port, GPIO_Pin pin) {
    //validate port and pin
    if ((!port) || pin < 0 || pin > 15) {
        return INVALID_PARAM;
    }

    //reset corresponding BSRR bit
    port->BSRR |= (SET_ONE << (pin + 16U));

    return SUCCESS;
}


/**
* @brief  Toggles the bit state of a GPIO pin
* @param  port: Pointer to GPIO_t structure containing the GPIO port
* @param  pin:  Number of the pin whose bit state will be toggled
* @retval Status indicating success, error or invalid parameters
*/
Status GPIO_Toggle_Pin(GPIO_t *port, GPIO_Pin pin) {
    //validate port and pin
    if ((!port) || pin < 0 || pin > 15) {
        return INVALID_PARAM;
    }

    //toggle the pin's output data register
    if (port->ODR & (SET_ONE << pin)) {
        GPIO_Reset_Pin(port, pin);
        return SUCCESS;
    } else {
        GPIO_Set_Pin(port, pin);
        return SUCCESS;
    }

    return ERROR;
}

/**
* @brief  Locks the configuration of a specified GPIO pin
* @param  port: Pointer to GPIO_t structure containing the GPIO port
* @param  pin:  Number of the pin to be locked
* @retval Status indicating success, error or invalid parameters
*/
Status GPIO_Lock_Pin(GPIO_t *port, GPIO_Pin pin) {
    //validate port and pin
    if ((!port) || pin < 0 || pin > 15) {
        return INVALID_PARAM;
    }

    //execute lock sequence
    port->LCKR |= (GPIO_LCKR_LCKK | (SET_ONE << pin));
    port->LCKR = (SET_ONE << pin);
    port->LCKR |= (GPIO_LCKR_LCKK | (SET_ONE << pin));
    uint32_t temp = port->LCKR;
    (void)temp;

    //validate lock
    if (!(port->LCKR & GPIO_LCKR_LCKK)) {
        return ERROR;
    }

    return SUCCESS;
}


/**********************************************************************************/
/*                             GPIO Interrupt Handlers                            */
/**********************************************************************************/

//insert any interrupt handlers linked to EXTI lines