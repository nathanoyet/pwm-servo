/* External Peripheral Layer for the STM32F411 - Blackpill
This file contains:
- Data structures and the address mapping for all external peripherals
- External peripherals' registers declarations and bits definition
- Macros to access external peripherals' registers hardware
*/

/* start header guard */
#ifndef __EXT_PERIPH_LAYER_H
#define __EXT_PERIPH_LAYER_H

/* start C linkage for C++ compiler */
#ifdef __cplusplus
    extern "C" {
#endif


#include <stdint.h>


/**********************************************************************************/
/*                     Interrupt Number Enumeration Definition                    */
/**********************************************************************************/

typedef enum {
/****************** Cortex M4 system exception interrupt numbers ******************/
    NMI_IRQn                = -14,
    HardFault_IRQn          = -13,
    MemManage_IRQn          = -12,
    BusFault_IRQn           = -11,
    UsageFault_IRQn         = -10,
    SVCall_IRQn             = -5,
    Debug_Monitor_IRQn      = -4,
    PendSV_IRQn             = -2,
    SysTick_IRQn            = -1,
/********************* External peripheral interrupt numbers **********************/
    WWDG_IRQn               = 0,
    PVD_IRQn                = 1,
    TAMP_STAMP_IRQn         = 2,
    RTC_WKUP_IRQn           = 3,
    FLASH_IRQn              = 4,
    RCC_IRQn                = 5,
    EXTI0_IRQn              = 6,
    EXTI1_IRQn              = 7,
    EXTI2_IRQn              = 8,
    EXTI3_IRQn              = 9,
    EXTI4_IRQn              = 10,
    DMA1_Stream0_IRQn       = 11,
    DMA1_Stream1_IRQn       = 12,
    DMA1_Stream2_IRQn       = 13,
    DMA1_Stream3_IRQn       = 14,
    DMA1_Stream4_IRQn       = 15,
    DMA1_Stream5_IRQn       = 16,
    DMA1_Stream6_IRQn       = 17,
    ADC_IRQn                = 18,
    EXTI9_5_IRQn            = 23,
    TIM1_BRK_TIM9_IRQn      = 24,
    TIM1_UP_TIM10_IRQn      = 25,
    TIM1_TRG_COM_TIM11_IRQn = 26,
    TIM1_CC_IRQn            = 27,
    TIM2_IRQn               = 28,
    TIM3_IRQn               = 29,
    TIM4_IRQn               = 30,
    I2C1_EV_IRQn            = 31,
    I2C1_ER_IRQn            = 32,
    I2C2_EV_IRQn            = 33,
    I2C2_ER_IRQn            = 34,
    SPI1_IRQn               = 35,
    SPI2_IRQn               = 36,
    USART1_IRQn             = 37,
    USART2_IRQn             = 38,
    EXTI15_10_IRQn          = 40,
    RTC_Alarm_IRQn          = 41,
    OTG_FS_WKUP_IRQn        = 42,
    DMA1_Stream7_IRQn       = 47,
    SDIO_IRQn               = 49,
    TIM5_IRQn               = 50,
    SPI3_IRQn               = 51,
    DMA2_Stream0_IRQn       = 56,
    DMA2_Stream1_IRQn       = 57,
    DMA2_Stream2_IRQn       = 58,
    DMA2_Stream3_IRQn       = 59,
    DMA2_Stream4_IRQn       = 60,
    OTG_FS_IRQn             = 67,
    DMA2_Stream5_IRQn       = 68,
    DMA2_Stream6_IRQn       = 69,
    DMA2_Stream7_IRQn       = 70,
    USART6_IRQn             = 71,
    I2C3_EV_IRQn            = 72,
    I2C3_ER_IRQn            = 73,
    FPU_IRQn                = 81,
    SPI4_IRQn               = 84,
    SPI5_IRQn               = 85,
} IRQn_t;


/**********************************************************************************/
/*                External Peripheral Registers Structures Definition             */
/**********************************************************************************/

/***************** EXTI Peripheral register structure definition ******************/
typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
} EXTI_t;

/***************** GPIO Peripheral register structure definition ******************/
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
} GPIO_t;

/****************** RCC Peripheral register structure definition ******************/
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t RESERVED_0[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED_1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t RESERVED_2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED_3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    uint32_t RESERVED_4[2];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED_5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED_6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    uint32_t RESERVED_7;
    volatile uint32_t DCKCFGR;
} RCC_t;

/********* System Configuration Controller register structure definition **********/
typedef struct {
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR1;
    volatile uint32_t EXTICR2;
    volatile uint32_t EXTICR3;
    volatile uint32_t EXTICR4;
    uint32_t RESERVED[2];
    volatile uint32_t CMPCR;
} SYSCFG_t;

/************************ TIM register structure definition ***********************/
typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
} TIM_t;

/*********************** USART register structure definition **********************/
typedef struct {
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;
} USART_t;


/**********************************************************************************/
/*                        External Peripheral Declaration                         */
/**********************************************************************************/
#define EXTI                        ((EXTI_t *) EXTI_BASE)

#define GPIOA                       ((GPIO_t *) GPIOA_BASE)
#define GPIOB                       ((GPIO_t *) GPIOB_BASE)
#define GPIOC                       ((GPIO_t *) GPIOC_BASE)
#define GPIOD                       ((GPIO_t *) GPIOD_BASE)
#define GPIOE                       ((GPIO_t *) GPIOE_BASE)
#define GPIOH                       ((GPIO_t *) GPIOH_BASE)

#define RCC                         ((RCC_t *) RCC_BASE)
#define SYSCFG                      ((SYSCFG_t *) SYSCFG_BASE)

#define TIM1                        ((TIM_t *) TIM1_BASE)
#define USART1                      ((USART_t *) USART1_BASE)
#define USART2                      ((USART_t *) USART2_BASE)
#define USART6                      ((USART_t *) USART6_BASE)


/**********************************************************************************/
/*                 External Peripheral Registers Memory Map Definition            */
/**********************************************************************************/

/************************** General memory map definition *************************/
#define FLASH_BASE                  0x08000000UL
#define SRAM1_BASE                  0x20000000UL
#define SRAM1_BB_BASE               0x22000000UL
#define PERIPH_BASE                 0x40000000UL
#define PERIPH_BB_BASE              0x42000000UL
#define BKPSRAM_BB_BASE             0x42480000UL
#define FLASH_END                   0x0807FFFFUL
#define FLASH_OTP_BASE              0x1FFF7800UL
#define FLASH_OTP_END               0x1FFF7A0FUL
#define DBGMCU_BASE                 0xE0042000UL   /* debug MCU registers base address definition*/

/************************ Peripheral memory map definition ************************/
#define APB1PERIPH_BASE             PERIPH_BASE
#define APB2PERIPH_BASE             (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE             (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE             (PERIPH_BASE + 0x10000000UL)

/********************* APB1 Peripherals memory map definition *********************/
#define TIM2_BASE                   (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE                   (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE                   (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE                   (APB1PERIPH_BASE + 0x0C00UL)
#define RTC_BASE                    (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE                   (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE                   (APB1PERIPH_BASE + 0x3000UL)
#define I2S2ext_BASE                (APB1PERIPH_BASE + 0x3400UL)
#define SPI2_BASE                   (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE                   (APB1PERIPH_BASE + 0x3C00UL)
#define I2S3ext_BASE                (APB1PERIPH_BASE + 0x4000UL)
#define USART2_BASE                 (APB1PERIPH_BASE + 0x4400UL)
#define I2C1_BASE                   (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE                   (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE                   (APB1PERIPH_BASE + 0x5C00UL)
#define PWR_BASE                    (APB1PERIPH_BASE + 0x7000UL)

/********************* APB2 Peripherals memory map definition *********************/
#define TIM1_BASE                   (APB2PERIPH_BASE + 0x0000UL)
#define USART1_BASE                 (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE                 (APB2PERIPH_BASE + 0x1400UL)
#define ADC1_BASE                   (APB2PERIPH_BASE + 0x2000UL)
#define ADC1_COMMON_BASE            (APB2PERIPH_BASE + 0x2300UL)   /* not included in data sheet memory map */
#define SDIO_BASE                   (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE                   (APB2PERIPH_BASE + 0x3000UL)
#define SPI4_BASE                   (APB2PERIPH_BASE + 0x3400UL)
#define SYSCFG_BASE                 (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE                   (APB2PERIPH_BASE + 0x3C00UL)
#define TIM9_BASE                   (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE                  (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE                  (APB2PERIPH_BASE + 0x4800UL)
#define SPI5_BASE                   (APB2PERIPH_BASE + 0x5000UL)

/********************* AHB1 Peripherals memory map definition *********************/
#define GPIOA_BASE                  (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE                  (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE                  (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE                  (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE                  (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE                  (AHB1PERIPH_BASE + 0x1C00UL)
#define CRC_BASE                    (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE                    (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE                (AHB1PERIPH_BASE + 0x3C00UL)
#define DMA1_BASE                   (AHB1PERIPH_BASE + 0x6000UL)
#define DMA1_Stream0_BASE           (DMA1_BASE + 0x010UL)
#define DMA1_Stream1_BASE           (DMA1_BASE + 0x028UL)
#define DMA1_Stream2_BASE           (DMA1_BASE + 0x040UL)
#define DMA1_Stream3_BASE           (DMA1_BASE + 0x058UL)
#define DMA1_Stream4_BASE           (DMA1_BASE + 0x070UL)
#define DMA1_Stream5_BASE           (DMA1_BASE + 0x088UL)
#define DMA1_Stream6_BASE           (DMA1_BASE + 0x0A0UL)
#define DMA1_Stream7_BASE           (DMA1_BASE + 0x0B8UL)
#define DMA2_BASE                   (AHB1PERIPH_BASE + 0x6400UL)
#define DMA2_Stream0_BASE           (DMA2_BASE + 0x010UL)
#define DMA2_Stream1_BASE           (DMA2_BASE + 0x028UL)
#define DMA2_Stream2_BASE           (DMA2_BASE + 0x040UL)
#define DMA2_Stream3_BASE           (DMA2_BASE + 0x058UL)
#define DMA2_Stream4_BASE           (DMA2_BASE + 0x070UL)
#define DMA2_Stream5_BASE           (DMA2_BASE + 0x880UL)
#define DMA2_Stream6_BASE           (DMA2_BASE + 0x0A0UL)
#define DMA2_Stream7_BASE           (DMA2_BASE + 0x0B8UL)

/********************* AHB2 Peripherals memory map definition *********************/
#define USB_OTG_FS_PERIPH_BASE      0x50000000UL


/**********************************************************************************/
/*                    External Peripheral Registers Bits Definition               */
/**********************************************************************************/

/**********************************************************************************/
/*                                                                                */
/*                   External Interrupt/Event Controller (EXTI)                   */
/*                                                                                */
/**********************************************************************************/

/********************** Bits definition for EXTI_IMR register *********************/
#define EXTI_IMR_MR0_Pos            (0U)
#define EXTI_IMR_MR0_Msk            (0x1UL << EXTI_IMR_MR0_Pos)
#define EXTI_IMR_MR0                EXTI_IMR_MR0_Msk

#define EXTI_IMR_MR1_Pos            (1U)
#define EXTI_IMR_MR1_Msk            (0x1UL << EXTI_IMR_MR1_Pos)
#define EXTI_IMR_MR1                EXTI_IMR_MR1_Msk

#define EXTI_IMR_MR2_Pos            (2U)
#define EXTI_IMR_MR2_Msk            (0x1UL << EXTI_IMR_MR2_Pos)
#define EXTI_IMR_MR2                EXTI_IMR_MR2_Msk

#define EXTI_IMR_MR3_Pos            (3U)
#define EXTI_IMR_MR3_Msk            (0x1UL << EXTI_IMR_MR3_Pos)
#define EXTI_IMR_MR3                EXTI_IMR_MR3_Msk

#define EXTI_IMR_MR4_Pos            (4U)
#define EXTI_IMR_MR4_Msk            (0x1UL << EXTI_IMR_MR4_Pos)
#define EXTI_IMR_MR4                EXTI_IMR_MR4_Msk

#define EXTI_IMR_MR5_Pos            (5U)
#define EXTI_IMR_MR5_Msk            (0x1UL << EXTI_IMR_MR5_Pos)
#define EXTI_IMR_MR5                EXTI_IMR_MR5_Msk

#define EXTI_IMR_MR6_Pos            (6U)
#define EXTI_IMR_MR6_Msk            (0x1UL << EXTI_IMR_MR6_Pos)
#define EXTI_IMR_MR6                EXTI_IMR_MR6_Msk

#define EXTI_IMR_MR7_Pos            (7U)
#define EXTI_IMR_MR7_Msk            (0x1UL << EXTI_IMR_MR7_Pos)
#define EXTI_IMR_MR7                EXTI_IMR_MR7_Msk

#define EXTI_IMR_MR8_Pos            (8U)
#define EXTI_IMR_MR8_Msk            (0x1UL << EXTI_IMR_MR8_Pos)
#define EXTI_IMR_MR8                EXTI_IMR_MR8_Msk

#define EXTI_IMR_MR9_Pos            (9U)
#define EXTI_IMR_MR9_Msk            (0x1UL << EXTI_IMR_MR9_Pos)
#define EXTI_IMR_MR9                EXTI_IMR_MR9_Msk

#define EXTI_IMR_MR10_Pos           (10U)
#define EXTI_IMR_MR10_Msk           (0x1UL << EXTI_IMR_MR10_Pos)
#define EXTI_IMR_MR10               EXTI_IMR_MR10_Msk

#define EXTI_IMR_MR11_Pos           (11U)
#define EXTI_IMR_MR11_Msk           (0x1UL << EXTI_IMR_MR11_Pos)
#define EXTI_IMR_MR11               EXTI_IMR_MR11_Msk

#define EXTI_IMR_MR12_Pos           (12U)
#define EXTI_IMR_MR12_Msk           (0x1UL << EXTI_IMR_MR12_Pos)
#define EXTI_IMR_MR12               EXTI_IMR_MR12_Msk

#define EXTI_IMR_MR13_Pos           (13U)
#define EXTI_IMR_MR13_Msk           (0x1UL << EXTI_IMR_MR13_Pos)
#define EXTI_IMR_MR13               EXTI_IMR_MR13_Msk

#define EXTI_IMR_MR14_Pos           (14U)
#define EXTI_IMR_MR14_Msk           (0x1UL << EXTI_IMR_MR14_Pos)
#define EXTI_IMR_MR14               EXTI_IMR_MR14_Msk

#define EXTI_IMR_MR15_Pos           (15U)
#define EXTI_IMR_MR15_Msk           (0x1UL << EXTI_IMR_MR15_Pos)
#define EXTI_IMR_MR15               EXTI_IMR_MR15_Msk

#define EXTI_IMR_MR16_Pos           (16U)
#define EXTI_IMR_MR16_Msk           (0x1UL << EXTI_IMR_MR16_Pos)
#define EXTI_IMR_MR16               EXTI_IMR_MR16_Msk

#define EXTI_IMR_MR17_Pos           (17U)
#define EXTI_IMR_MR17_Msk           (0x1UL << EXTI_IMR_MR17_Pos)
#define EXTI_IMR_MR17               EXTI_IMR_MR17_Msk

#define EXTI_IMR_MR18_Pos           (18U)
#define EXTI_IMR_MR18_Msk           (0x1UL << EXTI_IMR_MR18_Pos)
#define EXTI_IMR_MR18               EXTI_IMR_MR18_Msk

#define EXTI_IMR_MR21_Pos           (21U)
#define EXTI_IMR_MR21_Msk           (0x1UL << EXTI_IMR_MR21_Pos)
#define EXTI_IMR_MR21               EXTI_IMR_MR21_Msk

#define EXTI_IMR_MR22_Pos           (22U)
#define EXTI_IMR_MR22_Msk           (0x1UL << EXTI_IMR_MR22_Pos)
#define EXTI_IMR_MR22               EXTI_IMR_MR22_Msk

/********************** Bits definition for EXTI_EMR register *********************/
#define EXTI_EMR_MR0_Pos            (0U)
#define EXTI_EMR_MR0_Msk            (0x1UL << EXTI_EMR_MR0_Pos)
#define EXTI_EMR_MR0                EXTI_EMR_MR0_Msk

#define EXTI_EMR_MR1_Pos            (1U)
#define EXTI_EMR_MR1_Msk            (0x1UL << EXTI_EMR_MR1_Pos)
#define EXTI_EMR_MR1                EXTI_EMR_MR1_Msk

#define EXTI_EMR_MR2_Pos            (2U)
#define EXTI_EMR_MR2_Msk            (0x1UL << EXTI_EMR_MR2_Pos)
#define EXTI_EMR_MR2                EXTI_EMR_MR2_Msk

#define EXTI_EMR_MR3_Pos            (3U)
#define EXTI_EMR_MR3_Msk            (0x1UL << EXTI_EMR_MR3_Pos)
#define EXTI_EMR_MR3                EXTI_EMR_MR3_Msk

#define EXTI_EMR_MR4_Pos            (4U)
#define EXTI_EMR_MR4_Msk            (0x1UL << EXTI_EMR_MR4_Pos)
#define EXTI_EMR_MR4                EXTI_EMR_MR4_Msk

#define EXTI_EMR_MR5_Pos            (5U)
#define EXTI_EMR_MR5_Msk            (0x1UL << EXTI_EMR_MR5_Pos)
#define EXTI_EMR_MR5                EXTI_EMR_MR5_Msk

#define EXTI_EMR_MR6_Pos            (6U)
#define EXTI_EMR_MR6_Msk            (0x1UL << EXTI_EMR_MR6_Pos)
#define EXTI_EMR_MR6                EXTI_EMR_MR6_Msk

#define EXTI_EMR_MR7_Pos            (7U)
#define EXTI_EMR_MR7_Msk            (0x1UL << EXTI_EMR_MR7_Pos)
#define EXTI_EMR_MR7                EXTI_EMR_MR7_Msk

#define EXTI_EMR_MR8_Pos            (8U)
#define EXTI_EMR_MR8_Msk            (0x1UL << EXTI_EMR_MR8_Pos)
#define EXTI_EMR_MR8                EXTI_EMR_MR8_Msk

#define EXTI_EMR_MR9_Pos            (9U)
#define EXTI_EMR_MR9_Msk            (0x1UL << EXTI_EMR_MR9_Pos)
#define EXTI_EMR_MR9                EXTI_EMR_MR9_Msk

#define EXTI_EMR_MR10_Pos           (10U)
#define EXTI_EMR_MR10_Msk           (0x1UL << EXTI_EMR_MR10_Pos)
#define EXTI_EMR_MR10               EXTI_EMR_MR10_Msk

#define EXTI_EMR_MR11_Pos           (11U)
#define EXTI_EMR_MR11_Msk           (0x1UL << EXTI_EMR_MR11_Pos)
#define EXTI_EMR_MR11               EXTI_EMR_MR11_Msk

#define EXTI_EMR_MR12_Pos           (12U)
#define EXTI_EMR_MR12_Msk           (0x1UL << EXTI_EMR_MR12_Pos)
#define EXTI_EMR_MR12               EXTI_EMR_MR12_Msk

#define EXTI_EMR_MR13_Pos           (13U)
#define EXTI_EMR_MR13_Msk           (0x1UL << EXTI_EMR_MR13_Pos)
#define EXTI_EMR_MR13               EXTI_EMR_MR13_Msk

#define EXTI_EMR_MR14_Pos           (14U)
#define EXTI_EMR_MR14_Msk           (0x1UL << EXTI_EMR_MR14_Pos)
#define EXTI_EMR_MR14               EXTI_EMR_MR14_Msk

#define EXTI_EMR_MR15_Pos           (15U)
#define EXTI_EMR_MR15_Msk           (0x1UL << EXTI_EMR_MR15_Pos)
#define EXTI_EMR_MR15               EXTI_EMR_MR15_Msk

#define EXTI_EMR_MR16_Pos           (16U)
#define EXTI_EMR_MR16_Msk           (0x1UL << EXTI_EMR_MR16_Pos)
#define EXTI_EMR_MR16               EXTI_EMR_MR16_Msk

#define EXTI_EMR_MR17_Pos           (17U)
#define EXTI_EMR_MR17_Msk           (0x1UL << EXTI_EMR_MR17_Pos)
#define EXTI_EMR_MR17               EXTI_EMR_MR17_Msk

#define EXTI_EMR_MR18_Pos           (18U)
#define EXTI_EMR_MR18_Msk           (0x1UL << EXTI_EMR_MR18_Pos)
#define EXTI_EMR_MR18               EXTI_EMR_MR18_Msk

#define EXTI_EMR_MR21_Pos           (21U)
#define EXTI_EMR_MR21_Msk           (0x1UL << EXTI_EMR_MR21_Pos)
#define EXTI_EMR_MR21               EXTI_EMR_MR21_Msk

#define EXTI_EMR_MR22_Pos           (22U)
#define EXTI_EMR_MR22_Msk           (0x1UL << EXTI_EMR_MR22_Pos)
#define EXTI_EMR_MR22               EXTI_EMR_MR22_Msk

/********************* Bits definition for EXTI_RTSR register *********************/
#define EXTI_RTSR_TR0_Pos           (0U)
#define EXTI_RTSR_TR0_Msk           (0x1UL << EXTI_RTSR_TR0_Pos)
#define EXTI_RTSR_TR0               EXTI_RTSR_TR0_Msk

#define EXTI_RTSR_TR1_Pos           (1U)
#define EXTI_RTSR_TR1_Msk           (0x1UL << EXTI_RTSR_TR1_Pos)
#define EXTI_RTSR_TR1               EXTI_RTSR_TR1_Msk

#define EXTI_RTSR_TR2_Pos           (2U)
#define EXTI_RTSR_TR2_Msk           (0x1UL << EXTI_RTSR_TR2_Pos)
#define EXTI_RTSR_TR2               EXTI_RTSR_TR2_Msk

#define EXTI_RTSR_TR3_Pos           (3U)
#define EXTI_RTSR_TR3_Msk           (0x1UL << EXTI_RTSR_TR3_Pos)
#define EXTI_RTSR_TR3               EXTI_RTSR_TR3_Msk

#define EXTI_RTSR_TR4_Pos           (4U)
#define EXTI_RTSR_TR4_Msk           (0x1UL << EXTI_RTSR_TR4_Pos)
#define EXTI_RTSR_TR4               EXTI_RTSR_TR4_Msk

#define EXTI_RTSR_TR5_Pos           (5U)
#define EXTI_RTSR_TR5_Msk           (0x1UL << EXTI_RTSR_TR5_Pos)
#define EXTI_RTSR_TR5               EXTI_RTSR_TR5_Msk

#define EXTI_RTSR_TR6_Pos           (6U)
#define EXTI_RTSR_TR6_Msk           (0x1UL << EXTI_RTSR_TR6_Pos)
#define EXTI_RTSR_TR6               EXTI_RTSR_TR6_Msk

#define EXTI_RTSR_TR7_Pos           (7U)
#define EXTI_RTSR_TR7_Msk           (0x1UL << EXTI_RTSR_TR7_Pos)
#define EXTI_RTSR_TR7               EXTI_RTSR_TR7_Msk

#define EXTI_RTSR_TR8_Pos           (8U)
#define EXTI_RTSR_TR8_Msk           (0x1UL << EXTI_RTSR_TR8_Pos)
#define EXTI_RTSR_TR8               EXTI_RTSR_TR8_Msk

#define EXTI_RTSR_TR9_Pos           (9U)
#define EXTI_RTSR_TR9_Msk           (0x1UL << EXTI_RTSR_TR9_Pos)
#define EXTI_RTSR_TR9               EXTI_RTSR_TR9_Msk

#define EXTI_RTSR_TR10_Pos          (10U)
#define EXTI_RTSR_TR10_Msk          (0x1UL << EXTI_RTSR_TR10_Pos)
#define EXTI_RTSR_TR10              EXTI_RTSR_TR10_Msk

#define EXTI_RTSR_TR11_Pos          (11U)
#define EXTI_RTSR_TR11_Msk          (0x1UL << EXTI_RTSR_TR11_Pos)
#define EXTI_RTSR_TR11              EXTI_RTSR_TR11_Msk

#define EXTI_RTSR_TR12_Pos          (12U)
#define EXTI_RTSR_TR12_Msk          (0x1UL << EXTI_RTSR_TR12_Pos)
#define EXTI_RTSR_TR12              EXTI_RTSR_TR12_Msk

#define EXTI_RTSR_TR13_Pos          (13U)
#define EXTI_RTSR_TR13_Msk          (0x1UL << EXTI_RTSR_TR13_Pos)
#define EXTI_RTSR_TR13              EXTI_RTSR_TR13_Msk

#define EXTI_RTSR_TR14_Pos          (14U)
#define EXTI_RTSR_TR14_Msk          (0x1UL << EXTI_RTSR_TR14_Pos)
#define EXTI_RTSR_TR14              EXTI_RTSR_TR14_Msk

#define EXTI_RTSR_TR15_Pos          (15U)
#define EXTI_RTSR_TR15_Msk          (0x1UL << EXTI_RTSR_TR15_Pos)
#define EXTI_RTSR_TR15              EXTI_RTSR_TR15_Msk

#define EXTI_RTSR_TR16_Pos          (16U)
#define EXTI_RTSR_TR16_Msk          (0x1UL << EXTI_RTSR_TR16_Pos)
#define EXTI_RTSR_TR16              EXTI_RTSR_TR16_Msk

#define EXTI_RTSR_TR17_Pos          (17U)
#define EXTI_RTSR_TR17_Msk          (0x1UL << EXTI_RTSR_TR17_Pos)
#define EXTI_RTSR_TR17              EXTI_RTSR_TR17_Msk

#define EXTI_RTSR_TR18_Pos          (18U)
#define EXTI_RTSR_TR18_Msk          (0x1UL << EXTI_RTSR_TR18_Pos)
#define EXTI_RTSR_TR18              EXTI_RTSR_TR18_Msk

#define EXTI_RTSR_TR21_Pos          (21U)
#define EXTI_RTSR_TR21_Msk          (0x1UL << EXTI_RTSR_TR21_Pos)
#define EXTI_RTSR_TR21              EXTI_RTSR_TR21_Msk

#define EXTI_RTSR_TR22_Pos          (22U)
#define EXTI_RTSR_TR22_Msk          (0x1UL << EXTI_RTSR_TR22_Pos)
#define EXTI_RTSR_TR22              EXTI_RTSR_TR22_Msk

/********************* Bits definition for EXTI_FTSR register *********************/
#define EXTI_FTSR_TR0_Pos           (0U)
#define EXTI_FTSR_TR0_Msk           (0x1UL << EXTI_FTSR_TR0_Pos)
#define EXTI_FTSR_TR0               EXTI_FTSR_TR0_Msk

#define EXTI_FTSR_TR1_Pos           (1U)
#define EXTI_FTSR_TR1_Msk           (0x1UL << EXTI_FTSR_TR1_Pos)
#define EXTI_FTSR_TR1               EXTI_FTSR_TR1_Msk

#define EXTI_FTSR_TR2_Pos           (2U)
#define EXTI_FTSR_TR2_Msk           (0x1UL << EXTI_FTSR_TR2_Pos)
#define EXTI_FTSR_TR2               EXTI_FTSR_TR2_Msk

#define EXTI_FTSR_TR3_Pos           (3U)
#define EXTI_FTSR_TR3_Msk           (0x1UL << EXTI_FTSR_TR3_Pos)
#define EXTI_FTSR_TR3               EXTI_FTSR_TR3_Msk

#define EXTI_FTSR_TR4_Pos           (4U)
#define EXTI_FTSR_TR4_Msk           (0x1UL << EXTI_FTSR_TR4_Pos)
#define EXTI_FTSR_TR4               EXTI_FTSR_TR4_Msk

#define EXTI_FTSR_TR5_Pos           (5U)
#define EXTI_FTSR_TR5_Msk           (0x1UL << EXTI_FTSR_TR5_Pos)
#define EXTI_FTSR_TR5               EXTI_FTSR_TR5_Msk

