#pragma once
#include <Arduino.h>
#include <LoRa.h>
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "TP-LINK_5208"
#define WIFI_PASS "92700734"
#define TS_CH_ID 1720742
#define TS_WRITE "K67H5DP08Q28RJ8L"

unsigned long int channelID = TS_CH_ID;
const char *WiFissid = WIFI_SSID;
const char *WiFiPassword = WIFI_PASS;
const char *writeKey = TS_WRITE;

String lastSenderAdress = "00000000";
String* LoRaData;

unsigned const int lengthOfAdress = lastSenderAdress.length();
unsigned short sensorsCounter = 0;
int lastMsgId = 0;
unsigned short WiFiCounter = 0;
unsigned long long lastTimeWiFiConnection = 0;
unsigned long long lastSendTime = 0;
WiFiClient client;

bool isMessageSent = true;
bool isWiFiConnected = false;