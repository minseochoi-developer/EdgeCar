#include <Arduino.h>
#include "drivers/UltrasonicDriver.h"
#include "drivers/LineTrackingDriver.h"
#include "drivers/IRDriver.h"
#include "control/MotorControl.h"
#include "logic/LineTracking.h"
#include "logic/ObstacleDetection.h"
#include "logic/ModeManager.h"

UltrasonicDriver ultrasonicDriver;
LineTrackingDriver lineTrackingDriver;
IRDriver irDriver;
MotorControl *motorControl = new MotorControl();
LineTracking lineLogic;
ObstacleDetection obstacleLogic;
ModeManager modeManager;

void setup() {
    Serial.begin(9600);
    delay(3000);
    motorControl->begin();
    ultrasonicDriver.begin();
    lineTrackingDriver.begin();
    irDriver.begin();
    
    lineLogic.begin(&lineTrackingDriver, motorControl);
    obstacleLogic.begin(&ultrasonicDriver, motorControl);
    modeManager.begin();
}

void loop() {
    if (irDriver.available()) {
        unsigned long code = irDriver.read();
        // MANUAL 모드 : 5, LINE_TRACKING 모드 : 2
        if (code ==  3810328320)
            modeManager.setMode(Mode::MANUAL);
        else if (code == 3877175040)
            modeManager.setMode(Mode::LINE_TRACKING);
    }

    if (modeManager.getMode() == Mode::LINE_TRACKING) {
        if (obstacleLogic.detect()) {
            obstacleLogic.avoid();
        } else {
            lineLogic.update();
        }
    } else if (modeManager.getMode() == Mode::MANUAL) {
        motorControl->stop();
    }
    
    delay(500);
}