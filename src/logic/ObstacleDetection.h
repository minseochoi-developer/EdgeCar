#pragma once
#include "../drivers/UltrasonicDriver.h"
#include "../control/MotorControl.h"

class ObstacleDetection {
public:
    void begin(UltrasonicDriver* ultrasonicDriver, MotorControl* motorControl);
    bool detect();
    void avoid();
private:
    UltrasonicDriver* _ultrasonicDriver;
    MotorControl* _motorControl;
};