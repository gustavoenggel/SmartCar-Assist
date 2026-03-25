<<<<<<< Updated upstream
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
=======
#include <Adafruit_LiquidCrystal.h>
>>>>>>> Stashed changes

Adafruit_LiquidCrystal lcd_1(0);

<<<<<<< Updated upstream
// Inicializa o LCD no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
=======
// Pino do sensor
const int sensorTemp = A0;
>>>>>>> Stashed changes

// LEDs (ou saídas)
const int ledNormal  = 1;
const int ledAlerta  = 2;
const int ledCritico = 3;

<<<<<<< Updated upstream
void setupTemperatura() {
  lcd.init();
  lcd.backlight();
  
  pinMode(SENSOR, INPUT);
}

void loopTemperatura() {
  int valor = analogRead(SENSOR);
=======
// Limites (motor de carro)
const float TEMP_NORMAL_MAX = 90.0;
const float TEMP_ALERTA_MAX = 105.0;

void setup()
{
  pinMode(ledNormal, OUTPUT);
  pinMode(ledAlerta, OUTPUT);
  pinMode(ledCritico, OUTPUT);

  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);

  Serial.begin(9600);
}

void loop() {
  // Leitura do sensor (LM35)
  float V = analogRead(sensorTemp);
  V = V * (5.0 / 1023.0);
>>>>>>> Stashed changes

  float T = V * 100.0; // LM35: 10mV por grau

  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(T);
  lcd_1.print(" C");

  // Estados
  lcd_1.setCursor(0, 1);

<<<<<<< Updated upstream
  // Segunda linha: Exibe o status baseado nos novos limites.
  lcd.setCursor(0, 1);
=======
  if (T <= TEMP_NORMAL_MAX) {
    lcd_1.print("NORMAL");
    
    digitalWrite(ledNormal, HIGH);
    digitalWrite(ledAlerta, LOW);
    digitalWrite(ledCritico, LOW);
>>>>>>> Stashed changes

  } else if (T <= TEMP_ALERTA_MAX) {
    lcd_1.print("ALERTA!");
    
    digitalWrite(ledNormal, LOW);
    digitalWrite(ledAlerta, HIGH);
    digitalWrite(ledCritico, LOW);

  } else {
    lcd_1.print("CRITICO!!!");
    
    digitalWrite(ledNormal, LOW);
    digitalWrite(ledAlerta, LOW);
    digitalWrite(ledCritico, HIGH);
  }

<<<<<<< Updated upstream
  delay(1000);
}
=======
  Serial.print("Temperatura: ");
  Serial.println(T);

  delay(1000);
}
>>>>>>> Stashed changes
