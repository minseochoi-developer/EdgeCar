#include <Arduino.h>
#include "drivers/UltrasonicDriver.h"
#include "drivers/LineTrackingDriver.h"

UltrasonicDriver ultrasonic;
LineTrackingDriver lineTracking;

void setup() {
  Serial.begin(9600);
  ultrasonic.begin();
  lineTracking.begin();
}

void loop() {
  // 초음파 test
  float dist = ultrasonic.getDistance();
  Serial.print("Distance: ");
  if (dist < 0)
    Serial.println("timeout");
  else {
    Serial.print(dist);
    Serial.println(" cm");
  }

  // 라인트래킹 test
  LineState state = lineTracking.read();
  Serial.print("Left : ");
  Serial.println(state.left);
  Serial.print("Center : ");
  Serial.println(state.middle);
  Serial.print("Right : ");
  Serial.println(state.right);

  Serial.println("----------------------");
  delay(3000);
}