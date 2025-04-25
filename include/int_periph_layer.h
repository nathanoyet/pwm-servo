/* Internal Peripheral Layer for the ARM Cortex-M4
This file contains:
- Data structures and the address mapping for all internal peripherals 
- Internal peripherals' registers declarations and bits definition
- Macros to access internal peripherals' registers hardware

The internal peripheral layer also includes Armv7-M Architecture registers not included in
the Cortex-M4 Generic User Guide but included in the Armv7-M Architecture Reference Manual
*/

/* start header guard */
#ifndef __INT_PERIPH_LAYER_H
#define __INT_PERIPH_LAYER_H

/* start C linkage for C++ compiler */
#ifdef __cplusplus
    extern "C" {
#endif


#include <stdint.h>


/**********************************************************************************/
/*                Internal Peripheral Registers Structures Definition             */
/**********************************************************************************/

/****************** SCB Peripheral register structure definition ******************/
typedef struct {
    volatile const uint32_t CPUID;
    volatile uint32_t ICSR;
    volatile uint32_t VTOR;
    volatile uint32_t AIRCR;
    volatile uint32_t SCR;
    volatile uint32_t CCR;
    volatile uint8_t SHPR[12];
    volatile uint32_t SHCRS;
    volatile uint32_t CFSR;
    volatile uint32_t HFSR;
    volatile uint32_t DFSR;
    volatile uint32_t MMAR;
    volatile uint32_t BFAR;
    volatile uint32_t AFSR;
    volatile const uint32_t PFR[2];
    volatile const uint32_t DFR;
    volatile const uint32_t ADR;
    volatile const uint32_t MMFR[4];
    volatile const uint32_t ISAR[5];
    uint32_t RESERVED[5];
    volatile uint32_t CPACR;
} SCB_TypeDef;

/***************** SCNSCB Peripheral register structure definition ****************/
typedef struct {
    uint32_t RESERVED[2];
    volatile uint32_t ACTLR; 
} SCNSCB_TypeDef;


/***************** NVIC Peripheral register structure definition ******************/
typedef struct {
    volatile uint32_t ISER[8];
    uint32_t RESERVED_0[24];
    volatile uint32_t ICER[8];
    uint32_t RESERVED_1[24];
    volatile uint32_t ISPR[8];
    uint32_t RESERVED_2[24];
    volatile uint32_t ICPR[8];
    uint32_t RESERVED_3[24];
    volatile uint32_t IABR[8];
    uint32_t RESERVED_4[56];
    volatile uint8_t IPR[240];
    volatile uint32_t STIR;
} NVIC_TypeDef;

/******** System Timer (SYSTICK) Peripheral register structure definition *********/
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile const uint32_t CALIB;
} SYSTICK_TypeDef;



/**********************************************************************************/
/*                         Internal Peripheral Declaration                        */
/**********************************************************************************/

#define SCB                         ((SCB_TypeDef *) SCB_BASE)
#define SCNSCB                      ((SCNSCB_TypeDef *) SCS_BASE)
#define SYSTICK                     ((SYSTICK_TypeDef *) SYSTICK_BASE)
#define NVIC                        ((NVIC_TypeDef *) NVIC_BASE)



/**********************************************************************************/
/*                 Internal Peripheral Registers Memory Map Definition            */
/**********************************************************************************/

#define SCS_BASE                    (0xE000E000UL)
#define ITM_BASE                    (0xE0000000UL)
#define DWT_BASE                    (0xE0001000UL)
#define TPI_BASE                    (0xE0040000UL)
#define CORE_DEBUG_BASE             (0xE000EDF0UL)
#define SYSTICK_BASE                (SCS_BASE + 0x0010UL)
#define NVIC_BASE                   (SCS_BASE + 0x0100UL)
#define SCB_BASE                    (SCS_BASE + 0x0D00UL)


/**********************************************************************************/
/*                    Internal Peripheral Registers Bits Definition               */
/**********************************************************************************/

/**********************************************************************************/
/*                                                                                */
/*                             SYSTEM CONTROL BLOCK (SCB)                         */
/*                                                                                */
/**********************************************************************************/

/********************* Bits definition for SCB_CPUID register *********************/
#define SCB_CPUID_REVISION_Pos      (0U)
#define SCB_CPUID_REVISION_Msk      (0xFUL << SCB_CPUID_REVISION_Pos)
#define SCB_CPUID_REVISION          SCB_CPUID_REVISION_Msk

