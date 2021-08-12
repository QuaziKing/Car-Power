/********************************************************************************
 * Include
 ********************************************************************************/

#include "startupF030.h"

/********************************************************************************
 * Default reset
 ********************************************************************************/

static INLINE void InitializeData() {

    uint32_t *pSrc;
    uint32_t *pDest;

    // Load initialized data from FLASH to RAM
    pSrc = &__etext;
    pDest = &__data_start__;

    while (pDest < &__data_end__)
    *pDest++ = *pSrc++;

    // Clear uninitialized data
    pDest = &__bss_start__;

    while (pDest < &__bss_end__)
    *pDest++ = 0;
}

extern "C" void ResetHandler() {
    InitializeData();
    main();
}

/********************************************************************************
 * Vector table
 ********************************************************************************/

__attribute__ ((used,section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {

/************* Core exceptions ******************/

    pvf(&__StackTop),
	ResetHandler,
    sNMI::handler,
    sHardFault::handler,
    0,0,0,0,0,0,0,
    sSVC::handler,
    0,0,
    sPendSV::handler,
    sSysTick::handler,

/********** External exceptions ***************/

    sWWDG::handler,
    0,
    sRtc::weakeUp,
    sFlash::handler,
    sRcc::handler,
    sExti::line01Handler,
    sExti::line23Handler,
    sExti::line415Handler,
    0,
    sDma::channel1Handler,
    sDma::channel23Handler,
    sDma::channel45Handler,
    sAdc::handler,
    sTim1::breakeUpTriggerComHandler,
    sTim1::ccHandler,
	0,
	sTim3::handler,
    sTim6::handler,
    0,
	sTim14::handler,
    sTim15::handler,
	sTim16::handler,
    sTim17::handler,
    sI2C1::handler,
    sI2C2::handler,
    sSpi1::handler,
    sSpi2::handler,
    sUsart1::handler,
    sUsart2::handler,
    0,0,0
};

/********************************************************************************
 * Default interrupt
 ********************************************************************************/

WEAK void sNMI::handler()               { while (1) {} }
WEAK void sHardFault::handler()         { while (1) {} }
WEAK void sSVC::handler()               { while (1) {} }
WEAK void sPendSV::handler()            { while (1) {} }
WEAK void sSysTick::handler()           { while (1) {} }

WEAK void sWWDG::handler()              { while (1) {} }
WEAK void sRtc::weakeUp()               { while (1) {} }
WEAK void sFlash::handler()             { while (1) {} }
WEAK void sRcc::handler()               { while (1) {} }
WEAK void sExti::line01Handler()         { while (1) {} }
WEAK void sExti::line23Handler()         { while (1) {} }
WEAK void sExti::line415Handler()         { while (1) {} }
WEAK void sDma::channel1Handler()       { while (1) {} }
WEAK void sDma::channel23Handler()       { while (1) {} }
WEAK void sDma::channel45Handler()       { while (1) {} }
WEAK void sAdc::handler()               { while (1) {} }
WEAK void sTim1::breakeUpTriggerComHandler()   { while (1) {} }
WEAK void sTim1::ccHandler()        { while (1) {} }
WEAK void sTim3::handler()              { while (1) {} }
WEAK void sTim6::handler()              { while (1) {} }
WEAK void sTim14::handler()              { while (1) {} }
WEAK void sTim15::handler()              { while (1) {} }
WEAK void sTim16::handler()              { while (1) {} }
WEAK void sI2C1::handler()         { while (1) {} }
WEAK void sI2C2::handler()         { while (1) {} }
WEAK void sSpi1::handler()              { while (1) {} }
WEAK void sSpi2::handler()              { while (1) {} }
WEAK void sUsart1::handler()            { while (1) {} }
WEAK void sUsart2::handler()            { while (1) {} }
