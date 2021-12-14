#include <stdio.h>
#include "uart.h"
#include "adc.h"
#include "temperature.h"

uint32_t sensor_value = 0;
float temperature = 0.00;

void fpu_init(void)
{
    //CPACR is located at address 0xE000ED88
    __asm ("LDR.W R0, =0xE000ED88");
    //Read CPACR
    __asm ("LDR R1, [R0]");
    //Set bits 20-23 to enable CP10 and CP11 coprocessors
    __asm ("ORR R1, R1, #(0xF << 20)");
    //Write back the modified value to the CPACR
    __asm ("STR R1, [R0]");
    //wait for store to complete
    __asm ("DSB");
    //reset pipeline now the FPU is enabled
    __asm ("ISB");
}

int main(void)
{
    fpu_init();
    uart2_tx_init();
    pa1_adc_init();

    while(1)
    {
        start_conversion();
        sensor_value = adc_read();
        temperature = get_temperature_from_voltage(sensor_value);
    }
}
