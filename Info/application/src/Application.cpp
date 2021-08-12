/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Application.h"

/********************************************************************************
 * Variables
 ********************************************************************************/



/********************************************************************************
 * Class
 ********************************************************************************/

void Application::Init() {
    Application::SetUserSettings(8.0f, 1.0f);

    Application::StartHighSpeedProcessing();
    Application::StartLowSpeedProcessing();
}

void Application::SetUserSettings (float referenceVoltage, float referenceCurrent) {

}

void Application::StartHighSpeedProcessing() {
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;     

    TIM3->PSC = 36-1;
    TIM3->ARR = 200;
    TIM3->DIER |= TIM_DIER_UIE;
    TIM3->CR1  |= TIM_CR1_CEN;

    NVIC_EnableIRQ(TIM3_IRQn);
}

void Application::StartLowSpeedProcessing() {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;     

    TIM2->PSC = 36000-1;
    TIM2->ARR = 1000;
    TIM2->DIER |= TIM_DIER_UIE;
    TIM2->CR1  |= TIM_CR1_CEN;

    NVIC_EnableIRQ(TIM2_IRQn);
}

void Application::Run() {
	__WFI();
}

/********************************************************************************
 * High speed processing #1
 ********************************************************************************/

void sTim3::handler (void) {
    TIM3->SR &= ~TIM_SR_UIF;
}

/********************************************************************************
 * Low speed processing #1
 ********************************************************************************/

void sTim2::handler (void) {
    TIM2->SR &= ~TIM_SR_UIF;
}
