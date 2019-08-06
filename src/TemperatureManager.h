#include <Adafruit_SSD1306.h>
#include <DallasTemperature.h>
#include <OneWire.h>

class TemperatureManager {
    public:
        TemperatureManager(uint8_t oneWireBusPin);
        void init();
        void calculateTemps();
        void display(Adafruit_SSD1306& oled);

    private:
        OneWire m_oneWire;
        DallasTemperature m_sensors;
        float m_cpuTemp;
        float m_internalTemp1;
        float m_internalTemp2;
        float m_externalTemp1;
};
