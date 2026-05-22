#include "drivers/gpio/gpio.h"
#include "bsp/nano.h"
#include "drivers/interrupt/external_interrupt.h"
#include "drivers/timer/timer0.h"
#include <stdint.h>
#include "drivers/adc/adc.h"
#include "drivers/pwm/pwm.h"

static void buttonPress(void){
    GPIO_Toggle(D7);
}

int main(void) {
    Timer0_Init();
    GPIO_Init(D8, GPIO_INPUT);
    GPIO_Write(D8, GPIO_HIGH);
    GPIO_Init(D7, GPIO_OUTPUT);
    ExtInt_Init(INT_0, EXT_INT_FALLING_EDGE, buttonPress);
    GPIO_Init(D11, GPIO_OUTPUT)

    uint32_t last_time = 0;
    uint16_t pot_value = 0;
    uint8_t duty = 0;

    ADC_Init();
    PWM_Init(D11, 620);

    while(1){
        GPIO_Write(D7, GPIO_HIGH);
        if(Millis() - last_time >= 200){
            last_time = Millis();
            GPIO_Toggle(D11);
        }
        adc_value = ADC_Read(2);`
        duty = (uint8_t)(adc_value/4);
        PWM_SetDutyCycle(D11, duty);
    }
}