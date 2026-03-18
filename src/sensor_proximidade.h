#include <Arduino.h>

// Definicao dos pinos
const int pirPin = 2;     // Fio azul conectado ao sensor branco
const int ledPin = 13;    // LED da placa

// Variaveis de controle
int pirState = LOW;       
int sensorValue = 0;      

void setupproximidade() {
  pinMode(ledPin, OUTPUT);  
  pinMode(pirPin, INPUT);   
  
  Serial.begin(9600);       
  Serial.println("Sistema ativado. Mexa a bolinha DENTRO da area de alcance do sensor.");
}

void loopproximidade() {
  // O sensor branco so sabe dizer HIGH (tem movimento na area) ou LOW (nao tem)
  sensorValue = digitalRead(pirPin);  

  if (sensorValue == HIGH) {            
    digitalWrite(ledPin, HIGH); // Acende o LED simulando a porta abrindo
    
    if (pirState == LOW) {
      Serial.println("Chave detectada proxima ao carro. Abrindo a porta!"); 
      pirState = HIGH;          
    }
  } 
  else {
    digitalWrite(ledPin, LOW);  // Apaga o LED simulando a porta fechando
    
    if (pirState == HIGH) {
      Serial.println("Sem movimento proximo. Fechando a porta.");
      pirState = LOW;           
    }
  }
  
  delay(100); 
}