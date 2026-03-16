#define IR_USE_AVR_TIMER1
#include <Arduino.h>
#include <IRremote.hpp>
#include "IRDriver.h"
#include "../common/pins.h"

void IRDriver::begin() {
    IrReceiver.begin(PIN_IR_RECEIVER);
}

bool IRDriver::available() {
    return IrReceiver.decode();
}

unsigned long IRDriver::read() {
    unsigned long value = IrReceiver.decodedIRData.decodedRawData;
    IrReceiver.resume();
    return value;
}