#include <BLEDevice.h>

#include "ble.h"

void ble_setup() {
    BLEDevice::init("Irrigation");
}