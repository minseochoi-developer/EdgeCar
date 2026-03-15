#include "drivers/UltrasonicDriver.h"
#include "drivers/LineTrackingDriver.h"
#include "drivers/IRDriver.h"
#include "control/MotorControl.h"
#include "logic/LineTracking.h"
#include "logic/ObstacleDetection.h"
#include "logic/ModeManager.h"
#include <Arduino.h>

UltrasonicDriver ultrasonicDriver;
LineTrackingDriver lineTrackingDriver;
IRDriver irDriver;
MotorControl motorControl;
LineTracking lineLogic;
ObstacleDetection obstacleLogic;
ModeManager modeManager;

void setup() {
    Serial.begin(9600);
    ultrasonicDriver.begin();
    lineTrackingDriver.begin();
    irDriver.begin();
    motorControl.begin();
    lineLogic.begin(&lineTrackingDriver, &motorControl);
    obstacleLogic.begin(&ultrasonicDriver, &motorControl);
}

void loop() {
    if (irDriver.available()) {
        unsigned long code = irDriver.read();
        if (code == 0x00FF38C7 || code == 0x488F3CBB)
            modeManager.setMode(Mode::MANUAL);
        else if (code == 0x00FF18E7 || code == 0x48B73CB9)
            modeManager.setMode(Mode::LINE_TRACKING);
    }

    if (modeManager.getMode() == Mode::LINE_TRACKING) {
        if (obstacleLogic.detect()) {
            obstacleLogic.avoid();
        } else {
            lineLogic.update();
        }
    }
}