#include <M4x4_R3.h>
#include <WDT.h>

M4x4_R3 myMoltino4x4;

#define _0V  0
#define _5V  0x7F
#define _10V 0xFF


void setup() 
{
  wdt_disable();
  myMoltino4x4.begin();
  wdt_enable(WDTO_120MS);
}

void loop() 
{
  myMoltino4x4.readCounters();
  if( myMoltino4x4.readHoldingReg( analogOutput1 ) != _5V ) myMoltino4x4.writeSingleReg( analogOutput1, _5V );
  myMoltino4x4.sendTextLcd();
  wdt_reset();
}
