#pragma once

class MotorControl {
public:
    void begin();
    void forward();
    void backward();
    void turnLeft();
    void turnRight();
    void stop();
    void setSpeed(int speed);
};