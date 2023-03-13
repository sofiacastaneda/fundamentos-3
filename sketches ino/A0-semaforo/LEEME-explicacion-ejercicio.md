# Semáforo

Primer ejercicio de control de leds en simultáneo. Hice dos semáforos, la idea es que mientras uno está en verde el otro esté en rojo. 

#### Montaje

![Setup del arduino](https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/setup-semaforo.png)

Demo en Tinkercad 1: [https://www.tinkercad.com/things/29kWNGAkPyZ](https://www.tinkercad.com/things/29kWNGAkPyZ) <br>
Demo en Tinkercad 2: [https://www.tinkercad.com/things/0Ve5gqIvaW1](https://www.tinkercad.com/things/0Ve5gqIvaW1)


#### Código

Existe una [aproximación fácil](https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/secuencia_simple_semaforo_doble.ino) que hice en mi primer sketch, en la cual se secuencia cada uno de los leds utilizando un delay para manejar los intervalos. 

```C++
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
```

Funciona, pero si tuviera que hacer 10 semáforos sería caos. Además los delays hacen lento mi código. La segunda alternativa utiliza condicionales para determinar el comportamiento de cada uno de los semáforos, y en vez de utilizar delays utiliza la función `milis()`. Esta fue difícil de implementar. Todavía hay algo que no funciona pero no sé muy bien qué es. 

Para resolverlo escribí este pedacito de pseudocódigo:
![pseudocódigo](https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/pseudocodigo.jpeg)

_Nota: Hacer click en los intentos para acceder al archivo completo, por cuestiones de claridad omití algunas secciones del código._

#### [Intento 1](https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/semaforo-ii-condicionales.ino)
```C++
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
  
```

#### [Intento 2](https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/semaforo-ii-opuestos.ino)
```C++
int estadoLed1 = HIGH;
int estadoLed2 = LOW;
int estadoLed3 = LOW;
int estadoLed4 = LOW;
int estadoLed5 = LOW;
int estadoLed6 = HIGH;

(...)

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
```

***
#### Links útiles consultados
* [Como usar la función millis y delay en Arduino](https://fidiasrodriguez.com/como-usar-las-funciones-millis-y-delay-en-arduino/)
* [Arduino: Usando la función millis() en lugar de delay()](https://robots-argentina.com.ar/didactica/arduino-usando-la-funcion-millis-en-lugar-de-delay/)