#define EXTI_FTSR_TR6_Pos           (6U)
#define EXTI_FTSR_TR6_Msk           (0x1UL << EXTI_FTSR_TR6_Pos)
#define EXTI_FTSR_TR6               EXTI_FTSR_TR6_Msk

#define EXTI_FTSR_TR7_Pos           (7U)
#define EXTI_FTSR_TR7_Msk           (0x1UL << EXTI_FTSR_TR7_Pos)
#define EXTI_FTSR_TR7               EXTI_FTSR_TR7_Msk

#define EXTI_FTSR_TR8_Pos           (8U)
#define EXTI_FTSR_TR8_Msk           (0x1UL << EXTI_FTSR_TR8_Pos)
#define EXTI_FTSR_TR8               EXTI_FTSR_TR8_Msk

#define EXTI_FTSR_TR9_Pos           (9U)
#define EXTI_FTSR_TR9_Msk           (0x1UL << EXTI_FTSR_TR9_Pos)
#define EXTI_FTSR_TR9               EXTI_FTSR_TR9_Msk

#define EXTI_FTSR_TR10_Pos          (10U)
#define EXTI_FTSR_TR10_Msk          (0x1UL << EXTI_FTSR_TR10_Pos)
#define EXTI_FTSR_TR10              EXTI_FTSR_TR10_Msk

#define EXTI_FTSR_TR11_Pos          (11U)
#define EXTI_FTSR_TR11_Msk          (0x1UL << EXTI_FTSR_TR11_Pos)
#define EXTI_FTSR_TR11              EXTI_FTSR_TR11_Msk

#define EXTI_FTSR_TR12_Pos          (12U)
#define EXTI_FTSR_TR12_Msk          (0x1UL << EXTI_FTSR_TR12_Pos)
#define EXTI_FTSR_TR12              EXTI_FTSR_TR12_Msk

#define EXTI_FTSR_TR13_Pos          (13U)
#define EXTI_FTSR_TR13_Msk          (0x1UL << EXTI_FTSR_TR13_Pos)
#define EXTI_FTSR_TR13              EXTI_FTSR_TR13_Msk

#define EXTI_FTSR_TR14_Pos          (14U)
#define EXTI_FTSR_TR14_Msk          (0x1UL << EXTI_FTSR_TR14_Pos)
#define EXTI_FTSR_TR14              EXTI_FTSR_TR14_Msk

#define EXTI_FTSR_TR15_Pos          (15U)
#define EXTI_FTSR_TR15_Msk          (0x1UL << EXTI_FTSR_TR15_Pos)
#define EXTI_FTSR_TR15              EXTI_FTSR_TR15_Msk

#define EXTI_FTSR_TR16_Pos          (16U)
#define EXTI_FTSR_TR16_Msk          (0x1UL << EXTI_FTSR_TR16_Pos)
#define EXTI_FTSR_TR16              EXTI_FTSR_TR16_Msk

#define EXTI_FTSR_TR17_Pos          (17U)
#define EXTI_FTSR_TR17_Msk          (0x1UL << EXTI_FTSR_TR17_Pos)
#define EXTI_FTSR_TR17              EXTI_FTSR_TR17_Msk

#define EXTI_FTSR_TR18_Pos          (18U)
#define EXTI_FTSR_TR18_Msk          (0x1UL << EXTI_FTSR_TR18_Pos)
#define EXTI_FTSR_TR18              EXTI_FTSR_TR18_Msk

#define EXTI_FTSR_TR21_Pos          (21U)
#define EXTI_FTSR_TR21_Msk          (0x1UL << EXTI_FTSR_TR21_Pos)
#define EXTI_FTSR_TR21              EXTI_FTSR_TR21_Msk

#define EXTI_FTSR_TR22_Pos          (22U)
#define EXTI_FTSR_TR22_Msk          (0x1UL << EXTI_FTSR_TR22_Pos)
#define EXTI_FTSR_TR22              EXTI_FTSR_TR22_Msk

/********************* Bits definition for EXTI_SWIER register ********************/
#define EXTI_SWIER0_Pos             (0U)
#define EXTI_SWIER0_Msk             (0x1UL << EXTI_SWIER0_Pos)
#define EXTI_SWIER0                 EXTI_SWIER0_Msk

#define EXTI_SWIER1_Pos             (1U)
#define EXTI_SWIER1_Msk             (0x1UL << EXTI_SWIER1_Pos)
#define EXTI_SWIER1                 EXTI_SWIER1_Msk

#define EXTI_SWIER2_Pos             (2U)
#define EXTI_SWIER2_Msk             (0x1UL << EXTI_SWIER2_Pos)
#define EXTI_SWIER2                 EXTI_SWIER2_Msk

#define EXTI_SWIER3_Pos             (3U)
#define EXTI_SWIER3_Msk             (0x1UL << EXTI_SWIER3_Pos)
#define EXTI_SWIER3                 EXTI_SWIER3_Msk

#define EXTI_SWIER4_Pos             (4U)
#define EXTI_SWIER4_Msk             (0x1UL << EXTI_SWIER4_Pos)
#define EXTI_SWIER4                 EXTI_SWIER4_Msk

#define EXTI_SWIER5_Pos             (5U)
#define EXTI_SWIER5_Msk             (0x1UL << EXTI_SWIER5_Pos)
#define EXTI_SWIER5                 EXTI_SWIER5_Msk

#define EXTI_SWIER6_Pos             (6U)
#define EXTI_SWIER6_Msk             (0x1UL << EXTI_SWIER6_Pos)
#define EXTI_SWIER6                 EXTI_SWIER6_Msk

#define EXTI_SWIER7_Pos             (7U)
#define EXTI_SWIER7_Msk             (0x1UL << EXTI_SWIER7_Pos)
#define EXTI_SWIER7                 EXTI_SWIER7_Msk

#define EXTI_SWIER8_Pos             (8U)
#define EXTI_SWIER8_Msk             (0x1UL << EXTI_SWIER8_Pos)
#define EXTI_SWIER8                 EXTI_SWIER8_Msk

#define EXTI_SWIER9_Pos             (9U)
#define EXTI_SWIER9_Msk             (0x1UL << EXTI_SWIER9_Pos)
#define EXTI_SWIER9                 EXTI_SWIER9_Msk

#define EXTI_SWIER10_Pos            (10U)
#define EXTI_SWIER10_Msk            (0x1UL << EXTI_SWIER10_Pos)
#define EXTI_SWIER10                EXTI_SWIER10_Msk

#define EXTI_SWIER11_Pos            (11U)
#define EXTI_SWIER11_Msk            (0x1UL << EXTI_SWIER11_Pos)
#define EXTI_SWIER11                EXTI_SWIER11_Msk

#define EXTI_SWIER12_Pos            (12U)
#define EXTI_SWIER12_Msk            (0x1UL << EXTI_SWIER12_Pos)
#define EXTI_SWIER12                EXTI_SWIER12_Msk

#define EXTI_SWIER13_Pos            (13U)
#define EXTI_SWIER13_Msk            (0x1UL << EXTI_SWIER13_Pos)
#define EXTI_SWIER13                EXTI_SWIER13_Msk

#define EXTI_SWIER14_Pos            (14U)
#define EXTI_SWIER14_Msk            (0x1UL << EXTI_SWIER14_Pos)
#define EXTI_SWIER14                EXTI_SWIER14_Msk

#define EXTI_SWIER15_Pos            (15U)
#define EXTI_SWIER15_Msk            (0x1UL << EXTI_SWIER15_Pos)
#define EXTI_SWIER15                EXTI_SWIER15_Msk

#define EXTI_SWIER16_Pos            (16U)
#define EXTI_SWIER16_Msk            (0x1UL << EXTI_SWIER16_Pos)
#define EXTI_SWIER16                EXTI_SWIER16_Msk

#define EXTI_SWIER17_Pos            (17U)
#define EXTI_SWIER17_Msk            (0x1UL << EXTI_SWIER17_Pos)
#define EXTI_SWIER17                EXTI_SWIER17_Msk

#define EXTI_SWIER18_Pos            (18U)
#define EXTI_SWIER18_Msk            (0x1UL << EXTI_SWIER18_Pos)
#define EXTI_SWIER18                EXTI_SWIER18_Msk

#define EXTI_SWIER21_Pos            (21U)
#define EXTI_SWIER21_Msk            (0x1UL << EXTI_SWIER21_Pos)
#define EXTI_SWIER21                EXTI_SWIER21_Msk

#define EXTI_SWIER22_Pos            (22U)
#define EXTI_SWIER22_Msk            (0x1UL << EXTI_SWIER22_Pos)
#define EXTI_SWIER22                EXTI_SWIER22_Msk

/********************** Bits definition for EXTI_PR register **********************/
#define EXTI_PR0_Pos                (0U)
#define EXTI_PR0_Msk                (0x1UL << EXTI_PR0_Pos)
#define EXTI_PR0                    EXTI_PR0_Msk

#define EXTI_PR1_Pos                (1U)
#define EXTI_PR1_Msk                (0x1UL << EXTI_PR1_Pos)
#define EXTI_PR1                    EXTI_PR1_Msk

#define EXTI_PR2_Pos                (2U)
#define EXTI_PR2_Msk                (0x1UL << EXTI_PR2_Pos)
#define EXTI_PR2                    EXTI_PR2_Msk

#define EXTI_PR3_Pos                (3U)
#define EXTI_PR3_Msk                (0x1UL << EXTI_PR3_Pos)
#define EXTI_PR3                    EXTI_PR3_Msk

#define EXTI_PR4_Pos                (4U)
#define EXTI_PR4_Msk                (0x1UL << EXTI_PR4_Pos)
#define EXTI_PR4                    EXTI_PR4_Msk

#define EXTI_PR5_Pos                (5U)
#define EXTI_PR5_Msk                (0x1UL << EXTI_PR5_Pos)
#define EXTI_PR5                    EXTI_PR5_Msk

#define EXTI_PR6_Pos                (6U)
#define EXTI_PR6_Msk                (0x1UL << EXTI_PR6_Pos)
#define EXTI_PR6                    EXTI_PR6_Msk

#define EXTI_PR7_Pos                (7U)
#define EXTI_PR7_Msk                (0x1UL << EXTI_PR7_Pos)
#define EXTI_PR7                    EXTI_PR7_Msk

#define EXTI_PR8_Pos                (8U)
#define EXTI_PR8_Msk                (0x1UL << EXTI_PR8_Pos)
#define EXTI_PR8                    EXTI_PR8_Msk

#define EXTI_PR9_Pos                (9U)
#define EXTI_PR9_Msk                (0x1UL << EXTI_PR9_Pos)
#define EXTI_PR9                    EXTI_PR9_Msk

#define EXTI_PR10_Pos               (10U)
#define EXTI_PR10_Msk               (0x1UL << EXTI_PR10_Pos)
#define EXTI_PR10                   EXTI_PR10_Msk

#define EXTI_PR11_Pos               (11U)
#define EXTI_PR11_Msk               (0x1UL << EXTI_PR11_Pos)
#define EXTI_PR11                   EXTI_PR11_Msk

#define EXTI_PR12_Pos               (12U)
#define EXTI_PR12_Msk               (0x1UL << EXTI_PR12_Pos)
#define EXTI_PR12                   EXTI_PR12_Msk

#define EXTI_PR13_Pos               (13U)
#define EXTI_PR13_Msk               (0x1UL << EXTI_PR13_Pos)
#define EXTI_PR13                   EXTI_PR13_Msk

#define EXTI_PR14_Pos               (14U)
#define EXTI_PR14_Msk               (0x1UL << EXTI_PR14_Pos)
#define EXTI_PR14                   EXTI_PR14_Msk

#define EXTI_PR15_Pos               (15U)
#define EXTI_PR15_Msk               (0x1UL << EXTI_PR15_Pos)
#define EXTI_PR15                   EXTI_PR15_Msk

#define EXTI_PR16_Pos               (16U)
#define EXTI_PR16_Msk               (0x1UL << EXTI_PR16_Pos)
#define EXTI_PR16                   EXTI_PR16_Msk

#define EXTI_PR17_Pos               (17U)
#define EXTI_PR17_Msk               (0x1UL << EXTI_PR17_Pos)
#define EXTI_PR17                   EXTI_PR17_Msk

#define EXTI_PR18_Pos               (18U)
#define EXTI_PR18_Msk               (0x1UL << EXTI_PR18_Pos)
#define EXTI_PR18                   EXTI_PR18_Msk

#define EXTI_PR21_Pos               (21U)
#define EXTI_PR21_Msk               (0x1UL << EXTI_PR21_Pos)
#define EXTI_PR21                   EXTI_PR21_Msk

#define EXTI_PR22_Pos               (22U)
#define EXTI_PR22_Msk               (0x1UL << EXTI_PR22_Pos)
#define EXTI_PR22                   EXTI_PR22_Msk


/**********************************************************************************/
/*                                                                                */
/*                             General Purpose I/0 (GPIO)                         */
/*                                                                                */
/**********************************************************************************/

/********************* Bits definition for GPIO_MODER register ********************/
#define GPIO_MODER_MODER0_Pos       (0U)
#define GPIO_MODER_MODER0_Msk       (0x3UL << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0           GPIO_MODER_MODER0_Msk
#define GPIO_MODER_MODER0_IN        (0x0UL << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0_OUT       (0x1UL << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0_AF        (0x2UL << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0_AM        (0x3UL << GPIO_MODER_MODER0_Pos)

#define GPIO_MODER_MODER1_Pos       (2U)
#define GPIO_MODER_MODER1_Msk       (0x3UL << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER1           GPIO_MODER_MODER1_Msk
#define GPIO_MODER_MODER1_IN        (0x0UL << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER1_OUT       (0x1UL << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER1_AF        (0x2UL << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER1_AM        (0x3UL << GPIO_MODER_MODER1_Pos)

#define GPIO_MODER_MODER2_Pos       (4U)
#define GPIO_MODER_MODER2_Msk       (0x3UL << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER2           GPIO_MODER_MODER2_Msk
#define GPIO_MODER_MODER2_IN        (0x0UL << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER2_OUT       (0x1UL << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER2_AF        (0x2UL << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER2_AM        (0x3UL << GPIO_MODER_MODER2_Pos)

#define GPIO_MODER_MODER3_Pos       (6U)
#define GPIO_MODER_MODER3_Msk       (0x3UL << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER3           GPIO_MODER_MODER3_Msk
#define GPIO_MODER_MODER3_IN        (0x0UL << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER3_OUT       (0x1UL << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER3_AF        (0x2UL << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER3_AM        (0x3UL << GPIO_MODER_MODER3_Pos)

#define GPIO_MODER_MODER4_Pos       (8U)
#define GPIO_MODER_MODER4_Msk       (0x3UL << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER4           GPIO_MODER_MODER4_Msk
#define GPIO_MODER_MODER4_IN        (0x0UL << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER4_OUT       (0x1UL << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER4_AF        (0x2UL << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER4_AM        (0x3UL << GPIO_MODER_MODER4_Pos)

#define GPIO_MODER_MODER5_Pos       (10U)
#define GPIO_MODER_MODER5_Msk       (0x3UL << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5           GPIO_MODER_MODER5_Msk
#define GPIO_MODER_MODER5_IN        (0x0UL << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5_OUT       (0x1UL << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5_AF        (0x2UL << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5_AM        (0x3UL << GPIO_MODER_MODER5_Pos)

#define GPIO_MODER_MODER6_Pos       (12U)
#define GPIO_MODER_MODER6_Msk       (0x3UL << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER6           GPIO_MODER_MODER6_Msk
#define GPIO_MODER_MODER6_IN        (0x0UL << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER6_OUT       (0x1UL << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER6_AF        (0x2UL << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER6_AM        (0x3UL << GPIO_MODER_MODER6_Pos)

#define GPIO_MODER_MODER7_Pos       (14U)
#define GPIO_MODER_MODER7_Msk       (0x3UL << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER7           GPIO_MODER_MODER7_Msk
#define GPIO_MODER_MODER7_IN        (0x0UL << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER7_OUT       (0x1UL << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER7_AF        (0x2UL << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER7_AM        (0x3UL << GPIO_MODER_MODER7_Pos)

#define GPIO_MODER_MODER8_Pos       (16U)
#define GPIO_MODER_MODER8_Msk       (0x3UL << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER8           GPIO_MODER_MODER8_Msk
#define GPIO_MODER_MODER8_IN        (0x0UL << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER8_OUT       (0x1UL << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER8_AF        (0x2UL << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER8_AM        (0x3UL << GPIO_MODER_MODER8_Pos)

#define GPIO_MODER_MODER9_Pos       (18U)
#define GPIO_MODER_MODER9_Msk       (0x3UL << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER9           GPIO_MODER_MODER9_Msk
#define GPIO_MODER_MODER9_IN        (0x0UL << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER9_OUT       (0x1UL << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER9_AF        (0x2UL << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER9_AM        (0x3UL << GPIO_MODER_MODER9_Pos)

#define GPIO_MODER_MODER10_Pos      (20U)
#define GPIO_MODER_MODER10_Msk      (0x3UL << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER10          GPIO_MODER_MODER10_Msk
#define GPIO_MODER_MODER10_IN       (0x0UL << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER10_OUT      (0x1UL << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER10_AF       (0x2UL << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER10_AM       (0x3UL << GPIO_MODER_MODER10_Pos)

#define GPIO_MODER_MODER11_Pos      (22U)
#define GPIO_MODER_MODER11_Msk      (0x3UL << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER11          GPIO_MODER_MODER11_Msk
#define GPIO_MODER_MODER11_IN       (0x0UL << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER11_OUT      (0x1UL << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER11_AF       (0x2UL << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER11_AM       (0x3UL << GPIO_MODER_MODER11_Pos)

#define GPIO_MODER_MODER12_Pos      (24U)
#define GPIO_MODER_MODER12_Msk      (0x3UL << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER12          GPIO_MODER_MODER12_Msk
#define GPIO_MODER_MODER12_IN       (0x0UL << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER12_OUT      (0x1UL << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER12_AF       (0x2UL << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER12_AM       (0x3UL << GPIO_MODER_MODER12_Pos)

#define GPIO_MODER_MODER13_Pos      (26U)
#define GPIO_MODER_MODER13_Msk      (0x3UL << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER13          GPIO_MODER_MODER13_Msk
#define GPIO_MODER_MODER13_IN       (0x0UL << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER13_OUT      (0x1UL << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER13_AF       (0x2UL << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER13_AM       (0x3UL << GPIO_MODER_MODER13_Pos)

#define GPIO_MODER_MODER14_Pos      (28U)
#define GPIO_MODER_MODER14_Msk      (0x3UL << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER14          GPIO_MODER_MODER14_Msk
#define GPIO_MODER_MODER14_IN       (0x0UL << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER14_OUT      (0x1UL << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER14_AF       (0x2UL << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER14_AM       (0x3UL << GPIO_MODER_MODER14_Pos)

#define GPIO_MODER_MODER15_Pos      (30U)
#define GPIO_MODER_MODER15_Msk      (0x3UL << GPIO_MODER_MODER15_Pos)
#define GPIO_MODER_MODER15          GPIO_MODER_MODER15_Msk
#define GPIO_MODER_MODER15_IN       (0x0UL << GPIO_MODER_MODER15_Pos)
#define GPIO_MODER_MODER15_OUT      (0x1UL << GPIO_MODER_MODER15_Pos)
#define GPIO_MODER_MODER15_AF       (0x2UL << GPIO_MODER_MODER15_Pos)
#define GPIO_MODER_MODER15_AM       (0x3UL << GPIO_MODER_MODER15_Pos)

#define GPIO_MODER_MODER16_Pos      (32U)
#define GPIO_MODER_MODER16_Msk      (0x3UL << GPIO_MODER_MODER16_Pos)
#define GPIO_MODER_MODER16          GPIO_MODER_MODER16_Msk
#define GPIO_MODER_MODER16_IN       (0x0UL << GPIO_MODER_MODER16_Pos)
#define GPIO_MODER_MODER16_OUT      (0x1UL << GPIO_MODER_MODER16_Pos)
#define GPIO_MODER_MODER16_AF       (0x2UL << GPIO_MODER_MODER16_Pos)
#define GPIO_MODER_MODER16_AM       (0x3UL << GPIO_MODER_MODER16_Pos)

/****************** Bits definition for the GPIO_OTYPER register ******************/
#define GPIO_OTYPER_OT0_Pos         (0U)
#define GPIO_OTYPER_OT0_Msk         (0x1UL << GPIO_OTYPER_OT0_Pos)
#define GPIO_OTYPER_OT0             GPIO_OTYPER_OT0_Msk

#define GPIO_OTYPER_OT1_Pos         (1U)
#define GPIO_OTYPER_OT1_Msk         (0x1UL << GPIO_OTYPER_OT1_Pos)
#define GPIO_OTYPER_OT1             GPIO_OTYPER_OT1_Msk

#define GPIO_OTYPER_OT2_Pos         (2U)
#define GPIO_OTYPER_OT2_Msk         (0x1UL << GPIO_OTYPER_OT2_Pos)
#define GPIO_OTYPER_OT2             GPIO_OTYPER_OT2_Msk

#define GPIO_OTYPER_OT3_Pos         (3U)
#define GPIO_OTYPER_OT3_Msk         (0x1UL << GPIO_OTYPER_OT3_Pos)
#define GPIO_OTYPER_OT3             GPIO_OTYPER_OT3_Msk

#define GPIO_OTYPER_OT4_Pos         (4U)
#define GPIO_OTYPER_OT4_Msk         (0x1UL << GPIO_OTYPER_OT4_Pos)
#define GPIO_OTYPER_OT4             GPIO_OTYPER_OT4_Msk

#define GPIO_OTYPER_OT5_Pos         (5U)
#define GPIO_OTYPER_OT5_Msk         (0x1UL << GPIO_OTYPER_OT5_Pos)
#define GPIO_OTYPER_OT5             GPIO_OTYPER_OT5_Msk

#define GPIO_OTYPER_OT6_Pos         (6U)
#define GPIO_OTYPER_OT6_Msk         (0x1UL << GPIO_OTYPER_OT6_Pos)
#define GPIO_OTYPER_OT6             GPIO_OTYPER_OT6_Msk

#define GPIO_OTYPER_OT7_Pos         (7U)
#define GPIO_OTYPER_OT7_Msk         (0x1UL << GPIO_OTYPER_OT7_Pos)
#define GPIO_OTYPER_OT7             GPIO_OTYPER_OT7_Msk

#define GPIO_OTYPER_OT8_Pos         (8U)
#define GPIO_OTYPER_OT8_Msk         (0x1UL << GPIO_OTYPER_OT8_Pos)
#define GPIO_OTYPER_OT8             GPIO_OTYPER_OT8_Msk

#define GPIO_OTYPER_OT9_Pos         (9U)
#define GPIO_OTYPER_OT9_Msk         (0x1UL << GPIO_OTYPER_OT9_Pos)
#define GPIO_OTYPER_OT9             GPIO_OTYPER_OT9_Msk

#define GPIO_OTYPER_OT10_Pos        (10U)
#define GPIO_OTYPER_OT10_Msk        (0x1UL << GPIO_OTYPER_OT10_Pos)
#define GPIO_OTYPER_OT10            GPIO_OTYPER_OT10_Msk

#define GPIO_OTYPER_OT11_Pos        (11U)
#define GPIO_OTYPER_OT11_Msk        (0x1UL << GPIO_OTYPER_OT11_Pos)
#define GPIO_OTYPER_OT11            GPIO_OTYPER_OT11_Msk

#define GPIO_OTYPER_OT12_Pos        (12U)
#define GPIO_OTYPER_OT12_Msk        (0x1UL << GPIO_OTYPER_OT12_Pos)
#define GPIO_OTYPER_OT12            GPIO_OTYPER_OT12_Msk

#define GPIO_OTYPER_OT13_Pos        (13U)
#define GPIO_OTYPER_OT13_Msk        (0x1UL << GPIO_OTYPER_OT13_Pos)
#define GPIO_OTYPER_OT13            GPIO_OTYPER_OT13_Msk

#define GPIO_OTYPER_OT14_Pos        (14U)
#define GPIO_OTYPER_OT14_Msk        (0x1UL << GPIO_OTYPER_OT14_Pos)
#define GPIO_OTYPER_OTR14           GPIO_OTYPER_OT14_Msk

#define GPIO_OTYPER_OT15_Pos        (15U)
#define GPIO_OTYPER_OT15_Msk        (0x1UL << GPIO_OTYPER_OT15_Pos)
#define GPIO_OTYPER_OT15            GPIO_OTYPER_OT15_Msk

/***************** Bits definition for the GPIO_OSPEEDR register ******************/
#define GPIO_OSPEEDR_OSPEED0_Pos    (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)
#define GPIO_OSPEEDR_OSPEED0        GPIO_OSPEEDR_OSPEED0_Msk
#define GPIO_OSPEEDR_OSPEED0_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED0_Pos)
#define GPIO_OSPEEDR_OSPEED0_MED    (0x1UL << GPIO_OSPEEDR_OSPEED0_Pos)
#define GPIO_OSPEEDR_OSPEED0_FST    (0x2UL << GPIO_OSPEEDR_OSPEED0_Pos)
#define GPIO_OSPEEDR_OSPEED0_HI     (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)

#define GPIO_OSPEEDR_OSPEED1_Pos    (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)
#define GPIO_OSPEEDR_OSPEED1        GPIO_OSPEEDR_OSPEED1_Msk
#define GPIO_OSPEEDR_OSPEED1_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED1_Pos)
#define GPIO_OSPEEDR_OSPEED1_MED    (0x1UL << GPIO_OSPEEDR_OSPEED1_Pos)
#define GPIO_OSPEEDR_OSPEED1_FST    (0x2UL << GPIO_OSPEEDR_OSPEED1_Pos)
#define GPIO_OSPEEDR_OSPEED1_HI     (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)

#define GPIO_OSPEEDR_OSPEED2_Pos    (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)
#define GPIO_OSPEEDR_OSPEED2        GPIO_OSPEEDR_OSPEED2_Msk
#define GPIO_OSPEEDR_OSPEED2_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED2_Pos)
#define GPIO_OSPEEDR_OSPEED2_MED    (0x1UL << GPIO_OSPEEDR_OSPEED2_Pos)
#define GPIO_OSPEEDR_OSPEED2_FST    (0x2UL << GPIO_OSPEEDR_OSPEED2_Pos)
#define GPIO_OSPEEDR_OSPEED2_HI     (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)

#define GPIO_OSPEEDR_OSPEED3_Pos    (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)
#define GPIO_OSPEEDR_OSPEED3        GPIO_OSPEEDR_OSPEED3_Msk
#define GPIO_OSPEEDR_OSPEED3_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED3_Pos)
#define GPIO_OSPEEDR_OSPEED3_MED    (0x1UL << GPIO_OSPEEDR_OSPEED3_Pos)
#define GPIO_OSPEEDR_OSPEED3_FST    (0x2UL << GPIO_OSPEEDR_OSPEED3_Pos)
#define GPIO_OSPEEDR_OSPEED3_HI     (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)

#define GPIO_OSPEEDR_OSPEED4_Pos    (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)
#define GPIO_OSPEEDR_OSPEED4        GPIO_OSPEEDR_OSPEED4_Msk
#define GPIO_OSPEEDR_OSPEED4_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED4_Pos)
#define GPIO_OSPEEDR_OSPEED4_MED    (0x1UL << GPIO_OSPEEDR_OSPEED4_Pos)
#define GPIO_OSPEEDR_OSPEED4_FST    (0x2UL << GPIO_OSPEEDR_OSPEED4_Pos)
#define GPIO_OSPEEDR_OSPEED4_HI     (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)

