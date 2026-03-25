#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x27, 16, 2);

// Pino do sensor
const int sensorTemp = A0;

// Limites de temperatura (motor)
const float TEMP_NORMAL_MAX = 90.0;
const float TEMP_ALERTA_MAX = 105.0;

void setupTemperatura() {
  // Inicializa o display LCD via I2C
  lcd_1.init();
  // Liga a luz de fundo do display
  lcd_1.backlight();

  Serial.begin(9600);
}

void loopTemperatura() {
  // Leitura do LM35
  float V = analogRead(sensorTemp);
  V = V * (5.0 / 1023.0);

  float T = V * 100.0; // LM35

  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(T);
  lcd_1.print(" C");

  // Linha 2 → status
  lcd_1.setCursor(0, 1);

  if (T <= TEMP_NORMAL_MAX) {
    lcd_1.print("NORMAL");
    
  } else if (T <= TEMP_ALERTA_MAX) {
    lcd_1.print("ALERTA!");
    
  } else {
    lcd_1.print("CRITICO!!!");
  }

  // Monitor serial
  Serial.print("Temperatura: ");
  Serial.println(T);

  delay(1000);
}