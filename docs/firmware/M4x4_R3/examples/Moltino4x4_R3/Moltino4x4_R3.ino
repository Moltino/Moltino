#include <M4x4_R3.h>
#include <WDT.h>

// uint8_t pins1[] = { 5, 6, 9, 10 };
// uint8_t pins2[] = { 4, 7, 8, 15 };
// uint8_t pins3[] = { 3, 11, 12, 14 };

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


M4x4_R3 myMoltino4x4;

void setup() 
{
  wdt_disable();
  myMoltino4x4.begin();
  wdt_enable(WDTO_120MS);
}

void loop() 
{ 
  myMoltino4x4.dataMonitoring();
  myMoltino4x4.readCounters();
  myMoltino4x4.sendTextLcd();
  wdt_reset();
}
