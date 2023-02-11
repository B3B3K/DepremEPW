#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
String ssid = "IMDAT!_ACIL_ENKAZ";

void setup() {
  Wire.pins(0, 2);
  Wire.begin(0, 2);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid.c_str());
  delay(20000);
  sensors_event_t event;
  bmp.getEvent(&event);
  ssid = String(event.pressure) + "hPa";
  WiFi.softAPdisconnect(true);
  WiFi.softAP(ssid.c_str());
  delay(20000);
  bmp.getEvent(&event);
  ssid = String(event.pressure) + "hPa";
  WiFi.softAPdisconnect(true);
  WiFi.softAP(ssid.c_str());
}

void loop() {}
