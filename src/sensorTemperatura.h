#include <LiquidCrystal.h> // Importa a biblioteca do Display LCD
#include <Arduino.h>

// LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensor LM35 (Alterado para A1 para não conflitar com o LDR no A0)
const int pinoLM35 = A1; 

// Limites de temperatura
const float TEMP_ALERTA = 90.0;
const float TEMP_PERIGO = 100.0;

void setupTemperatura() { // Nome corrigido
  lcd.begin(16, 2);
  // Removi o Serial.begin(9600) daqui, pois já roda no main.cpp
}

void loopTemperatura() { // Nome corrigido
  // Aqui dentro vai ficar a sua logica do LM35 no futuro
  // lcd.clear();
  // ...
}