#define GPIO_OSPEEDR_OSPEED5_Pos    (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)
#define GPIO_OSPEEDR_OSPEED5        GPIO_OSPEEDR_OSPEED5_Msk
#define GPIO_OSPEEDR_OSPEED5_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED5_Pos)
#define GPIO_OSPEEDR_OSPEED5_MED    (0x1UL << GPIO_OSPEEDR_OSPEED5_Pos)
#define GPIO_OSPEEDR_OSPEED5_FST    (0x2UL << GPIO_OSPEEDR_OSPEED5_Pos)
#define GPIO_OSPEEDR_OSPEED5_HI     (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)

#define GPIO_OSPEEDR_OSPEED6_Pos    (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)
#define GPIO_OSPEEDR_OSPEED6        GPIO_OSPEEDR_OSPEED6_Msk
#define GPIO_OSPEEDR_OSPEED6_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED6_Pos)
#define GPIO_OSPEEDR_OSPEED6_MED    (0x1UL << GPIO_OSPEEDR_OSPEED6_Pos)
#define GPIO_OSPEEDR_OSPEED6_FST    (0x2UL << GPIO_OSPEEDR_OSPEED6_Pos)
#define GPIO_OSPEEDR_OSPEED6_HI     (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)

#define GPIO_OSPEEDR_OSPEED7_Pos    (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)
#define GPIO_OSPEEDR_OSPEED7        GPIO_OSPEEDR_OSPEED7_Msk
#define GPIO_OSPEEDR_OSPEED7_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED7_Pos)
#define GPIO_OSPEEDR_OSPEED7_MED    (0x1UL << GPIO_OSPEEDR_OSPEED7_Pos)
#define GPIO_OSPEEDR_OSPEED7_FST    (0x2UL << GPIO_OSPEEDR_OSPEED7_Pos)
#define GPIO_OSPEEDR_OSPEED7_HI     (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)

#define GPIO_OSPEEDR_OSPEED8_Pos    (16U)
#define GPIO_OSPEEDR_OSPEED8_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED8_Pos)
#define GPIO_OSPEEDR_OSPEED8        GPIO_OSPEEDR_OSPEED8_Msk
#define GPIO_OSPEEDR_OSPEED8_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED8_Pos)
#define GPIO_OSPEEDR_OSPEED8_MED    (0x1UL << GPIO_OSPEEDR_OSPEED8_Pos)
#define GPIO_OSPEEDR_OSPEED8_FST    (0x2UL << GPIO_OSPEEDR_OSPEED8_Pos)
#define GPIO_OSPEEDR_OSPEED8_HI     (0x3UL << GPIO_OSPEEDR_OSPEED8_Pos)

#define GPIO_OSPEEDR_OSPEED9_Pos    (18U)
#define GPIO_OSPEEDR_OSPEED9_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED9_Pos)
#define GPIO_OSPEEDR_OSPEED9        GPIO_OSPEEDR_OSPEED9_Msk
#define GPIO_OSPEEDR_OSPEED9_LOW    (0x0UL << GPIO_OSPEEDR_OSPEED9_Pos)
#define GPIO_OSPEEDR_OSPEED9_MED    (0x1UL << GPIO_OSPEEDR_OSPEED9_Pos)
#define GPIO_OSPEEDR_OSPEED9_FST    (0x2UL << GPIO_OSPEEDR_OSPEED9_Pos)
#define GPIO_OSPEEDR_OSPEED9_HI     (0x3UL << GPIO_OSPEEDR_OSPEED9_Pos)

#define GPIO_OSPEEDR_OSPEED10_Pos   (20U)
#define GPIO_OSPEEDR_OSPEED10_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED10_Pos)
#define GPIO_OSPEEDR_OSPEED10       GPIO_OSPEEDR_OSPEED10_Msk
#define GPIO_OSPEEDR_OSPEED10_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED10_Pos)
#define GPIO_OSPEEDR_OSPEED10_MED   (0x1UL << GPIO_OSPEEDR_OSPEED10_Pos)
#define GPIO_OSPEEDR_OSPEED10_FST   (0x2UL << GPIO_OSPEEDR_OSPEED10_Pos)
#define GPIO_OSPEEDR_OSPEED10_HI    (0x3UL << GPIO_OSPEEDR_OSPEED10_Pos)

#define GPIO_OSPEEDR_OSPEED11_Pos   (22U)
#define GPIO_OSPEEDR_OSPEED11_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED11_Pos)
#define GPIO_OSPEEDR_OSPEED11       GPIO_OSPEEDR_OSPEED11_Msk
#define GPIO_OSPEEDR_OSPEED11_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED11_Pos)
#define GPIO_OSPEEDR_OSPEED11_MED   (0x1UL << GPIO_OSPEEDR_OSPEED11_Pos)
#define GPIO_OSPEEDR_OSPEED11_FST   (0x2UL << GPIO_OSPEEDR_OSPEED11_Pos)
#define GPIO_OSPEEDR_OSPEED11_HI    (0x3UL << GPIO_OSPEEDR_OSPEED11_Pos)

#define GPIO_OSPEEDR_OSPEED12_Pos   (24U)
#define GPIO_OSPEEDR_OSPEED12_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED12_Pos)
#define GPIO_OSPEEDR_OSPEED12       GPIO_OSPEEDR_OSPEED12_Msk
#define GPIO_OSPEEDR_OSPEED12_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED12_Pos)
#define GPIO_OSPEEDR_OSPEED12_MED   (0x1UL << GPIO_OSPEEDR_OSPEED12_Pos)
#define GPIO_OSPEEDR_OSPEED12_FST   (0x2UL << GPIO_OSPEEDR_OSPEED12_Pos)
#define GPIO_OSPEEDR_OSPEED12_HI    (0x3UL << GPIO_OSPEEDR_OSPEED12_Pos)

#define GPIO_OSPEEDR_OSPEED13_Pos   (26U)
#define GPIO_OSPEEDR_OSPEED13_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED13_Pos)
#define GPIO_OSPEEDR_OSPEED13       GPIO_OSPEEDR_OSPEED13_Msk
#define GPIO_OSPEEDR_OSPEED13_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED13_Pos)
#define GPIO_OSPEEDR_OSPEED13_MED   (0x1UL << GPIO_OSPEEDR_OSPEED13_Pos)
#define GPIO_OSPEEDR_OSPEED13_FST   (0x2UL << GPIO_OSPEEDR_OSPEED13_Pos)
#define GPIO_OSPEEDR_OSPEED13_HI    (0x3UL << GPIO_OSPEEDR_OSPEED13_Pos)

#define GPIO_OSPEEDR_OSPEED14_Pos   (28U)
#define GPIO_OSPEEDR_OSPEED14_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED14_Pos)
#define GPIO_OSPEEDR_OSPEED14       GPIO_OSPEEDR_OSPEED14_Msk
#define GPIO_OSPEEDR_OSPEED14_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED14_Pos)
#define GPIO_OSPEEDR_OSPEED14_MED   (0x1UL << GPIO_OSPEEDR_OSPEED14_Pos)
#define GPIO_OSPEEDR_OSPEED14_FST   (0x2UL << GPIO_OSPEEDR_OSPEED14_Pos)
#define GPIO_OSPEEDR_OSPEED14_HI    (0x3UL << GPIO_OSPEEDR_OSPEED14_Pos)

#define GPIO_OSPEEDR_OSPEED15_Pos   (30U)
#define GPIO_OSPEEDR_OSPEED15_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED15_Pos)
#define GPIO_OSPEEDR_OSPEED15       GPIO_OSPEEDR_OSPEED15_Msk
#define GPIO_OSPEEDR_OSPEED15_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED15_Pos)
#define GPIO_OSPEEDR_OSPEED15_MED   (0x1UL << GPIO_OSPEEDR_OSPEED15_Pos)
#define GPIO_OSPEEDR_OSPEED15_FST   (0x2UL << GPIO_OSPEEDR_OSPEED15_Pos)
#define GPIO_OSPEEDR_OSPEED15_HI    (0x3UL << GPIO_OSPEEDR_OSPEED15_Pos)

#define GPIO_OSPEEDR_OSPEED16_Pos   (32U)
#define GPIO_OSPEEDR_OSPEED16_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED16_Pos)
#define GPIO_OSPEEDR_OSPEED16       GPIO_OSPEEDR_OSPEED16_Msk
#define GPIO_OSPEEDR_OSPEED16_LOW   (0x0UL << GPIO_OSPEEDR_OSPEED16_Pos)
#define GPIO_OSPEEDR_OSPEED16_MED   (0x1UL << GPIO_OSPEEDR_OSPEED16_Pos)
#define GPIO_OSPEEDR_OSPEED16_FST   (0x2UL << GPIO_OSPEEDR_OSPEED16_Pos)
#define GPIO_OSPEEDR_OSPEED16_HI    (0x3UL << GPIO_OSPEEDR_OSPEED16_Pos)

/****************** Bits definition for the GPIO_PUPDR register *******************/
#define GPIO_PUPDR_PUPD0_Pos        (0U)
#define GPIO_PUPDR_PUPD0_Msk        (0x3UL << GPIO_PUPDR_PUPD0_Pos)
#define GPIO_PUPDR_PUPD0            GPIO_PUPDR_PUPD0_Msk
#define GPIO_PUPDR_PUPD0_PU         (0x1UL << GPIO_PUPDR_PUPD0_Pos)
#define GPIO_PUPDR_PUPD0_PD         (0x2UL << GPIO_PUPDR_PUPD0_Pos)

#define GPIO_PUPDR_PUPD1_Pos        (2U)
#define GPIO_PUPDR_PUPD1_Msk        (0x3UL << GPIO_PUPDR_PUPD1_Pos)
#define GPIO_PUPDR_PUPD1            GPIO_PUPDR_PUPD1_Msk
#define GPIO_PUPDR_PUPD1_PU         (0x1UL << GPIO_PUPDR_PUPD1_Pos)
#define GPIO_PUPDR_PUPD1_PD         (0x2UL << GPIO_PUPDR_PUPD1_Pos)

#define GPIO_PUPDR_PUPD2_Pos        (4U)
#define GPIO_PUPDR_PUPD2_Msk        (0x3UL << GPIO_PUPDR_PUPD2_Pos)
#define GPIO_PUPDR_PUPD2            GPIO_PUPDR_PUPD2_Msk
#define GPIO_PUPDR_PUPD2_PU         (0x1UL << GPIO_PUPDR_PUPD2_Pos)
#define GPIO_PUPDR_PUPD2_PD         (0x2UL << GPIO_PUPDR_PUPD2_Pos)

#define GPIO_PUPDR_PUPD3_Pos        (6U)
#define GPIO_PUPDR_PUPD3_Msk        (0x3UL << GPIO_PUPDR_PUPD3_Pos)
#define GPIO_PUPDR_PUPD3            GPIO_PUPDR_PUPD3_Msk
#define GPIO_PUPDR_PUPD3_PU         (0x1UL << GPIO_PUPDR_PUPD3_Pos)
#define GPIO_PUPDR_PUPD3_PD         (0x2UL << GPIO_PUPDR_PUPD3_Pos)

#define GPIO_PUPDR_PUPD4_Pos        (8U)
#define GPIO_PUPDR_PUPD4_Msk        (0x3UL << GPIO_PUPDR_PUPD4_Pos)
#define GPIO_PUPDR_PUPD4            GPIO_PUPDR_PUPD4_Msk
#define GPIO_PUPDR_PUPD4_PU         (0x1UL << GPIO_PUPDR_PUPD4_Pos)
#define GPIO_PUPDR_PUPD4_PD         (0x2UL << GPIO_PUPDR_PUPD4_Pos)

#define GPIO_PUPDR_PUPD5_Pos        (10U)
#define GPIO_PUPDR_PUPD5_Msk        (0x3UL << GPIO_PUPDR_PUPD5_Pos)
#define GPIO_PUPDR_PUPD5            GPIO_PUPDR_PUPD5_Msk
#define GPIO_PUPDR_PUPD5_PU         (0x1UL << GPIO_PUPDR_PUPD5_Pos)
#define GPIO_PUPDR_PUPD5_PD         (0x2UL << GPIO_PUPDR_PUPD5_Pos)

#define GPIO_PUPDR_PUPD6_Pos        (12U)
#define GPIO_PUPDR_PUPD6_Msk        (0x3UL << GPIO_PUPDR_PUPD6_Pos)
#define GPIO_PUPDR_PUPD6            GPIO_PUPDR_PUPD6_Msk
#define GPIO_PUPDR_PUPD6_PU         (0x1UL << GPIO_PUPDR_PUPD6_Pos)
#define GPIO_PUPDR_PUPD6_PD         (0x2UL << GPIO_PUPDR_PUPD6_Pos)

#define GPIO_PUPDR_PUPD7_Pos        (14U)
#define GPIO_PUPDR_PUPD7_Msk        (0x3UL << GPIO_PUPDR_PUPD7_Pos)
#define GPIO_PUPDR_PUPD7            GPIO_PUPDR_PUPD7_Msk
#define GPIO_PUPDR_PUPD7_PU         (0x1UL << GPIO_PUPDR_PUPD7_Pos)
#define GPIO_PUPDR_PUPD7_PD         (0x2UL << GPIO_PUPDR_PUPD7_Pos)

#define GPIO_PUPDR_PUPD8_Pos        (16U)
#define GPIO_PUPDR_PUPD8_Msk        (0x3UL << GPIO_PUPDR_PUPD8_Pos)
#define GPIO_PUPDR_PUPD8            GPIO_PUPDR_PUPD8_Msk
#define GPIO_PUPDR_PUPD8_PU         (0x1UL << GPIO_PUPDR_PUPD8_Pos)
#define GPIO_PUPDR_PUPD8_PD         (0x2UL << GPIO_PUPDR_PUPD8_Pos)

#define GPIO_PUPDR_PUPD9_Pos        (18U)
#define GPIO_PUPDR_PUPD9_Msk        (0x3UL << GPIO_PUPDR_PUPD9_Pos)
#define GPIO_PUPDR_PUPD9            GPIO_PUPDR_PUPD9_Msk
#define GPIO_PUPDR_PUPD9_PU         (0x1UL << GPIO_PUPDR_PUPD9_Pos)
#define GPIO_PUPDR_PUPD9_PD         (0x2UL << GPIO_PUPDR_PUPD9_Pos)

#define GPIO_PUPDR_PUPD10_Pos       (20U)
#define GPIO_PUPDR_PUPD10_Msk       (0x3UL << GPIO_PUPDR_PUPD10_Pos)
#define GPIO_PUPDR_PUPD10           GPIO_PUPDR_PUPD10_Msk
#define GPIO_PUPDR_PUPD10_PU        (0x1UL << GPIO_PUPDR_PUPD10_Pos)
#define GPIO_PUPDR_PUPD10_PD        (0x2UL << GPIO_PUPDR_PUPD10_Pos)

#define GPIO_PUPDR_PUPD11_Pos       (22U)
#define GPIO_PUPDR_PUPD11_Msk       (0x3UL << GPIO_PUPDR_PUPD11_Pos)
#define GPIO_PUPDR_PUPD11           GPIO_PUPDR_PUPD11_Msk
#define GPIO_PUPDR_PUPD11_PU        (0x1UL << GPIO_PUPDR_PUPD11_Pos)
#define GPIO_PUPDR_PUPD11_PD        (0x2UL << GPIO_PUPDR_PUPD11_Pos)

#define GPIO_PUPDR_PUPD12_Pos       (24U)
#define GPIO_PUPDR_PUPD12_Msk       (0x3UL << GPIO_PUPDR_PUPD12_Pos)
#define GPIO_PUPDR_PUPD12           GPIO_PUPDR_PUPD12_Msk
#define GPIO_PUPDR_PUPD12_PU        (0x1UL << GPIO_PUPDR_PUPD12_Pos)
#define GPIO_PUPDR_PUPD12_PD        (0x2UL << GPIO_PUPDR_PUPD12_Pos)

#define GPIO_PUPDR_PUPD13_Pos       (26U)
#define GPIO_PUPDR_PUPD13_Msk       (0x3UL << GPIO_PUPDR_PUPD13_Pos)
#define GPIO_PUPDR_PUPD13           GPIO_PUPDR_PUPD13_Msk
#define GPIO_PUPDR_PUPD13_PU        (0x1UL << GPIO_PUPDR_PUPD13_Pos)
#define GPIO_PUPDR_PUPD13_PD        (0x2UL << GPIO_PUPDR_PUPD13_Pos)

#define GPIO_PUPDR_PUPD14_Pos       (28U)
#define GPIO_PUPDR_PUPD14_Msk       (0x3UL << GPIO_PUPDR_PUPD14_Pos)
#define GPIO_PUPDR_PUPD14           GPIO_PUPDR_PUPD14_Msk
#define GPIO_PUPDR_PUPD14_PU        (0x1UL << GPIO_PUPDR_PUPD14_Pos)
#define GPIO_PUPDR_PUPD14_PD        (0x2UL << GPIO_PUPDR_PUPD14_Pos)

#define GPIO_PUPDR_PUPD15_Pos       (30U)
#define GPIO_PUPDR_PUPD15_Msk       (0x3UL << GPIO_PUPDR_PUPD15_Pos)
#define GPIO_PUPDR_PUPD15           GPIO_PUPDR_PUPD15_Msk
#define GPIO_PUPDR_PUPD15_PU        (0x1UL << GPIO_PUPDR_PUPD15_Pos)
#define GPIO_PUPDR_PUPD15_PD        (0x2UL << GPIO_PUPDR_PUPD15_Pos)

/******************* Bits definition for the GPIO_IDR register ********************/
#define GPIO_IDR_ID0_Pos            (0U)
#define GPIO_IDR_ID0_Msk            (0x1UL << GPIO_IDR_ID0_Pos)
#define GPIO_IDR_ID0                GPIO_IDR_ID0_Msk

#define GPIO_IDR_ID1_Pos            (1U)
#define GPIO_IDR_ID1_Msk            (0x1UL << GPIO_IDR_ID1_Pos)
#define GPIO_IDR_ID1                GPIO_IDR_ID1_Msk

#define GPIO_IDR_ID2_Pos            (2U)
#define GPIO_IDR_ID2_Msk            (0x1UL << GPIO_IDR_ID2_Pos)
#define GPIO_IDR_ID2                GPIO_IDR_ID2_Msk

#define GPIO_IDR_ID3_Pos            (3U)
#define GPIO_IDR_ID3_Msk            (0x1UL << GPIO_IDR_ID3_Pos)
#define GPIO_IDR_ID3                GPIO_IDR_ID3_Msk

#define GPIO_IDR_ID4_Pos            (4U)
#define GPIO_IDR_ID4_Msk            (0x1UL << GPIO_IDR_ID4_Pos)
#define GPIO_IDR_ID4                GPIO_IDR_ID4_Msk

#define GPIO_IDR_ID5_Pos            (5U)
#define GPIO_IDR_ID5_Msk            (0x1UL << GPIO_IDR_ID5_Pos)
#define GPIO_IDR_ID5                GPIO_IDR_ID5_Msk

#define GPIO_IDR_ID6_Pos            (6U)
#define GPIO_IDR_ID6_Msk            (0x1UL << GPIO_IDR_ID6_Pos)
#define GPIO_IDR_ID6                GPIO_IDR_ID6_Msk

#define GPIO_IDR_ID7_Pos            (7U)
#define GPIO_IDR_ID7_Msk            (0x1UL << GPIO_IDR_ID7_Pos)
#define GPIO_IDR_ID7                GPIO_IDR_ID7_Msk

#define GPIO_IDR_ID8_Pos            (8U)
#define GPIO_IDR_ID8_Msk            (0x1UL << GPIO_IDR_ID8_Pos)
#define GPIO_IDR_ID8                GPIO_IDR_ID8_Msk

#define GPIO_IDR_ID9_Pos            (9U)
#define GPIO_IDR_ID9_Msk            (0x1UL << GPIO_IDR_ID9_Pos)
#define GPIO_IDR_ID9                GPIO_IDR_ID9_Msk

#define GPIO_IDR_ID10_Pos           (10U)
#define GPIO_IDR_ID10_Msk           (0x1UL << GPIO_IDR_ID10_Pos)
#define GPIO_IDR_ID10               GPIO_IDR_ID10_Msk

#define GPIO_IDR_ID11_Pos           (11U)
#define GPIO_IDR_ID11_Msk           (0x1UL << GPIO_IDR_ID11_Pos)
#define GPIO_IDR_ID11               GPIO_IDR_ID11_Msk

#define GPIO_IDR_ID12_Pos           (12U)
#define GPIO_IDR_ID12_Msk           (0x1UL << GPI0_IDR_ID12_Pos)
#define GPIO_IDR_ID12               GPIO_IDR_ID12_Msk

#define GPIO_IDR_ID13_Pos           (13U)
#define GPIO_IDR_ID13_Msk           (0x1UL << GPIO_IDR_ID13_Pos)
#define GPIO_IDR_ID13               GPIO_IDR_ID13_Msk

#define GPIO_IDR_ID14_Pos           (14U)
#define GPIO_IDR_ID14_Msk           (0x1UL << GPIO_IDR_ID14_Pos)
#define GPIO_IDR_ID14               GPIO_IDR_ID14_Msk

#define GPIO_IDR_ID15_Pos           (15U)
#define GPIO_IDR_ID15_Msk           (0x1UL << GPIO_IDR_ID15_Pos)
#define GPIO_IDR_ID15               GPIO_IDR_ID15_Msk

/******************* Bits definition for the GPIO_ODR register ********************/
#define GPIO_ODR_OD0_Pos            (0U)
#define GPIO_ODR_OD0_Msk            (0x1UL << GPIO_ODR_OD0_Pos)
#define GPIO_ODR_OD0                GPIO_ODR_OD0_Msk

#define GPIO_ODR_OD1_Pos            (1U)
#define GPIO_ODR_OD1_Msk            (0x1UL << GPIO_ODR_OD1_Pos)
#define GPIO_ODR_OD1                GPIO_ODR_OD1_Msk

#define GPIO_ODR_OD2_Pos            (2U)
#define GPIO_ODR_OD2_Msk            (0x1UL << GPIO_ODR_OD2_Pos)
#define GPIO_ODR_OD2                GPIO_ODR_OD2_Msk

#define GPIO_ODR_OD3_Pos            (3U)
#define GPIO_ODR_OD3_Msk            (0x1UL << GPIO_ODR_OD3_Pos)
#define GPIO_ODR_OD3                GPIO_ODR_OD3_Msk

#define GPIO_ODR_OD4_Pos            (4U)
#define GPIO_ODR_OD4_Msk            (0x1UL << GPIO_ODR_OD4_Pos)
#define GPIO_ODR_OD4                GPIO_ODR_OD4_Msk

#define GPIO_ODR_OD5_Pos            (5U)
#define GPIO_ODR_OD5_Msk            (0x1UL << GPIO_ODR_OD5_Pos)
#define GPIO_ODR_OD5                GPIO_ODR_OD5_Msk

#define GPIO_ODR_OD6_Pos            (6U)
#define GPIO_ODR_OD6_Msk            (0x1UL << GPIO_ODR_OD6_Pos)
#define GPIO_ODR_OD6                GPIO_ODR_OD6_Msk

#define GPIO_ODR_OD7_Pos            (7U)
#define GPIO_ODR_OD7_Msk            (0x1UL << GPIO_ODR_OD7_Pos)
#define GPIO_ODR_OD7                GPIO_ODR_OD7_Msk

#define GPIO_ODR_OD8_Pos            (8U)
#define GPIO_ODR_OD8_Msk            (0x1UL << GPIO_ODR_OD8_Pos)
#define GPIO_ODR_OD8                GPIO_ODR_OD8_Msk

#define GPIO_ODR_OD9_Pos            (9U)
#define GPIO_ODR_OD9_Msk            (0x1UL << GPIO_ODR_OD9_Pos)
#define GPIO_ODR_OD9                GPIO_ODR_OD9_Msk

#define GPIO_ODR_OD10_Pos           (10U)
#define GPIO_ODR_OD10_Msk           (0x1UL << GPIO_ODR_OD10_Pos)
#define GPIO_ODR_OD10               GPIO_ODR_OD10_Msk

#define GPIO_ODR_OD11_Pos           (11U)
#define GPIO_ODR_OD11_Msk           (0x1UL << GPIO_ODR_OD11_Pos)
#define GPIO_ODR_OD11               GPIO_ODR_OD11_Msk

#define GPIO_ODR_OD12_Pos           (12U)
#define GPIO_ODR_OD12_Msk           (0x1UL << GPIO_ODR_OD12_Pos)
#define GPIO_ODR_OD12               GPIO_ODR_OD12_Msk

#define GPIO_ODR_OD13_Pos           (13U)
#define GPIO_ODR_OD13_Msk           (0x1UL << GPIO_ODR_OD13_Pos)
#define GPIO_ODR_OD13               GPIO_ODR_OD13_Msk

#define GPIO_ODR_OD14_Pos           (14U)
#define GPIO_ODR_OD14_Msk           (0x1UL << GPIO_ODR_OD14_Pos)
#define GPIO_ODR_OD14               GPIO_ODR_OD14_Msk

#define GPIO_ODR_OD15_Pos           (15U)
#define GPIO_ODR_OD15_Msk           (0x1UL << GPIO_ODR_OD15_Pos)
#define GPIO_ODR_OD15               GPIO_ODR_OD15_Msk

/**************** Bits definition for the GPIO_BSRR (set) register ****************/
#define GPIO_BSRR_BS0_Pos           (0U)
#define GPIO_BSRR_BS0_Msk           (0x1UL << GPIO_BSRR_BS0_Pos)
#define GPIO_BSRR_BS0               GPIO_BSRR_BS0_Msk

#define GPIO_BSRR_BS1_Pos           (1U)
#define GPIO_BSRR_BS1_Msk           (0x1UL << GPIO_BSRR_BS1_Pos)
#define GPIO_BSRR_BS1               GPIO_BSRR_BS1_Msk

#define GPIO_BSRR_BS2_Pos           (2U)
#define GPIO_BSRR_BS2_Msk           (0x1UL << GPIO_BSRR_BS2_Pos)
#define GPIO_BSRR_BS2               GPIO_BSRR_BS2_Msk

#define GPIO_BSRR_BS3_Pos           (3U)
#define GPIO_BSRR_BS3_Msk           (0x1UL << GPIO_BSRR_BS3_Pos)
#define GPIO_BSRR_BS3               GPIO_BSRR_BS3_Msk

#define GPIO_BSRR_BS4_Pos           (4U)
#define GPIO_BSRR_BS4_Msk           (0x1UL << GPIO_BSRR_BS4_Pos)
#define GPIO_BSRR_BS4               GPIO_BSRR_BS4_Msk

#define GPIO_BSRR_BS5_Pos           (5U)
#define GPIO_BSRR_BS5_Msk           (0x1UL << GPIO_BSRR_BS5_Pos)
#define GPIO_BSRR_BS5               GPIO_BSRR_BS5_Msk

#define GPIO_BSRR_BS6_Pos           (6U)
#define GPIO_BSRR_BS6_Msk           (0x1UL << GPIO_BSRR_BS6_Pos)
#define GPIO_BSRR_BS6               GPIO_BSRR_BS6_Msk

#define GPIO_BSRR_BS7_Pos           (7U)
#define GPIO_BSRR_BS7_Msk           (0x1UL << GPIO_BSRR_BS7_Pos)
#define GPIO_BSRR_BS7               GPIO_BSRR_BS7_Msk

#define GPIO_BSRR_BS8_Pos           (8U)
#define GPIO_BSRR_BS8_Msk           (0x1UL << GPIO_BSRR_BS8_Pos)
#define GPIO_BSRR_BS8               GPIO_BSRR_BS8_Msk

#define GPIO_BSRR_BS9_Pos           (9U)
#define GPIO_BSRR_BS9_Msk           (0x1UL << GPIO_BSRR_BS9_Pos)
#define GPIO_BSRR_BS9               GPIO_BSRR_BS9_Msk

#define GPIO_BSRR_BS10_Pos          (10U)
#define GPIO_BSRR_BS10_Msk          (0x1UL << GPIO_BSRR_BS10_Pos)
#define GPIO_BSRR_BS10              GPIO_BSRR_BS10_Msk

#define GPIO_BSRR_BS11_Pos          (11U)
#define GPIO_BSRR_BS11_Msk          (0x1UL << GPIO_BSRR_BS11_Pos)
#define GPIO_BSRR_BS11              GPIO_BSRR_BS11_Msk

