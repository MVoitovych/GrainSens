#include <Arduino.h>
#include <LoRa.h>


//uint64_t time = 0;
String lastSenderAdress = "00000000";
unsigned const int lengthOfAdress = lastSenderAdress.length();

float dstemp[4];
int lastMsgId = 0;