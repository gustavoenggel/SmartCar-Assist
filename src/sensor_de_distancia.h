#include <Arduino.h>

// Definindo os pinos
const int pinoTrig = 9;
const int pinoEcho = 10;
const int pinoBuzzer = 8; // Pino onde ligamos o Buzzer

long tempo;
int distancia;

void setup() {
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(pinoBuzzer, OUTPUT); // Define o buzzer como saída de som
  
  Serial.begin(9600);
}

void loop() {
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
  if (distancia > 0 && distancia <= 30) {
    
    tone(pinoBuzzer, 1000); // Liga o apito (frequência de 1000 Hz)
    delay(50);              // Deixa apitando por 50 milissegundos
    noTone(pinoBuzzer);     // Desliga o apito
    
    // O pulo do gato: o tempo que ele fica em silêncio antes do 
    // próximo "bip" depende da distância! 
    // Se a distância for 30cm, espera 300ms. Se for 5cm, espera só 50ms.
    delay(distancia * 10); 
    
  } 
  // Se a distância for maior que 30 cm (sem perigo) ou 0 (erro de leitura)
  else {
    noTone(pinoBuzzer); // Garante que o buzzer fique em silêncio
    delay(100);         // Espera um pouquinho antes de ler de novo
  }
}