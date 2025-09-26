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

// max.: 16 char/var.                                 ADDRESS  MODBUS FUNC.
const char str0[]  PROGMEM = "COIL 1 STATE";       //  00000         01
const char str1[]  PROGMEM = "COIL 2 STATE";       //  00001         01
const char str2[]  PROGMEM = "COIL 3 STATE";       //  00002         01
const char str3[]  PROGMEM = "COIL 4 STATE";       //  00003         01
const char str4[]  PROGMEM = "DISCRET INPUT 1";    //  10000         02
const char str5[]  PROGMEM = "DISCRET INPUT 2";    //  10001         02
const char str6[]  PROGMEM = "DISCRET INPUT 3";    //  10002         02
const char str7[]  PROGMEM = "DISCRET INPUT 4";    //  10003         02
const char str8[]  PROGMEM = "LATCH INPUT 1";      //  10008         02
const char str9[]  PROGMEM = "LATCH INPUT 2";      //  10009         02
const char str10[] PROGMEM = "LATCH INPUT 3";      //  10010         02
const char str11[] PROGMEM = "LATCH INPUT 4";      //  10011         02
const char str12[] PROGMEM = "ANALOG INPUT 1";     //  30000         04
const char str13[] PROGMEM = "ANALOG INPUT 2";     //  30001         04
const char str14[] PROGMEM = "ANALOG INPUT 3";     //  30002         04
const char str15[] PROGMEM = "ANALOG INPUT 4";     //  30003         04
const char str16[] PROGMEM = "ANALOG OUTPUT 1";    //  40000         03
const char str17[] PROGMEM = "ANALOG OUTPUT 2";    //  40001         03
const char str18[] PROGMEM = "ANALOG OUTPUT 3";    //  40002         03
const char str19[] PROGMEM = "ANALOG OUTPUT 4";    //  40003         03
const char str20[] PROGMEM = "COUNTER 1";          //  40008         03
const char str21[] PROGMEM = "COUNTER 2";          //  40010         03
const char str22[] PROGMEM = "COUNTER 3";          //  40012         03
const char str23[] PROGMEM = "COUNTER 4";          //  40014         03
const char str24[] PROGMEM = "FREQ.DIG.INPUT 1";   //  40024         03
const char str25[] PROGMEM = "FREQ.DIG.INPUT 2";   //  40025         03
const char str26[] PROGMEM = "FREQ.DIG.INPUT 3";   //  40026         03
const char str27[] PROGMEM = "FREQ.DIG.INPUT 4";   //  40027         03
const char str28[] PROGMEM = "ERROR 4-20mA";       //  40032         03

//--------------------------------[ CONFIGURATION AREA ]------------------------------------
//--------------------------------/  DON'T CHANGE IT!  /------------------------------------

const char str29[] PROGMEM = "MODBUS ID:";         //  40033         03
const char str30[] PROGMEM = "SERIAL SPEED:";      //  40034         03
const char str31[] PROGMEM = "D.INPUTS MASK:";     //  40035         03
const char str32[] PROGMEM = "COUNTERS MEMORY:";   //  40036         03
const char str33[] PROGMEM = "COUNTERS CONFIG:";   //  40037         03
const char str34[] PROGMEM = "AIN.RECALIB VAL:";   //  40038         03
const char str35[] PROGMEM = "AOU.RECALIB VAL:";   //  40042         03
const char str36[] PROGMEM = "ANALOG MEAS.CH:";    //  40043         03
const char str37[] PROGMEM = "DELAY RELAY 1:";     //  40044         03
const char str38[] PROGMEM = "DELAY RELAY 2:";     //  40045         03
const char str39[] PROGMEM = "DELAY RELAY 3:";     //  40046         03
const char str40[] PROGMEM = "DELAY RELAY 4:";     //  40047         03


const MenuItem_t menuStrings[] PROGMEM = {
  str0, str1, str2, str3, str4, str5, str6, str7, str8, str9,
  str10, str11, str12, str13, str14, str15, str16, str17, str18,
  str19, str20, str21, str22, str23, str24, str25, str26, str27,
  str28, str29, str30, str31, str32, str33, str34, str35, str36,
  str37, str38, str39, str40
};

// USER REGISTERS:

#define coil1                   0
#define coil2                   1
#define coil3                   2
#define coil4                   3
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
#define counter32_1             40008
#define counter32_2             40010
#define counter32_3             40012
#define counter32_4             40014
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

#define coilOn                  0xFF00
#define coilOff                      0

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
    uint16_t readCoils( const uint16_t start, uint16_t quantity );
    uint16_t readDiscreteInputs( const uint16_t start, uint16_t quantity );
    uint16_t readInputReg( const uint16_t address );
    uint16_t readHoldingReg( const uint16_t address );
    void writeSingleCoil( const uint16_t address, uint16_t value );
    void writeSingleReg( const uint16_t address, uint16_t value );
    void writeMultipleCoils( uint16_t outputs_value );
    void resetCounters( const uint16_t register32, uint16_t Count );

 #include "M4x4_R3_internal.h"

};
