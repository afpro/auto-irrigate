#include <Arduino.h>

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.write("device startup");
}

void loop() {
}