#define GPIO_BSRR_BS12_Pos          (12U)
#define GPIO_BSRR_BS12_Msk          (0x1UL << GPIO_BSRR_BS12_Pos)
#define GPIO_BSRR_BS12              GPIO_BSRR_BS12_Msk

#define GPIO_BSRR_BS13_Pos          (13U)
#define GPIO_BSRR_BS13_Msk          (0x1UL << GPIO_BSRR_BS13_Pos)
#define GPIO_BSRR_BS13              GPIO_BSRR_BS13_Msk

#define GPIO_BSRR_BS14_Pos          (14U)
#define GPIO_BSRR_BS14_Msk          (0x1UL << GPIO_BSRR_BS14_Pos)
#define GPIO_BSRR_BS14              GPIO_BSRR_BS14_Msk

#define GPIO_BSRR_BS15_Pos          (15U)
#define GPIO_BSRR_BS15_Msk          (0x1UL << GPIO_BSRR_BS15_Pos)
#define GPIO_BSRR_BS15              GPIO_BSRR_BS15_Msk

/*************** Bits definition for the GPIO_BSRR (reset) register ***************/
#define GPIO_BSRR_BR0_Pos           (16U)
#define GPIO_BSRR_BR0_Msk           (0x1UL << GPIO_BSRR_BR0_Pos)
#define GPIO_BSRR_BR0               GPIO_BSRR_BR0_Msk

#define GPIO_BSRR_BR1_Pos           (17U)
#define GPIO_BSRR_BR1_Msk           (0x1UL << GPIO_BSRR_BR1_Pos)
#define GPIO_BSRR_BR1               GPIO_BSRR_BR1_Msk

#define GPIO_BSRR_BR2_Pos           (18U)
#define GPIO_BSRR_BR2_Msk           (0x1UL << GPIO_BSRR_BR2_Pos)
#define GPIO_BSRR_BR2               GPIO_BSRR_BR2_Msk

#define GPIO_BSRR_BR3_Pos           (19U)
#define GPIO_BSRR_BR3_Msk           (0x1UL << GPIO_BSRR_BR3_Pos)
#define GPIO_BSRR_BR3               GPIO_BSRR_BR3_Msk

#define GPIO_BSRR_BR4_Pos           (20U)
#define GPIO_BSRR_BR4_Msk           (0x1UL << GPIO_BSRR_BR4_Pos)
#define GPIO_BSRR_BR4               GPIO_BSRR_BR4_Msk

#define GPIO_BSRR_BR5_Pos           (21U)
#define GPIO_BSRR_BR5_Msk           (0x1UL << GPIO_BSRR_BR5_Pos)
#define GPIO_BSRR_BR5               GPIO_BSRR_BR5_Msk

#define GPIO_BSRR_BR6_Pos           (22U)
#define GPIO_BSRR_BR6_Msk           (0x1UL << GPIO_BSRR_BR6_Pos)
#define GPIO_BSRR_BR6               GPIO_BSRR_BR6_Msk

#define GPIO_BSRR_BR7_Pos           (23U)
#define GPIO_BSRR_BR7_Msk           (0x1UL << GPIO_BSRR_BR7_Pos)
#define GPIO_BSRR_BR7               GPIO_BSRR_BR7_Msk

#define GPIO_BSRR_BR8_Pos           (24U)
#define GPIO_BSRR_BR8_Msk           (0x1UL << GPIO_BSRR_BR8_Pos)
#define GPIO_BSRR_BR8               GPIO_BSRR_BR8_Msk

#define GPIO_BSRR_BR9_Pos           (25U)
#define GPIO_BSRR_BR9_Msk           (0x1UL << GPIO_BSRR_BR9_Pos)
#define GPIO_BSRR_BR9               GPIO_BSRR_BR9_Msk

#define GPIO_BSRR_BR10_Pos          (26U)
#define GPIO_BSRR_BR10_Msk          (0x1UL << GPIO_BSRR_BR10_Pos)
#define GPIO_BSRR_BR10              GPIO_BSRR_BR10_Msk

#define GPIO_BSRR_BR11_Pos          (27U)
#define GPIO_BSRR_BR11_Msk          (0x1UL << GPIO_BSRR_BR11_Pos)
#define GPIO_BSRR_BR11              GPIO_BSRR_BR11_Msk

#define GPIO_BSRR_BR12_Pos          (28U)
#define GPIO_BSRR_BR12_Msk          (0x1UL << GPIO_BSRR_BR12_Pos)
#define GPIO_BSRR_BR12              GPIO_BSRR_BR12_Msk

#define GPIO_BSRR_BR13_Pos          (29U)
#define GPIO_BSRR_BR13_Msk          (0x1UL << GPIO_BSRR_BR13_Pos)
#define GPIO_BSRR_BR13              GPIO_BSRR_BR13_Msk

#define GPIO_BSRR_BR14_Pos          (30U)
#define GPIO_BSRR_BR14_Msk          (0x1UL << GPIO_BSRR_BR14_Pos)
#define GPIO_BSRR_BR14              GPIO_BSRR_BR14_Msk

#define GPIO_BSRR_BR15_Pos          (31U)
#define GPIO_BSRR_BR15_Msk          (0x1UL << GPIO_BSRR_BR15_Pos)
#define GPIO_BSRR_BR15              GPIO_BSRR_BR15

/******************* Bits definition for the GPIO_LCKR register *******************/
#define GPIO_LCKR_LCK0_Pos          (0U)
#define GPIO_LCKR_LCK0_Msk          (0x1UL << GPIO_LCKR_LCK0_Pos)
#define GPIO_LCKR_LCK0              GPIO_LCKR_LCK0_Msk

#define GPIO_LCKR_LCK1_Pos          (1U)
#define GPIO_LCKR_LCK1_Msk          (0x1UL << GPIO_LCKR_LCK1_Pos)
#define GPIO_LCKR_LCK1              GPIO_LCKR_LCK1_Msk

#define GPIO_LCKR_LCK2_Pos          (2U)
#define GPIO_LCKR_LCK2_Msk          (0x1UL << GPIO_LCKR_LCK2_Pos)
#define GPIO_LCKR_LCK2              GPIO_LCKR_LCK2_Msk

#define GPIO_LCKR_LCK3_Pos          (3U)
#define GPIO_LCKR_LCK3_Msk          (0x1UL << GPIO_LCKR_LCK3_Pos)
#define GPIO_LCKR_LCK3              GPIO_LCKR_LCK3_Msk

#define GPIO_LCKR_LCK4_Pos          (4U)
#define GPIO_LCKR_LCK4_Msk          (0x1UL << GPIO_LCKR_LCK4_Pos)
#define GPIO_LCKR_LCK4              GPIO_LCKR_LCK4_Msk

#define GPIO_LCKR_LCK5_Pos          (5U)
#define GPIO_LCKR_LCK5_Msk          (0x1UL << GPIO_LCKR_LCK5_Pos)
#define GPIO_LCKR_LCK5              GPIO_LCKR_LCK5_Msk

#define GPIO_LCKR_LCK6_Pos          (6U)
#define GPIO_LCKR_LCK6_Msk          (0x1UL << GPIO_LCKR_LCK6_Pos)
#define GPIO_LCKR_LCK6              GPIO_LCKR_LCK6_Msk

#define GPIO_LCKR_LCK7_Pos          (7U)
#define GPIO_LCKR_LCK7_Msk          (0x1UL << GPIO_LCKR_LCK7_Pos)
#define GPIO_LCKR_LCK7              GPIO_LCKR_LCK7_Msk

#define GPIO_LCKR_LCK8_Pos          (8U)
#define GPIO_LCKR_LCK8_Msk          (0x1UL << GPIO_LCKR_LCK8_Pos)
#define GPIO_LCKR_LCK8              GPIO_LCKR_LCK8_Msk

#define GPIO_LCKR_LCK9_Pos          (9U)
#define GPIO_LCKR_LCK9_Msk          (0x1UL << GPIO_LCKR_LCK9_Pos)
#define GPIO_LCKR_LCK9              GPIO_LCKR_LCK9_Msk

#define GPIO_LCKR_LCK10_Pos         (10U)
#define GPIO_LCKR_LCK10_Msk         (0x1UL << GPIO_LCKR_LCK10_Pos)
#define GPIO_LCKR_LCK10             GPIO_LCKR_LCK10_Msk

#define GPIO_LCKR_LCK11_Pos         (11U)
#define GPIO_LCKR_LCK11_Msk         (0x1UL << GPIO_LCKR_LCK11_Pos)
#define GPIO_LCKR_LCK11             GPIO_LCKR_LCK11_Msk

#define GPIO_LCKR_LCK12_Pos         (12U)
#define GPIO_LCKR_LCK12_Msk         (0x1UL << GPIO_LCKR_LCK12_Pos)
#define GPIO_LCKR_LCK12             GPIO_LCKR_LCK12_Msk

#define GPIO_LCKR_LCK13_Pos         (13U)
#define GPIO_LCKR_LCK13_Msk         (0x1UL << GPIO_LCKR_LCK13_Pos)
#define GPIO_LCKR_LCK13             GPIO_LCKR_LCK13_Msk

#define GPIO_LCKR_LCK14_Pos         (14U)
#define GPIO_LCKR_LCK14_Msk         (0x1UL << GPIO_LCKR_LCK14_Pos)
#define GPIO_LCKR_LCK14             GPIO_LCKR_LCK14_Msk

#define GPIO_LCKR_LCK15_Pos         (15U)
#define GPIO_LCKR_LCK15_Msk         (0x1UL << GPIO_LCKR_LCK15_Pos)
#define GPIO_LCKR_LCK15             GPIO_LCKR_LCK15_Msk

#define GPIO_LCKR_LCKK_Pos          (16U)
#define GPIO_LCKR_LCKK_Msk          (0x1UL << GPIO_LCKR_LCKK_Pos)
#define GPIO_LCKR_LCKK              GPIO_LCKR_LCKK_Msk

/******************* Bits definition for the GPIO_AFRL register *******************/
#define GPIO_AFRL_AFSEL0_Pos        (0U)
#define GPIO_AFRL_AFSEL0_Msk        (0xFUL << GPIO_AFRL_AFSEL0_Pos)
#define GPIO_AFRL_AFSEL0            GPIO_AFRL_AFSEL0_Msk
#define GPIO_AFRL_AFSEL0_0          (0x1UL << GPIO_AFRL_AFSEL0_Pos)
#define GPIO_AFRL_AFSEL0_1          (0x2UL << GPIO_AFRL_AFSEL0_Pos)
#define GPIO_AFRL_AFSEL0_2          (0x4UL << GPIO_AFRL_AFSEL0_Pos)
#define GPIO_AFRL_AFSEL0_3          (0x8UL << GPIO_AFRL_AFSEL0_Pos)

#define GPIO_AFRL_AFSEL1_Pos        (4U)
#define GPIO_AFRL_AFSEL1_Msk        (0xFUL << GPIO_AFRL_AFSEL1_Pos)
#define GPIO_AFRL_AFSEL1            GPIO_AFRL_AFSEL1_Msk
#define GPIO_AFRL_AFSEL1_0          (0x1UL << GPIO_AFRL_AFSEL1_Pos)
#define GPIO_AFRL_AFSEL1_1          (0x2UL << GPIO_AFRL_AFSEL1_Pos)
#define GPIO_AFRL_AFSEL1_2          (0x4UL << GPIO_AFRL_AFSEL1_Pos)
#define GPIO_AFRL_AFSEL1_3          (0x8UL << GPIO_AFRL_AFSEL1_Pos)

#define GPIO_AFRL_AFSEL2_Pos        (8U)
#define GPIO_AFRL_AFSEL2_Msk        (0xFUL << GPIO_AFRL_AFSEL2_Pos)
#define GPIO_AFRL_AFSEL2            GPIO_AFRL_AFSEL2_Msk
#define GPIO_AFRL_AFSEL2_0          (0x1UL << GPIO_AFRL_AFSEL2_Pos)
#define GPIO_AFRL_AFSEL2_1          (0x2UL << GPIO_AFRL_AFSEL2_Pos)
#define GPIO_AFRL_AFSEL2_2          (0x4UL << GPIO_AFRL_AFSEL2_Pos)
#define GPIO_AFRL_AFSEL2_3          (0x8UL << GPIO_AFRL_AFSEL2_Pos)

#define GPIO_AFRL_AFSEL3_Pos        (12U)
#define GPIO_AFRL_AFSEL3_Msk        (0xFUL << GPIO_AFRL_AFSEL3_Pos)
#define GPIO_AFRL_AFSEL3            GPIO_AFRL_AFSEL3_Msk
#define GPIO_AFRL_AFSEL3_0          (0x1UL << GPIO_AFRL_AFSEL3_Pos)
#define GPIO_AFRL_AFSEL3_1          (0x2UL << GPIO_AFRL_AFSEL3_Pos)
#define GPIO_AFRL_AFSEL3_2          (0x4UL << GPIO_AFRL_AFSEL3_Pos)
#define GPIO_AFRL_AFSEL3_3          (0x8UL << GPIO_AFRL_AFSEL3_Pos)

#define GPIO_AFRL_AFSEL4_Pos        (16U)
#define GPIO_AFRL_AFSEL4_Msk        (0xFUL << GPIO_AFRL_AFSEL4_Pos)
#define GPIO_AFRL_AFSEL4            GPIO_AFRL_AFSEL4_Msk
#define GPIO_AFRL_AFSEL4_0          (0x1UL << GPIO_AFRL_AFSEL4_Pos)
#define GPIO_AFRL_AFSEL4_1          (0x2UL << GPIO_AFRL_AFSEL4_Pos)
#define GPIO_AFRL_AFSEL4_2          (0x4UL << GPIO_AFRL_AFSEL4_Pos)
#define GPIO_AFRL_AFSEL4_3          (0x8UL << GPIO_AFRL_AFSEL4_Pos)

#define GPIO_AFRL_AFSEL5_Pos        (20U)
#define GPIO_AFRL_AFSEL5_Msk        (0xFUL << GPIO_AFRL_AFSEL5_Pos)
#define GPIO_AFRL_AFSEL5            GPIO_AFRL_AFSEL5_Msk
#define GPIO_AFRL_AFSEL5_0          (0x1UL << GPIO_AFRL_AFSEL5_Pos)
#define GPIO_AFRL_AFSEL5_1          (0x2UL << GPIO_AFRL_AFSEL5_Pos)
#define GPIO_AFRL_AFSEL5_2          (0x4UL << GPIO_AFRL_AFSEL5_Pos)
#define GPIO_AFRL_AFSEL5_3          (0x8UL << GPIO_AFRL_AFSEL5_Pos)

#define GPIO_AFRL_AFSEL6_Pos        (24U)
#define GPIO_AFRL_AFSEL6_Msk        (0xFUL << GPIO_AFRL_AFSEL6_Pos)
#define GPIO_AFRL_AFSEL6            GPIO_AFRL_AFSEL6_Msk
#define GPIO_AFRL_AFSEL6_0          (0x1UL << GPIO_AFRL_AFSEL6_Pos)
#define GPIO_AFRL_AFSEL6_1          (0x2UL << GPIO_AFRL_AFSEL6_Pos)
#define GPIO_AFRL_AFSEL6_2          (0x4UL << GPIO_AFRL_AFSEL6_Pos)
#define GPIO_AFRL_AFSEL6_3          (0x8UL << GPIO_AFRL_AFSEL6_Pos)

#define GPIO_AFRL_AFSEL7_Pos        (28U)
#define GPIO_AFRL_AFSEL7_Msk        (0xFUL << GPIO_AFRL_AFSEL7_Pos)
#define GPIO_AFRL_AFSEL7            GPIO_AFRL_AFSEL7_Msk
#define GPIO_AFRL_AFSEL7_0          (0x1UL << GPIO_AFRL_AFSEL7_Pos)
#define GPIO_AFRL_AFSEL7_1          (0x2UL << GPIO_AFRL_AFSEL7_Pos)
#define GPIO_AFRL_AFSEL7_2          (0x4UL << GPIO_AFRL_AFSEL7_Pos)
#define GPIO_AFRL_AFSEL7_3          (0x8UL << GPIO_AFRL_AFSEL7_Pos)

/******************* Bits definition for the GPIO_AFRH register *******************/
#define GPIO_AFRH_AFSEL8_Pos        (0U)
#define GPIO_AFRH_AFSEL8_Msk        (0xFUL << GPIO_AFRH_AFSEL8_Pos)
#define GPIO_AFRH_AFSEL8            GPIO_AFRH_AFSEL8_Msk
#define GPIO_AFRH_AFSEL8_0          (0x1UL << GPIO_AFRH_AFSEL8_Pos)
#define GPIO_AFRH_AFSEL8_1          (0x2UL << GPIO_AFRH_AFSEL8_Pos)
#define GPIO_AFRH_AFSEL8_2          (0x4UL << GPIO_AFRH_AFSEL8_Pos)
#define GPIO_AFRH_AFSEL8_3          (0x8UL << GPIO_AFRH_AFSEL8_Pos)

#define GPIO_AFRH_AFSEL9_Pos        (4U)
#define GPIO_AFRH_AFSEL9_Msk        (0xFUL << GPIO_AFRH_AFSEL9_Pos)
#define GPIO_AFRH_AFSEL9            GPIO_AFRH_AFSEL9_Msk
#define GPIO_AFRH_AFSEL9_0          (0x1UL << GPIO_AFRH_AFSEL9_Pos)
#define GPIO_AFRH_AFSEL9_1          (0x2UL << GPIO_AFRH_AFSEL9_Pos)
#define GPIO_AFRH_AFSEL9_2          (0x4UL << GPIO_AFRH_AFSEL9_Pos)
#define GPIO_AFRH_AFSEL9_3          (0x8UL << GPIO_AFRH_AFSLE9_Pos)

#define GPIO_AFRH_AFSEL10_Pos       (8U)
#define GPIO_AFRH_AFSEL10_Msk       (0xFUL << GPIO_AFRH_AFSEL10_Pos)
#define GPIO_AFRH_AFSEL10           GPIO_AFRH_AFSEL10_Msk
#define GPIO_AFRH_AFSEL10_0         (0x1UL << GPIO_AFRH_AFSEL10_Pos)
#define GPIO_AFRH_AFSEL10_1         (0x2UL << GPIO_AFRH_AFSEL10_Pos)
#define GPIO_AFRH_AFSEL10_2         (0x4UL << GPIO_AFRH_AFSEL10_Pos)
#define GPIO_AFRH_AFSEL10_3         (0x8UL << GPIO_AFRH_AFSEL10_Pos)

#define GPIO_AFRH_AFSEL11_Pos       (12U)
#define GPIO_AFRH_AFSEL11_Msk       (0xFUL << GPIO_AFRH_AFSEL11_Pos)
#define GPIO_AFRH_AFSEL11           GPIO_AFRH_AFSEL11_Msk
#define GPIO_AFRH_AFSEL11_0         (0x1UL << GPIO_AFRH_AFSEL11_Pos)
#define GPIO_AFRH_AFSEL11_1         (0x2UL << GPIO_AFRH_AFSEL11_Pos)
#define GPIO_AFRH_AFSEL11_2         (0x4UL << GPIO_AFRH_AFSEL11_Pos)
#define GPIO_AFRH_AFSEL11_3         (0x8UL << GPIO_AFRH_AFSEL11_Pos)

#define GPIO_AFRH_AFSEL12_Pos       (16U)
#define GPIO_AFRH_AFSEL12_Msk       (0xFUL << GPIO_AFRH_AFSEL12_Pos)
#define GPIO_AFRH_AFSEL12           GPIO_AFRH_AFSEL12_Msk
#define GPIO_AFRH_AFSEL12_0         (0x1UL << GPIO_AFRH_AFSEL12_Pos)
#define GPIO_AFRH_AFSEL12_1         (0x2UL << GPIO_AFRH_AFSEL12_Pos)
#define GPIO_AFRH_AFSEL12_2         (0x4UL << GPIO_AFRH_AFSEL12_Pos)
#define GPIO_AFRH_AFSEL12_3         (0x8UL << GPIO_AFRH_AFSEL12_Pos)

#define GPIO_AFRH_AFSEL13_Pos       (20U)
#define GPIO_AFRH_AFSEL13_Msk       (0xFUL << GPIO_AFRH_AFSEL13_Pos)
#define GPIO_AFRH_AFSEL13           GPIO_AFRH_AFSEL13_Msk
#define GPIO_AFRH_AFSEL13_0         (0x1UL << GPIO_AFRH_AFSEL13_Pos)
#define GPIO_AFRH_AFSEL13_1         (0x2UL << GPIO_AFRH_AFSEL13_Pos)
#define GPIO_AFRH_AFSEL13_2         (0x4UL << GPIO_AFRH_AFSEL13_Pos)
#define GPIO_AFRH_AFSEL13_3         (0x8UL << GPIO_AFRH_AFSEL13_Pos)

#define GPIO_AFRH_AFSEL14_Pos       (24U)
#define GPIO_AFRH_AFSEL14_Msk       (0xFUL << GPIO_AFRH_AFSEL14_Pos)
#define GPIO_AFRH_AFSEL14           GPIO_AFRH_AFSEL14_Msk
#define GPIO_AFRH_AFSEL14_0         (0x1UL << GPIO_AFRH_AFSEL14_Pos)
#define GPIO_AFRH_AFSEL14_1         (0x2UL << GPIO_AFRH_AFSEL14_Pos)
#define GPIO_AFRH_AFSEL14_2         (0x4UL << GPIO_AFRH_AFSEL14_Pos)
#define GPIO_AFRH_AFSEL14_3         (0x8UL << GPIO_AFRH_AFSEL14_Pos)

#define GPIO_AFRH_AFSEL15_Pos       (28U)
#define GPIO_AFRH_AFSEL15_Msk       (0xFUL << GPIO_AFRH_AFSEL15_Pos)
#define GPIO_AFRH_AFSEL15           GPIO_AFRH_AFSEL15_Msk
#define GPIO_AFRH_AFSEL15_0         (0x1UL << GPIO_AFRH_AFSEL15_Pos)
#define GPIO_AFRH_AFSEL15_1         (0x2UL << GPIO_AFRH_AFSEL15_Pos)
#define GPIO_AFRH_AFSEL15_2         (0x4UL << GPIO_AFRH_AFSEL15_Pos)
#define GPIO_AFRH_AFSEL15_3         (0x8UL << GPIO_AFRH_AFSEL15_Pos)


/**********************************************************************************/
/*                                                                                */
/*                              Reset and Clock Control                           */
/*                                                                                */
/**********************************************************************************/

/*********************** Bits definition for RCC_CR register **********************/
#define RCC_CR_HSION_Pos            (0U)
#define RCC_CR_HSION_Msk            (0x1UL << RCC_CR_HSION_Pos)
#define RCC_CR_HSION                RCC_CR_HSION_Msk
#define RCC_CR_HSIRDY_Pos           (1U)
#define RCC_CR_HSIRDY_Msk           (0x1UL << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIRDY               RCC_CR_HSIRDY_Msk

#define RCC_CR_HSITRIM_Pos          (3U)
#define RCC_CR_HSITRIM_Msk          (0x1FUL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM              RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0            (0x01UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_1            (0x02UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_2            (0x04UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_3            (0x08UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_4            (0x10UL << RCC_CR_HSITRIM_Pos)

#define RCC_CR_HSICAL_Pos           (8U)
#define RCC_CR_HSICAL_Msk           (0xFFUL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL               RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0             (0x01UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_1             (0x02UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_2             (0x04UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_3             (0x08UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_4             (0x10UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_5             (0x20UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_6             (0x40UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_7             (0x80UL << RCC_CR_HSICAL_Pos)

#define RCC_CR_HSEON_Pos            (16U)
#define RCC_CR_HSEON_Msk            (0x1UL << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON                RCC_CR_HSEON_Msk
#define RCC_CR_HSERDY_Pos           (17U)
#define RCC_CR_HSERDY_Msk           (0x1UL << RCC_CR_HSERDY_Pos)
#define RCC_CR_HSERDY               RCC_CR_HSERDY_Msk
#define RCC_CR_HSEBYP_Pos           (18U)
#define RCC_CR_HSEBYP_Msk           (0x1UL << RCC_CR_HSEBYP_Pos)
#define RCC_CR_HSEBYP               RCC_CR_HSEBYP_Msk
#define RCC_CR_CSSON_Pos            (19U)
#define RCC_CR_CSSON_Msk            (0x1UL << RCC_CR_CSSON_Pos)
#define RCC_CR_CSSON                RCC_CR_CSSON_Msk
#define RCC_CR_PLLON_Pos            (24U)
#define RCC_CR_PLLON_Msk            (0x1UL << RCC_CR_PLLON_Pos)
#define RCC_CR_PLLON                RCC_CR_PLLON_Msk
#define RCC_CR_PLLRDY_Pos           (25U)
#define RCC_CR_PLLRDY_Msk           (0x1UL << RCC_CR_PLLRDY_Pos)
#define RCC_CR_PLLRDY               RCC_CR_PLLRDY_Msk
#define RCC_CR_PLLI2SON_Pos         (26U)
#define RCC_CR_PLLI2SON_Msk         (0x1UL << RCC_CR_PLLI2SON_Pos)
#define RCC_CR_PLLI2SON             RCC_CR_PLLI2SON_Msk
#define RCC_CR_PLLI2SRDY_Pos        (27U)
#define RCC_CR_PLLI2SRDY_Msk        (0x1UL << RCC_CR_PLLI2SRDY_Pos)
#define RCC_CR_PLLI2SRDY            RCC_CR_PLLI2SRDY_Msk

/******************** Bits definition for RCC_PLLCFGR register ********************/
#define RCC_PLLCFGR_PLLM_Pos        (0U)
#define RCC_PLLCFGR_PLLM_Msk        (0x3FUL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM            RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0          (0x01UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_1          (0x02UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_2          (0x04UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_3          (0x08UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_4          (0x10UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_5          (0x20UL << RCC_PLLCFGR_PLLM_Pos)

#define RCC_PLLCFGR_PLLN_Pos        (6U)
#define RCC_PLLCFGR_PLLN_Msk        (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN            RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0          (0x001UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_1          (0x002UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_2          (0x004UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_3          (0x008UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_4          (0x010UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_5          (0x020UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_6          (0x040UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_7          (0x080UL << RCC_PLLCFGR_PLLN_Pos)
#define RCC_PLLCFGR_PLLN_8          (0x100UL << RCC_PLLCFGR_PLLN_Pos)

#define RCC_PLLCFGR_PLLP_Pos        (16U)
#define RCC_PLLCFGR_PLLP_Msk        (0x3UL << RCC_PLLCFGR_PLLP_Pos)
#define RCC_PLLCFGR_PLLP            RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLP_0          (0x1UL << RCC_PLLCFGR_PLLP_Pos)
#define RCC_PLLCFGR_PLLP_1          (0x2UL << RCC_PLLCFGR_PLLP_Pos)

#define RCC_PLLCFGR_PLLSRC_Pos      (22U)
#define RCC_PLLCFGR_PLLSRC_Msk      (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)
#define RCC_PLLCFGR_PLLSRC          RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSE_Pos  (22U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk  (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos)
#define RCC_PLLCFGR_PLLSRC_HSE      RCC_PLLCFGR_PLLSRC_HSE_Msk
#define RCC_PLLCFGR_PLLSRC_HSI      (0x0UL << RCC_PLLCFGR_PLLSRC_Pos)

#define RCC_PLLCFGR_PLLQ_Pos        (24U)
#define RCC_PLLCFGR_PLLQ_Msk        (0xFFUL << RCC_PLLCFGR_PLLQ_Pos)
#define RCC_PLLCFGR_PLLQ            RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0          (0x01UL << RCC_PLLCFGR_PLLQ_Pos)
#define RCC_PLLCFGR_PLLQ_1          (0x02UL << RCC_PLLCFGR_PLLQ_Pos)
#define RCC_PLLCFGR_PLLQ_2          (0x04UL << RCC_PLLCFGR_PLLQ_Pos)
#define RCC_PLLCFGR_PLLQ_3          (0x08UL << RCC_PLLCFGR_PLLQ_Pos)

