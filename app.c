#include <LiquidCrystal.h>

// LCD conectado diretamente (sem I2C)
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

// Pinos dos dispositivos
const int pinLDR = A0;
const int ledVermelho = 8;
const int ledAmarelo = 9;
const int ledVerde = 10;
const int buzzer = 11;

// Controle de tempo do buzzer
unsigned long ultimoAlarme = 0;
const unsigned long intervaloAlarme = 3000;

void setup() {
  // Inicialização do LCD e pinos
  lcd.begin(16, 2);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  // Mensagem inicial
  lcd.setCursor(0, 0);
  lcd.print("Vinheria Agnello");
  lcd.setCursor(0, 1);
  lcd.print("Bem-vindo!");
  delay(3000);
  lcd.clear();
}

void loop() {
  int leituraLDR = analogRead(pinLDR);  // Lê o sensor LDR
  int porcentagem = map(leituraLDR, 0, 1023, 0, 100); // Converte para escala %

  // Debug no console
  Serial.print("LDR: ");
  Serial.print(leituraLDR);
  Serial.print(" -> ");
  Serial.print(porcentagem);
  Serial.println("%");

  // Mostra a leitura no LCD
  lcd.setCursor(0, 0);
  lcd.print("Luz: ");
  lcd.print(porcentagem);
  lcd.print("%     ");

  // Lógica de decisão
  if (porcentagem <= 30) {
    lcd.setCursor(0, 1);
    lcd.print("Status: Ideal    ");
    acenderLED(ledVerde, false);
  } 
  else if (porcentagem <= 60) {
    lcd.setCursor(0, 1);
    lcd.print("Status: Alerta   ");
    acenderLED(ledAmarelo, true);
  } 
  else {
    lcd.setCursor(0, 1);
    lcd.print("Status: Perigo   ");
    acenderLED(ledVermelho, true);
  }

  delay(500); // Pequeno delay para evitar oscilação
}

// Função que acende um LED e gerencia o buzzer
void acenderLED(int led, bool ligarBuzzer) {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(led, HIGH);

  if (ligarBuzzer && millis() - ultimoAlarme > intervaloAlarme) {
    tone(buzzer, 1000, 300); // Buzzer toca por 300ms
    ultimoAlarme = millis();
  } else {
    noTone(buzzer); // Garante que não fique tocando contínuo
  }
}
