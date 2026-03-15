#pragma once
#include "../drivers/LineTrackingDriver.h"
#include "../control/MotorControl.h"

class LineTracking {
public:
    void begin(LineTrackingDriver *lineDriver, MotorControl *motorControl);
    void update();
private:
    LineTrackingDriver *_lineDriver;
    MotorControl *_motorControl;
};