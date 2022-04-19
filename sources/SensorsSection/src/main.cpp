#include "header.h"

void setup()
{
  

  //Serial.begin(9600);
  dht.begin();
  LoRa.begin(433E6);

  LoRa.setTxPower(20);
  powerManager.setSleepMode(POWERDOWN_SLEEP);
  powerManager.autoCalibrate();
}

void loop()
{

  requestDS18Temp();
  power.sleepDelay(1024);
  
  float *dsArr = readDS18Temp();
  float *dhtArr = readDHT();
  sendData(dsArr, dhtArr);
  //printDhtInfo(dhtArr);
  //printDsInfo(dsArr);
  powerManager.sleepDelay(120000);
}