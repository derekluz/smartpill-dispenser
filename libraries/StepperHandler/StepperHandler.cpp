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

void StepperHandler::stepperSetup()
{
    // StepperHandler::containers[0].setSpeed(SPEED_RPM);
    // StepperHandler::containers[1].setSpeed(SPEED_RPM);   
}

void StepperHandler::dropPills(int numberOfPills, int containerNumber)
{
    if(numberOfPills == 0) {
        return;
    }
    // Turns 45 degrees for each pill to be dropped from the given container
    // for (int i = 10; i <= 20; i = i + 10)
    // {
    //     StepperHandler::containers[containerNumber].setSpeed(i);
    //     StepperHandler::containers[containerNumber].step(40 * i);
    // }
    Serial.print("Dropping ");
    Serial.print(numberOfPills);
    Serial.print(" from container ");
    Serial.println(containerNumber);
    StepperHandler::containers[containerNumber].setSpeed(10);
    StepperHandler::containers[containerNumber].step(400);
}