#define SCB_CPUID_PARTNO_Pos        (4U)
#define SCB_CPUID_PARTNO_Msk        (0xFFFUL << SCB_CPUID_PARTNO_Pos)
#define SCB_CPUID_PARTNO            SCB_CPUID_PARTNO_Msk

#define SCB_CPUID_CONSTANT_Pos      (16U)
#define SCB_CPUID_CONSTANT_Msk      (0xFUL << SCB_CPUID_CONSTANT_Pos)
#define SCB_CPUID_CONSTANT          SCB_CPUID_CONSTANT_Msk

#define SCB_CPUID_VARIANT_Pos       (20U)
#define SCB_CPUID_VARIANT_Msk       (0xFUL << SCB_CPUID_VARIANT_Pos)
#define SCB_CPUID_VARIANT           SCB_CPUID_VARIANT_Msk

#define SCB_CPUID_IMPLEMENTER_Pos   (24U)
#define SCB_CPUID_IMPLEMENTER_Msk   (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)
#define SCB_CPUID_IMPLEMENTER       SCB_CPUID_IMPLEMENTER_Msk

/********************* Bits definition for SCB_ICSR register **********************/
#define SCB_ICSR_VECTACTIVE_Pos     (0U)
#define SCB_ICSR_VECTACTIVE_Msk     (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)
#define SCB_ICSR_VECTACTIVE         SCB_ICSR_VECTACTIVE_Msk

#define SCB_ICSR_RETTOBASE_Pos      (11U)
#define SCB_ICSR_RETTOBASE_Msk      (0x1UL << SCB_ICSR_RETTOBASE_Pos)
#define SCB_ICSR_RETTOBASE          SCB_ICSR_RETTOBASE_Msk

#define SCB_ICSR_VECTPENDING_Pos    (12U)
#define SCB_ICSR_VECTPENDING_Msk    (0x3FUL << SCB_ICSR_VECTPENDING_Pos)
#define SCB_ICSR_VECTPENDING        SCB_ICSR_VECTPENDING_Msk

#define SCB_ICSR_ISRPENDING_Pos     (22U)
#define SCB_ICSR_ISRPENDING_Msk     (0x1UL << SCB_ICSR_ISRPENDING_Pos)
#define SCB_ICSR_ISRPENDING         SCB_ICSR_ISRPENDING_Msk

#define SCB_ICSR_PENDSTCLR_Pos      (25U)
#define SCB_ICSR_PENDSTCLR_Msk      (0x1UL << SCB_ICSR_PENDSTCLR_Pos)
#define SCB_ICSR_PENDSTCLR          SCB_ICSR_PENDSTCLR_Msk

#define SCB_ICSR_PENDSTSET_Pos      (26U)
#define SCB_ICSR_PENDSTSET_Msk      (0x1UL << SCB_ICSR_PENDSTSET_Pos)
#define SCB_ICSR_PENDSTSET          SCB_ICSR_PENDSTSET_Msk

#define SCB_ICSR_PENDSVCLR_Pos      (27U)
#define SCB_ICSR_PENDSVCLR_Msk      (0x1UL << SCB_ICSR_PENDSVCLR_Pos)
#define SCB_ICSR_PENDSVCLR          SCB_ICSR_PENDSVCLR_Msk

#define SCB_ICSR_PENDSVSET_Pos      (28U)
#define SCB_ICSR_PENDSVSET_Msk      (0x1UL << SCB_ICSR_PENDSVSET_Pos)
#define SCB_ICSR_PENDSVSET          SCB_ICSR_PENDSVSET_Msk

#define SCB_ICSR_NMIPENDSET_Pos     (31U)
#define SCB_ICSR_NMIPENDSET_Msk     (0x1UL << SCB_ICSR_NMIPENDSET_Pos)
#define SCB_ICSR_NMIPENDSET         SCB_ICSR_NMIPENDSET_Msk

/********************* Bits definition for SCB_VTOR register **********************/
#define SCB_VTOR_TBLOFF_Pos         (7U)
#define SCB_VTOR_TBLOFF_Msk         (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)
#define SCB_VTOR_TBLOFF             SCB_VTOR_TBLOFF_Msk

/********************* Bits definition for SCB_AIRCR register *********************/
#define SCB_AIRCR_VECTRESET_Pos     (0U)
#define SCB_AIRCR_VECTRESET_Msk     (0x1UL << SCB_AIRCR_VECTRESET_Pos)
#define SCB_AIRCR_VECTRESET         SCB_AIRCR_VECTRESET_Msk

