#include "device_id.h"

#include <SPIFFS.h>

namespace {
    char storage[37] = "00000000-0000-0000-0000-000000000000";
} // namespace

bool setup_device_id() {
    if (!SPIFFS.begin("/data")) {
        Serial.write("SPIFFS.begin fail\n");
        return false;
    }

    // read
    bool ok;
    {
        File f = SPIFFS.open("/device-id");
        if (f) {
            size_t s = f.readBytes(storage, 36);
            ok = s == 36;
        } else {
            ok = false;
        }
    }

    SPIFFS.end();
    return ok;
}

bool change_device_id(const char *id) {
    if (!id || strlen(id) != 36)
        return false;

    if (!SPIFFS.begin("/data")) {
        Serial.write("SPIFFS.begin fail\n");
        return false;
    }

    bool ok;
    {
        File f = SPIFFS.open("/device-id", FILE_WRITE, true);
        if (f) {
            size_t s = f.write((const uint8_t *) id, 36);
            ok = s == 36;
        } else {
            ok = false;
        }
    }

    SPIFFS.end();

    if (ok) {
        memcpy(storage, id, 36);
    }

    return ok;
}

const char *get_device_id() {
    return storage;
}
