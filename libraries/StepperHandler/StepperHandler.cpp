/*
  StepperHandler.cpp
  Library for handling the steppers' movement of the Smartpill Dispenser
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#include <ESP8266HTTPClient.h>
#include <Stepper.h>
#include "StepperHandler.h"

Stepper stepper1(STEPS_PER_REVOLUTION, D0, D2, D1, D3);
Stepper stepper2(STEPS_PER_REVOLUTION, D4, D6, D5, D7);
Stepper StepperHandler::containers[2] = {stepper1, stepper2};

void StepperHandler::stepperSetup() {}

void StepperHandler::dropPills(int numberOfPills, int containerNumber)
{
    if(numberOfPills == 0) {
        return;
    }
    // Turns 45 degrees for each pill to be dropped from the given container
    int angle = numberOfPills * DEGREES_45;
    StepperHandler::containers[containerNumber].setSpeed(SPEED_RPM);
    StepperHandler::containers[containerNumber].step(angle);
}