#include <Wire.h>
#include "MPU9250_asukiaaa.h"
uint16_t mX, mY, mZ;
MPU9250_asukiaaa mySensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  mySensor.setWire(&Wire);
  mySensor.beginMag();
}

void loop() {
  mySensor.magUpdate();
  mX = mySensor.magX();
  mY = mySensor.magY();
  mZ = mySensor.magZ();
  
  float heading = atan2(mySensor.magY, mySensor.magX) * 180 / PI;
  if (heading < 0) {
    heading += 360;
  }

  Serial.print("Heading: ");
  Serial.print(heading);
  Serial.println(" degrees");

  delay(1000);
}
