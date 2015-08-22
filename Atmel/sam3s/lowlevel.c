/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * Provides the low-level initialization function that called on chip startup.
 */

#include "SAM3S.h"
#include "compiler.h"

/*----------------------------------------------------------------------------
 *        Local definitions
 *----------------------------------------------------------------------------*/
/* Clock settings at 64MHz */
#ifdef MAIN_OSCILLATOR_64MHZ
uint32_t SystemCoreClock = 64000000;
#define BOARD_OSCOUNT   (CKGR_MOR_MOSCXTST(0x8))
#define BOARD_PLLAR     (CKGR_PLLAR_STUCKTO1 \
                       | CKGR_PLLAR_MULA(0x0f) \
                       | CKGR_PLLAR_PLLACOUNT(0x1) \
                       | CKGR_PLLAR_DIVA(0x3))
#define BOARD_MCKR      (PMC_MCKR_PRES_CLK | PMC_MCKR_CSS_PLLA_CLK)
#else
#error Undefined main oscillator frequency
#endif

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

/**
 * \brief Performs the low-level initialization of the chip.
 * This includes EFC and master clock configuration.
 * It also enable a low level on the pin NRST triggers a user reset.
 */
extern WEAK void LowLevelInit( void )
{
    /* Set 3 FWS for Embedded Flash Access */
    EFC->EEFC_FMR = EEFC_FMR_FWS(3);

    /* Select external slow clock */
/*    if ((SUPC->SUPC_SR & SUPC_SR_OSCSEL) != SUPC_SR_OSCSEL_CRYST)
    {
        SUPC->SUPC_CR = (uint32_t)(SUPC_CR_XTALSEL_CRYSTAL_SEL | SUPC_CR_KEY(0xA5));
        while (!(SUPC->SUPC_SR & SUPC_SR_OSCSEL_CRYST) );
    }
*/
    /* Initialize main oscillator */
    if ( !(PMC->CKGR_MOR & CKGR_MOR_MOSCSEL) )
    {
        PMC->CKGR_MOR = CKGR_MOR_KEY(0x37) | BOARD_OSCOUNT | CKGR_MOR_MOSCRCEN | CKGR_MOR_MOSCXTEN;
        while (!(PMC->PMC_SR & PMC_SR_MOSCXTS));
    }

    /* Switch to 3-20MHz Xtal oscillator */
    PMC->CKGR_MOR = CKGR_MOR_KEY(0x37) | BOARD_OSCOUNT | CKGR_MOR_MOSCRCEN |
                    CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCSEL;
    while (!(PMC->PMC_SR & PMC_SR_MOSCSELS));
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~(uint32_t)PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
    while(!(PMC->PMC_SR & PMC_SR_MCKRDY)) {}

    /* Initialize PLLA */
    PMC->CKGR_PLLAR = BOARD_PLLAR;
    while (!(PMC->PMC_SR & PMC_SR_LOCKA));

    /* Switch to main clock */
    PMC->PMC_MCKR = (BOARD_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
    while (!(PMC->PMC_SR & PMC_SR_MCKRDY)) {}

    PMC->PMC_MCKR = BOARD_MCKR ;
    while(!(PMC->PMC_SR & PMC_SR_MCKRDY)) {}
}
