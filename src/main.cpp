#include <Arduino.h>
#include <HardwareSerial.h>
#include "DisplayAndConnectManager.h"

#define OLED_ADDRESS 0x3C
#define ONEWIRE_BUS_PIN 0x00
auto dAndC = DisplayAndConnectManager(OLED_ADDRESS, ONEWIRE_BUS_PIN);

void setup() {
  // initialize serial communications at 115200 bps
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  dAndC.init();
}

void loop() {
  // Main loop
  Serial.println("mainLoop() called.");
  dAndC.checkModeChange();
  dAndC.connectAndCollectStats();
  dAndC.display();
  Serial.println("mainLoop() end.\n");
  delay(2500);
}
