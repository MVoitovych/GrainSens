#include "header.h"

#define SS 15
#define RST 16
#define DIO0 2
void beginLoRa()
{
    LoRa.setPins(SS, RST, DIO0);
    if (!LoRa.begin(433E6))
    {
        Serial.println("Starting LoRa failed!");
        while (1)
            ;
    }
    else
    {
        Serial.println("LoRa Receiver");
    }
}

void onReceive(int packetSize)
{
    if (packetSize <= lengthOfAdress)
    {
        return;
    }
    else
    {
        Serial.println("Received packet");
        String senderAdress = LoRa.readStringUntil('|');
        int msgId = LoRa.readStringUntil('|').toInt();
        if (senderAdress.length() == lengthOfAdress)
        {
            if (lastSenderAdress == senderAdress && lastMsgId == msgId)
            {
                Serial.println("packet repeat");
            }
            else
            {
                Serial.print("adress is ");
                Serial.println(senderAdress);

                Serial.println("msg ID ");
                Serial.println(msgId);

                uint16_t dsNum = LoRa.readStringUntil('|').toInt();
                sensorsCounter = dsNum + 2;
                String *receivedData = new String[sensorsCounter];
                for (int i = 0; i < sensorsCounter; i++)
                {
                    Serial.print("sensor ");
                    Serial.println(i + 1);
                    receivedData[i] = LoRa.readStringUntil('|');
                    Serial.println(receivedData[i]);
                }
                isMessageSent = false;
                LoRaData = receivedData;
                lastMsgId = msgId;
                lastSenderAdress = senderAdress;
                Serial.print("With RSSI ");
                Serial.println(LoRa.packetRssi());
                //delete receivedData;
            }
        }
        else
        {
            return;
        }
    }
}
