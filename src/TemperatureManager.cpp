#include "TemperatureManager.h"

#include <HardwareSerial.h>

TemperatureManager::TemperatureManager(uint8_t oneWireBusPin)
  : m_oneWire(oneWireBusPin)
  , m_sensors(&m_oneWire)
{}

void TemperatureManager::init()
{
  m_sensors.begin();
}

void TemperatureManager::calculateTemps() {
  /*
   * Calc temps, cpu, internal x2, external
   */
  Serial.println("calculateTemps() called.");
  m_sensors.requestTemperatures();
  m_internalTemp1 = m_sensors.getTempCByIndex(0);
  Serial.print(m_internalTemp1);
  Serial.println("ºC");
  m_internalTemp2 = m_sensors.getTempCByIndex(1);
  Serial.print(m_internalTemp1);
  Serial.println("ºC");
}

void TemperatureManager::display(Adafruit_SSD1306& oled) {
  oled.setCursor(0, 0);

  oled.setTextColor(BLACK);
  oled.fillRect(0, 16, 64, 8, BLACK);
  oled.fillRect(0, 48, 64, 8, BLACK);


  if (m_internalTemp1 > 30.0f)
  {
    oled.fillRect(0, 16, 16, 8, WHITE);
  }
  if (m_internalTemp1 < 19.0f)
  {
    oled.fillRect(0, 16, 16, 8, WHITE);
  }

  if (m_internalTemp2 > 30.0f)
  {
    oled.fillRect(0, 48, 16, 8, WHITE);
  }
  if (m_internalTemp2 < 19.0f)
  {
    oled.fillRect(0, 48, 16, 8, WHITE);
  }


  oled.setTextColor(WHITE);

  oled.setCursor(0, 0);
  oled.print("   Temp1:");
  oled.setCursor(0, 16);
  char tempString[20];
  sprintf(tempString, "   %.3fC", m_internalTemp1);
  oled.print(tempString);

  oled.setCursor(0, 32);
  oled.print("   Temp2:");
  oled.setCursor(0, 48);
  sprintf(tempString, "   %.3fC", m_internalTemp2);
  oled.print(tempString);

  oled.display();
}