#define SCB_AIRCR_VECTCLRACTIVE_Pos (1U)
#define SCB_AIRCR_VECTCLRACTIVE_Msk (0x1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)
#define SCB_AIRCR_VECTCLRACTIVE     SCB_AIRCR_VECTCLRACTIVE_Msk

#define SCB_AIRCR_SYSRESETREQ_Pos   (2U)
#define SCB_AIRCR_SYSRESETREQ_Msk   (0x1UL << SCB_AIRCR_SYSRESETREQ_Pos)
#define SCB_AIRCR_SYSRESETREQ       SCB_AIRCR_SYSRESETREQ_Msk

#define SCB_AIRCR_PRIGROUP_Pos      (8U)
#define SCB_AIRCR_PRIGROUP_Msk      (0x7UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP          SCB_AIRCR_PRIGROUP_Msk
#define SCB_AIRCR_PRIGROUP_G7S1     (0x0UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G6S2     (0x1UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G5S3     (0x2UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G4S4     (0x3UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G3S5     (0x4UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G2S6     (0x5UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G1S7     (0x6UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP_G0S8     (0x7UL << SCB_AIRCR_PRIGROUP_Pos)

#define SCB_AIRCR_ENDIANNESS_Pos    (15U)
#define SCB_AIRCR_ENDIANNESS_Msk    (0x1UL << SCB_AIRCR_ENDIANNESS_Pos)
#define SCB_AIRCR_ENDIANNESS        SCB_AIRCR_ENDIANNESS_Msk

#define SCB_AIRCR_VECTKEY_Pos       (16U)
#define SCB_AIRCR_VECTKEY           (0x05FAUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEYSTAT       (0xFA05UL << SCB_AIRCR_VECTKEY_Pos)

/********************* Bits definition for SCB_SCR register ***********************/
#define SCB_SCR_SLEEPONEXIT_Pos     (1U)
#define SCB_SCR_SLEEPONEXIT_Msk     (0x1UL << SCB_SCR_SLEEPONEXIT_Pos)
#define SCB_SCR_SLEEPONEXIT         SCB_SCR_SLEEPONEXIT_Msk

#define SCB_SCR_SLEEPDEEP_Pos       (2U)
#define SCB_SCR_SLEEPDEEP_Msk       (0x1UL << SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SLEEPDEEP           SCB_SCR_SLEEPDEEP_Msk

#define SCB_SCR_SEVONPEND_Pos       (4U)
#define SCB_SCR_SEVONPEND_Msk       (0x1UL << SCB_SCR_SEVONPEND_Pos)
#define SCB_SCR_SEVONPEND          SCB_SCR_SEVONPEND_Msk

/********************* Bits definition for SCB_CCR register ***********************/
#define SCB_CCR_NONBASETHRDENA_Pos  (0U)
#define SCB_CCR_NONBASETHRDENA_Msk  (0x1UL << SCB_CCR_NONBASETHRDENA_Pos)
#define SCB_CCR_NONBASETHRDENA      SCB_CCR_NONBASETHRDENA_Msk

#define SCB_CCR_USERSETMPEND_Pos    (1U)
#define SCB_CCR_USERSETMPEND_Msk    (0x1UL << SCB_CCR_USERSETMPEND_Pos)
#define SCB_CCR_USERSETMPEND        SCB_CCR_USERSETMPEND_Msk

#define SCB_CCR_UNALIGN_TRP_Pos     (3U)
#define SCB_CCR_UNALIGN_TRP_Msk     (0x1UL << SCB_CCR_UNALIGN_TRP_Pos)
#define SCB_CCR_UNALIGN_TRP         SCB_CCR_UNALIGN_TRP_Msk

#define SCB_CCR_DIV_0_TRP_Pos       (4U)
#define SCB_CCR_DIV_0_TRP_Msk       (0x1UL << SCB_CCR_DIV_0_TRP_Pos)
#define SCB_CCR_DIV_0_TRP           SCB_CCR_DIV_0_TRP_Msk

#define SCB_CCR_BFHFNMIGN_Pos       (8U)
#define SCB_CCR_BFHFNMIGN_Msk       (0x1UL << SCB_CCR_BFHFNMIGN_Pos)
#define SCB_CCR_BFHFNMIGN           SCB_CCR_BFHFNMIGN_Msk

