
#pragma once

/********************************************************************************
 * Include
 ********************************************************************************/

#include <stdint.h>

/********************************************************************************
 * Define 
 ********************************************************************************/

#define WEAK                __attribute__ ((weak))
#define INLINE inline       __attribute__((always_inline))

__attribute__ ((section(".co_stack")))

/********************************************************************************
 * Section for linker script
 ********************************************************************************/

extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

extern char __StackTop;

typedef void (* pvf)();

/********************************************************************************
 * Function prototype
 ********************************************************************************/

/********************************************************************************
 * Class
 ********************************************************************************/

class sNMI {
public:
    static void handler (void);
};

class sHardFault {
public:
    static void handler (void);
};

class sSVC {
public:
    static void handler (void);
};

class sPendSV {
public:
    static void handler (void);
};

class sSysTick {
public:
    static void handler (void);
};

class sWWDG {
public:
    static void handler (void);
};

class sRtc {
public:
    static void weakeUp (void);
};

class sFlash {
public:
    static void handler (void);
    };

class sRcc {
public:
    static void handler (void);
};

class sExti {
public:
    static void line01Handler (void);
    static void line23Handler (void);
    static void line415Handler (void);
};

class sDma {
public:
    static void channel1Handler (void);
    static void channel23Handler (void);
    static void channel45Handler (void);
};

class sAdc {
public:
    static void handler (void);
};

class sTim1 {
public:
    static void breakeUpTriggerComHandler (void);
    static void ccHandler (void);
};

class sTim3 {
public:
    static void handler (void);
};

class sTim6 {
public:
	static void handler (void);
};

class sTim14 {
public:
	static void handler (void);
};

class sTim15 {
public:
	static void handler (void);
};

class sTim16 {
public:
	static void handler (void);
};

class sTim17 {
public:
	static void handler (void);
};

class sI2C1 {
public:
	static void handler (void);
};

class sI2C2 {
public:
	static void handler (void);
};

class sSpi1 {
public:
	static void handler (void);
};

class sSpi2 {
public:
	static void handler (void);
};

class sUsart1 {
public:
	static void handler (void);
};

class sUsart2 {
public:
	static void handler (void);
};
