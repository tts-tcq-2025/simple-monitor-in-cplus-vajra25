#include <iostream>
#include <assert.h>
using namespace std;

bool inRange(float value, float min, float max, const char* message) {
  if(value < min || value > max) {
    cout << message << " out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  return inRange(temperature, 0, 45, "Temperature") &&
         inRange(soc, 20, 80, "State of Charge") &&
         inRange(chargeRate, 0, 0.8, "Charge Rate");
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  cout << "All tests passed successfully!\n";
  return 0;
}