#define SCB_CCR_STKALIGN_Pos        (9U)
#define SCB_CCR_STKALIGN_Msk        (0x1UL << SCB_CCR_STKALIGN_Pos)
#define SCB_CCR_STKALIGN            SCB_CCR_STKALIGN_Msk

/********************* Bits definition for SCB_SHCSR register *********************/
#define SCB_SHCSR_MEMFAULTACT_Pos   (0U)
#define SCB_SHCSR_MEMFAULTACT_Msk   (0x1UL << SCB_SHCSR_MEMFAULTACT_Pos)
#define SCB_SHCSR_MEMFAULTACT       SCB_SHCSR_MEMFAULTACT_Msk

#define SCB_SHCSR_BUSFAULTACT_Pos   (1U)
#define SCB_SHCSR_BUSFAULTACT_Msk   (0x1UL << SCB_SHCSR_BUSFAULTACT_Pos)
#define SCB_SHCSR_BUSFAULTACT       SCB_SHCSR_BUSFAULTACT_Msk

#define SCB_SHCSR_USGFAULTACT_Pos   (3U)
#define SCB_SHCSR_USGFAULTACT_Msk   (0x1UL << SCB_SHCSR_USGFAULTACT_Pos)
#define SCB_SHCSR_USGFAULTACT       SCB_SHCSR_USGFAULTACT_Msk

#define SCB_SHCSR_SVCALLACT_Pos     (7U)
#define SCB_SHCSR_SVCALLACT_Msk     (0x1UL << SCB_SHCSR_SVCALLACT_Pos)
#define SCB_SHCSR_SVCALLACT         SCB_SHCSR_SVCALLACT_Msk

#define SCB_SHCSR_MONITORACT_Pos    (8U)
#define SCB_SHCSR_MONITORACT_Msk    (0x1UL << SCB_SHCSR_MONITORACT_Pos)
#define SCB_SHCSR_MONITORACT        SCB_SHCSR_MONITORACT_Msk

#define SCB_SHCSR_PENDSVACT_Pos     (10U)
#define SCB_SHCSR_PENDSVACT_Msk     (0x1UL << SCB_SHCSR_PENDSVACT_Pos)
#define SCB_SHCSR_PENDSVACT         SCB_SHCSR_PENDSVACT_Msk

#define SCB_SHCSR_SYSTICKACT_Pos    (11U)
#define SCB_SHCSR_SYSTICKACT_Msk    (0x1UL << SCB_SHCSR_SYSTICKACT_Pos)
#define SCB_SHCSR_SYSTICKACT        SCB_SHCSR_SYSTICKACT_Msk

#define SCB_SHCSR_USGFAULTPEND_Pos  (12U)
#define SCB_SHCSR_USGFAULTPEND_Msk  (0x1UL << SCB_SHCSR_USGFAULTPEND_Pos)
#define SCB_SHCSR_USGFAULTPEND      SCB_SHCSR_USGFAULTPEND_Msk

#define SCB_SHCSR_MEMFAULTPEND_Pos  (13U)
#define SCB_SHCSR_MEMFAULTPEND_Msk  (0x1UL << SCB_SHCSR_MEMFAULTPEND_Pos)
#define SCB_SHCSR_MEMFAULTPEND      SCB_SHCSR_MEMFAULTPEND_Msk

#define SCB_SHCSR_BUSFAULTPEND_Pos  (14U)
#define SCB_SHCSR_BUSFAULTPEND_Msk  (0x1UL << SCB_SHCSR_BUSFAULTPEND_Pos)
#define SCB_SHCSR_BUSFAULTPEND      SCB_SHCSR_BUSFAULTPEND_Msk

#define SCB_SHCSR_SVCALLPEND_Pos    (15U)
#define SCB_SHCSR_SVCALLPEND_Msk    (0x1UL << SCB_SHCSR_SVCALLPEND_Pos)
#define SCB_SHCSR_SVCALLPEND        SCB_SHCSR_SVCALLPEND_Msk

#define SCB_SHCSR_MEMFAULTENA_Pos   (16U)
#define SCB_SHCSR_MEMFAULTENA_Msk   (0x1UL << SCB_SHCSR_MEMFAULTENA_Pos)
#define SCB_SHCSR_MEMFAULTENA       SCB_SHCSR_MEMFAULTENA_Msk

