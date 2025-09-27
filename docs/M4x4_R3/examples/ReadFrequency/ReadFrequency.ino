#include <M4x4_R3.h>
#include <WDT.h>

M4x4_R3 myMoltino4x4;

uint32_t counterH = 0;
uint16_t counterL = 0;
uint32_t counter32 = 0;
uint16_t freq = 0;

void setup() 
{
  wdt_disable();
  myMoltino4x4.begin();
  wdt_enable(WDTO_120MS);
}

void loop() 
{ 
  myMoltino4x4.readCounters();
  myMoltino4x4.sendTextLcd();
  freq = myMoltino4x4.readHoldingReg( freqDI1 );
  if(freq >= 1000 )
  {
    counterH = myMoltino4x4.readHoldingReg( counter1H );
    counterL = myMoltino4x4.readHoldingReg( counter1L );
    counter32 = counterH << 16 | counterL;
    if( counter32 >= 10000 ) myMoltino4x4.writeSingleCoil( coil4, coilOn );
    if( counter32 >= 20000 )
    {
      myMoltino4x4.resetCounters( counter32_1, 1 );
      myMoltino4x4.writeSingleCoil( coil4, coilOff );
    }
  }
  wdt_reset();
}
