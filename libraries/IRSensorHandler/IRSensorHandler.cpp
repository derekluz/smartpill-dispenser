/*
  IRSensorHandler.cpp
  Library for handling the IR Sensor of the Smartpill Dispenser
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#include <ESP8266HTTPClient.h>
#include "IRSensorHandler.h"

int IRSensorHandler::obstaclePin;

void IRSensorHandler::IRSensorSetup(int obstaclePin)
{
    IRSensorHandler::obstaclePin = obstaclePin;
    pinMode(obstaclePin, INPUT);
}

bool IRSensorHandler::pillWasNotTaken()
{
    //Reads the output of the obstacle sensor
    //LOW means something is ahead
    int hasObstacle = (digitalRead(IRSensorHandler::obstaclePin) == LOW); 
    if (hasObstacle) 
    {
        Serial.println("Warning! Pill in container.");
    }
    else
    {
        Serial.println("Container is empty");
    }
    return hasObstacle;
}
