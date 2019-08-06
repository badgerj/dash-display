#include "OBD2Manager.h"

#include <HardwareSerial.h>

OBD2Manager::OBD2Manager()
  : m_isConnected(false)
{}

void OBD2Manager::init() {
}

void OBD2Manager::connectAndCollectStats()
{
  /*
   * Collect ODB2 stats if wifi
   */
  Serial.println("connectAndCollectStats() called.");
  auto isConnected = connect();
  if (isConnected == true)
  {
    collectStats();
  }
}

bool OBD2Manager::connect() {
  /*
   * Connect to wifi/return()
   */
  Serial.println("connect() called.");
  return true;
}

void OBD2Manager::collectStats() {
  /*
   * Get air intake and fuel mix ratio
   * Compute?
   */
  Serial.println("collectStats() called.");
}

void OBD2Manager::display(Adafruit_SSD1306& oled) {
}


