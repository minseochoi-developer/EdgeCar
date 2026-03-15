#include "ModeManager.h"
#include <Arduino.h>

void ModeManager::begin() {
    _currentMode = Mode::LINE_TRACKING;
}

Mode ModeManager::getMode() {
    return _currentMode;
}

void ModeManager::setMode(Mode mode) {
    _currentMode = mode;
}