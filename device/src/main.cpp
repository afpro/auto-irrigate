#include "device_id.h"

#include <Arduino.h>

void setup() {
    delay(1000);
    Serial.begin(9600);
    Serial.write("device startup\n");

    if (setup_device_id()) {
        const char *id = get_device_id();
        Serial.write("device id: ");
        Serial.write(id);
        Serial.write('\n');
    } else {
        Serial.write("setup device id failed\n");
    }
}

void loop() {}