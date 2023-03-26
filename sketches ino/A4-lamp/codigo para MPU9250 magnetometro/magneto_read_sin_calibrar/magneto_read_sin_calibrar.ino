#include <MPU9250_asukiaaa.h>
MPU9250_asukiaaa mySensor;
float mDirection;
uint16_t mX, mY, mZ;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mySensor.setWire(&Wire);
  mySensor.beginMag();
}

void loop() {
  mySensor.magUpdate();
  mX = mySensor.magX();
  mY = mySensor.magY();
  mZ = mySensor.magZ();
  mDirection = mySensor.magHorizDirection();
  /*Serial.print("DATA:");
  Serial.print(mX);
  Serial.print(",");
  Serial.print(mY);
  Serial.print(",");
  Serial.print(mZ);
  Serial.print("//");*/
  Serial.println(mDirection);
  // Do what you want
}
