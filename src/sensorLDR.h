// ==========================================
// Sistema de Acionamento Automático de Farol (2 LEDs)
// ==========================================

// 1. Definição de Pinos e Constantes
const int pinoLDR = A0;       // Pino analógico onde o LDR está conectado
const int pinoFarol1 = 2;     // Pino digital conectado ao primeiro LED/Relé
const int pinoFarol2 = 4;     // Pino digital conectado ao segundo LED/Relé
const int limiteEscuro = 400; // Limite de luz (ajuste conforme a iluminação do ambiente)

void setupLDR() {
  // 2. Configuração inicial        
  pinMode(pinoLDR, INPUT);     // Configura o pino do LDR como entrada
  pinMode(pinoFarol1, OUTPUT); // Configura o pino do primeiro farol como saída
  pinMode(pinoFarol2, OUTPUT); // Configura o pino do segundo farol como saída
  
  // Garante que ambos os faróis iniciem desligados
  digitalWrite(pinoFarol1, LOW); 
  digitalWrite(pinoFarol2, LOW); 
}

void loopLDR() {
  // 3. Leitura do Sensor
  int nivelLuz = analogRead(pinoLDR);
  
  // Imprime o valor no Monitor Serial para calibração
  Serial.print("Nível de luminosidade: ");
  Serial.println(nivelLuz);

  // 4. Lógica de Acionamento
  // Se a luz ambiente for menor que o limite definido, acende os faróis
  if (nivelLuz < limiteEscuro) {
    digitalWrite(pinoFarol1, HIGH); // Liga o farol 1
    digitalWrite(pinoFarol2, HIGH); // Liga o farol 2
    Serial.println("Status: Escuro -> Faróis LIGADOS");
  } else {
    digitalWrite(pinoFarol1, LOW);  // Desliga o farol 1
    digitalWrite(pinoFarol2, LOW);  // Desliga o farol 2
    Serial.println("Status: Claro -> Faróis DESLIGADOS");
  }

  // Pequeno atraso para evitar leituras frenéticas e oscilações do relé/LEDs
  delay(500); 
}