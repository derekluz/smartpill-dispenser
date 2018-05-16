/*
  HttpHandler.cpp
  Library for handling HTTP requests of the Smartpill Dispenser
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "HttpHandler.h"

char *HttpHandler::ssid;
char *HttpHandler::password;
char *HttpHandler::userId;
char *HttpHandler::smartpillApiUrl;

void HttpHandler::wifiSetup()
{
  HttpHandler::ssid = "monsta_VAP";
  HttpHandler::password = "sosechsunddreissig";
  HttpHandler::userId = "5adfb411509abd1758956981";
  HttpHandler::smartpillApiUrl = "http://192.168.0.103:3000/dispenser/";
  Serial.println("Wifi connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP());
}

int* HttpHandler::getPillsForCurrentMinute()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    String url = String(smartpillApiUrl) + String(userId);
    http.begin(url);
    int httpCode = http.GET();
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end();

    const size_t bufferSize = JSON_ARRAY_SIZE(3) + 10;
    DynamicJsonBuffer jsonBuffer(bufferSize);
    JsonArray& root = jsonBuffer.parseArray(payload);
    int intArray[2] = {root[0], root[1]};
    return intArray;
  }
  else
  {
    Serial.println("Error in WiFi connection");
  }
}

void HttpHandler::sendAlert()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    String url = String(smartpillApiUrl) + String(userId) + String("/alert");
    http.begin(url);
    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.POST("ALERT");
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end();
  }
  else
  {
    Serial.println("Error in WiFi connection");
  }
}