#include "header.h"

void setup()
{
  Serial.begin(9600);
  dht.begin();

  if (!LoRa.begin(433E6))
  {
    while (1)
      ;
  }
  LoRa.setTxPower(20);
}

void loop()
{
  requestDS18Temp();
  float *dhtArr = readDHT();
  float *dsArr = readDS18Temp();
  sendData(dsArr, dhtArr);
  printDhtInfo(dhtArr);
  printDsInfo(dsArr);
  
  delay(10000);
}