#define SCB_SHCSR_BUSFAULTENA_Pos   (17U)
#define SCB_SHCSR_BUSFAULTENA_Msk   (0x1UL << SCB_SHCSR_BUSFAULTENA_Pos)
#define SCB_SHCSR_BUSFAULTENA       SCB_SHCSR_BUSFAULTENA_Msk

#define SCB_SHCSR_USGFAULTENA_Pos   (18U)
#define SCB_SHCSR_USGFAULTENA_Msk   (0x1UL << SCB_SHCSR_USGFAULTENA_Pos)
#define SCB_SHCSR_USGFAULTENA       SCB_SHCSR_USGFAULTENA_Msk

/********************* Bits definition for SCB_CFSR register **********************/
#define SCB_CFSR_MMFSR_Pos          (0U)
#define SCB_CFSR_MMFSR_Msk          (0xFFUL << SCB_CFSR_MMFSR_Pos)
#define SCB_CFSR_MMFSR              SCB_CFSR_MMFSR_Msk

#define SCB_CFSR_BFSR_Pos           (8U)
#define SCB_CFSR_BFSR_Msk           (0xFFUL << SCB_CFSR_BFSR_Pos)
#define SCB_CFSR_BFSR               SCB_CFSR_BFSR_Msk

#define SCB_CFSR_UFSR_Pos           (16U)
#define SCB_CFSR_UFSR_Msk           (0xFFUL << SCB_CFSR_UFSR_Pos)
#define SCB_CFSR_UFSR               SCB_CFSR_UFSR_Msk

/**************** Bits definition for SCB_CFSR register components ****************/
#define SCB_CFSR_IACCVIOL_Pos       (SCB_CFSR_MMFSR_Pos + 0U)
#define SCB_CFSR_IACCVIOL_Msk       (0x1UL << SCB_CFSR_IACCVIOL_Pos)
#define SCB_CFSR_IACCVIOL           SCB_CFSR_IACCVIOL_Msk

#define SCB_CFSR_DACCVIOL_Pos       (SCB_CFSR_MMFSR_Pos + 1U)
#define SCB_CFSR_DACCVIOL_Msk       (0x1UL << SCB_CFSR_DACCVIOL_Pos)
#define SCB_CFSR_DACCVIOL           SCB_CFSR_DACCVIOL_Msk

#define SCB_CFSR_MUNSTKERR_Pos      (SCB_CFSR_MMFSR_Pos + 3U)
#define SCB_CFSR_MUNSTKERR_Msk      (0x1UL << SCB_CFSR_MUNSTKERR_Pos)
#define SCB_CFSR_MUNSTKERR          SCB_CFSR_MUNSTKERR_Msk

#define SCB_CFSR_MSTKERR_Pos        (SCB_CFSR_MMFSR_Pos + 4U)
#define SCB_CFSR_MSTKERR_Msk        (0x1UL << SCB_CFSR_MSTKERR_Pos)
#define SCB_CFSR_MSTKERR            SCB_CFSR_MSTKERR_Msk

#define SCB_CFSR_MLSPERR_Pos        (SCB_CFSR_MMFSR_Pos + 5U)
#define SCB_CFSR_MLSPERR_Msk        (0x1UL << SCB_CFSR_MLSPERR_Pos)
#define SCB_CFSR_MLSPERR            SCB_CFSR_MLSPERR_Msk

#define SCB_CFSR_MMARVALID_Pos      (SCB_CFSR_MMFSR_Pos + 7U)
#define SCB_CFSR_MMARVALID_Msk      (0x1UL << SCB_CFSR_MMARVALID_Pos)
#define SCB_CFSR_MMARVALID          SCB_CFSR_MMARVALID_Msk

#define SCB_CFSR_IBUSERR_Pos        (SCB_CFSR_BFSR_Pos + 0U)
#define SCB_CFSR_IBUSERR_Msk        (0x1UL << SCB_CFSR_IBUSERR_Pos)
#define SCB_CFSR_IBUSERR            SCB_CFSR_IBUSERR_Msk

#define SCB_CFSR_PRECISERR_Pos      (SCB_CFSR_BFSR_Pos + 1U)
#define SCB_CFSR_PRECISERR_Msk      (0x1UL << SCB_CFSR_PRECISERR_Pos)
#define SCB_CFSR_PRECISERR          SCB_CFSR_PRECISERR_Msk

