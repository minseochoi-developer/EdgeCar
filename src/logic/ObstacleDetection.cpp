#include "ObstacleDetection.h"
#include "../common/config.h"
#include <Arduino.h>

void ObstacleDetection::begin(UltrasonicDriver* ultrasonicDriver, MotorControl* motorControl) {
    _ultrasonicDriver = ultrasonicDriver;
    _motorControl = motorControl;
}

bool ObstacleDetection::detect() {
    float distance = _ultrasonicDriver->getDistance();
    if (distance >= 0.0f && distance <= OBSTACLE_DISTANCE_CM) {
        return true;
    }

    return false;
}

void ObstacleDetection::avoid() {
    _motorControl->stop();
    delay(500);
    _motorControl->backward();
    delay(OBSTACLE_BACK_MS);
    _motorControl->turnRight();
    delay(OBSTACLE_TURN_MS);
    _motorControl->forward();
    delay(500);
}
