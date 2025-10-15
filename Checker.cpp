#include <iostream>
#include <assert.h>
using namespace std;

bool isTemperatureOk(float temperature) {
  return (temperature >= 0 && temperature <= 45);
}

bool isSocOk(float soc) {
  return (soc >= 20 && soc <= 80);
}

bool isChargeRateOk(float chargeRate) {
  return (chargeRate <= 0.8);
}

void printTemperatureMessage(float temperature) {
  if (temperature < 0)
    cout << "Temperature too low!\n";
  else if (temperature > 45)
    cout << "Temperature too high!\n";
}

void printSocMessage(float soc) {
  if (soc < 20)
    cout << "State of Charge too low!\n";
  else if (soc > 80)
    cout << "State of Charge too high!\n";
}

void printChargeRateMessage(float chargeRate) {
  if (chargeRate > 0.8)
    cout << "Charge Rate too high!\n";
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool tempOk = isTemperatureOk(temperature);
  bool socOk = isSocOk(soc);
  bool rateOk = isChargeRateOk(chargeRate);

  if (!tempOk) printTemperatureMessage(temperature);
  if (!socOk) printSocMessage(soc);
  if (!rateOk) printChargeRateMessage(chargeRate);

  return tempOk && socOk && rateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 70, 0.7) == false);
  assert(batteryIsOk(-5, 70, 0.7) == false);
  assert(batteryIsOk(25, 10, 0.7) == false);
  assert(batteryIsOk(25, 90, 0.7) == false);
  assert(batteryIsOk(25, 70, 0.9) == false);
  assert(batteryIsOk(0, 20, 0.8) == true);
  assert(batteryIsOk(45, 80, 0) == true);

  cout << "All tests passed successfully!\n";
}


