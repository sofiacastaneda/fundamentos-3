/*nabo.dev
Primero se calibra el sensor durante 20s para tener lecturas estables.
*/

#include <MPU9250_asukiaaa.h> //Shoutout a asukiaa porque hizo la única librería que funciona, tqm <3

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 21
#define SCL_PIN 22
#endif

#define CALIB_SEC 20

MPU9250_asukiaaa mySensor;

uint8_t sensorId;
float mDirection, mX, mY, mZ;

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  Serial.begin(115200);

  //PARA CALIBRAR
  while(!Serial);
  Serial.println("started");

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  Wire.begin(SDA_PIN, SCL_PIN); // SDA, SCL
#else
  Wire.begin();
#endif

  mySensor.setWire(&Wire);
  while (mySensor.readId(&sensorId) != 0) {
    Serial.println("Cannot find device to read sensorId");
    delay(2000);
  }
  mySensor.beginMag();

  float magXMin, magXMax, magYMin, magYMax, magZ, magZMin, magZMax;
  Serial.println("Start scanning values of magnetometer to get offset values.");
  Serial.println("Rotate your device for " + String(CALIB_SEC) + " seconds.");
  setMagMinMaxAndSetOffset(&mySensor, CALIB_SEC);
  Serial.println("Finished setting offset values.");
  ///////

  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

//PARA CALIBRAR
void setMagMinMaxAndSetOffset(MPU9250_asukiaaa* sensor, int seconds) {
  unsigned long calibStartAt = millis();
  float magX, magXMin, magXMax, magY, magYMin, magYMax, magZ, magZMin, magZMax;

  sensor->magUpdate();
  magXMin = magXMax = sensor->magX();
  magYMin = magYMax = sensor->magY();
  magZMin = magZMax = sensor->magZ();

  while(millis() - calibStartAt < (unsigned long) seconds * 1000) {
    delay(100);
    sensor->magUpdate();
    magX = sensor->magX();
    magY = sensor->magY();
    magZ = sensor->magZ();
    if (magX > magXMax) magXMax = magX;
    if (magY > magYMax) magYMax = magY;
    if (magZ > magZMax) magZMax = magZ;
    if (magX < magXMin) magXMin = magX;
    if (magY < magYMin) magYMin = magY;
    if (magZ < magZMin) magZMin = magZ;
  }

  sensor->magXOffset = - (magXMax + magXMin) / 2;
  sensor->magYOffset = - (magYMax + magYMin) / 2;
  sensor->magZOffset = - (magZMax + magZMin) / 2;
}

void loop() {

  String direction;
  if (mDirection >= -180 && mDirection < -120) {
    direction = "Rojo";
    // Red
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    
  } else if (mDirection >= -120 && mDirection < -60) {
    direction = "Amarillo";
    // Yellow
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);

  } else if (mDirection >= -60 && mDirection < 0) {
    direction = "Verde";
    // Green
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  
  } else if (mDirection >= 0 && mDirection < 60) {
    direction = "Cian";
    // Cyan
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    
  } else if (mDirection >= 60 && mDirection < 120) {
    direction = "Azul";
    //Blue
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    
  } else if (mDirection >= 120 && mDirection < 180) {
    direction = "Magenta";
    // Magenta
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  } 
  
  Serial.println("sensorId: " + String(sensorId));
  //LECTURAS DEL SENSOR SERIAL
  mySensor.magUpdate();
  mX = mySensor.magX();
  mY = mySensor.magY();
  mZ = mySensor.magZ();
  mDirection = mySensor.magHorizDirection();
  Serial.println("mySensor.magXOffset = " + String(mySensor.magXOffset) + ";");
  Serial.println("mySensor.maxYOffset = " + String(mySensor.magYOffset) + ";");
  Serial.println("mySensor.magZOffset = " + String(mySensor.magZOffset) + ";");
  Serial.println("magX: " + String(mX));
  Serial.println("maxY: " + String(mY));
  Serial.println("magZ: " + String(mZ));
  Serial.println("horizontal direction: " + String(mDirection));
  Serial.println("at " + String(millis()) + "ms");
  Serial.print("Espectro: ");
  Serial.print(direction);
  Serial.println(""); // Add an empty line
  delay(100);
  /////////////////////

   
}
