#include <Adafruit_SSD1306.h>

class OBD2Manager {
    public:
        OBD2Manager();
        void init();
        void connectAndCollectStats();
        void collectStats();
        void display(Adafruit_SSD1306& oled);

    private:
        bool connect();
        bool m_isConnected;
};
