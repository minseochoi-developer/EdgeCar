#include <Arduino.h>
#include "MotorControl.h"
#include "../common/pins.h"
#include "../common/config.h"

// IN1, IN2 -> 오른쪽 모터 방향 제어
// IN3, IN4 -> 왼쪽 모터 방향 제어
// ENA -> 오른쪽 모터 속도 제어
// ENB -> 왼쪽 모터 속도 제어

void MotorControl::begin() {
    pinMode(PIN_MOTOR_ENA, OUTPUT);
    pinMode(PIN_MOTOR_ENB, OUTPUT);
    pinMode(PIN_MOTOR_IN1, OUTPUT);
    pinMode(PIN_MOTOR_IN2, OUTPUT);
    pinMode(PIN_MOTOR_IN3, OUTPUT);
    pinMode(PIN_MOTOR_IN4, OUTPUT);
}

void MotorControl::forward() {
    digitalWrite(PIN_MOTOR_IN1, LOW);
    digitalWrite(PIN_MOTOR_IN2, HIGH);
    digitalWrite(PIN_MOTOR_IN3, HIGH);
    digitalWrite(PIN_MOTOR_IN4, LOW);
    analogWrite(PIN_MOTOR_ENA, MOTOR_SPEED_NORMAL);
    analogWrite(PIN_MOTOR_ENB, MOTOR_SPEED_NORMAL);
}

void MotorControl::backward() {
    digitalWrite(PIN_MOTOR_IN1, HIGH);
    digitalWrite(PIN_MOTOR_IN2, LOW);
    digitalWrite(PIN_MOTOR_IN3, LOW);
    digitalWrite(PIN_MOTOR_IN4, HIGH);
    analogWrite(PIN_MOTOR_ENA, MOTOR_SPEED_NORMAL);
    analogWrite(PIN_MOTOR_ENB, MOTOR_SPEED_NORMAL);
}

void MotorControl::turnLeft() {
    // 오른쪽 모터는 정회전, 왼쪽 모터는 역회전
    digitalWrite(PIN_MOTOR_IN1, LOW);
    digitalWrite(PIN_MOTOR_IN2, HIGH);
    digitalWrite(PIN_MOTOR_IN3, LOW);
    digitalWrite(PIN_MOTOR_IN4, HIGH);
    analogWrite(PIN_MOTOR_ENA, MOTOR_SPEED_NORMAL);
    analogWrite(PIN_MOTOR_ENB, MOTOR_SPEED_NORMAL);
}

void MotorControl::turnRight() {
    // 오른쪽 모터는 역회전, 왼쪽 모터는 정회전
    digitalWrite(PIN_MOTOR_IN1, HIGH);
    digitalWrite(PIN_MOTOR_IN2, LOW);
    digitalWrite(PIN_MOTOR_IN3, HIGH);
    digitalWrite(PIN_MOTOR_IN4, LOW);
    analogWrite(PIN_MOTOR_ENA, MOTOR_SPEED_NORMAL);
    analogWrite(PIN_MOTOR_ENB, MOTOR_SPEED_NORMAL);
}

void MotorControl::stop() {
    digitalWrite(PIN_MOTOR_IN1, LOW);
    digitalWrite(PIN_MOTOR_IN2, LOW);
    digitalWrite(PIN_MOTOR_IN3, LOW);
    digitalWrite(PIN_MOTOR_IN4, LOW);
}