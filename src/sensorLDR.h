int LDR = A0;          // pino do LDR
int farol1 = 2;        // LED 1 (farol esquerdo)
int farol2 = 4;        // LED 2 (farol direito)
int valorLDR = 0;      

void setupLDR()
{
  pinMode(farol1, OUTPUT);
  pinMode(farol2, OUTPUT);
  
 
}

void loopLDR()
{
  valorLDR = analogRead(LDR);   // leitura do LDR
  Serial.println(valorLDR);     // mostra no monitor serial

  if(valorLDR > 1000)  // ambiente escuro
  {
    digitalWrite(farol1, HIGH); // liga LED 1
    digitalWrite(farol2, HIGH); // liga LED 2
  }
  else                // ambiente claro
  {
    digitalWrite(farol1, LOW);  // desliga LED 1
    digitalWrite(farol2, LOW);  // desliga LED 2
  }

  delay(200);
}