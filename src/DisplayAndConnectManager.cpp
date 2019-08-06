#include "DisplayAndConnectManager.h"

#include <HardwareSerial.h>


DisplayAndConnectManager::DisplayAndConnectManager(uint8_t portAddress, uint8_t oneWireBusPin)
  : m_oled(-1)
  , m_obd2Manager()
  , m_tempManager(oneWireBusPin)
  , m_portAddress(portAddress)
  , m_mode(0)
{
}

void DisplayAndConnectManager::init() {
  m_oled.begin(SSD1306_SWITCHCAPVCC, m_portAddress);
  m_oled.clearDisplay();
  m_oled.display();
  m_oled.setRotation(1);
  m_obd2Manager.init();
  m_tempManager.init();
}

void DisplayAndConnectManager::connectAndCollectStats() {
  m_obd2Manager.connectAndCollectStats();
  m_tempManager.calculateTemps();
}

void DisplayAndConnectManager::checkModeChange() {
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

void DisplayAndConnectManager::display() {
  /*
   * Display based on mode()
  - Add warning for temp near zero
   */
  Serial.println("displayI2C() called.");
  m_obd2Manager.display(m_oled);
  m_tempManager.display(m_oled);
}
