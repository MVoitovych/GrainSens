#include "header.h"

void sendData(float *dsTemp, float *dhtInfo)
{
    LoRa.idle();
    LoRa.beginPacket();
    LoRa.print(localAddress);
    LoRa.print('|');
    LoRa.print(packetID);
    LoRa.print('|');
    LoRa.print(ds18Amount);
    LoRa.print('|');
    for (unsigned int i = 0; i < sizeof(ds18Amount); i++)
    {
        LoRa.print(dsTemp[i]);
        LoRa.print('|');
    }
    LoRa.print(dhtInfo[0]);
    LoRa.print('|');
    LoRa.print(dhtInfo[1]);
    LoRa.print('|');
    LoRa.endPacket();
    LoRa.sleep();
}
