#pragma once

struct LineState {
    bool left;
    bool middle;
    bool right;
};

class LineTrackingDriver {
    public:
        void begin();
        LineState read();
};