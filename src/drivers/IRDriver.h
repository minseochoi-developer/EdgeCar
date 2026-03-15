#pragma once

class IRDriver {
public:
    void begin();
    bool available();
    unsigned long read();
};