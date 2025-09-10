/*
 * ## 🔒 Firmware License Notice

The firmware for MOLTINO is provided **in precompiled binary form only**.

- The source code is **not** shared.
- The firmware is licensed under a **proprietary license**.
- You may use the binary firmware **only with MOLTINO hardware**.
- Redistribution, reverse engineering, or use on other hardware is **not permitted** without written permission.

See [`LICENSE_FIRMWARE.txt`](./LICENSE_FIRMWARE.txt) for full terms.

*/
// ver.:4.0

#pragma once

#include <Arduino.h>
#include <EEPROM.h>
#include <Adafruit_ADS1X15.h>
#include <digitalWriteFast.h>

typedef const char* const MenuItem_t;

extern const MenuItem_t menuStrings[] PROGMEM;

#define bit0                      1
#define bit1                      2
#define bit2                      4
#define bit3                      8
#define bit4                     16
#define bit5                     32
#define bit6                     64
#define bit7                    128

// ADDRESS BORDERS:
//--------------------[ COILS ]-------------------------------------------
#define CoilsIni1                   0
#define CoilsFin1                   3
#define CoilsIni2                   4
#define CoilsFin2                   7
//-------------------[ DISCRET INPUTS ]-----------------------------------
#define InpDiscIni1             10000
#define InpDiscFin1             10003
#define InpDiscIni2             10004
#define InpDiscFin2             10007
#define InpDiscIni3             10008
#define InpDiscFin3             10011
#define InpDiscIni4             10012
#define InpDiscFin4             10015
//------------------[ INPUT REGISTER ]-----------------------------------
#define InpRegIni1              30000
#define InpRegFin1              30003
#define InpRegIni2              30004
#define InpRegFin2              30007
//-----------------[ HOLDING REGISTER ]----------------------------------
#define HoldRegIni1             40000
#define HoldRegFin1             40003
#define HoldRegIni2             40004
#define HoldRegFin2             40007
#define HoldRegIni3             40008
#define HoldRegFin3             40015
#define HoldRegIni4             40016
#define HoldRegFin4             40023
#define HoldRegIni5             40024
#define HoldRegFin5             40027
#define HoldRegIni6             40028
#define HoldRegFin6             40031
#define HoldRegIni7             40032
#define HoldRegFin7             40032
#define HoldRegIni8             40033
#define HoldRegFin8             40043
#define HoldRegIni9             40044
#define HoldRegFin9             40047
#define HoldRegIni10            40052
#define HoldRegFin10            40055

// USER REGISTERS:

#define coils1                  0
#define coils2                  1
#define coils3                  2
#define coils4                  3
#define digitalInput1           10000
#define digitalInput2           10001
#define digitalInput3           10002
#define digitalInput4           10003
#define latch1                  10008
#define latch2                  10009
#define latch3                  10010
#define latch4                  10011
#define analogInput1            30000
#define analogInput2            30001
#define analogInput3            30002
#define analogInput4            30003
#define analogOutput1           40000
#define analogOutput2           40001
#define analogOutput3           40002
#define analogOutput4           40003
#define counter1H               40008
#define counter1L               40009
#define counter2H               40010
#define counter2L               40011
#define counter3H               40012
#define counter3L               40013
#define counter4H               40014
#define counter4L               40015
#define freqDI1                 40024
#define freqDI2                 40025
#define freqDI3                 40026
#define freqDI4                 40027

#define CurrLoopErrorReg        40032

// CONFIG REGISTERS:

#define IdReg                   40033
#define SerSpeedReg             40034
#define MaskReg                 40035
#define EnabSaveCountReg        40036
#define CountUpDownReg          40037
#define CalibAnaInputReg        40038
#define Reserved                40039
#define ModeAnaInputReg         40040
#define ResAnaOutputReg         40041
#define CalibAnaOutputReg       40042
#define LcdMeasTypeReg          40043
#define ReleTimeCntDwnReg1      40044
#define ReleTimeCntDwnReg2      40045
#define ReleTimeCntDwnReg3      40046
#define ReleTimeCntDwnReg4      40047
#define ReleTimeCntDwnReg5      40048
#define ReleTimeCntDwnReg6      40049
#define ReleTimeCntDwnReg7      40050
#define ReleTimeCntDwnReg8      40051
#define Tipo_shield_arduino     40052
#define Hardware_version        40053
#define Softvare_version        40054
#define Serial_number           40055

