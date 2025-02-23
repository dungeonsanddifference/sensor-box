#include "Page.h"
#include "../Definitions.h"

const char* Page::tabs[numTabs] = {"Thermal", "Distance", "Gesture", "IR Fork"};

void Page::drawTabs() {
    // Tab background
    tft.fillRect(0, 0, SCREEN_WIDTH, TAB_AREA_HEIGHT, TAB_INACTIVE_BG);
    uint16_t tabWidths[numTabs];
    for (uint8_t i = 0; i < numTabs; i++) {
        tabWidths[i] = tft.textWidth(tabs[i]);
    }
    
    for (uint8_t i = 0; i < numTabs; i++) {
        uint8_t tabX = TAB_SPACING + i * (TAB_WIDTH + TAB_SPACING);
        // Check if the current tab is the active tab
        if (tabs[i] == name) {
            tft.fillRoundRect(tabX, 1, TAB_WIDTH, TAB_HEIGHT, TAB_CORNER_RADIUS, TAB_ACTIVE_BG);
            tft.setTextColor(TAB_ACTIVE_TEXT);
        } else {
            tft.fillRoundRect(tabX, 1, TAB_WIDTH, TAB_HEIGHT, TAB_CORNER_RADIUS, TAB_INACTIVE_BG);
            tft.setTextColor(TAB_INACTIVE_TEXT);
        }
        uint16_t w = tabWidths[i];
        uint16_t cursorX = tabX + (TAB_WIDTH/2) - (w/2);
        tft.drawString(tabs[i], cursorX, 5);
    }
    tft.fillRect(0, TAB_AREA_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT - TAB_AREA_HEIGHT, CANVAS_BACKGROUND);
}
