#include "header.h"

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
        Serial.println(senderAdress.length());
        Serial.println(senderAdress);
        ;

        Serial.println("masg ID ");
        Serial.println(msgId);

        int dsNum = LoRa.readStringUntil('|').toInt();
        Serial.print("num of ds18 ");
        Serial.println(dsNum);
        float *receivedData = new float[dsNum + 2];
        for (int i = 0; i < dsNum + 2; i++)
        {
          Serial.print("sensor ");
          Serial.println(i + 1);
          receivedData[i] = LoRa.readStringUntil('|').toFloat();
          Serial.println(receivedData[i]);
        }

        delete receivedData;
        lastMsgId = msgId;
        lastSenderAdress = senderAdress;
      }
    }
    else{
      return ;
    }
  }
}
