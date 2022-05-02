#include <LoRaFuncs.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6))
  {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }    
}

void loop()
{
  onReceive(LoRa.parsePacket());
}
