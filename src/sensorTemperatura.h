#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensor LM35
const int sensorPin = A0;

// Limites de temperatura
const float TEMP_ALERTA = 90.0;
const float TEMP_PERIGO = 100.0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorPin);

  float tensao = leitura * (5.0 / 1023.0);
  float temperatura = tensao * 100.0;

  lcd.clear();

  // Linha 1: temperatura
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");

  // Linha 2: status
  lcd.setCursor(0, 1);

  if (temperatura >= TEMP_PERIGO) {
    lcd.print("!!! PERIGO !!!");
    Serial.println("PERIGO: Superaquecendo!");
  }
  else if (temperatura >= TEMP_ALERTA) {
    lcd.print("Atencao!");
    Serial.println("ALERTA: Temp alta!");
  }
  else {
    lcd.print("Normal");
    Serial.println("Temperatura normal");
  }

  Serial.print("Temp: ");
  Serial.println(temperatura);

  delay(1000);
}