#include "Page.h"

struct InfraredForkData {
    bool sensorVal;
    bool priorVal;
    unsigned long lastDetectionTime;
    unsigned long currentDetectionTime;
    uint16_t count;
};

class InfraredFork : public Page {
public:
    InfraredForkData data;
    InfraredFork(TFT_eSPI& tft);
    void setup() override;
    void readSensor() override;
    void updateDisplay() override;
};
