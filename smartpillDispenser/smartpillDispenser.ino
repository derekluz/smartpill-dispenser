/*
  SmartpillDispenser.ino
  Main file of the Smartpill Dispenser Project
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#include <HttpHandler.h>
#include <StepperHandler.h>
#include <IRSensorHandler.h>

void setup() {
  Serial.begin(115200);
  HttpHandler::wifiSetup();
  IRSensorHandler::IRSensorSetup(D8);
  StepperHandler::stepperSetup();
}

void loop() {
  Serial.println();
  Serial.println("New Loop - Every 30s");
  if(IRSensorHandler::pillWasNotTaken()) {
    HttpHandler::sendAlert();
  }
  int* pillsForCurrentMinute = HttpHandler::getPillsForCurrentMinute();

  // Drop pills for the minute from first container
  StepperHandler::dropPills(pillsForCurrentMinute[0], 0);

  // Drop pills for the minute from second container
  // StepperHandler::dropPills(pillsForCurrentMinute[1], 1);
  delay(30000);
}
