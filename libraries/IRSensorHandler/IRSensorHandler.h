/*
  IRSensorHandler.h
  Library for handling the IR Sensor of the Smartpill Dispenser
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#ifndef IRSensorHandler_h
#define IRSensorHandler_h

class IRSensorHandler {
  private:
    // Pin number of obstacle IR Sensor
    static int obstaclePin;

  public:
    // Configures the IR Sensor
    static void IRSensorSetup(int obstaclePin);
    
    // Returns true if pill still in final container
    static bool pillWasNotTaken();
};

#endif