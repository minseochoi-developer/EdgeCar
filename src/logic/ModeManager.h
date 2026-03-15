#pragma once

enum class Mode
{
    MANUAL,
    LINE_TRACKING
};

class ModeManager {
public:
    void begin();
    Mode getMode();
    void setMode(Mode mode);

private:
    Mode _currentMode;
};