#include <SoftwareSerial.h>
#include "Dabble.h"

// Pines L298N
#define ENA 5      // PWM motor izquierdo
#define IN1 6      // Motor izquierdo IN1
#define IN2 7      // Motor izquierdo IN2
#define ENB 10     // PWM motor derecho
#define IN3 8      // Motor derecho IN3
#define IN4 9      // Motor derecho IN4

SoftwareSerial BT(2, 3); // RX, TX para HM-10

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  BT.begin(9600);
  Dabble.begin(BT);
}

void loop() {
  Dabble.processInput();

  if (GamePad.isUpPressed()) adelante();
  else if (GamePad.isDownPressed()) atras();
  else if (GamePad.isLeftPressed()) izquierda();
  else if (GamePad.isRightPressed()) derecha();
  else detener();
}

void adelante() {
  // Motor izquierdo normal
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor derecho INVERTIDO (corrección)
  digitalWrite(IN3, LOW);  // Invertido
  digitalWrite(IN4, HIGH); // Invertido
  analogWrite(ENA, 200);   // Ajusta velocidad si es necesario
  analogWrite(ENB, 200);
}

void atras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Motor derecho INVERTIDO
  digitalWrite(IN3, HIGH); // Invertido
  digitalWrite(IN4, LOW);  // Invertido
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void izquierda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Motor derecho INVERTIDO
  digitalWrite(IN3, LOW);  // Invertido
  digitalWrite(IN4, HIGH); // Invertido
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void derecha() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor derecho INVERTIDO
  digitalWrite(IN3, HIGH); // Invertido
  digitalWrite(IN4, LOW);  // Invertido
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void detener() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analog