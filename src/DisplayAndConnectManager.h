#include <OBD2Manager.h>
#include <TemperatureManager.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayAndConnectManager {
    public:
        DisplayAndConnectManager(uint8_t portAddress, uint8_t oneWireBusPin);
        void init();
        void connectAndCollectStats();
        void checkModeChange();
        void display();

    private:
        Adafruit_SSD1306 m_oled;
        OBD2Manager m_obd2Manager;
        TemperatureManager m_tempManager;
        uint8_t m_portAddress;
        uint8_t m_mode;
};