/********************** Bits definition for RCC_CFGR register *********************/
#define RCC_CFGR_SW_Pos             (0U)
#define RCC_CFGR_SW_Msk             (0x3UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW                 RCC_CFGR_SW_Msk
#define RCC_CFGR_SW_0               (0x1UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_1               (0x2UL << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SW_HSI             0x00000001UL
#define RCC_CFGR_SW_HSE             0x00000002UL
#define RCC_CFGR_SW_PLL             0x00000004UL

#define RCC_CFGR_SWS_Pos            (2U)
#define RCC_CFGR_SWS_Msk            (0x3UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS                RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_0              (0x1UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_1              (0x2UL << RCC_CFGR_SWS_Pos)

#define RCC_CFGR_SWS_HSI            0x00000000UL
#define RCC_CFGR_SWS_HSE            0x00000004UL
#define RCC_CFGR_SWS_PLL            0x00000008UL

#define RCC_CFGR_HPRE_Pos           (4U)
#define RCC_CFGR_HPRE_Msk           (0xFUL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE               RCC_CFGR_HPRE_Msk
#define RCC_CFGR_HPRE_0             (0x1UL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_1             (0x2UL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_2             (0x4UL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_3             (0x8UL << RCC_CFGR_HPRE_Pos)

#define RCC_CFGR_HPRE_DIV1          0x00000000UL
#define RCC_CFGR_HPRE_DIV2          0x00000080UL
#define RCC_CFGR_HPRE_DIV4          0x00000090UL
#define RCC_CFGR_HPRE_DIV8          0x000000A0UL
#define RCC_CFGR_HPRE_DIV16         0x000000B0UL
#define RCC_CFGR_HPRE_DIV64         0x000000C0UL
#define RCC_CFGR_HPRE_DIV128        0x000000D0UL
#define RCC_CFGR_HPRE_DIV256        0x000000E0UL
#define RCC_CFGR_HPRE_DIV512        0x000000F0UL

#define RCC_CFGR_PPRE1_Pos          (10U)
#define RCC_CFGR_PPRE1_Msk          (0x7UL << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1              RCC_CFGR_PPRE1_Msk
#define RCC_CFGR_PPRE1_0            (0x1UL << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_1            (0x2UL << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_2            (0x4UL << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_PPRE1_DIV1         0x00000000UL
#define RCC_CFGR_PPRE1_DIV2         0x00001000UL
#define RCC_CFGR_PPRE1_DIV4         0x00001400UL
#define RCC_CFGR_PPRE1_DIV8         0x00001800UL
#define RCC_CFGR_PPRE1_DIV16        0x00001C00UL

#define RCC_CFGR_PPRE2_Pos          (13U)
#define RCC_CFGR_PPRE2_Msk          (0x7UL << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2              RCC_CFGR_PPRE2_Msk
#define RCC_CFGR_PPRE2_0            (0x1UL << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_1            (0x2UL << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_2            (0x4UL << RCC_CFGR_PPRE2_Pos)

#define RCC_CFGR_PPRE2_DIV1         0x0000000UL
#define RCC_CFGR_PPRE2_DIV2         0x0000800UL
#define RCC_CFGR_PPRE2_DIV4         0x0000A00UL
#define RCC_CFGR_PPRE2_DIV8         0x0000C00UL
#define RCC_CFGR_PPRE2_DIV16        0x0000E00UL

#define RCC_CFGR_RTCPRE_Pos         (16U)
#define RCC_CFGR_RTCPRE_Msk         (0x7UL << RCC_CFGR_RTCPRE_Pos)
#define RCC_CFGR_RTCPRE             RCC_CFGR_RTCPRE_Msk
#define RCC_CFGR_RTCPRE_0           (0x01UL << RCC_CFGR_RTCPRE_Pos)
#define RCC_CFGR_RTCPRE_1           (0x02UL << RCC_CFGR_RTCPRE_Pos)
#define RCC_CFGR_RTCPRE_2           (0x04UL << RCC_CFGR_RTCPRE_Pos)
#define RCC_CFGR_RTCPRE_3           (0x08UL << RCC_CFGR_RTCPRE_Pos)
#define RCC_CFGR_RTCPRE_4           (0x10UL << RCC_CFGR_RTCPRE_Pos)

#define RCC_CFGR_MCO1_Pos           (21U)
#define RCC_CFGR_MCO1_Msk           (0x3UL << RCC_CFGR_MCO1_Pos)
#define RCC_CFGR_MCO1               RCC_CFGR_MCO1_Msk
#define RCC_CFGR_MCO1_0             (0x1UL << RCC_CFGR_MCO1_Pos)
#define RCC_CFGR_MCO1_1             (0x2UL << RCC_CFGR_MCO1_Pos)

#define RCC_CFGR_I2SSRC_Pos         (23U)
#define RCC_CFGR_I2SSRC_Msk         (0x1UL << RCC_CFGR_I2SSRC_Pos)
#define RCC_CFGR_I2SSRC             RCC_CFGR_I2SSRC_Msk

#define RCC_CFGR_MCO1PRE_Pos        (24U)
#define RCC_CFGR_MCO1PRE_Msk        (0x7UL << RCC_CFGR_MCO1PRE_Pos)
#define RCC_CFGR_MCO1PRE            RCC_CFGR_MCO1PRE_Msk
#define RCC_CFGR_MCO1PRE_0          (0x1UL << RCC_CFGR_MCO1PRE_Pos)
#define RCC_CFGR_MCO1PRE_1          (0x2UL << RCC_CFGR_MCO1PRE_Pos)
#define RCC_CFGR_MCO1PRE_2          (0x4UL << RCC_CFGR_MCO1PRE_Pos)

#define RCC_CFGR_MCO2PRE_Pos        (27U)
#define RCC_CFGR_MCO2PRE_Msk        (0x7UL << RCC_CFGR_MCO2PRE_Pos)
#define RCC_CFGR_MCO2PRE            RCC_CFGR_MCO2PRE_Msk
#define RCC_CFGR_MCO2PRE_0          (0x1UL << RCC_CFGR_MCO2PRE_Pos)
#define RCC_CFGR_MCO2PRE_1          (0x2UL << RCC_CFGR_MCO2PRE_Pos)
#define RCC_CFGR_MCO2PRE_2          (0x4UL << RCC_CFGR_MCO2PRE_Pos)

#define RCC_CFGR_MCO2_Pos           (30U)
#define RCC_CFGR_MCO2_Msk           (0x2UL << RCC_CFGR_MCO2_Pos)
#define RCC_CFGR_MCO2               RCC_CFGR_MCO2_Msk
#define RCC_CFGR_MCO2_0             (0x1UL << RCC_CFGR_MCO2_Pos)
#define RCC_CFGR_MCO2_1             (0x2UL << RCC_CFGR_MCO2_Pos)

/********************** Bits definition for RCC_CIR register **********************/
#define RCC_CIR_LSIRDYF_Pos         (0U)
#define RCC_CIR_LSIRDYF_Msk         (0x1UL << RCC_CIR_LSIRDYF_Pos)
#define RCC_CIR_LSIRDY              RCC_CIR_LSIRDYF_Msk
#define RCC_CIR_LSERDYF_Pos         (1U)
#define RCC_CIR_LSERDYF_Msk         (0x1UL << RCC_CIR_LSERDYF_Pos)
#define RCC_CIR_LSERDYF             RCC_CIR_LSERDYF_Msk
#define RCC_CIR_HSIRDYF_Pos         (2U)
#define RCC_CIR_HSIRDYF_Msk         (0x1UL << RCC_CIR_HSIRDYF_Pos)
#define RCC_CIR_HSIRDYF             RCC_CIR_HSIRDYF_Msk
#define RCC_CIR_HSERDYF_Pos         (3U)
#define RCC_CIR_HSERDYF_Msk         (0x1UL << RCC_CIR_HSERDYF_Pos)
#define RCC_CIR_HSERDYF             RCC_CIR_HSERDYF_Msk
#define RCC_CIR_PLLRDYF_Pos         (4U)
#define RCC_CIR_PLLRDYF_Msk         (0x1UL << RCC_CIR_PLLRDYF_Pos)
#define RCC_CIR_PLLRDYF             RCC_CIR_PLLRDYF_Msk
#define RCC_CIR_PLLI2SRDYF_Pos      (5U)
#define RCC_CIR_PLLI2SRDYF_Msk      (0x1UL << RCC_CIR_PLLI2SRDYF_Pos)
#define RCC_CIR_PLLI2SRDYF          RCC_CIR_PLLI2SRDYF_Msk

#define RCC_CIR_CSSF_Pos            (7U)
#define RCC_CIR_CSSF_Msk            (0x1UL << RCC_CIR_CSSF_Pos)
#define RCC_CIR_CSSF                RCC_CIR_CSSF_Msk
#define RCC_CIR_LSIRDYIE_Pos        (8U)
#define RCC_CIR_LSIRDYIE_Msk        (0x1UL << RCC_CIR_LSIRDYIE_Pos)
#define RCC_CIR_LSIRDYIE            RCC_CIR_LSIRDYIE_Msk
#define RCC_CIR_LSERDYIE_Pos        (9U)
#define RCC_CIR_LSERDYIE_Msk        (0x1UL << RCC_CIR_LSERDYIE_Pos)
#define RCC_CIR_LSERDYIE            RCC_CIR_LSERDYIE_Msk
#define RCC_CIR_HSIRDYIE_Pos        (10U)
#define RCC_CIR_HSIRDYIE_Msk        (0x1UL << RCC_CIR_HSIRDYIE_Pos)
#define RCC_CIR_HSIRDYIE            RCC_CIR_HSIRDYIE_Msk
#define RCC_CIR_HSERDYIE_Pos        (11U)
#define RCC_CIR_HSERDYIE_Msk        (0x1UL << RCC_CIR_HSERDYIE_Pos)
#define RCC_CIR_HSERDYIE            RCC_CIR_HSERDYIE_Msk
#define RCC_CIR_PLLRDYIE_Pos        (12U)
#define RCC_CIR_PLLRDYIE_Msk        (0x1UL << RCC_CIR_PLLRDYIE_Pos)
#define RCC_CIR_PLLRDYIE            RCC_CIR_PLLRDYIE_Msk
#define RCC_CIR_PLLI2SRDYIE_Pos     (13U)
#define RCC_CIR_PLLI2SRDYIE_Msk     (0x1UL << RCC_CIR_PLLI2SRDYIE_Pos)
#define RCC_CIR_PLLI2SRDYIE         RCC_CIR_PLLI2SRDYIE_Msk

#define RCC_CIR_LSIRDYC_Pos         (16U)
#define RCC_CIR_LSIRDYC_Msk         (0x1UL << RCC_CIR_LSIRDYC_Pos)
#define RCC_CIR_LSIRDYC             RCC_CIR_LSIRDYC_Msk
#define RCC_CIR_LSERDYC_Pos         (17U)
#define RCC_CIR_LSERDYC_Msk         (0x1UL << RCC_CIR_LSERDYC_Pos)
#define RCC_CIR_LSERDYC             RCC_CIR_LSERDYC_Msk
#define RCC_CIR_HSIRDYC_Pos         (18U)
#define RCC_CIR_HSIRDYC_Msk         (0x1UL << RCC_CIR_HSIRDYC_Pos)
#define RCC_CIR_HSIRDYC             RCC_CIR_HSIRDYC_Msk
#define RCC_CIR_HSERDYC_Pos         (19U)
#define RCC_CIR_HSERDYC_Msk         (0x1UL << RCC_CIR_HSERDYC_Pos)
#define RCC_CIR_HSERDYC             RCC_CIR_HSERDYC_Msk
#define RCC_CIR_PLLRDYC_Pos         (20U)
#define RCC_CIR_PLLRDYC_Msk         (0x1UL << RCC_CIR_PLLRDYC_Pos)
#define RCC_CIR_PLLRDYC             RCC_CIR_PLLRDYC_Msk
#define RCC_CIR_PLLI2SRDYC_Pos      (21U)
#define RCC_CIR_PLLI2SRDYC_Msk      (0x1UL << RCC_CIR_PLLI2SRDYC_Pos)
#define RCC_CIR_PLLI2SRDYC          RCC_CIR_PLLI2SRDYC_Msk
#define RCC_CIR_CSSC_Pos            (22U)
#define RCC_CIR_CSSC_Msk            (0x1UL << RCC_CIR_CSSC_Pos)
#define RCC_CIR_CSSC                RCC_CIR_CSSC_Msk

/******************** Bits definition for RCC_AHB1RSTR register *******************/
#define RCC_AHB1RSTR_GPIOARST_Pos   (0U)
#define RCC_AHB1RSTR_GPIOARST_Msk   (0x1UL << RCC_AHB1RSTR_GPIOARST_Pos)
#define RCC_AHB1RSTR_GPIOARST       RCC_AHB1RSTR_GPIOARST_Msk

#define RCC_AHB1RSTR_GPIOBRST_Pos   (1U)
#define RCC_AHB1RSTR_GPIOBRST_Msk   (0x1UL << RCC_AHB1RSTR_GPIOBRST_Pos)
#define RCC_AHB1RSTR_GPIOBRST       RCC_AHB1RSTR_GPIOBRST_Msk

#define RCC_AHB1RSTR_GPIOCRST_Pos   (2U)
#define RCC_AHB1RSTR_GPIOCRST_Msk   (0x1UL << RCC_AHB1RSTR_GPIOCRST_Pos)
#define RCC_AHB1RSTR_GPIOCRST       RCC_AHB1RSTR_GPIOCRST_Msk

#define RCC_AHB1RSTR_GPIODRST_Pos   (3U)
#define RCC_AHB1RSTR_GPIODRST_Msk   (0x1UL << RCC_AHB1RSTR_GPIODRST_Pos)
#define RCC_AHB1RSTR_GPIODRST       RCC_AHB1RSTR_GPIODRST_Msk

#define RCC_AHB1RSTR_GPIOERST_Pos   (4U)
#define RCC_AHB1RSTR_GPIOERST_Msk   (0x1UL << RCC_AHB1RSTR_GPIOERST_Pos)
#define RCC_AHB1RSTR_GPIOERST       RCC_AHB1RSTR_GPIOERST_Msk

#define RCC_AHB1RSTR_GPIOHRST_Pos   (7U)
#define RCC_AHB1RSTR_GPIOHRST_Msk   (0x1UL << RCC_AHB1RSTR_GPIOHRST_Pos)
#define RCC_AHB1RSTR_GPIOHRST       RCC_AHB1RSTR_GPIOHRST_Msk

#define RCC_AHB1RSTR_CRCRST_Pos     (12U)
#define RCC_AHB1RSTR_CRCRST_Msk     (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)
#define RCC_AHB1RSTR_CRCRST         RCC_AHB1RSTR_CRCRST_Msk

#define RCC_AHB1RSTR_DMA1RST_Pos    (21U)
#define RCC_AHB1RSTR_DMA1RST_Msk    (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos)
#define RCC_AHB1RSTR_DMA1RST        RCC_AHB1RSTR_DMA1RST_Msk

#define RCC_AHB1RSTR_DMA2RST_Pos    (22U)
#define RCC_AHB1RSTR_DMA2RST_Msk    (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos)
#define RCC_AHB1RSTR_DMA2RST        RCC_AHB1RSTR_DMA2RST_Msk

/******************** Bits definition for RCC_AHB2RSTR register *******************/
#define RCC_AHB2RSTR_OTGFSRST_Pos   (7U)
#define RCC_AHB2RSTR_OTGFSRST_Msk   (0x1UL << RCC_AHB2RSTR_OTGFSRST_Pos)
#define RCC_AHB2RSTR_OTGFSRST       RCC_AHB2RSTR_OTGFSRST_Msk

/******************** Bits definition for RCC_APB1RSTR register *******************/
#define RCC_APB1RSTR_TIM2RST_Pos    (0U)
#define RCC_APB1RSTR_TIM2RST_Msk    (0x1UL << RCC_APB1RSTR_TIM2RST_Pos)
#define RCC_APB1RSTR_TIM2RST        RCC_APB1RSTR_TIM2RST_Msk

#define RCC_APB1RSTR_TIM3RST_Pos    (1U)
#define RCC_APB1RSTR_TIM3RST_Msk    (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)
#define RCC_APB1RSTR_TIM3RST        RCC_APB1RSTR_TIM3RST_Msk

#define RCC_APB1RSTR_TIM4RST_Pos    (2U)
#define RCC_APB1RSTR_TIM4RST_Msk    (0x1UL << RCC_APB1RSTR_TIM4RST_Pos)
#define RCC_APB1RSTR_TIM4RST        RCC_APB1RSTR_TIM4RST_Msk

#define RCC_APB1RSTR_TIM5RST_Pos    (3U)
#define RCC_APB1RSTR_TIM5RST_Msk    (0x1UL << RCC_APB1RSTR_TIM5RST_Pos)
#define RCC_APB1RSTR_TIM5RST        RCC_APB1RSTR_TIM5RST_Msk

#define RCC_APB1RSTR_WWDGRST_Pos    (11U)
#define RCC_APB1RSTR_WWDGRST_Msk    (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)
#define RCC_APB1RSTR_WWDGRST        RCC_APB1RSTR_WWDGRST_Msk

#define RCC_APB1RSTR_SPI2RST_Pos    (14U)
#define RCC_APB1RSTR_SPI2RST_Msk    (0x1UL << RCC_APB1RSTR_SPI2RST_Pos)
#define RCC_APB1RSTR_SPI2RST        RCC_APB1RSTR_SPI2RST_Msk

#define RCC_APB1RSTR_SPI3RST_Pos    (15U)
#define RCC_APB1RSTR_SPI3RST_Msk    (0x1UL << RCC_APB1RSTR_SPI3RST_Pos)
#define RCC_APB1RSTR_SPI3RST        RCC_APB1RSTR_SPI3RST_Msk

#define RCC_APB1RSTR_USART2RST_Pos  (17U)
#define RCC_APB1RSTR_USART2RST_Msk  (0x1UL << RCC_APB1RSTR_USART2RST_Pos)
#define RCC_APB1RSTR_USART2RST      RCC_APB1RSTR_USART2RST_Msk

#define RCC_APB1RSTR_I2C1RST_Pos    (21U)
#define RCC_APB1RSTR_I2C1RST_Msk    (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)
#define RCC_APB1RSTR_I2C1RST        RCC_APB1RSTR_I2C1RST_Msk

#define RCC_APB1RSTR_I2C2RST_Pos    (22U)
#define RCC_APB1RSTR_I2C2RST_Msk    (0x1UL << RCC_APB1RSTR_I2C2RST_Pos)
#define RCC_APB1RSTR_I2C2RST        RCC_APB1RSTR_I2C2RST_Msk

#define RCC_APB1RSTR_I2C3RST_Pos    (23U)
#define RCC_APB1RSTR_I2C3RST_Msk    (0x1UL << RCC_APB1RSTR_I2C3RST_Pos)
#define RCC_APB1RSTR_I2C3RST        RCC_APB1RSTR_I2C3RST_Msk

#define RCC_APB1RSTR_PWRRST_Pos     (28U)
#define RCC_APB1RSTR_PWRRST_Msk     (0x1UL << RCC_APB1RSTR_PWRRST_Pos)
#define RCC_APB1RSTR_PWRRST         RCC_APB1RSTR_PWRRST_Msk

/******************** Bits definition for RCC_APB2RSTR register *******************/
#define RCC_APB2RSTR_TIM1RST_Pos    (0U)
#define RCC_APB2RSTR_TIM1RST_Msk    (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)
#define RCC_APB2RSTR_TIM1RST        RCC_APB2RSTR_TIM1RST_Msk

#define RCC_APB2RSTR_USART1RST_Pos  (4U)
#define RCC_APB2RSTR_USART1RST_Msk  (0x1UL << RCC_APB2RSTR_USART1RST_Pos)
#define RCC_APB2RSTR_USART1RST      RCC_APB2RSTR_USART1RST_Msk

#define RCC_APB2RSTR_USART6RST_Pos  (5U)
#define RCC_APB2RSTR_USART6RST_Msk  (0x1UL << RCC_APB2RSTR_USART6RST_Pos)
#define RCC_APB2RSTR_USART6RST      RCC_APB2RSTR_USART6RST_Msk

#define RCC_APB2RSTR_ADC1RST_Pos    (8U)
#define RCC_APB2RSTR_ADC1RST_Msk    (0x1UL << RCC_APB2RSTR_ADC1RST_Pos)
#define RCC_APB2RSTR_ADC1RST        RCC_APB2RSTR_ADC1RST_Msk

#define RCC_APB2RSTR_SDIORST_Pos    (11U)
#define RCC_APB2RSTR_SDIORST_Msk    (0x1UL << RCC_APB2RSTR_SDIORST_Pos)
#define RCC_APB2RSTR_SDIORST        RCC_APB2RSTR_SDIORST_Msk

#define RCC_APB2RSTR_SPI1RST_Pos    (12U)
#define RCC_APB2RSTR_SPI1RST_Msk    (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)
#define RCC_APB2RSTR_SPI1RST        RCC_APB2RSTR_SPI1RST_Msk

#define RCC_APB2RSTR_SPI4RST_Pos    (13U)
#define RCC_APB2RSTR_SPI4RST_Msk    (0x1UL << RCC_APB2RSTR_SPI4RST_Pos)
#define RCC_APB2RSTR_SPI4RST        RCC_APB2RSTR_SPI4RST_Msk

#define RCC_APB2RSTR_SYSCFGRST_Pos  (14U)
#define RCC_APB2RSTR_SYSCFGRST_Msk  (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos)
#define RCC_APB2RSTR_SYSCFGRST      RCC_APB2RSTR_SYSCFGRST_Msk

#define RCC_APB2RSTR_TIM9RST_Pos    (16U)
#define RCC_APB2RSTR_TIM9RST_Msk    (0x1UL << RCC_APB2RSTR_TIM9RST_Pos)
#define RCC_APB2RSTR_TIM9RST        RCC_APB2RSTR_TIM9RST_Msk

#define RCC_APB2RSTR_TIM10RST_Pos   (17U)
#define RCC_APB2RSTR_TIM10RST_Msk   (0x1UL << RCC_APB2RSTR_TIM10RST_Pos)
#define RCC_APB2RSTR_TIM10RST       RCC_APB2RSTR_TIM10RST_Msk

#define RCC_APB2RSTR_TIM11RST_Pos   (18U)
#define RCC_APB2RSTR_TIM11RST_Msk   (0x1UL << RCC_APB2RSTR_TIM11RST_Pos)
#define RCC_APB2RSTR_TIM11RST       RCC_APB2RSTR_TIM11RST_Msk

#define RCC_APB2RSTR_SPI5RST_Pos    (20U)
#define RCC_APB2RSTR_SPI5RST_Msk    (0x1UL << RCC_APB2RSTR_SPI5RST_Pos)
#define RCC_APB2RSTR_SPI5RST        RCC_APB2RSTR_SPI5RST_Msk

/******************** Bits definition for RCC_AHB1ENR register ********************/
#define RCC_AHB1ENR_GPIOAEN_Pos     (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN         RCC_AHB1ENR_GPIOAEN_Msk

#define RCC_AHB1ENR_GPIOBEN_Pos     (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)
#define RCC_AHB1ENR_GPIOBEN         RCC_AHB1ENR_GPIOBEN_Msk

#define RCC_AHB1ENR_GPIOCEN_Pos     (2U)
#define RCC_AHB1ENR_GPIOCEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)
#define RCC_AHB1ENR_GPIOCEN         RCC_AHB1ENR_GPIOCEN_Msk

#define RCC_AHB1ENR_GPIODEN_Pos     (3U)
#define RCC_AHB1ENR_GPIODEN_Msk     (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)
#define RCC_AHB1ENR_GPIODEN         RCC_AHB1ENR_GPIODEN_Msk

#define RCC_AHB1ENR_GPIOEEN_Pos     (4U)
#define RCC_AHB1ENR_GPIOEEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)
#define RCC_AHB1ENR_GPIOEEN         RCC_AHB1ENR_GPIOEEN_Msk

#define RCC_AHB1ENR_GPIOHEN_Pos     (7U)
#define RCC_AHB1ENR_GPIOHEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)
#define RCC_AHB1ENR_GPIOHEN         RCC_AHB1ENR_GPIOHEN_Msk

#define RCC_AHB1ENR_CRCEN_Pos       (12U)
#define RCC_AHB1ENR_CRCEN_Msk       (0x1UL << RCC_AHB1ENR_CRCEN_Pos)
#define RCC_AHB1ENR_CRCEN           RCC_AHB1ENR_CRCEN_Msk

#define RCC_AHB1ENR_DMA1EN_Pos      (21U)
#define RCC_AHB1ENR_DMA1EN_Msk      (0x1UL << RCC_AHB1ENR_DMA1EN_Pos)
#define RCC_AHB1ENR_DMA1EN          RCC_AHB1ENR_DMA1EN_Msk

#define RCC_AHB1ENR_DMA2EN_Pos      (22U)
#define RCC_AHB1ENR_DMA2EN_Msk      (0x1UL << RCC_AHB1ENR_DMA2EN_Pos)
#define RCC_AHB1ENR_DMA2EN          RCC_AHB1ENR_DMA2EN_Msk

/******************** Bits definition for RCC_AHB2ENR register ********************/
#define RCC_AHB2ENR_OTGFSEN_Pos     (7U)
#define RCC_AHB2ENR_OTGFSEN_Msk     (0x1UL << RCC_AHB2ENR_OTGFSEN_Pos)
#define RCC_AHB2ENR_OTGFSEN         RCC_AHB2ENR_OTGFSEN_Msk

/******************** Bits definition for RCC_APB1ENR register ********************/
#define RCC_APB1ENR_TIM2EN_Pos      (0U)
#define RCC_APB1ENR_TIM2EN_Msk      (0x1UL << RCC_APB1ENR_TIM2EN_Pos)
#define RCC_APB1ENR_TIM2EN          RCC_APB1ENR_TIM2EN_Msk

#define RCC_APB1ENR_TIM3EN_Pos      (1U)
#define RCC_APB1ENR_TIM3EN_Msk      (0x1UL << RCC_APB1ENR_TIM3EN_Pos)
#define RCC_APB1ENR_TIM3EN          RCC_APB1ENR_TIM3EN_Msk

#define RCC_APB1ENR_TIM4EN_Pos      (2U)
#define RCC_APB1ENR_TIM4EN_Msk      (0x1UL << RCC_APB1ENR_TIM4EN_Pos)
#define RCC_APB1ENR_TIM4EN          RCC_APB1ENR_TIM4EN_Msk

#define RCC_APB1ENR_TIM5EN_Pos      (3U)
#define RCC_APB1ENR_TIM5EN_Msk      (0x1UL << RCC_APB1ENR_TIM5EN_Pos)
#define RCC_APB1ENR_TIM5EN          RCC_APB1ENR_TIM5EN_Msk

#define RCC_APB1ENR_WWDGEN_Pos      (11U)
#define RCC_APB1ENR_WWDGEN_Msk      (0x1UL << RCC_APB1ENR_WWDGEN_Pos)
#define RCC_APB1ENR_WWDGEN          RCC_APB1ENR_WWDGEN_Msk

#define RCC_APB1ENR_SPI2EN_Pos      (14U)
#define RCC_APB1ENR_SPI2EN_Msk      (0x1UL << RCC_APB1ENR_SPI2EN_Pos)
#define RCC_APB1ENR_SPI2EN          RCC_APB1ENR_SPI2EN_Msk

#define RCC_APB1ENR_SPI3EN_Pos      (15U)
#define RCC_APB1ENR_SPI3EN_Msk      (0x1UL << RCC_APB1ENR_SPI3EN_Pos)
#define RCC_APB1ENR_SPI3EN          RCC_APB1ENR_SPI3EN_Msk

#define RCC_APB1ENR_USART2EN_Pos    (17U)
#define RCC_APB1ENR_USART2EN_Msk    (0x1UL << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART2EN        RCC_APB1ENR_USART2EN_Msk

