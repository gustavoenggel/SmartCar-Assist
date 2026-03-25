#include <Arduino.h>

// Definindo os pinos
const int pinoTrig = 9;
const int pinoEcho = 10;
const int pinoBuzzer = 8; // Pino onde ligamos o Buzzer

long tempo;
int distancia;

void setupDISTANCIA() {
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(pinoBuzzer, OUTPUT); // Define o buzzer como saída de som
  
 
}

void loopDISTANCIA() {
  // 1. Envia o pulso de som (grito do sensor)
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // 2. Calcula o tempo e a distância
  tempo = pulseIn(pinoEcho, HIGH);
  distancia = tempo * 0.034 / 2;
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  /// 3. Lógica do Apito (Sensor de Ré)
  
  // Condição 1: MUITO PERTO (Batida iminente: menor ou igual a 10 cm)
  if (distancia > 0 && distancia <= 10) {
    
    tone(pinoBuzzer, 1500); 
    delay(50); // Apenas um pequeno atraso para estabilizar o ciclo do loop
  } 
  
  // Condição 2: DISTÂNCIA DE APROXIMAÇÃO (Entre 10 e 30 cm)
  else if (distancia > 10 && distancia <= 30) {
    tone(pinoBuzzer, 1500); 
    delay(80);             
    noTone(pinoBuzzer);     
    
    delay(distancia * 15); 
  } 
 
  else {
    noTone(pinoBuzzer); 
    delay(50);          
  }
}