#define SCB_CFSR_IMPRECISERR_Pos    (SCB_CFSR_BFSR_Pos + 2U)
#define SCB_CFSR_IMPRECISERR_Msk    (0x1UL << SCB_CFSR_IMPRECISERR_Pos)
#define SCB_CFSR_IMPRECISERR        SCB_CFSR_IMPRECISERR_Msk

#define SCB_CFSR_UNSTKERR_Pos       (SCB_CFSR_BFSR_Pos + 3U)
#define SCB_CFSR_UNSTKERR_Msk       (0x1UL << SCB_CFSR_UNSTKERR_Pos)
#define SCB_CFSR_UNSTKERR           SCB_CFSR_UNSTKERR_Msk

#define SCB_CFSR_STKERR_Pos         (SCB_CFSR_BFSR_Pos + 4U)
#define SCB_CFSR_STKERR_Msk         (0x1UL << SCB_CFSR_STKERR_Pos)
#define SCB_CFSR_STKERR             SCB_CFSR_STKERR_Msk

#define SCB_CFSR_LSPERR_Pos         (SCB_CFSR_BFSR_Pos + 5U)
#define SCB_CFSR_LSPERR_Msk         (0x1UL << SCB_CFSR_LSPERR_Pos)
#define SCB_CFSR_LSPERR             SCB_CFSR_LSPERR_Msk

#define SCB_CFSR_BFARVALID_Pos      (SCB_CFSR_BFSR_Pos + 7U)
#define SCB_CFSR_BFARVALID_Msk      (0x1UL << SCB_CFSR_BFARVALID_Pos)
#define SCB_CFSR_BFARVALID          SCB_CFSR_BFARVALID_Msk

#define SCB_CFSR_UNDEFINSTR_Pos     (SCB_CFSR_UFSR_Pos + 0U)
#define SCB_CFSR_UNDEFINSTR_Msk     (0x1UL << SCB_CFSR_UNDEFINSTR_Pos)
#define SCB_CFSR_UNDEFINSTR         SCB_CFSR_UNDEFINSTR_Msk

#define SCB_CFSR_INVSTATE_Pos       (SCB_CFSR_UFSR_Pos + 1U)
#define SCB_CFSR_INVSTATE_Msk       (0x1UL << SCB_CFSR_INVSTATE_Pos)
#define SCB_CFSR_INVSTATE           SCB_CFSR_INVSTATE_Msk

#define SCB_CFSR_INVPC_Pos          (SCB_CFSR_UFSR_Pos + 2U)
#define SCB_CFSR_INVPC_Msk          (0x1UL << SCB_CFSR_INVPC_Pos)
#define SCB_CFSR_INVPC              SCB_CFSR_INVPC_Msk

#define SCB_CFSR_NOCP_Pos           (SCB_CFSR_UFSR_Pos + 3U)
#define SCB_CFSR_NOCP_Msk           (0x1UL << SCB_CFSR_NOCP_Pos)
#define SCB_CFSR_NOCP               SCB_CFSR_NOCP_Msk

#define SCB_CFSR_UNALIGNED_Pos      (SCB_CFSR_UFSR_Pos + 8U)
#define SCB_CFSR_UNALIGNED_Msk      (0x1UL << SCB_CFSR_UNALIGNED_Pos)
#define SCB_CFSR_UNALIGNED          SCB_CFSR_UNALIGNED_Msk

#define SCB_CFSR_DIVBYZERO_Pos      (SCB_CFSR_UFSR_Pos + 9U)
#define SCB_CFSR_DIVBYZERO_Msk      (0x1UL << SCB_CFSR_DIVBYZERO_Pos)
#define SCB_CFSR_DIVBYZERO          SCB_CFSR_DIVBYZERO_Msk

/********************* Bits definition for SCB_HFSR register **********************/
#define SCB_HFSR_VECTTBL_Pos        (1U)
#define SCB_HFSR_VECTTBL_Msk        (0x1UL << SCB_HFSR_VECTTBL_Pos)
#define SCB_HFSR_VECTTBL            SCB_HFSR_VECTTBL_Msk

#define SCB_HFSR_FORCED_Pos         (30U)
#define SCB_HFSR_FORCED_Msk         (0x1UL << SCB_HFSR_FORCED_Pos)
#define SCB_HFSR_FORCED             SCB_HFSR_FORCED_Msk

