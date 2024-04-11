
#ifndef C111_H
#define C111_H

#include "C111_Pinout.h"

#include <Wire.h>
#include <TMP1075.h>
#include <MCP23008.h>
#include <array>

class C111 {
public:

    C111();
    ~C111();

    bool initialize();

    void setPowerSupplyKeepAliveEnabled(bool enabled);
    bool isPowerSupplyKeepAliveEnabled();
    float getPowerSupplyVoltage();

    void setCanTerminated(bool terminated);
    bool isCanTerminated();

    void setDifferentialDataEnabled(bool enabled);
    bool isDifferentialDataEnabled();

    float getTemperatureCelcius();
    void setOverheatTempCelcius(float temp);
    bool isOverHeated();

    float getPSU1Current();
    float getPSU1TemperatureCelcius();
    void setPSU1Enabled(bool enabled);
    bool isPSU1Enabled();

    float getPSU2Current();
    float getPSU2TemperatureCelcius();
    void setPSU2Enabled(bool enabled);
    bool isPSU2Enabled();

    uint8_t getUserInputState(uint8_t input);

    std::array<uint8_t, 8> getUserInputState();

    uint16_t readLineLevelAudio();

private:
    TwoWire wire;
    TMP1075::TMP1075 tempSensor;
    MCP23008 ioExpander;
    bool initialized;
    float overheatTempCelcius;
};

#endif
