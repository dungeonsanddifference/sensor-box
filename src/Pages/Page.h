#ifndef PAGE_H
#define PAGE_H

#include <TFT_eSPI.h>

class Page {
public:
    const char* name;
    TFT_eSPI& tft;
    static const uint8_t numTabs = 4;
    static const char* tabs[numTabs];

    Page(TFT_eSPI& tft_) : tft(tft_) {}
    
    void drawTabs(); // draw tabs, highlight one corresponding to sensor.name
    
    virtual void setup() = 0;     // Initialize the sensor
    virtual void readSensor() = 0; // Read the sensor data
    virtual void updateDisplay() = 0;     // Update the TFT display with the sensor's data
    
    virtual ~Page() = default;  // Virtual destructor for base class
};

class ThermalSensor : public Page {
public:
    ThermalSensor(TFT_eSPI& tft);
    void setup() override;
    void readSensor() override;
    void updateDisplay() override;
};

class DistanceSensor : public Page {
public:
    DistanceSensor(TFT_eSPI& tft);
    void setup() override;
    void readSensor() override;
    void updateDisplay() override;
};

class GestureSensor : public Page {
public:
    GestureSensor(TFT_eSPI& tft);
    void setup() override;
    void readSensor() override;
    void updateDisplay() override;
};

#endif // PAGE_H