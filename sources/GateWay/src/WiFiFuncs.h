#include "header.h"

void connectWiFI(const char *ssid, const char *pass)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFiCounter = 0;
        isWiFiConnected = true;
        return;
    }
    if (millis() - lastTimeWiFiConnection > 10000)
    {
        if (WiFiCounter == 5)
        {
            WiFiCounter = 0;
            Serial.println("WiFi connection failed :(");
            isWiFiConnected = false;
        }
        else
        {
            WiFiCounter++;
            WiFi.mode(WIFI_STA);
            WiFi.begin(ssid, pass);
            isWiFiConnected = false;
            lastTimeWiFiConnection = millis();
        }
    }
}

void sendTSData(String *dataArr, uint16_t numOfSensors)
{
    for (int i = 1; i <= numOfSensors; i++)
    {
        ThingSpeak.setField(i, dataArr[i-1]);
    }
    if(ThingSpeak.writeFields(channelID, writeKey) == 200){
        isMessageSent = true;
        Serial.println("message sent");
        delete LoRaData;
    }
    else{
        isMessageSent = false;
        Serial.println("message isn`t sent");
    }
}

