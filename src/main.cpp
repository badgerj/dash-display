#include <Arduino.h>
#include <HardwareSerial.h>
#include "DisplayAndConnect.h"

void setup() {
  // initialize serial communications at 115200 bps
  Serial.begin(115200);
}

void loop() {
  // Main loop
  Serial.println("mainLoop() called.");
  auto display = DisplayAndConnect();
  display.checkModeChange();
  display.connectAndCollectStats();
  display.calculateTemps();
  display.display();
  Serial.println("mainLoop() end.\n"); 
  delay(2000);
}



