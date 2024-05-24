/* =====================================================
 * Name : Yousef Sami
 *
 * Project : freeRTOS
 *
 * Date handle in : 05 / 04 /2024
 *=======================================================*/

#include "rgb.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void RGB_init(void){

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)){}
    GPIOPinTypeGPIOOutput(RED_PORT_BASE, RED_PIN);
    GPIOPinTypeGPIOOutput(GREEN_PORT_BASE, GREEN_PIN);
    GPIOPinTypeGPIOOutput(BLUE_PORT_BASE, BLUE_PIN);

}

void RGB_RedLedOn(void){
    GPIOPinWrite(RED_PORT_BASE, RED_PIN, RED_PIN);
}
void RGB_BlueLedOn(void){
    GPIOPinWrite(GREEN_PORT_BASE, GREEN_PIN, GREEN_PIN);

}
void RGB_GreenLedOn(void){
    GPIOPinWrite(BLUE_PORT_BASE, BLUE_PIN, BLUE_PIN);

}

void RGB_RedLedOff(void){
    GPIOPinWrite(RED_PORT_BASE, RED_PIN, 0x00);
}
void RGB_BlueLedOff(void){
    GPIOPinWrite(GREEN_PORT_BASE, GREEN_PIN, 0x00);
}
void RGB_GreenLedOff(void){
    GPIOPinWrite(BLUE_PORT_BASE, BLUE_PIN, 0x00);
}

