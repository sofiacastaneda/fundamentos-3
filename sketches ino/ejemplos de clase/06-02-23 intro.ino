void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT); // rojo
    pinMode(4, OUTPUT); // amarillo
      pinMode(5, OUTPUT); // verde

      //tres leds independientes van a tres pines independientes
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  delay(1000);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  delay(1000);
  digitalWrite(3, HIGH);
  delay(5000);
  digitalWrite(3, LOW);
  delay(3000);
}