#define SCB_HFSR_DEBUGEVT_Pos       (31U)
#define SCB_HFSR_DEBUGEVT_Msk       (0x1UL << SCB_HFSR_DEBUGEVT_Pos)
#define SCB_HFSR_DEBUGEVT           SCB_HFSR_DEBUGEVT_Msk

/********************* Bits definition for SCB_DFSR register **********************/
#define SCB_DFSR_HALTED_Pos         (0U)
#define SCB_DFSR_HALTED_Msk         (0x1UL << SCB_DFSR_HALTED_Pos)
#define SCB_DFSR_HALTED             SCB_DFSR_HALTED_Msk

#define SCB_DFSR_BKPT_Pos           (1U)
#define SCB_DFSR_BKPT_Msk           (0x1UL << SCB_DFSR_BKPT_Pos)
#define SCB_DFSR_BKPT               SCB_DFSR_BKPT_Msk

#define SCB_DFSR_DWTTRAP_Pos        (2U)
#define SCB_DFSR_DWTTRAP_Msk        (0x1UL << SCB_DFSR_DWTTRAP_Pos)
#define SCB_DFSR_DWTTRAP            SCB_DFSR_DWTTRAP_Msk

#define SCB_DFSR_VCATCH_Pos         (3U)
#define SCB_DFSR_VCATCH_Msk         (0x1UL << SCB_DFSR_VCATCH_Pos)
#define SCB_DFSR_VCATCH             SCB_DFSR_VCATCH_Msk

#define SCB_DFSR_EXTERNAL_Pos       (4U)
#define SCB_DFSR_EXTERNAL_Msk       (0x1UL << SCB_DFSR_EXTERNAL_Pos)
#define SCB_DFSR_EXTERNAL           SCB_DFSR_EXTERNAL_Msk

/********************* Bits definition for SCB_MMFAR register *********************/
#define SCB_MMFAR_ADDRESS_Pos       (0U)
#define SCB_MMFAR_ADDRESS_Msk       (0xFFFFFFFFUL << SCB_MMFAR_ADDRESS_Pos)
#define SCB_MMFAR_ADDRESS           SCB_MMFAR_ADDRESS_Msk

/********************* Bits definition for SCB_BFAR register **********************/
#define SCB_BFAR_ADDRESS_Pos        (0U)
#define SCB_BFAR_ADDRESS_Msk        (0xFFFFFFFFUL << SCB_BFAR_ADDRESS_Pos)
#define SCB_BFAR_ADDRESS            SCB_BFAR_ADDRESS_Msk

/********************* Bits definition for SCB_AFSR register **********************/
#define SCB_AFSR_IMPDEF_Pos         (0U)
#define SCB_AFSR_IMPDEF_Msk         (0xFFFFFFFFUL << SCB_AFSR_IMPDEF_Pos)
#define SCB_AFSR_IMPDEF             SCB_AFSR_IMPDEF_Msk

/********************* Bits definition for SCB_CPACR register *********************/
#define SCB_CPACR_CP10_Pos          (20U)
#define SCB_CPACR_CP10_Msk          (0x3UL << SCB_CPACR_CP10_Pos)
#define SCB_CPACR_CP10              SCB_CPACR_CP10_Msk

#define SCB_CPACR_CP11_Pos          (22U)
#define SCB_CPACR_CP11_Msk          (0x3UL << SCB_CPACR_CP11_Pos)
#define SCB_CPACR_CP11              SCB_CPACR_CP11_Msk


/**********************************************************************************/
/*                                                                                */
/*                             SYSTEM CONTROLS NOT IN SCB                         */
/*                                                                                */
/**********************************************************************************/

/******************** Bits definition for SCNSCB_ACTLR register *******************/
#define SCNSCB_ACTLR_DISMCYCINT_Pos (0U)
#define SCNSCB_ACTLR_DISMCYCINT_Msk (0x1UL << SCNSCB_ACTLR_DISMCYCINT_Pos)
#define SCNSCB_ACTLR_DISMCYCINT     SCNSCB_ACTLR_DISMCYCINT_Msk

#define SCNSCB_ACTLR_DISDEFWBUF_Pos (1U)
#define SCNSCB_ACTLR_DISDEFWBUF_Msk (0x1UL << SCNSCB_ACTLR_DISDEFWBUF_Pos)
#define SCNSCB_ACTLR_DISDEFWBUF     SCNSCB_ACTLR_DISDEFWBUF_Msk

