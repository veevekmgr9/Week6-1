#include "exti.h"
#include "myClockConf.h"
#include "TimerConf.h"
#include "stm32f4xx.h"

#define UBTN EXTI_PR_PR13

uint32_t duty = 0;

int main(void){

	setClock();
	pc13_exti_init();
	Timer2_PWM_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	GPIOA->MODER &= ~GPIO_MODER_MODER5_Msk;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;


	while(1){

	}
}

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & UBTN){
		duty = duty + 25;
		if(duty > 100){
			duty = 0;
		}
		Timer2_SetDutyCycle(duty);
	}
	EXTI->PR |= UBTN;

}
