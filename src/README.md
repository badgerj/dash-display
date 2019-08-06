/* TODO list
 *
 * Fix OLED constructor (don't use -1)
 * Add helper class for DisplayManger
    Investigate use of alarms
  /*
  uint8_t high = 30;
  uint8_t low = 31;
  m_sensors.setHighAlarmTemp(&high, 30);
  m_sensors.setLowAlarmTemp(&low, 32);
  */

  uint8_t address;
  bool result;
  result = m_sensors.getAddress(&address, 0);
  if (result)
  {
    Serial.println("Got it");
  }
  auto high = m_sensors.getHighAlarmTemp(&address);

 * Add helper class for OBD2Manager
 * Make a decent base class w and w/out wifi
 * One/two switches
 */
