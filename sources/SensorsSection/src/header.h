#pragma once
#define DHTPIN 8
#define DS18PIN 3
#define ONEWIREPIN 3

#include <Arduino.h>
#include <GyverPower.h>
#include <microDS18B20.h>
#include <DHT.h>
#include <LoRa.h>
#include <OneWire.h>

int counter = 0;
String localAddress = "abcdffff";
unsigned int ds18Amount = 2;
uint32_t time = 0;
unsigned int interval = 2000;

uint8_t adr1[] = {0x28, 0xFF, 0x64, 0x2, 0xEF, 0x4C, 0xF4, 0x1A};
uint8_t adr2[] = {0x28, 0xFF, 0x64, 0x2, 0xEF, 0x4, 0x61, 0xD9};
uint8_t *adresses[2] = {adr1, adr2};

DHT dht(DHTPIN, DHT11);
GyverPower powerManager;
MicroDS18B20<DS18PIN, DS_ADDR_MODE> *dsSensors = new MicroDS18B20<DS18PIN, DS_ADDR_MODE>[ds18Amount];
