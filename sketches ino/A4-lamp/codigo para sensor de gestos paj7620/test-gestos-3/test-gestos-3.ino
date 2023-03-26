#include <Wire.h>
#include <paj7620.h>

paj7620 gestureSensor(0x73); // initialize Paj7620 object

void setup() {
  Serial.begin(9600);
  Wire.begin();
  gestureSensor.initialize(); // initialize Paj7620 sensor
}

void loop() {
  int gesture = gestureSensor.readGesture(); // read gesture data
  if (gesture != 0) { // check if gesture data is valid
    Serial.println(gesture); // print the gesture number
  }
  delay(100); // wait for a short period
}