#define RCC_APB1ENR_I2C1EN_Pos      (21U)
#define RCC_APB1ENR_I2C1EN_Msk      (0x1UL << RCC_APB1ENR_I2C1EN_Pos)
#define RCC_APB1ENR_I2C1EN          RCC_APB1ENR_I2C1EN_Msk

#define RCC_APB1ENR_I2C2EN_Pos      (22U)
#define RCC_APB1ENR_I2C2EN_Msk      (0x1UL << RCC_APB1ENR_I2C2EN_Pos)
#define RCC_APB1ENR_I2C2EN          RCC_APB1ENR_I2C2EN_Msk

#define RCC_APB1ENR_I2C3EN_Pos      (23U)
#define RCC_APB1ENR_I2C3EN_Msk      (0x1UL << RCC_APB1ENR_I2C3EN_Pos)
#define RCC_APB1ENR_I2C3EN          RCC_APB1ENR_I2C3EN_Msk

#define RCC_APB1ENR_PWREN_Pos       (28U)
#define RCC_APB1ENR_PWREN_Msk       (0x1UL << RCC_APB1ENR_PWREN_Pos)
#define RCC_APB1ENR_PWREN           RCC_APB1ENR_PWREN_Msk

/******************** Bits definition for RCC_APB2ENR register ********************/
#define RCC_APB2ENR_TIM1EN_Pos      (0U)
#define RCC_APB2ENR_TIM1EN_Msk      (0x1UL << RCC_APB2ENR_TIM1EN_Pos)
#define RCC_APB2ENR_TIM1EN          RCC_APB2ENR_TIM1EN_Msk

#define RCC_APB2ENR_USART1EN_Pos    (4U)
#define RCC_APB2ENR_USART1EN_Msk    (0x1UL << RCC_APB2ENR_USART1EN_Pos)
#define RCC_APB2ENR_USART1EN        RCC_APB2ENR_USART1EN_Msk

#define RCC_APB2ENR_USART6EN_Pos    (5U)
#define RCC_APB2ENR_USART6EN_Msk    (0x1UL << RCC_APB2ENR_USART6EN_Pos)
#define RCC_APB2ENR_USART6EN        RCC_APB2ENR_USART6EN_Msk

#define RCC_APB2ENR_ADC1EN_Pos      (8U)
#define RCC_APB2ENR_ADC1EN_Msk      (0x1UL << RCC_APB2ENR_ADC1EN_Pos)
#define RCC_APB2ENR_ADC1EN          RCC_APB2ENR_ADC1EN_Msk

#define RCC_APB2ENR_SDIOEN_Pos      (11U)
#define RCC_APB2ENR_SDIOEN_Msk      (0x1UL << RCC_APB2ENR_SDIOEN_Pos)
#define RCC_APB2ENR_SDIOEN          RCC_APB2ENR_SDIOEN_Msk

#define RCC_APB2ENR_SPI1EN_Pos      (12U)
#define RCC_APB2ENR_SPI1EN_Msk      (0x1UL << RCC_APB2ENR_SPI1EN_Pos)
#define RCC_APB2ENR_SPI1EN          RCC_APB2ENR_SPI1EN_Msk

#define RCC_APB2ENR_SPI4EN_Pos      (13U)
#define RCC_APB2ENR_SPI4EN_Msk      (0x1UL << RCC_APB2ENR_SPI4EN_Pos)
#define RCC_APB2ENR_SPI4EN          RCC_APB2ENR_SPI4EN_Msk

#define RCC_APB2ENR_SYSCFGEN_Pos    (14U)
#define RCC_APB2ENR_SYSCFGEN_Msk    (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)
#define RCC_APB2ENR_SYSCFGEN        RCC_APB2ENR_SYSCFGEN_Msk

#define RCC_APB2ENR_TIM9EN_Pos      (16U)
#define RCC_APB2ENR_TIM9EN_Msk      (0x1UL << RCC_APB2ENR_TIM9EN_Pos)
#define RCC_APB2ENR_TIM9EN          RCC_APB2ENR_TIM9EN_Msk

#define RCC_APB2ENR_TIM10EN_Pos     (17U)
#define RCC_APB2ENR_TIM10EN_Msk     (0x1UL << RCC_APB2ENR_TIM10EN_Pos)
#define RCC_APB2ENR_TIM10EN         RCC_APB2ENR_TIM10EN_Msk

#define RCC_APB2ENR_TIM11EN_Pos     (18U)
#define RCC_APB2ENR_TIM11EN_Msk     (0x1UL << RCC_APB2ENR_TIM11EN_Pos)
#define RCC_APB2ENR_TIM11EN         RCC_APB2ENR_TIM11EN_Msk

#define RCC_APB2ENR_SPI5EN_Pos      (20U)
#define RCC_APB2ENR_SPI5EN_Msk      (0x1UL << RCC_APB2ENR_SPI5EN_Pos)
#define RCC_APB2ENR_SPI5EN          RCC_APB2ENR_SPI5EN_Msk

/******************* Bits definition for RCC_AHB1LPENR register *******************/
#define RCC_AHB1LPENR_GPIOALPEN_Pos     (0U)
#define RCC_AHB1LPENR_GPIOALPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOALPEN_Pos)
#define RCC_AHB1LPENR_GPIOALPEN         RCC_AHB1LPENR_GPIOALPEN_Msk

#define RCC_AHB1LPENR_GPIOBLPEN_Pos     (1U)
#define RCC_AHB1LPENR_GPIOBLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOBLPEN_Pos)
#define RCC_AHB1LPENR_GPIOBLPEN         RCC_AHB1LPENR_GPIOBLPEN_Msk

#define RCC_AHB1LPENR_GPIOCLPEN_Pos     (2U)
#define RCC_AHB1LPENR_GPIOCLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOCLPEN_Pos)
#define RCC_AHB1LPENR_GPIOCLPEN         RCC_AHB1LPENR_GPIOCLPEN_Msk

#define RCC_AHB1LPENR_GPIODLPEN_Pos     (3U)
#define RCC_AHB1LPENR_GPIODLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIODLPEN_Pos)
#define RCC_AHB1LPENR_GPIODLPEN         RCC_AHB1LPENR_GPIODLPEN_Msk

#define RCC_AHB1LPENR_GPIOELPEN_Pos     (4U)
#define RCC_AHB1LPENR_GPIOELPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOELPEN_Pos)
#define RCC_AHB1LPENR_GPIOELPEN         RCC_AHB1LPENR_GPIOELPEN_Msk

#define RCC_AHB1LPENR_GPIOHLPEN_Pos     (7U)
#define RCC_AHB1LPENR_GPIOHLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOHLPEN_Pos)
#define RCC_AHB1LPENR_GPIOHLPEN         RCC_AHB1LPENR_GPIOHLPEN_Msk

#define RCC_AHB1LPENR_CRCLPEN_Pos       (12U)
#define RCC_AHB1LPENR_CRCLPEN_Msk       (0x1UL << RCC_AHB1LPENR_CRCLPEN_Pos)
#define RCC_AHB1LPENR_CRCLPEN           RCC_AHB1LPENR_CRCLPEN_Msk

#define RCC_AHB1LPENR_FLITFLPEN_Pos     (15U)
#define RCC_AHB1LPENR_FLITFLPEN_Msk     (0x1UL << RCC_AHB1LPENR_FLITFLPEN_Pos)
#define RCC_AHB1LPENR_FLITFLPEN         RCC_AHB1LPENR_FLITFLPEN_Msk

#define RCC_AHB1LPENR_SRAM1LPEN_Pos     (16U)
#define RCC_AHB1LPENR_SRAM1LPEN_Msk     (0x1UL << RCC_AHB1LPENR_SRAM1LPEN_Pos)
#define RCC_AHB1LPENR_SRAM1LPEN         RCC_AHB1LPENR_SRAM1LPEN_Msk

#define RCC_AHB1LPENR_DMA1LPEN_Pos      (21U)
#define RCC_AHB1LPENR_DMA1LPEN_Msk      (0x1UL << RCC_AHB1LPENR_DMA1LPEN_Pos)
#define RCC_AHB1LPENR_DMA1LPEN          RCC_AHB1LPENR_DMA1LPEN_Msk

#define RCC_AHB1LPENR_DMA2LPEN_Pos      (22U)
#define RCC_AHB1LPENR_DMA2LPEN_Msk      (0x1UL << RCC_AHB1LPENR_DMA2LPEN_Pos)
#define RCC_AHB1LPENR_DMA2LPEN          RCC_AHB1LPENR_DMA2LPEN_Msk

/******************* Bits definition for RCC_AHB2LPENR register *******************/
#define RCC_AHB1LPENR_OTGFSLPEN_Pos     (7U)
#define RCC_AHB1LPENR_OTGFSLPEN_Msk     (0x1UL << RCC_AHB1LPENR_OTGFSLPEN_Pos)
#define RCC_AHB1LPENR_OTGFSLPEN         RCC_AHB1LPENR_OTGFSLPEN_Msk

/******************* Bits definition for RCC_APB1LPENR register *******************/
#define RCC_APB1LPENR_TIM2LPEN_Pos      (0U)
#define RCC_APB1LPENR_TIM2LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos)
#define RCC_APB1LPENR_TIM2LPEN          RCC_APB1LPENR_TIM2LPEN_Msk

#define RCC_APB1LPENR_TIM3LPEN_Pos      (1U)
#define RCC_APB1LPENR_TIM3LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos)
#define RCC_APB1LPENR_TIM3LPEN          RCC_APB1LPENR_TIM3LPEN_Msk

#define RCC_APB1LPENR_TIM4LPEN_Pos      (2U)
#define RCC_APB1LPENR_TIM4LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos)
#define RCC_APB1LPENR_TIM4LPEN          RCC_APB1LPENR_TIM4LPEN_Msk

#define RCC_APB1LPENR_TIM5LPEN_Pos      (3U)
#define RCC_APB1LPENR_TIM5LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos)
#define RCC_APB1LPENR_TIM5LPEN          RCC_APB1LPENR_TIM5LPEN_Msk

#define RCC_APB1LPENR_WWDGLPEN_Pos      (11U)
#define RCC_APB1LPENR_WWDGLPEN_Msk      (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos)
#define RCC_APB1LPENR_WWDGLPEN          RCC_APB1LPENR_WWDGLPEN_Msk

#define RCC_APB1LPENR_SPI2LPEN_Pos      (14U)
#define RCC_APB1LPENR_SPI2LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos)
#define RCC_APB1LPENR_SPI2LPEN          RCC_APB1LPENR_SPI2LPEN_Msk

#define RCC_APB1LPENR_SPI3LPEN_Pos      (15U)
#define RCC_APB1LPENR_SPI3LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos)
#define RCC_APB1LPENR_SPI3LPEN          RCC_APB1LPENR_SPI3LPEN_Msk

#define RCC_APB1LPENR_USART2LPEN_Pos    (17U)
#define RCC_APB1LPENR_USART2LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos)
#define RCC_APB1LPENR_USART2LPEN        RCC_APB1LPENR_USART2LPEN_Msk

#define RCC_APB1LPENR_I2C1LPEN_Pos      (21U)
#define RCC_APB1LPENR_I2C1LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos)
#define RCC_APB1LPENR_I2C1LPEN          RCC_APB1LPENR_I2C1LPEN_Msk

#define RCC_APB1LPENR_I2C2LPEN_Pos      (22U)
#define RCC_APB1LPENR_I2C2LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos)
#define RCC_APB1LPENR_I2C2LPEN          RCC_APB1LPENR_I2C2LPEN_Msk

#define RCC_APB1LPENR_I2C3LPEN_Pos      (23U)
#define RCC_APB1LPENR_I2C3LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C3LPEN_Pos)
#define RCC_APB1LPENR_I2C3LPEN          RCC_APB1LPENR_I2C3LPEN_Msk

#define RCC_APB1LPENR_PWRLPEN_Pos       (28U)
#define RCC_APB1LPENR_PWRLPEN_Msk       (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos)
#define RCC_APB1LPENR_PWRLPEN           RCC_APB1LPENR_PWRLPEN_Msk

/******************* Bits definition for RCC_APB2LPENR register *******************/
#define RCC_APB2LPENR_TIM1LPEN_Pos      (0U)
#define RCC_APB2LPENR_TIM1LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM1LPEN_Pos)
#define RCC_APB2LPENR_TIM1LPEN          RCC_APB2LPENR_TIM1LPEN_Msk

#define RCC_APB2LPENR_USART2LPEN_Pos    (4U)
#define RCC_APB2LPENR_USART2LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART2LPEN_Pos)
#define RCC_APB2LPENR_USART2LPEN        RCC_APB2LPENR_USART2LPEN_Msk

#define RCC_APB2LPENR_USART6LPEN_Pos    (5U)
#define RCC_APB2LPENR_USART6LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART6LPEN_Pos)
#define RCC_APB2LPENR_USART6LPEN        RCC_APB2LPENR_USART6LPEN_Msk

#define RCC_APB2LPENR_ADC1LPEN_Pos      (8U)
#define RCC_APB2LPENR_ADC1LPEN_Msk      (0x1UL << RCC_APB2LPENR_ADC1LPEN_Pos)
#define RCC_APB2LPENR_ADC1LPEN           RCC_APB2LPENR_ADC1LPEN_Msk

#define RCC_APB2LPENR_SDIOLPEN_Pos      (11U)
#define RCC_APB2LPENR_SDIOLPEN_Msk      (0x1UL << RCC_APB2LPENR_SDIOLPEN_Pos)
#define RCC_APB2LPENR_SDIOLPEN          RCC_APB2LPENR_SDIOLPEN_Msk

#define RCC_APB2LPENR_SPI1LPEN_Pos      (12U)
#define RCC_APB2LPENR_SPI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos)
#define RCC_APB2LPENR_SPI1LPEN          RCC_APB2LPENR_SPI1LPEN_Msk

#define RCC_APB2LPENR_SPI4LPEN_Pos      (13U)
#define RCC_APB2LPENR_SPI4LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI4LPEN_Pos)
#define RCC_APB2LPENR_SPI4LPEN          RCC_APB2LPENR_SPI4LPEN_Msk

#define RCC_APB2LPENR_SYSCFGLPEN_Pos    (14U)
#define RCC_APB2LPENR_SYSCFGLPEN_Msk    (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos)
#define RCC_APB2LPENR_SYSCFGLPEN        RCC_APB2LPENR_SYSCFGLPEN_Msk

#define RCC_APB2LPENR_TIM9LPEN_Pos      (16U)
#define RCC_APB2LPENR_TIM9LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos)
#define RCC_APB2LPENR_TIM9LPEN          RCC_APB2LPENR_TIM9LPEN_Msk

#define RCC_APB2LPENR_TIM10LPEN_Pos     (17U)
#define RCC_APB2LPENR_TIM10LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos)
#define RCC_APB2LPENR_TIM10LPEN         RCC_APB2LPENR_TIM10LPEN_Msk

#define RCC_APB2LPENR_TIM11LPEN_Pos     (18U)
#define RCC_APB2LPENR_TIM11LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos)
#define RCC_APB2LPENR_TIM11LPEN         RCC_APB2LPENR_TIM11LPEN_Msk

#define RCC_APB2LPENR_SPI5LPEN_Pos      (20U)
#define RCC_APB2LPENR_SPI5LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI5LPEN_Pos)
#define RCC_APB2LPENR_SPI5LPEN          RCC_APB2LPENR_SPI5LPEN_Msk

/********************** Bits definition for RCC_BCDR register *********************/
#define RCC_BDCR_LSEON_Pos          (0U)
#define RCC_BDCR_LSEON_Msk          (0x1UL << RCC_BDCR_LSEON_Pos)
#define RCC_BDCR_LSEON              RCC_BDCR_LSEON_Msk

#define RCC_BDCR_LSERDY_Pos         (1U)
#define RCC_BDCR_LSERDY_Msk         (0x1UL << RCC_BDCR_LSERDY_Pos)
#define RCC_BDCR_LSERDY             RCC_BDCR_LSERDY_Msk

#define RCC_BDCR_LSEBYP_Pos         (2U)
#define RCC_BDCR_LSEBYP_Msk         (0x1UL << RCC_BDCR_LSEBYP_Pos)
#define RCC_BDCR_LSEBYP             RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_LSEMOD_Pos         (3U)
#define RCC_BDCR_LSEMOD_Msk         (0x1UL << RCC_BDCR_LSEMOD_Pos)
#define RCC_BDCR_LSEMOD             RCC_BDCR_LSEMOD_Msk

#define RCC_BDCR_RTCSEL_Pos         (8U)
#define RCC_BDCR_RTCSEL_Msk         (0x3UL << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL             RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0           (0x1UL << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_1           (0x2UL << RCC_BDCR_RTCSEL_Pos)

#define RCC_BDCR_RTCEN_Pos          (15U)
#define RCC_BDCR_RTCEN_Msk          (0x1UL << RCC_BDCR_RTCEN_Pos)
#define RCC_BDCR_RTCEN              RCC_BDCR_RTCEN_Msk

#define RCC_BDCR_BDRST_Pos          (16U)
#define RCC_BDCR_BDRST_Msk          (0x1UL << RCC_BDCR_BDRST_Pos)
#define RCC_BDCR_BDRST              RCC_BDCR_BDRST_Msk

/********************** Bits definition for RCC_CSR register **********************/
#define RCC_CSR_LSION_Pos           (0U)
#define RCC_CSR_LSION_Msk           (0x1UL << RCC_CSR_LSION_Pos)
#define RCC_CSR_LSION               RCC_CSR_LSION_Msk

#define RCC_CSR_LSIRDY_Pos          (1U)
#define RCC_CSR_LSIRDY_Msk          (0x1UL << RCC_CSR_LSIRDY_Pos)
#define RCC_CSR_LSIRDY              RCC_CSR_LSIRDY_Msk

#define RCC_CSR_RMVF_Pos            (24U)
#define RCC_CSR_RMVF_Msk            (0x1UL << RCC_CSR_RMVF_Pos)
#define RCC_CSR_RMVF                RCC_CSR_RMVF_Msk

#define RCC_CSR_BORRSTF_Pos         (25U)
#define RCC_CSR_BORRSTF_Msk         (0x1UL << RCC_CSR_BORRSTF_Pos)
#define RCC_CSR_BORRSTF             RCC_CSR_BORRSTF_Msk

#define RCC_CSR_PINRSTF_Pos         (26U)
#define RCC_CSR_PINRSTF_Msk         (0x1UL << RCC_CSR_PINRSTF_Pos)
#define RCC_CSR_PINRSTF             RCC_CSR_PINRSTF_Msk

#define RCC_CSR_PORRSTF_Pos         (27U)
#define RCC_CSR_PORRSTF_Msk         (0x1UL << RCC_CSR_PORRSTF_Pos)
#define RCC_CSR_PORRSTF             RCC_CSR_PORRSTF_Msk

#define RCC_CSR_SFTRSTF_Pos         (28U)
#define RCC_CSR_SFTRSTF_Msk         (0x1UL << RCC_CSR_SFTRSTF_Pos)
#define RCC_CSR_SFTRSTF             RCC_CSR_SFTRSTF_Msk

#define RCC_CSR_IWDGRSTF_Pos        (29U)
#define RCC_CSR_IWDGRSTF_Msk        (0x1UL << RCC_CSR_IWDGRSTF_Pos)
#define RCC_CSR_IWDGRSTF            RCC_CSR_IWDGRSTF_Msk

#define RCC_CSR_WWDGRSTF_Pos        (30U)
#define RCC_CSR_WWDGRSTF_Msk        (0x1UL << RCC_CSR_WWDGRSTF_Pos)
#define RCC_CSR_WWDGRSTF            RCC_CSR_WWDGRSTF_Msk

#define RCC_CSR_LPWRRSTF_Pos        (31U)
#define RCC_CSR_LPWRRSTF_Msk        (0x1UL << RCC_CSR_LPWRRSTF_Pos)
#define RCC_CSR_LPWRRSTF            RCC_CSR_LPWRRSTF_Msk

/********************* Bits definition for RCC_SSCGR register *********************/
#define RCC_SSCGR_MODPER_Pos        (0U)
#define RCC_SSCGR_MODPER_Msk        (0x1FFFUL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER            RCC_SSCGR_MODPER_Msk
#define RRC_SSCGR_MODPER_0          (0x0001UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_1          (0x0002UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_2          (0x0004UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_3          (0x0008UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_4          (0x0010UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_5          (0x0020UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_6          (0x0040UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_7          (0x0080UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_8          (0x0100UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_9          (0x0200UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_10         (0x0400UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_11         (0x0800UL << RCC_SSCGR_MODPER_Pos)
#define RCC_SSCGR_MODPER_12         (0x1000UL << RCC_SSCGR_MODPER_Pos)

#define RCC_SSCGR_INCSTEP_Pos       (14U)
#define RCC_SSCGR_INCSTEP_Msk       (0x7FFFUL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP           RCC_SSCGR_INCSTEP_Msk
#define RCC_SSCGR_INCSTEP_0         (0x0001UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_1         (0x0002UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_2         (0x0004UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_3         (0x0008UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_4         (0x0010UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_5         (0x0020UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_6         (0x0040UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_7         (0x0080UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_8         (0x0100UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_9         (0x0200UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_10        (0x0400UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_11        (0x0800UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_12        (0x1000UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_13        (0x2000UL << RCC_SSCGR_INCSTEP_Pos)
#define RCC_SSCGR_INCSTEP_14        (0x4000UL << RCC_SSCGR_INCSTEP_Pos)

#define RCC_SSCGR_SPREADSEL_Pos     (30U)
#define RCC_SSCGR_SPREADSEL_Msk     (0x1UL << RCC_SSCGR_SPREADSEL_Pos)
#define RCC_SSCGR_SPREADSEL         RCC_SSCGR_SPREADSEL_Msk

#define RCC_SSCGR_SSCGEN_Pos        (31U)
#define RCC_SSCGR_SSCGEN_Msk        (0x1UL << RCC_SSCGR_SSCGEN_Pos)
#define RCC_SSCGR_SSCGEN            RCC_SSCGR_SSCGEN_Msk

/******************* Bits definition for RCC_PLLI2SCFGR register ******************/
#define RCC_PLLI2SCFGR_PLLI2SM_Pos  (0U)
#define RCC_PLLI2SCFGR_PLLI2SM_Msk  (0x3FUL << RCC_PLLI2SCFGR_PLLI2SM_Pos)
#define RCC_PLLI2SCFGR_PLLI2SM      RCC_PLLI2SCFGR_PLLI2SM_Msk
#define RCC_PLLI2SCFGR_PLLI2SM_0    (0x01UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)
#define RCC_PLLI2SCFGR_PLLI2SM_1    (0x02UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)
#define RCC_PLLI2SCFGR_PLLI2SM_2    (0x04UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)
#define RCC_PLLI2SCFGR_PLLI2SM_3    (0x08UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)
#define RCC_PLLI2SCFGR_PLLI2SM_4    (0x10UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)
#define RCC_PLLI2SCFGR_PLLI2SM_5    (0x20UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)

#define RCC_PLLI2SCFGR_PLLI2SN_Pos  (6U)
#define RCC_PLLI2SCFGR_PLLI2SN_Msk  (0x1FFUL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN      RCC_PLLI2SCFGR_PLLI2SN_Msk
#define RCC_PLLI2SCFGR_PLLI2SN_0    (0x001UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_1    (0x002UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_2    (0x004UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_3    (0x008UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_4    (0x010UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_5    (0x020UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_6    (0x040UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_7    (0x080UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)
#define RCC_PLLI2SCFGR_PLLI2SN_8    (0x100UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)

#define RCC_PLLI2SCFGR_PLLI2SR_Pos  (28U)
#define RCC_PLLI2SCFGR_PLLI2SR_Msk  (0x3UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)
#define RCC_PLLI2SCFGR_PLLI2SR      RCC_PLLI2SCFGR_PLLI2SR_Msk
#define RCC_PLLI2SCFGR_PLLI2SR_0    (0x1UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)
#define RCC_PLLI2SCFGR_PLLI2SR_1    (0x2UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)
#define RCC_PLLI2SCFGR_PLLI2SR_2    (0x4UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)

/********************* Bits definition for RCC_DCKCFGR register ********************/
#define RCC_DCKCFGR_TIMPRE_Pos       (24U)
#define RCC_DCKCFGR_TIMPRE_Msk       (0x1UL << RCC_DCKCFGR_TIMPRE_Pos)
#define RCC_DCKCFGR_TIMPRE           RCC_DCKCFGR_TIMPRE_Msk


/**********************************************************************************/
/*                                                                                */
/*                          System Configuration Controller                       */
/*                                                                                */
/**********************************************************************************/

/******************** Bits definition for SYSCFG_MEMRMP register ******************/
#define SYSCFG_MEMRMP_MEM_MODE_Pos      (0U)
#define SYSCFG_MEMRMP_MEM_MODE_FLASH    (0x0UL << SYSCFG_MEMRMP_MEM_MODE_Pos)
#define SYSCFG_MEMRMP_MEM_MODE_SYS      (0x1UL << SYSCFG_MEMRMP_MEM_MODE_Pos)
#define SYSCFG_MEMRMP_MEM_MODE_SRAM     (0x3UL << SYSCFG_MEMRMP_MEM_MODE_Pos)

/********************** Bits definition for SYSCFG_PMC register *******************/
#define SYSCFG_PMC_Pos              (16U)
#define SYSCFG_ADCxDC2              (0x1UL << SYSCFG_PMC_Pos)

/******************** Bits definition for SYSCFG_EXTICR1 register *****************/
#define SYSCFG_EXTICR1_EXTI0_Pos        (0U)
#define SYSCFG_EXTICR1_EXTI0_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos)
#define SYSCFG_EXTICR1_EXTI0            SYSCFG_EXTICR1_EXTI0_Msk
#define SYSCFG_EXTICR1_EXTI0_PA0        (0x0UL << SYSCFG_EXTICR1_EXTI0_Pos)
#define SYSCFG_EXTICR1_EXTI0_PB0        (0x1UL << SYSCFG_EXTICR1_EXTI0_Pos)
#define SYSCFG_EXTICR1_EXTI0_PC0        (0x2UL << SYSCFG_EXTICR1_EXTI0_Pos)
#define SYSCFG_EXTICR1_EXTI0_PD0        (0x3UL << SYSCFG_EXTICR1_EXTI0_Pos)
#define SSYCFG_EXTICR1_EXTI0_PE0        (0x4UL << SYSCFG_EXTICR1_EXTI0_Pos)
#define SYSCFG_EXTICR1_EXTI0_PH0        (0x7UL << SYSCFG_EXTICR1_EXTI0_Pos)

#define SYSCFG_EXTICR1_EXTI1_Pos        (4U)
#define SYSCFG_EXTICR1_EXTI1_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1            SYSCFG_EXTICR1_EXTI1_Msk
#define SYSCFG_EXTICR1_EXTI1_PA1        (0x0UL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1_PB1        (0x1UL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1_PC1        (0x2UL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1_PD1        (0x3UL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1_PE1        (0x4UL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1_PH1        (0x7UL << SYSCFG_EXTICR1_EXTI1_Pos)

#define SYSCFG_EXTICR1_EXTI2_Pos        (8U)
#define SYSCFG_EXTICR1_EXTI2_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2            SYSCFG_EXTICR1_EXTI2_Msk
#define SYSCFG_EXTICR1_EXTI2_PA2        (0x0UL << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2_PB2        (0x1UL << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2_PC2        (0x2UL << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2_PD2        (0x3UL << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2_PE2        (0x4UL << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2_PH2        (0x7UL << SYSCFG_EXTICR1_EXTI2_Pos)

#define SYSCFG_EXTICR1_EXTI3_Pos        (12U)
#define SYSCFG_EXTICR1_EXTI3_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3            SYSCFG_EXTICR1_EXTI3_Msk
#define SYSCFG_EXTICR1_EXTI3_PA3        (0x0UL << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3_PB3        (0x1UL << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3_PC3        (0x2UL << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3_PD3        (0x3UL << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3_PE3        (0x4UL << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3_PH3        (0x7UL << SYSCFG_EXTICR1_EXTI3_Pos)

