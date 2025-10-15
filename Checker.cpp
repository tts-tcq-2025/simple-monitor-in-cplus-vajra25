#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

// Helper function to check if value is within range
bool isInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

// Pure check functions
bool isTemperatureOk(float temperature) {
    return isInRange(temperature, 0, 45);
}

bool isSocOk(float soc) {
    return isInRange(soc, 20, 80);
}

bool isChargeRateOk(float chargeRate) {
    return isInRange(chargeRate, 0, 0.8);
}

// Function to print detailed messages for each parameter
bool reportBatteryStatus(float temperature, float soc, float chargeRate) {
    bool temperatureOk = isTemperatureOk(temperature);
    bool socOk = isSocOk(soc);
    bool chargeRateOk = isChargeRateOk(chargeRate);

    if (!temperatureOk) {
        if (temperature < 0) cout << "Temperature too low!\n";
        else cout << "Temperature too high!\n";
    }

    if (!socOk) {
        if (soc < 20) cout << "State of Charge too low!\n";
        else cout << "State of Charge too high!\n";
    }

    if (!chargeRateOk) {
        if (chargeRate > 0.8) cout << "Charge Rate too high!\n";
    }

    return (temperatureOk && socOk && chargeRateOk);
}

// Wrapper function for testing purpose
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return reportBatteryStatus(temperature, soc, chargeRate);
}

int main() {
    // Normal case
    assert(batteryIsOk(25, 70, 0.7) == true);

    // Temperature too high
    assert(batteryIsOk(50, 70, 0.7) == false);

    // Temperature too low
    assert(batteryIsOk(-5, 70, 0.7) == false);

    // SOC too low
    assert(batteryIsOk(25, 10, 0.7) == false);

    // SOC too high
    assert(batteryIsOk(25, 90, 0.7) == false);

    // Charge rate too high
    assert(batteryIsOk(25, 70, 0.9) == false);

    // Edge values (boundary conditions)
    assert(batteryIsOk(0, 20, 0.8) == true);
    assert(batteryIsOk(45, 80, 0) == true);

    cout << "All tests passed successfully!\n";
    return 0;
}

