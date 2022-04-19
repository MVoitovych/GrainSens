#define DHTPIN 8
#define DS18PIN 7
#define ONEWIREPIN 5

#include <Arduino.h>
#include <LoRa.h>
#include <OneWire.h>
#include <microDS18B20.h>
#include <DHT.h>
#include <GyverPower.h>

int counter = 0;
byte localAddress = 0xBB;
byte destination = 0xFF;
uint32_t time = 0;
long lastSendTime = 0;
unsigned int interval = 2000;
// uint64_t timer = 0;

uint8_t adr1[] = {0x28, 0xFF, 0x64, 0x2, 0xEF, 0x4C, 0xF4, 0x1A};
uint8_t adr2[] = {0x28, 0xFF, 0x64, 0x2, 0xEF, 0x4, 0x61, 0xD9};
uint8_t adr3[] = {0x28, 0xFF, 0x64, 0x2, 0x19, 0xCE, 0x13, 0x92};

DHT dht(DHTPIN, DHT11);
GyverPower powerManager;
MicroDS18B20<ONEWIREPIN, adr1> ds1;
MicroDS18B20<ONEWIREPIN, adr2> ds2;
MicroDS18B20<ONEWIREPIN, adr3> ds3;

void sendData(float *dsTemp, float *dhtInfo)
{
    //Serial.print("Sending packet: ");
    Serial.println(counter);

    LoRa.beginPacket();
    LoRa.println(destination);
    LoRa.println(localAddress);
    LoRa.println(dsTemp[0]);
    LoRa.println(dsTemp[1]);
    LoRa.println(dsTemp[2]);
    LoRa.println(dhtInfo[0]);
    LoRa.println(dhtInfo[1]);
    LoRa.println(counter);
    LoRa.endPacket();

    counter++;
}

float *readDHT()
{
    static float dhtSensorsInfo[2];
    dhtSensorsInfo[0] = dht.readHumidity();
    dhtSensorsInfo[1] = dht.readTemperature();
    return dhtSensorsInfo;
}

float *readDS18Temp()
{
    static float temps[3] = {404, 404, 404};
    if (ds1.readTemp() && ds2.readTemp() && ds3.readTemp())
    {
        temps[0] = ds1.getTemp();
        temps[1] = ds2.getTemp();
        temps[2] = ds3.getTemp();
    }
    return temps;
}

void requestDS18Temp()
{
    ds1.requestTemp();
    ds2.requestTemp();
    ds3.requestTemp();
}
void printDhtInfo(float *dhtArr)
{
    Serial.println("DHT");
    Serial.println(dhtArr[0]);
    Serial.println(dhtArr[1]);
    Serial.println("______________");
}
void printDsInfo(float *dsArr)
{
    Serial.println("DS");
    Serial.println(dsArr[0]);
    Serial.println(dsArr[1]);
    Serial.println(dsArr[2]);
    Serial.println("______________");
}
