#include "InfraredFork.h"
#include "../Definitions.h"

InfraredFork::InfraredFork(TFT_eSPI& tft) : Page(tft) {
    name = "IR Fork";
    data.sensorVal = HIGH;
    data.priorVal = HIGH;
    data.lastDetectionTime = 0;
    data.currentDetectionTime = 0;
    data.count = 0;
}

void InfraredFork::setup() {
    pinMode(14, INPUT_PULLUP);
}

void InfraredFork::readSensor() {
    // Read the sensor data
    data.sensorVal = digitalRead(FORK_PIN);
    if (data.sensorVal != data.priorVal) {
        if (data.sensorVal == LOW) {
            data.currentDetectionTime = millis();
            data.priorVal = data.sensorVal;
            data.lastDetectionTime = data.currentDetectionTime;
            data.count = data.count + 1;
        }
    }
}

void InfraredFork::updateDisplay() {
    // Update the TFT display with the sensor's data
}
