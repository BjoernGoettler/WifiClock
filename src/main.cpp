#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define AP_SSID "Your wifi SSID goes here"
#define AP_PASS "Your wifi password goes here"
#define DANISH_SUMMER_TIME_OFFSET 7200

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void connectToWifi()
{
  Serial.println("Connecting to wifi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
}

void setAP(int hour, int minute)
{
  Serial.println("Attempting to set AP");
  Serial.println(hour);
  Serial.println(minute);
  
  char buf[64];
  snprintf(buf, 64, "Klokken er %02d%s%02d", hour, ":",minute);
  
  Serial.println(buf);
  
  WiFi.mode(WIFI_AP);
  WiFi.softAP(buf, AP_PASS);
  Serial.print("Set AP ip address : ");
  Serial.println(WiFi.softAPIP());
}

void setup()
{
  Serial.begin(9600);
  Serial.println();
  
  connectToWifi();

  timeClient.begin();
  timeClient.setTimeOffset(DANISH_SUMMER_TIME_OFFSET);
  timeClient.update();

  setAP(timeClient.getHours(), timeClient.getMinutes());
  
  delay(60000);
  ESP.restart();
}

void loop() {
  // Nothing here
}