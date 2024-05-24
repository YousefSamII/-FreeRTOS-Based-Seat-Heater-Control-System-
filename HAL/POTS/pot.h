/* =====================================================
 * Name : Yousef Sami
 *
 * Project : freeRTOS
 *
 * Date handle in : 05 / 04 /2024
 *=======================================================*/

#ifndef HAL_POTS_POTS_H_
#define HAL_POTS_POTS_H_

#include <stdint.h>

#define MAX_VALUE_POT1   4096
#define MAX_VALUE_POT2   4096

void vPOT1_Init(void);
uint32_t u32POT1_GetValue();

void vPOT2_Init(void);
uint32_t u32POT2_GetValue();


#endif /* HAL_POTS_POTS_H_ */
