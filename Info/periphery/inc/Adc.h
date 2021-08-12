/********************************************************************************
 * project     Class for initialization and read ADC                            *
 *                                                                              *
 * file        Adc.h                                                            *
 * author      Ilya Galkin                                                      *
 * date        15.05.2020                                                       *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f0xx.h"
#include "startupF030.h"
#include "Gpio.h"

/********************************************************************************
 * Class ADC
 * 
 * Pin voltage input    - PA0   - ADC1 IN1
 * Pin current input    - PA1   - ADC1 IN2
 * Pin voltage output   - PA2   - ADC1 IN3
 * Pin current output   - PA3   - ADC1 IN4
 * 
 ********************************************************************************/

class Adc {

    public:
        constexpr static uint16_t sizeBuffer = 50;

        static uint16_t inputVoltage [sizeBuffer];
        static uint16_t inputCurrent [sizeBuffer];
        static uint16_t outputVoltage [sizeBuffer];
        static uint16_t outputCurrent [sizeBuffer];
        static uint8_t step;

        struct Status {
            static bool stopInputVoltage;
            static bool stopInputCurrent;
            static bool stopOutputVoltage;
            static bool stopOutputCurrent;
        };

    public:
        static void Init();

    private:    
        static void GpioInit();
        static void StartCallibrationAdc();
        static void InitTimerEvent();
};
