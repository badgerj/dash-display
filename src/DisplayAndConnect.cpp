#include <HardwareSerial.h>

#include "DisplayAndConnect.h"


DisplayAndConnect::DisplayAndConnect() {
}

void DisplayAndConnect::connectAndCollectStats() {
  /*
   * Collect ODB2 stats if wifi
   */
  Serial.println("connectAndCollectStats() called.");
  auto isConnected = connectToOBD2();
  if (isConnected == true)
  {
    collectOBD2Stats();
  }
}

bool DisplayAndConnect::connectToOBD2() {
  /*
   * Connect to wifi/return()
   */
  Serial.println("connectToOBD2() called.");
  return true;
}

void DisplayAndConnect::collectOBD2Stats() {
  /*
   * Get air intake and fuel mix ratio
   * Compute?
   */
  Serial.println("collectOBD2Stats() called.");
}

void DisplayAndConnect::calculateTemps() {
  /*
   * Calc temps, cpu, internal x2, external
   */
  Serial.println("calculateTemps() called.");
}

void DisplayAndConnect::checkModeChange() {
  /*
   * Check for mode change/reset
   *
   * Dash - Temp/Fuel
   * Temp - Internal x 2, External
   * Fuel - Air in Fuel
   * Other? wifi/bluetooth
   *
   * Reset
   * Brightness/select (change C to F)
   */
   Serial.println("checkChangeMode() called.");
}

void DisplayAndConnect::display() {
  /*
   * Display based on mode()
  - Add warning for temp near zero
   */
  Serial.println("displayI2C() called.");
}

/* TODO list
 *
 *
 * Get OLED wired in I2C
 * Get temp control wired in
 * Make a decent base class w and w/out wifi

https://tinyurl.com/y2k2cz4v DS18b20
One/two switches

 */
