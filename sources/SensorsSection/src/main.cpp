#include "SensorsFuncs.h"
#include "LoRaFuncs.h"

void setup()
{

  dht.begin();
  LoRa.begin(433E6);
  LoRa.setTxPower(20);
  LoRa.sleep();

  powerManager.setSleepMode(POWERDOWN_SLEEP);
  powerManager.autoCalibrate();

  for (unsigned int i = 0; i < ds18Amount; i++)
  {
    dsSensors[i].setAddress(adresses[i]);
  }

}

void loop()
{
  requestDS18Temp();

  power.sleepDelay(1024);

  float *dhtArr = readDHT();
  float *dsArr = readDS18Temp();
  
  sendData(dsArr, dhtArr);
  power.sleepDelay(128);
  sendData(dsArr, dhtArr);
  packetID++;

  delete dsArr;
  powerManager.sleepDelay(600000);
}