#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int SENSOR = A5;

// Inicializa o LCD no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temperatura;

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
}