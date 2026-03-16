#include <Arduino.h>
#include "LineTrackingDriver.h"
#include "../common/pins.h"

// 적외선을 발사해 반사되는 양 측정
// 검은색 선 HIGH, 흰색 선 LOW
// 라인트래킹 센서 3개를 사용하여 왼쪽, 중앙, 오른쪽의 상태를 읽어옴

void LineTrackingDriver::begin() {
    pinMode(PIN_LINE_LEFT, INPUT);
    pinMode(PIN_LINE_CENTER, INPUT);
    pinMode(PIN_LINE_RIGHT, INPUT);
}

// 검은 라인 위 -> true, 이탈 -> false
LineState LineTrackingDriver::read() {
    LineState state;
    state.left = digitalRead(PIN_LINE_LEFT) == HIGH;
    state.middle = digitalRead(PIN_LINE_CENTER) == HIGH;
    state.right = digitalRead(PIN_LINE_RIGHT) == HIGH;
    return state;
}