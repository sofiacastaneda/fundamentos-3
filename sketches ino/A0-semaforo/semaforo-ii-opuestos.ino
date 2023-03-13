int rojo_A = 5;
int amarillo_A = 4;
int verde_A = 3;

int rojo_B = 11;
int amarillo_B = 10;
int verde_B = 9;

int estadoLed1 = HIGH;
int estadoLed2 = LOW;
int estadoLed3 = LOW;
int estadoLed4 = LOW;
int estadoLed5 = LOW;
int estadoLed6 = HIGH;

int periodo_semaforo = 300;
int periodo_cambio = 150;
unsigned long tiempoAnterior = 0;

void setup() {
  //Semáforo A
  pinMode(rojo_A, OUTPUT);
  pinMode(amarillo_A, OUTPUT);
  pinMode(verde_A, OUTPUT);

  //Semáforo B
  pinMode(rojo_B, OUTPUT);
  pinMode(amarillo_B, OUTPUT);
  pinMode(verde_B, OUTPUT);
}


void cambiar_estado(){
  estadoLed1=!estadoLed1;
    //estadoLed2=!estadoLed2;
    estadoLed3=!estadoLed3;
    estadoLed4=!estadoLed4;
    //estadoLed5=!estadoLed5;
    estadoLed6=!estadoLed6;
}
  

void loop() {
   //luces semaforo A
   digitalWrite(verde_A, estadoLed1);
   //digitalWrite(amarillo_A, estadoLed2);
   digitalWrite(rojo_A, estadoLed3);
  
   //luces semaforo B
   digitalWrite(verde_B, estadoLed4);
   //digitalWrite(amarillo_B, estadoLed5);
   digitalWrite(rojo_B, estadoLed6);
  
  if(millis()-tiempoAnterior>=periodo_semaforo){ 
    cambiar_estado();

    digitalWrite(verde_A, estadoLed1);
    //digitalWrite(amarillo_A, estadoLed2);
    digitalWrite(rojo_A, estadoLed3);

    digitalWrite(verde_A, estadoLed3);
    //digitalWrite(amarillo_A, estadoLed4);
    digitalWrite(rojo_A, estadoLed5);
  }
  
  
}
