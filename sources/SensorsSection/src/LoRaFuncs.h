#include "header.h"


void sendData(float *dsTemp, float *dhtInfo)
{
    LoRa.beginPacket();

    LoRa.println(localAddress);

    for (unsigned int i = 0; i < sizeof(ds18Amount); i++)
    {
        LoRa.println(dsTemp[i]);
    }

    LoRa.println(dhtInfo[0]);
    LoRa.println(dhtInfo[1]);
    LoRa.println(counter);
    LoRa.endPacket();

    counter++;
}

void recieveMessage();