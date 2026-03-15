#include "LineTracking.h"
#include "../common/config.h"
#include <Arduino.h>

void LineTracking::begin(LineTrackingDriver *lineDriver, MotorControl *motorControl) {
    _lineDriver = lineDriver;
    _motorControl = motorControl;
}

void LineTracking::update() {
    LineState state = _lineDriver->read();
    _motorControl->setSpeed(MOTOR_SPEED_NORMAL);
    if (state.middle && !state.left && !state.right) {
        _motorControl->forward();
    } else if(state.left && !state.right) {
        _motorControl->turnLeft();
    } else if (!state.left && state.right){
        _motorControl->turnRight();
    } else if (state.left && state.right) {
        _motorControl->forward();
    } else {
        _motorControl->stop();
    }
}