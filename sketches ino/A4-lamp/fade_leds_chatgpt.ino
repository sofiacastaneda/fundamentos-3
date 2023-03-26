void setup() {
  pinMode(9, OUTPUT);  // set pin 9 as output
  pinMode(10, OUTPUT); // set pin 10 as output
  pinMode(11, OUTPUT); // set pin 11 as output
}

void loop() {
  analogWrite(9, 255); // set red to maximum brightness (255 out of 255)
  analogWrite(10, 0);  // set green to minimum brightness (0 out of 255)
  analogWrite(11, 0);  // set blue to minimum brightness (0 out of 255)
  delay(1000);         // wait for 1 second
  
  analogWrite(9, 0);   // set red to minimum brightness (0 out of 255)
  analogWrite(10, 255);// set green to maximum brightness (255 out of 255)
  analogWrite(11, 0);  // set blue to minimum brightness (0 out of 255)
  delay(1000);         // wait for 1 second
  
  analogWrite(9, 0);   // set red to minimum brightness (0 out of 255)
  analogWrite(10, 0);  // set green to minimum brightness (0 out of 255)
  analogWrite(11, 255);// set blue to maximum brightness (255 out of 255)
  delay(1000);         // wait for 1 second
}
