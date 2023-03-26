#include <Wire.h>
#include "MPU9250_asukiaaa.h"

MPU9250_asukiaaa mySensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  mySensor.setWire(&Wire);
  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();
}

void loop() {
  mySensor.magUpdate();

  float heading = atan2(mySensor.magUpdate, mySensor.magUpdate) * 180 / PI;
  if (heading < 0) {
    heading += 360;
  }

  String direction;
  if (heading >= 337.5 || heading < 22.5) {
    direction = "North";
  } else if (heading >= 22.5 && heading < 67.5) {
    direction = "Northeast";
  } else if (heading >= 67.5 && heading < 112.5) {
    direction = "East";
  } else if (heading >= 112.5 && heading < 157.5) {
    direction = "Southeast";
  } else if (heading >= 157.5 && heading < 202.5) {
    direction = "South";
  } else if (heading >= 202.5 && heading < 247.5) {
    direction = "Southwest";
  } else if (heading >= 247.5 && heading < 292.5) {
    direction = "West";
  } else if (heading >= 292.5 && heading < 337.5) {
    direction = "Northwest";
  }

  Serial.print("Heading: ");
  Serial.print(heading);
  Serial.print(" degrees (");
  Serial.print(direction);
  Serial.println(")");

  delay(1000);
}