/******************** Bits definition for SYSCFG_EXTICR2 register *****************/
#define SYSCFG_EXTICR2_EXTI4_Pos        (0U)
#define SYSCFG_EXTICR2_EXTI4_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4            SYSCFG_EXTICR2_EXTI4_Msk
#define SYSCFG_EXTICR2_EXTI4_PA4        (0x0UL << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4_PB4        (0x1UL << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4_PC4        (0x2UL << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4_PD4        (0x3UL << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4_PE4        (0x4UL << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4_PH4        (0x7UL << SYSCFG_EXTICR2_EXTI4_Pos)

#define SYSCFG_EXTICR2_EXTI5_Pos        (4U)
#define SYSCFG_EXTICR2_EXTI5_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5            SYSCFG_EXTICR2_EXTI5_Msk
#define SYSCFG_EXTICR2_EXTI5_PA5        (0x0UL << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5_PB5        (0x1UL << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5_PC5        (0x2UL << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5_PD5        (0x3UL << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5_PE5        (0x4UL << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5_PH5        (0x7UL << SYSCFG_EXTICR2_EXTI5_Pos)

#define SYSCFG_EXTICR2_EXTI6_Pos        (8U)
#define SYSCFG_EXTICR2_EXTI6_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6            SYSCFG_EXTICR2_EXTI6_Msk
#define SYSCFG_EXTICR2_EXTI6_PA6        (0x0UL << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6_PB6        (0x1UL << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6_PC6        (0x2UL << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6_PD6        (0x3UL << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6_PE6        (0x4UL << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6_PH6        (0x7UL << SYSCFG_EXTICR2_EXTI6_Pos)

#define SYSCFG_EXTICR2_EXTI7_Pos        (12U)
#define SYSCFG_EXTICR2_EXTI7_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7            SYSCFG_EXTICR2_EXTI7_Msk
#define SYSCFG_EXTICR2_EXTI7_PA7        (0x0UL << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7_PB7        (0x1UL << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7_PC7        (0x2UL << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7_PD7        (0x3UL << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7_PE7        (0x4UL << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7_PH7        (0x7UL << SYSCFG_EXTICR2_EXTI7_Pos)

/******************** Bits definition for SYSCFG_EXTICR3 register *****************/
#define SYSCFG_EXTICR3_EXTI8_Pos        (0U)
#define SYSCFG_EXTICR3_EXTI8_Msk        (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8            SYSCFG_EXTICR3_EXTI8_Msk
#define SYSCFG_EXTICR3_EXTI8_PA8        (0x0UL << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8_PB8        (0x1UL << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8_PC8        (0x2UL << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8_PD8        (0x3UL << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8_PE8        (0x4UL << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8_PH8        (0x7UL << SYSCFG_EXTICR3_EXTI8_Pos)

#define SYSCFG_EXTICR3_EXTI9_Pos        (4U)
#define SYSCFG_EXTICR3_EXTI9_Msk        (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9            SYSCFG_EXTICR3_EXTI9_Msk
#define SYSCFG_EXTICR3_EXTI9_PA9        (0x0UL << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9_PB9        (0x1UL << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9_PC9        (0x2UL << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9_PD9        (0x3UL << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9_PE9        (0x4UL << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9_PH9        (0x7UL << SYSCFG_EXTICR3_EXTI9_Pos)

#define SYSCFG_EXTICR3_EXTI10_Pos       (8U)
#define SYSCFG_EXTICR3_EXTI10_Msk       (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10           SYSCFG_EXTICR3_EXTI10_Msk
#define SYSCFG_EXTICR3_EXTI10_PA10      (0x0UL << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10_PB10      (0x1UL << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10_PC10      (0x2UL << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10_PD10      (0x3UL << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10_PE10      (0x4UL << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10_PH10      (0x7UL << SYSCFG_EXTICR3_EXTI10_Pos)

#define SYSCFG_EXTICR3_EXTI11_Pos       (12U)
#define SYSCFG_EXTICR3_EXTI11_Msk       (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11           SYSCFG_EXTICR3_EXTI11_Msk
#define SYSCFG_EXTICR3_EXTI11_PA11      (0x0UL << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11_PB11      (0x1UL << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11_PC11      (0x2UL << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11_PD11      (0x3UL << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11_PE11      (0x4UL << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11_PH11      (0x7UL << SYSCFG_EXTICR3_EXTI11_Pos)

/******************** Bits definition for SYSCFG_EXTICR4 register *****************/
#define SYSCFG_EXTICR4_EXTI12_Pos       (0U)
#define SYSCFG_EXTICR4_EXTI12_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12           SYSCFG_EXTICR4_EXTI12_Msk
#define SYSCFG_EXTICR4_EXTI12_PA12      (0x0UL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12_PB12      (0x1UL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12_PC12      (0x2UL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12_PD12      (0x3UL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12_PE12      (0x4UL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12_PH12      (0x7UL << SYSCFG_EXTICR4_EXTI12_Pos)

#define SYSCFG_EXTICR4_EXTI13_Pos       (4U)
#define SYSCFG_EXTICR4_EXTI13_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13           SYSCFG_EXTICR4_EXTI13_Msk
#define SYSCFG_EXTICR4_EXTI13_PA13      (0x0UL << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13_PB13      (0x1UL << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13_PC13      (0x2UL << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13_PD13      (0x3UL << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13_PE13      (0x4UL << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13_PH13      (0x7UL << SYSCFG_EXTICR4_EXTI13_Pos)

#define SYSCFG_EXTICR4_EXTI14_Pos       (8U)
#define SYSCFG_EXTICR4_EXTI14_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14           SYSCFG_EXTICR4_EXTI14_Msk
#define SYSCFG_EXTICR4_EXTI14_PA14      (0x0UL << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14_PB14      (0x1UL << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14_PC14      (0x2UL << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14_PD14      (0x3UL << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14_PE14      (0x4UL << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14_PH14      (0x7UL << SYSCFG_EXTICR4_EXTI14_Pos)

#define SYSCFG_EXTICR4_EXTI15_Pos       (12U)
#define SYSCFG_EXTICR4_EXTI15_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15           SYSCFG_EXTICR4_EXTI15_Msk
#define SYSCFG_EXTICR4_EXTI15_PA15      (0x0UL << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15_PB15      (0x1UL << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15_PC15      (0x2UL << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15_PD15      (0x3UL << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15_PE15      (0x4UL << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15_PH15      (0x7UL << SYSCFG_EXTICR4_EXTI15_Pos)


/**********************************************************************************/
/*                                                                                */
/*                   TIMERS (TIM1 | TIM2 - TIM5 | TIM9 - TIM11)                   */
/*                                                                                */
/**********************************************************************************/

/********************** Bits definition for TIM_CR1 register **********************/
#define TIM_CR1_CEN_Pos                 (0U)
#define TIM_CR1_CEN_Msk                 (0x1UL << TIM_CR1_CEN_Pos)
#define TIM_CR1_CEN                     TIM_CR1_CEN_Msk

#define TIM_CR1_UDIS_Pos                (1U)
#define TIM_CR1_UDIS_Msk                (0x1UL << TIM_CR1_UDIS_Pos)
#define TIM_CR1_UDIS                    TIM_CR1_UDIS_Msk

#define TIM_CR1_URS_Pos                 (2U)
#define TIM_CR1_URS_Msk                 (0x1UL << TIM_CR1_URS_Pos)
#define TIM_CR1_URS                     TIM_CR1_URS_Msk

#define TIM_CR1_OPM_Pos                 (3U)
#define TIM_CR1_OPM_Msk                 (0x1UL << TIM_CR1_OPM_Pos)
#define TIM_CR1_OPM                     TIM_CR1_OPM_Msk

#define TIM_CR1_DIR_Pos                 (4U)
#define TIM_CR1_DIR_Msk                 (0x1UL << TIM_CR1_DIR_Pos)
#define TIM_CR1_DIR                     TIM_CR1_DIR_Msk

#define TIM_CR1_CMS_Pos                 (5U)
#define TIM_CR1_CMS_Msk                 (0x3UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS                     TIM_CR1_CMS_Msk
#define TIM_CR1_CMS_EDGE                (0x0UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS_DOWN                (0x1UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS_UP                  (0x2UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS_BOTH                (0x3UL << TIM_CR1_CMS_Pos)

#define TIM_CR1_ARPE_Pos                (7U)
#define TIM_CR1_ARPE_Msk                (0x1UL << TIM_CR1_ARPE_Pos)
#define TIM_CR1_ARPE                    TIM_CR1_ARPE_Msk

#define TIM_CR1_CKD_Pos                 (8U)
#define TIM_CR1_CKD_Msk                 (0x3UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD                     TIM_CR1_CKD_Msk
#define TIM_CR1_CKD_EQUAL               (0x0UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD_DOUBLE              (0x1UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD_QUADRUPLE           (0x2UL << TIM_CR1_CKD_Pos)

/********************** Bits definition for TIM_CR2 register **********************/
#define TIM_CR2_CCPC_Pos                (0U)
#define TIM_CR2_CCPC_Msk                (0x1UL << TIM_CR2_CCPC_Pos)
#define TIM_CR2_CCPC                    TIM_CR2_CCPC_Msk

#define TIM_CR2_CCUS_Pos                (2U)
#define TIM_CR2_CCUS_Msk                (0x1UL << TIM_CR2_CCUS_Pos)
#define TIM_CR2_CCUS                    TIM_CR2_CCUS_Msk

#define TIM_CR2_CCDS_Pos                (3U)
#define TIM_CR2_CCDS_Msk                (0x1UL << TIM_CR2_CCDS_Pos)
#define TIM_CR2_CCDS                    TIM_CR2_CCDS_Msk

#define TIM_CR2_MMS_Pos                 (4U)
#define TIM_CR2_MMS_Msk                 (0x7UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS                     TIM_CR2_MMS_Msk
#define TIM_CR2_MMS_RESET               (0x0UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_ENABLE              (0x1UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_UPDATE              (0x2UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_COMPARE             (0x3UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_OC1REF              (0x4UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_OC2REF              (0x5UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_OC3REF              (0x6UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_OC4REF              (0x7UL << TIM_CR2_MMS_Pos)

#define TIM_CR2_TI1S_Pos                (7U)
#define TIM_CR2_TI1S_Msk                (0x1UL << TIM_CR2_TI1S_Pos)
#define TIM_CR2_TI1S                    TIM_CR2_TI1S_Msk

#define TIM_CR2_OIS1_Pos                (8U)
#define TIM_CR2_OIS1_Msk                (0x1UL << TIM_CR2_OIS1_Pos)
#define TIM_CR2_OIS1                    TIM_CR2_OIS1_Msk

#define TIM_CR2_OIS1N_Pos               (9U)
#define TIM_CR2_OIS1N_Msk               (0x1UL << TIM_CR2_OIS1N_Pos)
#define TIM_CR2_OIS1N                   TIM_CR2_OIS1N_Msk

#define TIM_CR2_OIS2_Pos                (10U)
#define TIM_CR2_OIS2_Msk                (0x1UL << TIM_CR2_OIS2_Pos)
#define TIM_CR2_OIS2                    TIM_CR2_OIS2_Msk

#define TIM_CR2_OIS2N_Pos               (11U)
#define TIM_CR2_OIS2N_Msk               (0x1UL << TIM_CR2_OIS2N_Pos)
#define TIM_CR2_OIS2N                   TIM_CR2_OIS2N_Msk

#define TIM_CR2_OIS3_Pos                (12U)
#define TIM_CR2_OIS3_Msk                (0x1UL << TIM_CR2_OIS3_Pos)
#define TIM_CR2_OIS3                    TIM_CR2_OIS3_Msk

#define TIM_CR2_OIS3N_Pos               (13U)
#define TIM_CR2_OIS3N_Msk               (0x1UL << TIM_CR2_OIS3N_Pos)
#define TIM_CR2_OIS3N                   TIM_CR2_OIS3N_Msk

#define TIM_CR2_OIS4_Pos                (14U)
#define TIM_CR2_OIS4_Msk                (0x1UL << ITM_CR2_OIS4_Pos)
#define TIM_CR2_OIS4                    TIM_CR2_OIS4_Msk

/********************** Bits definition for TIM_SMCR register *********************/
#define TIM_SMCR_SMS_Pos                (0U)
#define TIM_SMCR_SMS_Msk                (0x7UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS                    TIM_SMCR_SMS_Msk
#define TIM_SMCR_SMS_DIS                (0x0UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_EM1                (0x1UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_EM2                (0x2UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_EM3                (0x3UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_RESET              (0x4UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_GATED              (0x5UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_TRIGGER            (0x6UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_ECM1               (0x7UL << TIM_SMCR_SMS_Pos)

#define TIM_SMCR_TS_Pos                 (4U)
#define TIM_SMCR_TS_Msk                 (0x7UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS                     TIM_SMCR_TS_Msk
#define TIM_SMCR_TS_ITR0                (0x0UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_ITR1                (0x1UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_ITR2                (0x2UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_ITR3                (0x3UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_TI1F_ED             (0x4UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_TI1FP1              (0x5UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_TI2FP2              (0x6UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_ETRF                (0x7UL << TIM_SMCR_TS_Pos)

#define TIM_SMCR_MSM_Pos                (7U)
#define TIM_SMCR_MSM_Msk                (0x1UL << TIM_SMCR_MSM_Pos)
#define TIM_SMCR_MSM                    TIM_SMCR_MSM_Msk

#define TIM_SMCR_ETF_Pos                (8U)
#define TIM_SMCR_ETF_Msk                (0xFUL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF                    TIM_SMCR_ETF_Msk
#define TIM_SMCR_ETF_0                  (0x1UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_1                  (0x2UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_2                  (0x4UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_3                  (0x8UL << TIM_SMCR_ETF_Pos)

#define TIM_SMCR_ETPS_Pos               (12U)
#define TIM_SMCR_ETPS_Msk               (0x3UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS                   TIM_SMCR_ETPS_Msk
#define TIM_SMCR_ETPS_OFF               (0x0UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS_TWO               (0x1UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS_FOUR              (0x2UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS_EIGHT             (0x3UL << TIM_SMCR_ETPS_Pos)

#define TIM_SMCR_ECE_Pos                (14U)
#define TIM_SMCR_ECE_Msk                (0x1UL << TIM_SMCR_ECE_Pos)
#define TIM_SMCR_ECE                    TIM_SMCR_ECE_Msk

#define TIM_SMCR_ETP_Pos                (15U)
#define TIM_SMCR_ETP_Msk                (0x1UL << TIM_SMCR_ETP_Pos)
#define TIM_SMCR_ETP                    TIM_SMCR_ETP_Msk

/********************** Bits definition for TIM_DIER register *********************/
#define TIM_DIER_UIE_Pos                (0U)
#define TIM_DIER_UIE_Msk                (0x1UL << TIM_DIER_UIE_Pos)
#define TIM_DIER_UIE                    TIM_DIER_UIE_Msk

#define TIM_DIER_CC1IE_Pos              (1U)
#define TIM_DIER_CC1IE_Msk              (0x1UL << TIM_DIER_CC1IE_Pos)
#define TIM_DIER_CC1IE                  TIM_DIER_CC1IE_Msk

#define TIM_DIER_CC2IE_Pos              (2U)
#define TIM_DIER_CC2IE_Msk              (0x1UL << TIM_DIER_CC2IE_Pos)
#define TIM_DIER_CC2IE                  TIM_DIER_CC2IE_Msk

#define TIM_DIER_CC3IE_Pos              (3U)
#define TIM_DIER_CC3IE_Msk              (0x1UL << TIM_DIER_CC3IE_Pos)
#define TIM_DIER_CC3IE                  TIM_DIER_CC3IE_Msk

#define TIM_DIER_CC4IE_Pos              (4U)
#define TIM_DIER_CC4IE_Msk              (0x1UL << TIM_DIER_CC4IE_Pos)
#define TIM_DIER_CC4IE                  TIM_DIER_CC4IE_Msk

#define TIM_DIER_COMIE_Pos              (5U)
#define TIM_DIER_COMIE_Msk              (0x1UL << TIM_DIER_COMIE_Pos)
#define TIM_DIER_COMIE                  TIM_DIER_COMIE_Msk

#define TIM_DIER_TIE_Pos                (6U)
#define TIM_DIER_TIE_Msk                (0x1UL << TIM_DIER_TIE_Pos)
#define TIM_DIER_TIE                    TIM_DIER_TIE_Msk

#define TIM_DIER_BIE_Pos                (7U)
#define TIM_DIER_BIE_Msk                (0x1UL << TIM_DIER_BIE_Pos)
#define TIM_DIER_BIE                    TIM_DIER_BIE_Msk

#define TIM_DIER_UDE_Pos                (8U)
#define TIM_DIER_UDE_Msk                (0x1UL << TIM_DIER_UDE_Pos)
#define TIM_DIER_UDE                    TIM_DIER_UDE_Msk

#define TIM_DIER_CC1DE_Pos              (9U)
#define TIM_DIER_CC1DE_Msk              (0x1UL << TIM_DIER_CC1DE_Pos)
#define TIM_DIER_CC1DE                  TIM_DIER_CC1DE_Msk

#define TIM_DIER_CC2DE_Pos              (10U)
#define TIM_DIER_CC2DE_Msk              (0x1UL << TIM_DIER_CC2DE_Pos)
#define TIM_DIER_CC2DE                  TIM_DIER_CC2DE_Msk

#define TIM_DIER_CC3DE_Pos              (11U)
#define TIM_DIER_CC3DE_Msk              (0x1UL << TIM_DIER_CC3DE_Pos)
#define TIM_DIER_CC3DE                  TIM_DIER_CC3DE_Msk

#define TIM_DIER_CC4DE_Pos              (12U)
#define TIM_DIER_CC4DE_Msk              (0x1UL << TIM_DIER_CC4DE_Pos)
#define TIM_DIER_CC4DE                  TIM_DIER_CC4DE_Msk

#define TIM_DIER_COMDE_Pos              (13U)
#define TIM_DIER_COMDE_Msk              (0x1UL << TIM_DIER_COMDE_Pos)
#define TIM_DIER_COMDE                  TIM_DIER_COMDE_Msk

#define TIM_DIER_TDE_Pos                (14U)
#define TIM_DIER_TDE_Msk                (0x1UL << TIM_DIER_TDE_Pos)
#define TIM_DIER_TDE                    TIM_DIER_TDE_Msk

/*********************** Bits definition for TIM_SR register **********************/
#define TIM_SR_UIF_Pos                  (0U)
#define TIM_SR_UIF_Msk                  (0x1UL << TIM_SR_UIF_Pos)
#define TIM_SR_UIF                      TIM_SR_UIF_Msk

#define TIM_SR_CC1IF_Pos                (1U)
#define TIM_SR_CC1IF_Msk                (0x1UL << TIM_SR_CC1IF_Pos)
#define TIM_SR_CC1IF                    TIM_SR_CC1IF_Msk

#define TIM_SR_CC2IF_Pos                (2U)
#define TIM_SR_CC2IF_Msk                (0x1UL << TIM_SR_CC2IF_Pos)
#define TIM_SR_CC2IF                    TIM_SR_CC2IF_Msk

#define TIM_SR_CC3IF_Pos                (3U)
#define TIM_SR_CC3IF_Msk                (0x1UL << TIM_SR_CC3IF_Pos)
#define TIM_SR_CC3IF                    TIM_SR_CC3IF_Msk

#define TIM_SR_CC4IF_Pos                (4U)
#define TIM_SR_CC4IF_Msk                (0x1UL << TIM_SR_CC4IF_Pos)
#define TIM_SR_CC4IF                    TIM_SR_CC4IF_Msk

#define TIM_SR_COMIF_Pos                (5U)
#define TIM_SR_COMIF_Msk                (0x1UL << TIM_SR_COMIF_Pos)
#define TIM_SR_COMIF                    TIM_SR_COMIF_Msk

#define TIM_SR_TIF_Pos                  (6U)
#define TIM_SR_TIF_Msk                  (0x1UL << TIM_SR_TIF_Pos)
#define TIM_SR_TIF                      TIM_SR_TIF_Msk

#define TIM_SR_BIF_Pos                  (7U)
#define TIM_SR_BIF_Msk                  (0x1UL << TIM_SR_BIF_Pos)
#define TIM_SR_BIF                      TIM_SR_BIF_Msk

#define TIM_SR_CC1OF_Pos                (9U)
#define TIM_SR_CC1OF_Msk                (0x1UL << TIM_SR_CC1OF_Pos)
#define TIM_SR_CC1OF                    TIM_SR_CC1OF_Msk

#define TIM_SR_CC2OF_Pos                (10U)
#define TIM_SR_CC2OF_Msk                (0x1UL << TIM_SR_CC2OF_Pos)
#define TIM_SR_CC2OF                    TIM_SR_CC2OF_Msk

#define TIM_SR_CC3OF_Pos                (11U)
#define TIM_SR_CC3OF_Msk                (0x1UL << TIM_SR_CC3OF_Pos)
#define TIM_SR_CC3OF                    TIM_SR_CC3OF_Msk

#define TIM_SR_CC4OF_Pos                (12U)
#define TIM_SR_CC4OF_Msk                (0x1UL << TIM_SR_CC4OF_Pos)
#define TIM_SR_CC4OF                    TIM_SR_CC4OF_Msk

/********************** Bits definition for TIM_EGR register **********************/
#define TIM_EGR_UG_Pos                  (0U)
#define TIM_EGR_UG_Msk                  (0x1UL << TIM_EGR_UG_Pos)
#define TIM_EGR_UG                      TIM_EGR_UG_Msk

#define TIM_EGR_CC1G_Pos                (1U)
#define TIM_EGR_CC1G_Msk                (0x1UL << TIM_EGR_CC1G_Pos)
#define TIM_EGR_CC1G                    TIM_EGR_CC1G_Msk

#define TIM_EGR_CC2G_Pos                (2U)
#define TIM_EGR_CC2G_Msk                (0x1UL << TIM_EGR_CC2G_Pos)
#define TIM_EGR_CC2G                    TIM_EGR_CC2G_Msk

#define TIM_EGR_CC3G_Pos                (3U)
#define TIM_EGR_CC3G_Msk                (0x1UL << TIM_EGR_CC3G_Pos)
#define TIM_EGR_CC3G                    TIM_EGR_CC3G_Msk

#define TIM_EGR_CC4G_Pos                (4U)
#define TIM_EGR_CC4G_Msk                (0x1UL << TIM_EGR_CC4G_Pos)
#define TIM_EGR_CC4G                    TIM_EGR_CC4G_Msk

#define TIM_EGR_COMG_Pos                (5U)
#define TIM_EGR_COMG_Msk                (0x1UL << TIM_EGR_COMG_Pos)
#define TIM_EGR_COMG                    TIM_EGR_COMG_Msk

#define TIM_EGR_TG_Pos                  (6U)
#define TIM_EGR_TG_Msk                  (0x1UL << TIM_EGR_TG_Pos)
#define TIM_EGR_TG                      TIM_EGR_TG_Msk

#define TIM_EGR_BG_Pos                  (7U)
#define TIM_EGR_BG_Msk                  (0x1UL << TIM_EGR_BG_Pos)
#define TIM_EGR_BG                      TIM_EGR_BG_Msk

/*************** Bits definition for TIM_CCMR1 register (Selection) ***************/
#define TIM_CCMR1_CC1S_Pos              (0U)
#define TIM_CCMR1_CC1S_Msk              (0x3UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S                  TIM_CCMR1_CC1S_Msk
#define TIM_CCMR1_CC1S_OUT              (0x0UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S_TI1              (0x1UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S_TI2              (0x2UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S_TRC              (0x3UL << TIM_CCMR1_CC1S_Pos)

#define TIM_CCMR1_CC2S_Pos              (8U)
#define TIM_CCMR1_CC2S_Msk              (0x3UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S                  TIM_CCMR1_CC2S_Msk
#define TIM_CCMR1_CC2S_OUT              (0x0UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S_TI2              (0x1UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S_TI1              (0x2UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S_TRC              (0x3UL << TIM_CCMR1_CC2S_Pos)

/*************** Bits definition for TIM_CCMR1 register (Input Mode) **************/
#define TIM_CCMR1_IC1PSC_Pos            (2U)
#define TIM_CCMR1_IC1PSC_Msk            (0x3UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC                TIM_CCMR1_IC1PSC_Msk
#define TIM_CCMR1_IC1PSC_0              (0x0UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC_2              (0x1UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC_4              (0x2UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC_8              (0x3UL << TIM_CCMR1_IC1PSC_Pos)

#define TIM_CCMR1_IC1F_Pos              (4U)
#define TIM_CCMR1_IC1F_Msk              (0xFUL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F                  TIM_CCMR1_IC1F_Msk
#define TIM_CCMR1_IC1F_NOFILTER         (0x0UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_0                (0x1UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_1                (0x2UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_2                (0x4UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_3                (0x8UL << TIM_CCMR1_IC1F_Pos)

#define TIM_CCMR1_IC2PSC_Pos            (10U)
#define TIM_CCMR1_IC2PSC_Msk            (0x3UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC                TIM_CCMR1_IC2PSC_Msk
#define TIM_CCMR1_IC2PSC_0              (0x0UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC_2              (0x1UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC_4              (0x2UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC_8              (0x3UL << TIM_CCMR1_IC2PSC_Pos)

#define TIM_CCMR1_IC2F_Pos              (12U)
#define TIM_CCMR1_IC2F_Msk              (0xFUL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F                  TIM_CCMR1_IC2F_Msk
#define TIM_CCMR1_IC2F_0                (0x1UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_1                (0x2UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_2                (0x4UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_3                (0x8UL << TIM_CCMR1_IC2F_Pos)

/************** Bits definition for TIM_CCMR1 register (Output Mode) **************/
#define TIM_CCMR1_OC1FE_Pos             (2U)
#define TIM_CCMR1_OC1FE_Msk             (0x1UL << TIM_CCMR1_OC1FE_Pos)
#define TIM_CCMR1_OC1FE                 TIM_CCMR1_OC1FE_Msk

#define TIM_CCMR1_OC1PE_Pos             (3U)
#define TIM_CCMR1_OC1PE_Msk             (0x1UL << TIM_CCMR1_OC1PE_Pos)
#define TIM_CCMR1_OC1PE                 TIM_CCMR1_OC1PE_Msk

#define TIM_CCMR1_OC1M_Pos              (4U)
#define TIM_CCMR1_OC1M_Msk              (0x7UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M                  TIM_CCMR1_OC1M_Msk
#define TIM_CCMR1_OC1M_FROZEN           (0x0UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_ACTIVE           (0x1UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_INACTIVE         (0x2UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_TOGGLE           (0x3UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_FORCE_INACTIVE   (0x4UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_FORCE_ACTIVE     (0x5UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_PWM_ONE          (0x6UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_PWM_TWO          (0x7UL << TIM_CCMR1_OC1M_Pos)

#define TIM_CCMR1_OC1CE_Pos             (7U)
#define TIM_CCMR1_OC1CE_Msk             (0x1UL << TIM_CCMR1_OC1CE_Pos)
#define TIM_CCMR1_OC1CE                 TIM_CCMR1_OC1CE_Msk

#define TIM_CCMR1_OC2FE_Pos             (10U)
#define TIM_CCMR1_OC2FE_Msk             (0x1UL << TIM_CCMR1_OC2FE_Pos)
#define TIM_CCMR1_OC2FE                 TIM_CCMR1_OC2FE_Msk

#define TIM_CCMR1_OC2PE_Pos             (11U)
#define TIM_CCMR1_OC2PE_Msk             (0x1UL << TIM_CCMR1_OC2PE_Pos)
#define TIM_CCMR1_OC2PE                 TIM_CCMR1_OC2PE_Msk

#define TIM_CCMR1_OC2M_Pos              (12U)
#define TIM_CCMR1_OC2M_Msk              (0x7UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M                  TIM_CCMR1_OC2M_Msk
#define TIM_CCMR1_OC2M_FROZEN           (0x0UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_ACTIVE           (0x1UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_INACTIVE         (0x2UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_TOGGLE           (0x3UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_FORCE_INACTIVE   (0x4UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_FORCE_ACTIVE     (0x5UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_PWM_ONE          (0x6UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_PWM_TWO          (0x7UL << TIM_CCMR1_OC2M_Pos)

