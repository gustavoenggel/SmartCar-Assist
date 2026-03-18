#include <Arduino.h> 

#include "sensorLDR.h"
#include "sensorTemperatura.h"
// #include "sensor_de_distancia.h"  <-- Comente esta linha
// #include "sensor_proximidade.h"   <-- Comente esta linha

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Sistema SmartCar...");

  setupLDR();
  setupTemperatura();
}

void loop() {
  loopLDR();
  loopTemperatura();

  delay(100); 
}