/*
  StepperHandler.h
  Library for handling the steppers' movement of the Smartpill Dispenser
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#ifndef StepperHandler_h
#define StepperHandler_h
#include <Stepper.h>

// defines the number of steps in one revolution of the motor 
#define STEPS_PER_REVOLUTION 512
#define DEGREES_90 512
#define DEGREES_45 256

// defines the speed in rpm of the motor 
#define SPEED_RPM 50

class StepperHandler {
  private:
    // Medicine containers
    static Stepper containers[2];

  public:
    // Configures the Steppers
    static void stepperSetup();
    
    // Moves the given stepper by 45 degrees for each pill
    static void dropPills(int numberOfPills, int containerNumber);
};

#endif