#define TIM_CCMR1_OC2CE_Pos             (15U)
#define TIM_CCMR1_OC2CE_Msk             (0x7UL << TIM_CCMR1_OC2CE_Pos)
#define TIM_CCMR1_OC2CE                 TIM_CCMR1_OC2CE_Msk

/*************** Bits definition for TIM_CCMR2 register (Selection) ***************/
#define TIM_CCMR2_CC3S_Pos              (0U)
#define TIM_CCMR2_CC3S_Msk              (0x3UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S                  TIM_CCMR2_CC3S_Msk
#define TIM_CCMR2_CC3S_OUT              (0x0UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S_TI3              (0x1UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S_TI4              (0x2UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S_TRC              (0x3UL << TIM_CCMR2_CC3S_Pos)

#define TIM_CCMR2_CC4S_Pos              (8U)
#define TIM_CCMR2_CC4S_Msk              (0x3UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S                  TIM_CCMR2_CC4S_Msk
#define TIM_CCMR2_CC4S_OUT              (0x0UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S_TI4              (0x1UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S_TI3              (0x2UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S_TRC              (0x3UL << TIM_CCMR2_CC4S_Pos)

/*************** Bits definition for TIM_CCMR2 register (Input Mode) **************/
#define TIM_CCMR2_IC3PSC_Pos            (2U)
#define TIM_CCMR2_IC3PSC_Msk            (0x3UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC                TIM_CCMR2_IC3PSC_Msk
#define TIM_CCMR2_IC3PSC_ZERO           (0x0UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC_TWO            (0x1UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC_FOUR           (0x2UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC_EIGHT          (0x3UL << TIM_CCMR2_IC3PSC_Pos)

#define TIM_CCMR2_IC3F_Pos              (4U)
#define TIM_CCMR2_IC3F_Msk              (0xFUL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F                  TIM_CCMR2_IC3F_Msk
#define TIM_CCMR2_IC3F_NOFILTER         (0x0UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_0                (0x1UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_1                (0x2UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_2                (0x4UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_3                (0x8UL << TIM_CCMR2_IC3F_Pos)

#define TIM_CCMR2_IC4PSC_Pos            (10U)
#define TIM_CCMR2_IC4PSC_Msk            (0x3UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC                TIM_CCMR2_IC4PSC_Msk
#define TIM_CCMR2_IC4PSC_ZERO           (0x0UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC_TWO            (0x1UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC_FOUR           (0x2UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC_EIGHT          (0x3UL << TIM_CCMR2_IC4PSC_Pos)

#define TIM_CCMR2_IC4F_Pos              (12U)
#define TIM_CCMR2_IC4F_Msk              (0xFUL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F                  TIM_CCMR2_IC4F_Msk
#define TIM_CCMR2_IC4F_NOFILTER         (0x0UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_0                (0x1UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_1                (0x2UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_2                (0x4UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_3                (0x8UL << TIM_CCMR2_IC4F_Pos)

/************** Bits definition for TIM_CCMR2 register (Output Mode) **************/
#define TIM_CCMR2_OC3FE_Pos             (2U)
#define TIM_CCMR2_OC3FE_Msk             (0x1UL << TIM_CCMR2_OC3FE_Pos)
#define TIM_CCMR2_OC3FE                 TIM_CCMR2_OC3FE_Msk

#define TIM_CCMR2_OC3PE_Pos             (3U)
#define TIM_CCMR2_OC3PE_Msk             (0x1UL << TIM_CCMR2_OC3PE_Pos)
#define TIM_CCMR2_OC3PE                 TIM_CCMR2_OC3PE_Msk

#define TIM_CCMR2_OC3M_Pos              (4U)
#define TIM_CCMR2_OC3M_Msk              (0x7UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M                  TIM_CCMR2_OC3M_Msk
#define TIM_CCMR2_OC3M_FROZEN           (0x0UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_ACTIVE           (0x1UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_INACTIVE         (0x2UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_TOGGLE           (0x3UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_FORCE_INACTIVE   (0x4UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_FORCE_ACTIVE     (0x5UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_PWM_ONE          (0x6UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_PWM_TWO          (0x7UL << TIM_CCMR2_OC3M_Pos)

#define TIM_CCMR2_OC3CE_Pos             (7U)
#define TIM_CCMR2_OC3CE_Msk             (0x1UL << TIM_CCMR2_OC3CE_Pos)
#define TIM_CCMR2_OC3CE                 TIM_CCMR2_OC3CE_Msk

#define TIM_CCMR2_OC4FE_Pos             (10U)
#define TIM_CCMR2_OC4FE_Msk             (0x1UL << TIM_CCMR2_OC4FE_Pos)
#define TIM_CCMR2_OC4FE                 TIM_CCMR2_OC4FE_Msk

#define TIM_CCMR2_OC4PE_Pos             (11U)
#define TIM_CCMR2_OC4PE_Msk             (0x1UL << TIM_CCMR2_OC4PE_Pos)
#define TIM_CCMR2_OC4PE                 TIM_CCMR2_OC4PE_Msk

#define TIM_CCMR2_OC4M_Pos              (12U)
#define TIM_CCMR2_OC4M_Msk              (0x7UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M                  TIM_CCMR2_OC4M_Msk
#define TIM_CCMR2_OC4M_FROZEN           (0x0UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_ACTIVE           (0x1UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_INACTIVE         (0x2UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_TOGGLE           (0x3UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_FORCE_INACTIVE   (0x4UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_FORCE_ACTIVE     (0x5UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_PWM_ONE          (0x6UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_PWM_TWO          (0x7UL << TIM_CCMR2_OC4M_Pos)

#define TIM_CCMR2_OC4CE_Pos             (15U)
#define TIM_CCMR2_OC4CE_Msk             (0x1UL << TIM_CCMR2_OC4CE_Pos)
#define TIM_CCMR2_OC4CE                 TIM_CCMR2_OC4CE_Msk

/********************** Bits definition for TIM_CCER register *********************/
#define TIM_CCER_CC1E_Pos               (0U)
#define TIM_CCER_CC1E_Msk               (0x1UL << TIM_CCER_CC1E_Pos)
#define TIM_CCER_CC1E                   TIM_CCER_CC1E_Msk

#define TIM_CCER_CC1P_Pos               (1U)
#define TIM_CCER_CC1P_Msk               (0x1UL << TIM_CCER_CC1P_Pos)
#define TIM_CCER_CC1P                   TIM_CCER_CC1P_Msk

#define TIM_CCER_CC1NE_Pos              (2U)
#define TIM_CCER_CC1NE_Msk              (0x1UL << TIM_CCER_CC1NE_Pos)
#define TIM_CCER_CC1NE                  TIM_CCER_CC1NE_Msk

#define TIM_CCER_CC1NP_Pos              (3U)
#define TIM_CCER_CC1NP_Msk              (0x1UL << TIM_CCER_CC1NP_Pos)
#define TIM_CCER_CC1NP                  TIM_CCER_CC1NP_Msk

#define TIM_CCER_CC2E_Pos               (4U)
#define TIM_CCER_CC2E_Msk               (0x1UL << TIM_CCER_CC2E_Pos)
#define TIM_CCER_CC2E                   TIM_CCER_CC2E_Msk

#define TIM_CCER_CC2P_Pos               (5U)
#define TIM_CCER_CC2P_Msk               (0x1UL << TIM_CCER_CC2P_Pos)
#define TIM_CCER_CC2P                   TIM_CCER_CC2P_Msk

#define TIM_CCER_CC2NE_Pos              (6U)
#define TIM_CCER_CC2NE_Msk              (0x1UL << TIM_CCER_CC2NE_Pos)
#define TIM_CCER_CC2NE                  TIM_CCER_CC2NE_Msk

#define TIM_CCER_CC2NP_Pos              (7U)
#define TIM_CCER_CC2NP_Msk              (0x1UL << TIM_CCER_CC2NP_Pos)
#define TIM_CCER_CC2NP                  TIM_CCER_CC2NP_Msk

#define TIM_CCER_CC3E_Pos               (8U)
#define TIM_CCER_CC3E_Msk               (0x1UL << TIM_CCER_CC3E_Pos)
#define TIM_CCER_CC3E                   TIM_CCER_CC3E_Msk

#define TIM_CCER_CC3P_Pos               (9U)
#define TIM_CCER_CC3P_Msk               (0x1UL << TIM_CCER_CC3P_Pos)
#define TIM_CCER_CC3P                   TIM_CCER_CC3P_Msk

#define TIM_CCER_CC3NE_Pos              (10U)
#define TIM_CCER_CC3NE_Msk              (0x1UL << TIM_CCER_CC3NE_Pos)
#define TIM_CCER_CC3NE                  TIM_CCER_CC3NE_Msk

#define TIM_CCER_CC3NP_Pos              (11U)
#define TIM_CCER_CC3NP_Msk              (0x1UL << TIM_CCER_CC3NP_Pos)
#define TIM_CCER_CC3NP                  TIM_CCER_CC3NP_Msk

#define TIM_CCER_CC4E_Pos               (12U)
#define TIM_CCER_CC4E_Msk               (0x1UL << TIM_CCER_CC4E_Pos)
#define TIM_CCER_CC4E                   TIM_CCER_CC4E_Msk

#define TIM_CCER_CC4P_Pos               (13U)
#define TIM_CCER_CC4P_Msk               (0x1UL << TIM_CCER_CC4P_Pos)
#define TIM_CCER_CC4P                   TIM_CCER_CC4P_Msk

/********************** Bits definition for TIM_CNT register **********************/
#define TIM_CNT_Pos                     (0U)
#define TIM_CNT_Msk                     (0xFFFFFFFFUL << TIM_CNT_Pos)
#define TIM_CNT                         TIM_CNT_Msk

/********************** Bits definition for TIM_PSC register **********************/
#define TIM_PSC_Pos                     (0U)
#define TIM_PSC_Msk                     (0xFFFFFFFFUL << TIM_PSC_Pos)
#define TIM_PSC                         TIM_PSC_Msk

/********************** Bits definition for TIM_ARR register **********************/
#define TIM_ARR_Pos                     (0U)
#define TIM_ARR_Msk                     (0xFFFFFFFFUL << TIM_ARR_Pos)
#define TIM_ARR                         TIM_ARR_Msk

/********************** Bits definition for TIM_RCR register **********************/
#define TIM_RCR_Pos                     (0U)
#define TIM_RCR_Msk                     (0xFFUL << TIM_RCR_Pos)
#define TIM_RCR                         TIM_RCR_Msk

/********************** Bits definition for TIM_CCR1 register *********************/
#define TIM_CCR1_Pos                    (0U)
#define TIM_CCR1_Msk                    (0xFFFFUL << TIM_CCR1_Pos)
#define TIM_CCR1                        TIM_CCR1_Msk

/********************** Bits definition for TIM_CCR2 register *********************/
#define TIM_CCR2_Pos                    (0U)
#define TIM_CCR2_Msk                    (0xFFFFUL << TIM_CCR2_Pos)
#define TIM_CCR2                        TIM_CCR2_Msk

/********************** Bits definition for TIM_CCR3 register *********************/
#define TIM_CCR3_Pos                    (0U)
#define TIM_CCR3_Msk                    (0xFFFFUL << TIM_CCR3_Pos)
#define TIM_CCR3                        TIM_CCR3_Msk

/********************** Bits definition for TIM_CCR4 register *********************/
#define TIM_CCR4_Pos                    (0U)
#define TIM_CCR4_Msk                    (0xFFFFUL << TIM_CCR4_Pos)
#define TIM_CCR4                        TIM_CCR4_Msk

/********************** Bits definition for TIM_BDTR register *********************/
#define TIM_BDTR_DTG_Pos                (0U)
#define TIM_BDTR_DTG_Msk                (0xFFUL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG                    TIM_BDTR_DTG_Msk
#define TIM_BDTR_DTG_0                  (0x01UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_1                  (0x02UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_2                  (0x04UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_3                  (0x08UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_4                  (0x10UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_5                  (0x20UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_6                  (0x40UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_7                  (0x80UL << TIM_BDTR_DTG_Pos)

#define TIM_BDTR_LOCK_Pos               (8U)
#define TIM_BDTR_LOCK_Msk               (0x3UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK                   TIM_BDTR_LOCK_Msk
#define TIM_BDTR_LOCK_OFF               (0x0UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK_ONE               (0x1UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK_TWO               (0x2UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK_THREE             (0x3UL << TIM_BDTR_LOCK_Pos)

#define TIM_BDTR_OSSI_Pos               (10U)
#define TIM_BDTR_OSSI_Msk               (0x1UL << TIM_BDTR_OSSI_Pos)
#define TIM_BDTR_OSSI                   TIM_BDTR_OSSI_Msk

#define TIM_BDTR_OSSR_Pos               (11U)
#define TIM_BDTR_OSSR_Msk               (0x1UL << TIM_BDTR_OSSR_Pos)
#define TIM_BDTR_OSSR                   TIM_BDTR_OSSR_Msk

#define TIM_BDTR_BKE_Pos                (12U)
#define TIM_BDTR_BKE_Msk                (0x1UL << TIM_BDTR_BKE_Pos)
#define TIM_BDTR_BKE                    TIM_BDTR_BKE_Msk

#define TIM_BDTR_BKP_Pos                (13U)
#define TIM_BDTR_BKP_Msk                (0x1UL << TIM_BDTR_BKP_Pos)
#define TIM_BDTR_BKP                    TIM_BDTR_BKP_Msk

#define TIM_BDTR_AOE_Pos                (14U)
#define TIM_BDTR_AOE_Msk                (0x1UL << TIM_BDTR_AOE_Pos)
#define TIM_BDTR_AOE                    TIM_BDTR_AOE_Msk

#define TIM_BDTR_MOE_Pos                (15U)
#define TIM_BDTR_MOE_Msk                (0x1UL << TIM_BDTR_MOE_Pos)
#define TIM_BDTR_MOE                    TIM_BDTR_MOE_Msk

/********************** Bits definition for TIM_DCR register **********************/
#define TIM_DCR_DBA_Pos                 (0U)
#define TIM_DCR_DBA_Msk                 (0x1FUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA                     TIM_DCR_DBA_Msk
#define TIM_DCR_DBA_CR1                 (0x00UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CR2                 (0x01UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_SMCR                (0x02UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_DIER                (0x03UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_SR                  (0x04UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_EGR                 (0x05UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCMR1               (0x06UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCMR2               (0x07UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCER                (0x08UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CNT                 (0x09UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_PSC                 (0x0AUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_ARR                 (0x0BUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_RCR                 (0x0CUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCR1                (0x0DUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCR2                (0x0EUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCR3                (0x0FUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_CCR4                (0x10UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_BDTR                (0x11UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_DCR                 (0x12UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_DMAR                (0x13UL << TIM_DCR_DBA_Pos)

#define TIM_DCR_DBL_Pos                 (8U)
#define TIM_DCR_DBL_Msk                 (0x1FUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL                     TIM_DCR_DBL_Msk
#define TIM_DCR_DBL_1                   (0x00UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_2                   (0x01UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_3                   (0x02UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_4                   (0x03UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_5                   (0x04UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_6                   (0x05UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_7                   (0x06UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_8                   (0x07UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_9                   (0x08UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_10                  (0x09UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_11                  (0x0AUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_12                  (0x0BUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_13                  (0x0CUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_14                  (0x0DUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_15                  (0x0EUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_16                  (0x0FUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_17                  (0x10UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_18                  (0x11UL << TIM_DCR_DBL_Pos)

/********************** Bits definition for TIM_DMAR register *********************/
#define TIM_DMAR_Pos                    (0U)
#define TIM_DMAR_Msk                    (0xFFFFUL << TIM_DMAR_Pos)
#define TIM_DMAR                        TIM_DMAR_Msk


/**********************************************************************************/
/*                                                                                */
/*                                      USART                                     */
/*                                                                                */
/**********************************************************************************/

/*********************** Bits definition for TIM_SR register **********************/
#define USART_SR_PE_Pos                 (0U)
#define USART_SR_PE_Msk                 (0x1UL << USART_SR_PE_Pos)
#define USART_SR_PE                     USART_SR_PE_Msk

#define USART_SR_FE_Pos                 (1U)
#define USART_SR_FE_Msk                 (0x1UL << USART_SR_FE_Pos)
#define USART_SR_FE                     USART_SR_FE_Msk

#define USART_SR_NF_Pos                 (2U)
#define USART_SR_NF_Msk                 (0x1UL << USART_SR_NF_Pos)
#define USART_SR_NF                     USART_SR_NF_Msk

#define USART_SR_ORE_Pos                (3U)
#define USART_SR_ORE_Msk                (0x1UL << USART_SR_ORE_Pos)
#define USART_SR_ORE                    USART_SR_ORE_Msk

#define USART_SR_IDLE_Pos               (4U)
#define USART_SR_IDLE_Msk               (0x1UL << USART_SR_IDLE_Pos)
#define USART_SR_IDLE                   USART_SR_IDLE_Msk

#define USART_SR_RXNE_Pos               (5U)
#define USART_SR_RXNE_Msk               (0x1UL << USART_SR_RXNE_Pos)
#define USART_SR_RXNE                   USART_SR_RXNE_Msk

#define USART_SR_TC_Pos                 (6U)
#define USART_SR_TC_Msk                 (0x1UL << USART_SR_TC_Pos)
#define USART_SR_TC                     USART_SR_TC_Msk

#define USART_SR_TXE_Pos                (7U)
#define USART_SR_TXE_Msk                (0x1UL << USART_SR_TXE_Pos)
#define USART_SR_TXE                    USART_SR_TXE_Msk

#define USART_SR_LBD_Pos                (8U)
#define USART_SR_LBD_Msk                (0x1UL << USART_SR_LBD_Pos)
#define USART_SR_LBD                    USART_SR_LBD_Msk

#define USART_SR_CTS_Pos                (9U)
#define USART_SR_CTS_Msk                (0x1UL << USART_SR_CTS_Pos)
#define USART_SR_CTS                    USART_SR_CTS_Msk

/*********************** Bits definition for TIM_DR register **********************/
#define USART_DR_Pos                    (0U)
#define USART_DR_Msk                    (0x1FFUL << USART_DR_Pos)
#define USART_DR                        USART_DR_Msk

/********************** Bits definition for TIM_BRR register **********************/
#define USART_BRR_DIV_FRACTION_Pos      (0U)
#define USART_BRR_DIV_FRACTION_Msk      (0xFUL << USART_BRR_DIV_FRACTION_Pos)
#define USART_BRR_DIV_FRACTION          USART_BRR_DIV_FRACTION_Msk

#define USART_BRR_DIV_MANTISSA_Pos      (4U)
#define USART_BRR_DIV_MANTISSA_Msk      (0xFFFUL << USART_BRR_DIV_MANTISSA_Pos)
#define USART_BRR_DIV_MANTISSA          USART_BRR_DIV_MANTISSA_Msk

/********************** Bits definition for TIM_CR1 register **********************/
#define USART_CR1_SBK_Pos               (0U)
#define USART_CR1_SBK_Msk               (0x1UL << USART_CR1_SBK_Pos)
#define USART_CR1_SBK                   USART_CR1_SBK_Msk

#define USART_CR1_RWU_Pos               (1U)
#define USART_CR1_RWU_Msk               (0x1UL << USART_CR1_RWU_Pos)
#define USART_CR1_RWU                   USART_CR1_RWU_Msk

#define USART_CR1_RE_Pos                (2U)
#define USART_CR1_RE_Msk                (0x1UL << USART_CR1_RE_Pos)
#define USART_CR1_RE                    USART_CR1_RE_Msk

#define USART_CR1_TE_Pos                (3U)
#define USART_CR1_TE_Msk                (0x1UL << USART_CR1_TE_Pos)
#define USART_CR1_TE                    USART_CR1_TE_Msk

#define USART_CR1_IDLEIE_Pos            (4U)
#define USART_CR1_IDLEIE_Msk            (0x1UL << USART_CR1_IDLEIE_Pos)
#define USART_CR1_IDLEIE                USART_CR1_IDLEIE_Msk

#define USART_CR1_RXNEIE_Pos            (5U)
#define USART_CR1_RXNEIE_Msk            (0x1UL << USART_CR1_RXNEIE_Pos)
#define USART_CR1_RXNEIE                USART_CR1_RXNEIE_Msk

#define USART_CR1_TCIE_Pos              (6U)
#define USART_CR1_TCIE_Msk              (0x1UL << USART_CR1_TCIE_Pos)
#define USART_CR1_TCIE                  USART_CR1_TCIE_Msk

#define USART_CR1_TXEIE_Pos             (7U)
#define USART_CR1_TXEIE_Msk             (0x1UL << USART_CR1_TXEIE_Pos)
#define USART_CR1_TXEIE                 USART_CR1_TXEIE_Msk

#define USART_CR1_PEIE_Pos              (8U)
#define USART_CR1_PEIE_Msk              (0x1UL << USART_CR1_PEIE_Pos)
#define USART_CR1_PEIE                  USART_CR1_PEIE_Msk

#define USART_CR1_PS_Pos                (9U)
#define USART_CR1_PS_Msk                (0x1UL << USART_CR1_PS_Pos)
#define USART_CR1_PS                    USART_CR1_PS_Msk

#define USART_CR1_PCE_Pos               (10U)
#define USART_CR1_PCE_Msk               (0x1UL << USART_CR1_PCE_Pos)
#define USART_CR1_PCE                   USART_CR1_PCE_Msk

#define USART_CR1_WAKE_Pos              (11U)
#define USART_CR1_WAKE_Msk              (0x1UL << USART_CR1_WAKE_Pos)
#define USART_CR1_WAKE                  USART_CR1_WAKE_Msk

#define USART_CR1_M_Pos                 (12U)
#define USART_CR1_M_Msk                 (0x1UL << USART_CR1_M_Pos)
#define USART_CR1_M                     USART_CR1_M_Msk

#define USART_CR1_UE_Pos                (13U)
#define USART_CR1_UE_Msk                (0x1UL << USART_CR1_UE_Pos)
#define USART_CR1_UE                    USART_CR1_UE_Msk

#define USART_CR1_OVER8_Pos             (15U)
#define USART_CR1_OVER8_Msk             (0x1UL << USART_CR1_OVER8_Pos)
#define USART_CR1_OVER8                 USART_CR1_OVER8_Msk

/********************** Bits definition for TIM_CR2 register **********************/
#define USART_CR2_ADD_Pos               (0U)
#define USART_CR2_ADD_Msk               (0x7UL << USART_CR2_ADD_Pos)
#define USART_CR2_ADD                   USART_CR2_ADD_Msk

#define USART_CR2_LBDL_Pos              (5U)
#define USART_CR2_LBDL_Msk              (0x1UL << USART_CR2_LBDL_Pos)
#define USART_CR2_LBDL                  USART_CR2_LBDL_Msk

#define USART_CR2_LBDIE_Pos             (6U)
#define USART_CR2_LBDIE_Msk             (0x1UL << USART_CR2_LBDIE_Pos)
#define USART_CR2_LBDIE                 USART_CR2_LBDIE_Msk

#define USART_CR2_LBCL_Pos              (8U)
#define USART_CR2_LBCL_Msk              (0x1UL << USART_CR2_LBCL_Pos)
#define USART_CR2_LBCL                  USART_CR2_LBCL_Msk

#define USART_CR2_CPHA_Pos              (9U)
#define USART_CR2_CPHA_Msk              (0x1UL << USART_CR2_CPHA_Pos)
#define USART_CR2_CPHA                  USART_CR2_CPHA_Msk

#define USART_CR2_CPOL_Pos              (10U)
#define USART_CR2_CPOL_Msk              (0x1UL << USART_CR2_CPOL_Pos)
#define USART_CR2_CPOL                  USART_CR2_CPOL_Msk

#define USART_CR2_CLKEN_Pos             (11U)
#define USART_CR2_CLKEN_Msk             (0x1U << USART_CR2_CLKEN_Pos)
#define USART_CR2_CLKEN                 USART_CR2_CLKEN_Msk

#define USART_CR2_STOP_Pos              (12U)
#define USART_CR2_STOP_Msk              (0x1UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP                  USART_CR2_STOP_Msk
#define USART_CR2_STOP_1                (0x0UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP_0_5              (0X1UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP_2                (0x2UL << USART_CR2_STOP_Pos)

#define USART_CR2_LINEN_Pos             (14U)
#define USART_CR2_LINEN_Msk             (0x1UL << USART_CR2_LINEN_Pos)
#define USART_CR2_LINEN                 USART_CR2_LINEN_Msk

/********************** Bits definition for TIM_CR3 register **********************/
#define USART_CR3_EIE_Pos               (0U)
#define USART_CR3_EIE_Msk               (0x1UL << USART_CR3_EIE_Pos)
#define USART_CR3_EIE                   USART_CR3_EIE_Msk

#define USART_CR3_IREN_Pos              (1U)
#define USART_CR3_IREN_Msk              (0x1UL << USART_CR3_IREN_Pos)
#define USART_CR3_IREN                  USART_CR3_IREN_Msk

#define USART_CR3_IRLP_Pos              (2U)
#define USART_CR3_IRLP_Msk              (0x1UL << USART_CR3_IRLP_Pos)
#define USART_CR3_IRLP                  USART_CR3_IRLP_Msk

#define USART_CR3_HDSEL_Pos             (3U)
#define USART_CR3_HDSEL_Msk             (0x1UL << USART_CR3_HDSEL_Pos)
#define USART_CR3_HDSEL                 USART_CR3_HDSEL_Msk

#define USART_CR3_NACK_Pos              (4U)
#define USART_CR3_NACK_Msk              (0x1UL << USART_CR3_NACK_Pos)
#define USART_CR3_NACK                  USART_CR3_NACK_Msk

#define USART_CR3_SCEN_Pos              (5U)
#define USART_CR3_SCEN_Msk              (0x1UL << USART_CR3_SCEN_Pos)
#define USART_CR3_SCEN                  USART_CR3_SCEN_Msk

#define USART_CR3_DMAR_Pos              (6U)
#define USART_CR3_DMAR_Msk              (0x1UL << USART_CR3_DMAR_Pos)
#define USART_CR3_DMAR                  USART_CR3_DMAR_Msk

#define USART_CR3_DMAT_Pos              (7U)
#define USART_CR3_DMAT_Msk              (0x1UL << USART_CR3_DMAT_Pos)
#define USART_CR3_DMAT                  USART_CR3_DMAT_Msk

#define USART_CR3_RTSE_Pos              (8U)
#define USART_CR3_RTSE_Msk              (0x1UL << USART_CR3_RTSE_Pos)
#define USART_CR3_RTSE                  USART_CR3_RTSE_Msk

#define USART_CR3_CTSE_Pos              (9U)
#define USART_CR3_CTSE_Msk              (0x1UL << USART_CR3_CTSE_Pos)
#define USART_CR3_CTSE                  USART_CR3_CTSE_Msk

#define USART_CR3_CTSIE_Pos             (10U)
#define USART_CR3_CTSIE_Msk             (0x1UL << USART_CR3_CTSIE_Pos)
#define USART_CR3_CTSIE                 USART_CR3_CTSIE_Msk

#define USART_CR3_ONEBIT_Pos            (11U)
#define USART_CR3_ONEBIT_Msk            (0x1UL << USART_CR3_ONEBIT_Pos)
#define USART_CR3_ONEBIT                USART_CR3_ONEBIT_Msk

/********************** Bits definition for TIM_GTPR register *********************/
#define USART_GTPR_PSC_Pos              (0U)
#define USART_GTPR_PSC_Msk              (0xFFUL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC                  USART_GTPR_PSC_Msk

#define USART_GTPR_GT_Pos               (8U)
#define USART_GTPR_GT_Msk               (0xFFUL << USART_GTPR_GT_Pos)
#define USART_GTPR_GT                   USART_GTPR_GT_Msk





/* end C linkage and return to C++ linkage */
#ifdef __cplusplus
}
#endif

/* end header guard */
#endif

