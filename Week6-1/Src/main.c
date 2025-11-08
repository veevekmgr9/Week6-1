#include "exti.h"           // Custom header for external interrupt configuration
#include "myClockConf.h"    // Custom header for system clock configuration
#include "TimerConf.h"      // Custom header for Timer (PWM) configuration
#include "stm32f4xx.h" 

// Define a name for EXTI line 13 (user button on PC13)
#define UBTN EXTI_PR_PR13
// Variable to store current PWM duty cycle percentage
uint32_t duty = 0;

int main(void) {
    // Initialize and configure system clock
    setClock();
    // Configure EXTI line for PC13 (user button)
    pc13_exti_init();
    // Initialize Timer 2 in PWM mode
    Timer2_PWM_Init();
    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // Configure PA5 as a general-purpose output 
    GPIOA->MODER &= ~GPIO_MODER_MODER5_Msk;  // Clear mode bits
    GPIOA->MODER |= GPIO_MODER_MODER5_0;     // Set as output mode
    // Infinite loop (main work is done via interrupt)
    while(1) {}
}
// Interrupt Service Routine for EXTI (handles PC13 button press)
void EXTI15_10_IRQHandler(void) {
    // Check if the interrupt was triggered by the user button (PC13)
    if (EXTI->PR & UBTN) {
        // Increase PWM duty cycle by 25% each time the button is pressed
        duty = duty + 25;
        // If duty exceeds 100%, reset back to 0%
        if (duty > 100) {
            duty = 0;
        }
        // Update Timer2 PWM duty cycle with the new value
        Timer2_SetDutyCycle(duty);
    }
    // Clear the interrupt pending flag for EXTI
    EXTI->PR |= UBTN;
}
