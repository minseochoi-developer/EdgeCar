#include "UltrasonicDriver.h"
#include "../common/pins.h"
#include <Arduino.h>

// 2cm ~ 500cm 범위 내의 장애물 거리를 측정
// Trig 핀에 10us 이상의 HIGH 신호를 보내면 초음파가 발사되고, Echo 핀에서 초음파가 돌아오는 시간을 측정하여 거리를 계산

void UltrasonicDriver::begin() {
    pinMode(PIN_ULTRASONIC_TRIG, OUTPUT);
    pinMode(PIN_ULTRASONIC_ECHO, INPUT);
}

float UltrasonicDriver::getDistance() {
    digitalWrite(PIN_ULTRASONIC_TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(PIN_ULTRASONIC_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_ULTRASONIC_TRIG, LOW);

    long duration = pulseIn(PIN_ULTRASONIC_ECHO, HIGH, 30000);
    
    if (duration == 0)
        return -1.0f;

    return (duration / 2.0f) * 0.034f;
}