<<<<<<< HEAD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
=======
#include <LiquidCrystal.h> // Importa a biblioteca do Display LCD
#include <Arduino.h>
>>>>>>> 46ac52165eeb597b0ec632e5f9ba9b32065cf5ef

const int SENSOR = A5;

<<<<<<< HEAD
// Inicializa o LCD no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
=======
// Sensor LM35 (Alterado para A1 para não conflitar com o LDR no A0)
const int pinoLM35 = A1; 
>>>>>>> 46ac52165eeb597b0ec632e5f9ba9b32065cf5ef

float temperatura;

<<<<<<< HEAD
void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(SENSOR, INPUT);
}

void loop() {
  int valor = analogRead(SENSOR);

  // Converter leitura para temperatura (LM35)
  // 5.0V / 1023 passos * 100 para converter os 10mV/°C do LM35
  temperatura = (valor * 5.0 / 1023.0) * 30.0;

  lcd.clear();

  // Primeira linha: Exibe o valor numérico
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1); // Exibe com 1 casa decimal
  lcd.print(" C");

  // Segunda linha: Exibe o status baseado nos novos limites
  lcd.setCursor(0, 1);

  if (temperatura <= 90) {
    lcd.print("Status: Normal");
  } 
  else if (temperatura > 90 && temperatura <= 100) {
    lcd.print("Status: ATENCAO");
  } 
  else {
    lcd.print("ALERTA PERIGO!");
  }

  delay(1000);
=======
void setupTemperatura() { // Nome corrigido
  lcd.begin(16, 2);
  // Removi o Serial.begin(9600) daqui, pois já roda no main.cpp
}

void loopTemperatura() { // Nome corrigido
  // Aqui dentro vai ficar a sua logica do LM35 no futuro
  // lcd.clear();
  // ...
>>>>>>> 46ac52165eeb597b0ec632e5f9ba9b32065cf5ef
}