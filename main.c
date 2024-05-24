/* =====================================================
 * Name : Yousef Sami
 *
 * Project : freeRTOS
 *
 * File Name : main.c
 *
 * Date handle in : 14 / 04 /2024
 *=======================================================*/

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* MCAL includes. */
#include "gpio.h"
void _delay_ms(unsigned long long n);

#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 369

/* The HW setup function */
static void vHW_init( void );
/* FreeRTOS tasks */
void vTaskGreenLed(void *pvParameters);
void vTaskRedLed(void *pvParameters);

int main(void)
{
    /* Setup the hardware for use with the Tiva C board. */
    vHW_init();
    /* Create Tasks here */
    xTaskCreate(vTaskGreenLed, "Task 1", 256, NULL, 1, NULL);
    xTaskCreate(vTaskRedLed, "Task 2", 256, NULL, 1, NULL);

    /* Now all the tasks have been started - start the scheduler.

    NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
    The processor MUST be in supervisor mode when vTaskStartScheduler is
    called.  The demo applications included in the FreeRTOS.org download switch
    to supervisor mode prior to main being called.  If you are not using one of
    these demo application projects then ensure Supervisor mode is used here. */
    vTaskStartScheduler();

    /* Should never reach here!  If you do then there was not enough heap
    available for the idle task to be created. */
    for (;;);

}


static void vHW_init( void )
{
    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
    GPIO_BuiltinButtonsLedsInit();
}

void vTaskGreenLed(void *pvParameters)
{
    for (;;)
    {
        _delay_ms(1000);
        GPIO_GreenLedToggle();
    }
}

void vTaskRedLed(void *pvParameters)
{
    for (;;)
    {
        GPIO_RedLedToggle();
        _delay_ms(1000);
    }
}

void _delay_ms(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}

/*-----------------------------------------------------------*/
