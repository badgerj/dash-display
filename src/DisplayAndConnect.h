
class DisplayAndConnect {
    public:
        DisplayAndConnect();
        void connectAndCollectStats();
        bool connectToOBD2();
        void collectOBD2Stats();
        void calculateTemps();
        void checkModeChange();
        void display();

    private:
        uint8_t m_connection;
        uint8_t m_mode;
        bool m_isConnected;
        uint8_t m_cpuTemp;
        uint8_t m_internalTemp1;
        uint8_t m_internalTemp2;
};
