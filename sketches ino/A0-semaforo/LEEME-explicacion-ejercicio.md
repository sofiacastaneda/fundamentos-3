# Semáforo

Primer ejercicio de control de leds en simultáneo. Hice dos semáforos, la idea es que mientras uno está en verde el otro esté en rojo. 

#### Montaje

![Setup del arduino](https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/setup-semaforo.png)


#### Código

Existe una [aproximación fácil] que hice en mi primer sketch, (https://github.com/sofiacastaneda/fundamentos-3/blob/main/sketches%20ino/A0-semaforo/secuencia_simple_semaforo_doble.ino), en la cual se secuencia cada uno de los leds utilizando un delay para manejar los intervalos. 

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

Funciona, pero si tuviera que hacer 10 semáforos sería caos. Además los delays hacen lento mi código. La segunda alternativa utiliza condicionales para determinar el comportamiento de cada uno de los semáforos, y en vez de utilizar delays utiliza la función `milis()`.


```C++
a
```

***
#### Links útiles consultados
* [Como usar la función millis y delay en Arduino](https://fidiasrodriguez.com/como-usar-las-funciones-millis-y-delay-en-arduino/)
* [Arduino: Usando la función millis() en lugar de delay()](https://robots-argentina.com.ar/didactica/arduino-usando-la-funcion-millis-en-lugar-de-delay/)
