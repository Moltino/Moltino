#include <M4x4_R3.h>
#include <WDT.h>

M4x4_R3 myMoltino4x4;

void setup() 
{
  wdt_disable();
  myMoltino4x4.begin();
  wdt_enable(WDTO_120MS);
}

void loop() 
{ 
  myMoltino4x4.readCounters();
 if( myMoltino4x4.readInputReg( analogInput1 ) > 5000 ) myMoltino4x4.writeSingleCoil( coil1, coilOn );
 else myMoltino4x4.writeSingleCoil( coil1, coilOff );
  myMoltino4x4.sendTextLcd();
  wdt_reset();
}