#define SCNSCB_ACTLR_DISFOLD_Pos    (2U)
#define SCNSCB_ACTLR_DISFOLD_Msk    (0x1UL << SCNSCB_ACTLR_DISFOLD_Pos)
#define SCNSCB_ACTLR_DISFOLD        SCNSCB_ACTLR_DISFOLD_Msk

#define SCNSCB_ACTLR_DISFPCA_Pos    (8U)
#define SCNSCB_ACTLR_DISFPCA_Msk    (0x1UL << SCNSCB_ACTLR_DISFPCA_Pos)
#define SCNSCB_ACTLR_DISFPCA        SCNSCB_ACTLR_DISFPCA_Msk

#define SCNSCB_ACTLR_DISOOFP_Pos    (9U)
#define SCNSCB_ACTLR_DISOOFP_Msk    (0x1UL << SCNSCB_ACTLR_DISOOFP_Pos)
#define SCNSCB_ACTLR_DISOOFP        SCNSCB_ACTLR_DISOOFP_Msk


/**********************************************************************************/
/*                                                                                */
/*                               SYSTEM TIMER (SYSTICK)                           */
/*                                                                                */
/**********************************************************************************/

/******************** Bits definition for SYSTICK_CTRL register *******************/
#define SYSTICK_CTRL_ENABLE_Pos     (0U)
#define SYSTICK_CTRL_ENABLE_Msk     (0x1UL << SYSTICK_CTRL_ENABLE_Pos)
#define SYSTICK_CTRL_ENABLE         SYSTICK_CTRL_ENABLE_Msk

#define SYSTICK_CTRL_TICKINT_Pos    (1U)
#define SYSTICK_CTRL_TICKINT_Msk    (0x1UL << SYSTICK_CTRL_TICKINT_Pos)
#define SYSTICK_CTRL_TICKINT        SYSTICK_CTRL_TICKINT_Msk

#define SYSTICK_CTRL_CLKSOURCE_Pos  (2U)
#define SYSTICK_CTRL_CLKSOURCE_Msk  (0x1UL << SYSTICK_CTRL_CLKSOURCE_Pos)
#define SYSTICK_CTRL_CLKSOURCE      SYSTICK_CTRL_CLKSOURCE_Msk

#define SYSTICK_CTRL_COUNTFLAG_Pos  (16U)
#define SYSTICK_CTRL_COUNTFLAG_Msk  (0x1UL << SYSTICK_CTRL_COUNTFLAG_Pos)
#define SYSTICK_CTRL_COUNTFLAG      SYSTICK_CTRL_COUNTFLAG_Msk

/**************** Bits definition for SYSTICK_LOAD_RELOAD register ****************/
#define SYSTICK_LOAD_RELOAD_Pos     (0U)
#define SYSTICK_LOAD_RELOAD_Msk     (0xFFFFFFUL << SYSTICK_LOAD_RELOAD_Pos)
#define SYSTICK_LOAD_RELOAD         SYSTICK_LOAD_RELOAD_Msk

/**************** Bits definition for SYSTICK_VAL_CURRENT register ****************/
#define SYSTICK_VAL_CURRENT_Pos     (0U)
#define SYSTICK_VAL_CURRENT_Msk     (0xFFFFFFUL << SYSTICK_VAL_CURRENT_Pos)
#define SYSTICK_VAL_CURRENT         SYSTICK_VAL_CURRENT_Msk

/******************* Bits definition for SYSTICK_CALIB register *******************/
#define SYSTICK_CALIB_TENMS_Pos     (0U)
#define SYSTICK_CALIB_TENMS_Msk     (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)
#define SYSTICK_CALIB_TENMS         SYSTICK_CALIB_TENMS_Msk

#define SYSTICK_CALIB_SKEW_Pos      (30U)
#define SYSTICK_CALIB_SKEW_Msk      (0x1UL << SYSTICK_CALIB_SKEW_Pos)
#define SYSTICK_CALIB_SKEW          SYSTICK_CALIB_SKEW_Msk

#define SYSTICK_CALIB_NOREF_Pos     (31U)
#define SYSTICK_CALIB_NOREF_Msk     (0x1UL << SYSTICK_CALIB_NOREF_Pos)
#define SYSTICK_CALIB_NOREF         SYSTICK_CALIB_NOREF_Msk






/* end C linkage and return to C++ linkage */
#ifdef __cplusplus 
}
#endif


/* end header guard */
#endif
