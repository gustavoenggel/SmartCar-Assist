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

  // Mostra no monitor serial para você acompanhar
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // 3. Lógica do Apito (Sensor de Ré)
  // Se a distância for maior que 0 e menor ou igual a 30 cm...
  if (distancia > 0 && distancia < 10) {
    tone(pinoBuzzer, 2000); 
    delay(30);              
    noTone(pinoBuzzer);
    delay(40);             
  } 
  // Condição 2: DISTÂNCIA MÉDIA (Entre 10 e 30 cm)
  else if (distancia >= 10 && distancia <= 30) {
    tone(pinoBuzzer, 1000); 
    delay(50);              
    noTone(pinoBuzzer);     
    
    delay(distancia * 10); 
  } 
  // Condição 3: LONGE OU ERRO (Maior que 30 cm ou 0)
  else {
    noTone(pinoBuzzer); // Garante que o buzzer fique em silêncio
    delay(100);         
  }
}