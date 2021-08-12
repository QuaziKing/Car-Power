
/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Clock.h"

/********************************************************************************
 * Class Clock
 ********************************************************************************/

void Clock::Init (void) {
    RCC->CR |= RCC_CR_HSEON;                                    // Enable system for external crystall
    while (!(RCC->CR & RCC_CR_HSERDY));                         // Waiting flag about enable

    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;          // Latency for internal flash memory
    RCC->CFGR2 |= RCC_CFGR2_PREDIV_0;                           // Divider crystal HSE/2
    RCC->CFGR  |= RCC_CFGR_PLLMUL9;                             // Select multiplier frequency for PLL x9
    RCC->CFGR  |= RCC_CFGR_PLLSRC;                              // Select source external crystall
    RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV10;                     // Select divider for ADC = AHB/10
    /* Выбираем HSI как источник системной частоты */
    //RCC_SYSCLKConfig( RCC_CFGR_SW_HSI);
    //RCC->CFGR |= RCC_CFGR_SW_HSI;

    /* Ожидаем, пока HSI выберется как источник системной частоты */
    //while (RCC->CFGR & (uint32_t)RCC_CFGR_SWS) {}

    /* Выключаем PLL */
    //RCC_PLLCmd( DISABLE);
    RCC->CR &= ~RCC_CR_PLLON;

    /* Ожидаем, пока PLL снимет бит готовности */
    while( RCC->CR & RCC_CR_PLLRDY ) {}

    /* Конфигурируем множитель PLL: PLLCLK = HSI * PllMul */
    //RCC_PLLConfig(RCC_CFGR_PLLSRC_HSI_DIV2, RCC_CFGR_PLLMUL6);
    RCC->CFGR &= ~(RCC_CFGR_PLLMUL | RCC_CFGR_PLLSRC);
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSI_DIV2 | RCC_CFGR_PLLMUL12);

    RCC->CR |= RCC_CR_PLLON;                                    // Enable PLL system
    while((RCC->CR & RCC_CR_PLLRDY) == 0){}                     // Waiting flag about enable
    RCC->CFGR |= RCC_CFGR_SW_PLL;                               // Select source SYSCLK = PLL
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {}      // Waiting flag about enable
};



void Clock::EnableMCO (Status status) {
    if (status == Clock::Status::enable) {
        Gpio::Init<8>(GPIOA, Gpio::Mode::outputAF, Gpio::Type::PP, Gpio::Speed::veryHigh);
        RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;                       // Select source PLL
        RCC->CFGR |= RCC_CFGR_PLLNODIV;                         // PLL divider for MCO
    }
            
    if (status == Clock::Status::disable) {
        Gpio::Init<8>(GPIOA, Gpio::Mode::input);
    }
};
