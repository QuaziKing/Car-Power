/********************************************************************************
 * Class        Application logic for dc/dc buck-boost                          *
 *                                                                              *
 * file         Application.h                                                   *
 * author       Ilya Galkin                                                     *
 * date         18.06.2020                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f0xx.h"
#include "startupF030.h"

/********************************************************************************
 * Class Application
 * 
 * High speed handler   -   2 kHz
 * Low speed handler    -   1 Hz
 * 
 ********************************************************************************/

class Application {
    public:      
        static float referenceOutputVoltage;
        static float referenceOutputCurrent;
        
        static uint16_t dutyResult;
        static float inputVoltage;
        static float outputVoltage;
        static float outputCurrent;

    public:
        static void Init();
        static void SetUserSettings (float referenceVoltage, float referenceCurrent);
        
        static void Run();

    private:
        static void StartHighSpeedProcessing();
        static void StartLowSpeedProcessing();
};
