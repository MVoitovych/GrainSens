#include <LoRaFuncs.h>
#include <WiFiFuncs.h>

void setup()
{

  Serial.begin(9600);
  Serial.println("esp started");
  beginLoRa();
  // LoRa.onReceive(onReceive);
  connectWiFI(WiFissid, WiFiPassword);
  ThingSpeak.begin(client);
}

void loop()
{
  onReceive(LoRa.parsePacket());
  connectWiFI(WiFissid, WiFiPassword);
  if (isWiFiConnected && !isMessageSent && millis() - lastSendTime > 20000)
  {
    lastSendTime = millis();
    sendTSData(LoRaData, sensorsCounter);
  }
}
