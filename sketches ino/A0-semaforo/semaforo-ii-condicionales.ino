int rojo_A = 5;
int amarillo_A = 4;
int verde_A = 3;

int rojo_B = 11;
int amarillo_B = 10;
int verde_B = 9;

bool otro_semaforo_en_verde;
bool otro_semaforo_en_rojo;
bool cambio = false;

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

void secuencia_semaforo(){
  
  otro_semaforo_en_verde = true;
  otro_semaforo_en_rojo = true;
  
  if(millis()-tiempoAnterior>=periodo_semaforo){
  cambio = true;
  tiempoAnterior=millis();
  }
  
  if(millis()-tiempoAnterior>=periodo_cambio){
  cambio = false;
  otro_semaforo_en_verde = false;
  otro_semaforo_en_rojo = false;
  tiempoAnterior=millis();
  }
  
}


void loop() {
  
  secuencia_semaforo();
  
  if (otro_semaforo_en_verde == true){
     //luces semaforo B
     digitalWrite(verde_B, LOW);
     digitalWrite(amarillo_B, LOW);
     digitalWrite(rojo_B, HIGH);
  } else {
     //luces semaforo B
     digitalWrite(verde_B, HIGH);
     digitalWrite(amarillo_B, LOW);
     digitalWrite(rojo_B, LOW);
  }

  if (otro_semaforo_en_rojo == true){
    //luces semaforo A
     digitalWrite(verde_A, HIGH);
     digitalWrite(amarillo_A, LOW);
     digitalWrite(rojo_A, LOW);
  } else{
     //luces semaforo A
     digitalWrite(verde_A, LOW);
     digitalWrite(amarillo_A, LOW);
     digitalWrite(rojo_A, HIGH);
  }
  
  if (cambio == true){
     //luces semaforo A
     digitalWrite(verde_A, LOW);
     digitalWrite(amarillo_A, HIGH);
     digitalWrite(rojo_A, LOW);
     //luces semaforo B
     digitalWrite(verde_B, LOW);
     digitalWrite(amarillo_B, HIGH);
     digitalWrite(rojo_B, LOW);
  }
  

  
}



/*
  if (apagar == true){
  semaforo_en_verde == false;
  otro_semaforo_en_rojo == false;
   
  }

  if (verde_A == HIGH){
     //luces semaforo A
     digitalWrite(rojo_A, LOW);
     digitalWrite(amarillo_A, LOW);
     //luces semaforo B
     digitalWrite(verde_B, LOW);
     digitalWrite(amarillo_B, LOW);
     digitalWrite(verde_B, HIGH);
  } 
  else(verde_A == LOW){
     //luces semaforo A
     digitalWrite(rojo_A, HIGH);
     digitalWrite(amarillo_A, LOW);
     //luces semaforo B
     digitalWrite(verde_B, LOW);
     digitalWrite(amarillo_B, LOW);
     digitalWrite(verde_B, HIGH);
  } */
  
