/* =====================================================
 * Name : Yousef Sami
 *
 * Project : freeRTOS
 *
 * Date handle in : 05 / 04 /2024
 *=======================================================*/
#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

typedef enum LevelType_HeatDegree {
    HEATING_OFF, HEATING_LOW, HEATING_MEDIUM, HEATING_HIGH
} HeatingLevelType;

typedef enum StateTypeHeatDegree {
    HEATER_OFF, HEATER_LOW, HEATER_MEDIUM, HEATER_HIGH
} HeaterStateType;

typedef struct {
    uint8_t u8TempValueC_Seat1;
    LevelType_HeatDegree Seat1heatingLevel;
    StateTypeHeatDegree Seat1heaterState;
    uint8_t u8TempValueC_Seat2;
    LevelType_HeatDegree Seat2heatingLevel;
    StateTypeHeatDegree Seat2heaterState;
}SystemStateStructureType;



#endif /* DEFINITIONS_H_ */
