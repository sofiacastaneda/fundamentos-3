Aprendiendo: 

Solution #3 suggests trying a different I2C address to solve the "PAJ7620 I2C error - halting" issue with the GY-PAJ7620 sensor.
Try a different I2C address: Some sensors may have a default I2C address that conflicts with other devices on the same bus. Try changing the I2C address of the sensor by connecting the AD pin to the VCC or GND pin on the sensor module, depending on the address you want to set.

__

The I2C bus allows multiple devices to communicate with each other using a single bus. Each device on the bus has a unique I2C address, which allows the Arduino to address and communicate with each device individually.

Some sensors, including the GY-PAJ7620, may have a default I2C address that conflicts with other devices on the same bus. In this case, you can try changing the I2C address of the sensor by connecting the AD pin to the VCC or GND pin on the sensor module, depending on the address you want to set.

The AD pin on the GY-PAJ7620 sensor module is used to set the I2C address. By connecting the AD pin to VCC or GND, you can set the I2C address to a different value. The default I2C address of the sensor is 0x73.

To change the I2C address of the sensor, you can connect the AD pin to either VCC or GND. If you connect the AD pin to VCC, the new I2C address will be 0x77. If you connect the AD pin to GND, the new I2C address will be 0x72.

After setting the new I2C address, you will need to update your code to use the new address. You can find examples of how to do this in the GY-PAJ7620 library documentation or in online tutorials.
