#include <Arduino.h> 

// 1. Incluindo todos os seus arquivos de sensores
#include "sensorLDR.h"
#include "sensorTemperatura.h"
#include "sensor_de_distancia.h"
#include "sensor_proximidade.h"

void setup() {
  // Inicia a comunicação serial uma única vez para todo o projeto
  Serial.begin(9600);
  Serial.println("Iniciando Sistema SmartCar...");

  // 2. Chamando as configurações de cada sensor
  setupLDR();
  setupTemperatura();
  setupDISTANCIA();
  setupproximidade();


  // setupDistancia();  // (Descomente se tiver criado essa função no .h)
  // setupProximidade(); // (Descomente se tiver criado essa função no .h)
}

void loop() {
  // 3. Executando a lógica de cada sensor continuamente
  loopLDR();
  loopTemperatura();
  loopDISTANCIA();
  loopproximidade();

  // loopDistancia();
  // loopProximidade();

  // Opcional: um pequeno delay geral para não travar o microcontrolador
  delay(100); 
}