// PINS:

#define RS485TRX                2
#define LEDC                   13
#define button1                16
#define button2                17

// MACROS:

#define RS485TX()               digitalWriteFast(RS485TRX,HIGH)
#define RS485RX()               digitalWriteFast(RS485TRX,LOW)
#define LEDC_ON()               digitalWriteFast(LEDC,HIGH)
#define LEDC_OFF()              digitalWriteFast(LEDC,LOW)
#define LEDC_TOGGLE()           digitalToggleFast(LEDC)

#define coil0_ON()              digitalWriteFast(_pin[8],HIGH)
#define coil0_OFF()             digitalWriteFast(_pin[8],LOW)
#define coil1_ON()              digitalWriteFast(_pin[9],HIGH)
#define coil1_OFF()             digitalWriteFast(_pin[9],LOW)
#define coil2_ON()              digitalWriteFast(_pin[10],HIGH)
#define coil2_OFF()             digitalWriteFast(_pin[10],LOW)
#define coil3_ON()              digitalWriteFast(_pin[11],HIGH)
#define coil3_OFF()             digitalWriteFast(_pin[11],LOW)
#define coil4_ON()              digitalWriteFast(_pin[12],HIGH)
#define coil4_OFF()             digitalWriteFast(_pin[12],LOW)
#define coil5_ON()              digitalWriteFast(_pin[13],HIGH)
#define coil5_OFF()             digitalWriteFast(_pin[13],LOW)
#define coil6_ON()              digitalWriteFast(_pin[14],HIGH)
#define coil6_OFF()             digitalWriteFast(_pin[14],LOW)
#define coil7_ON()              digitalWriteFast(_pin[15],HIGH)
#define coil7_OFF()             digitalWriteFast(_pin[15],LOW)

#define MASKBIT(n)              (MASK >> n) & 1

// CONSTANT VALUES:

#define PWMmax8bits             255
#define PWMmax10bits            1023
#define PWMmax12bits            4095
#define PWMmax14bits            16383

#define ADmax10bits             1023
#define ADmax12bits             4095
#define ADmax14bits             16383
#define ADmax15bits             32767
#define ADmax16bits             65535

// PARAMETERS

#define ADNoiseMaxLevel         9

#define tick                    1001702

// #define debug
// #define LCD_REFRESH
#define LCD_TIME                10 // sec
#define INTRO_LINE1             "MOLTINO 4x4"
#define INTRO_LINE2             "renaissance"

class M4x4_R3
{
public:
     M4x4_R3();
    ~M4x4_R3();
    static M4x4_R3* instance() { return theM4x4_R3; }
    void isr_M4x4_R3();
    void isr_DI1();
    void isr_DI2_DI3();
    void isr_DI4();
//-----------------------------------------[ FUNCTIONS API ]---------------------------------------
    void begin();
    void dataMonitoring();
    void readCounters();
    void sendTextLcd();
    uint8_t read_Coils(const uint8_t start, uint8_t quantity );
    uint16_t read_Discrete_Inputs(const uint16_t start, uint8_t quantity );
    uint16_t read_Holding_Reg(const uint16_t address );
    void write_Single_Coil(const uint16_t address, uint16_t value );
    void write_Single_Reg(const uint16_t address, uint16_t value );
    void write_Multiple_Coils();
    void write_Multiple_Registers(const uint16_t address, uint16_t value );
    void resetCounters(const uint16_t _register, uint16_t Count );
    uint16_t readInputAnalog( uint8_t channel );
    uint16_t INPUT_REG[4];
    uint16_t HOLDING_REG[17];

 #include "M4x4_R3_internal.h"

};
