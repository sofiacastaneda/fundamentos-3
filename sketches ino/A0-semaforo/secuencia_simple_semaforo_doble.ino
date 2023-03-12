int rojo_A = 5;
int amarillo_A = 4;
int verde_A = 3;

int rojo_B = 11;
int amarillo_B = 10;
int verde_B = 9;

bool encendido_A = true;

void setup() {
  
  //Semáforo A
  pinMode(rojo_A, OUTPUT);
  pinMode(amarillo_A, OUTPUT);
  pinMode(verde_A, OUTPUT);

  //Semáforo B
  pinMode(rojo_B, OUTPUT);
  pinMode(amarillo_B, OUTPUT);
  pinMode(verde_B, OUTPUT);

  digitalWrite(rojo_A, LOW);
  digitalWrite(amarillo_A, LOW);
  digitalWrite(verde_A, LOW);

  digitalWrite(rojo_B, LOW);
  digitalWrite(amarillo_B, LOW);
  digitalWrite(verde_B, LOW);
}

void loop() {
  digitalWrite(rojo_A, HIGH);
  digitalWrite(verde_B, HIGH);
  delay(1000);
  digitalWrite(rojo_A, LOW);
  digitalWrite(verde_B, LOW);

  digitalWrite(amarillo_A, HIGH);
  digitalWrite(amarillo_B, HIGH);
  delay(1000);
  digitalWrite(amarillo_A, LOW);
  digitalWrite(amarillo_B, LOW);

  digitalWrite(verde_A, HIGH);
  digitalWrite(rojo_B, HIGH);
  delay(1000);
  digitalWrite(verde_A, LOW);
  digitalWrite(rojo_B, LOW);
}
