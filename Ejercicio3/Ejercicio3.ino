int PULSADOR = 2;
int LED = 3;
int ESTADO = LOW;


void setup (){
  pinMode(PULSADOR, INPUT);   // pin como entrada
  pinMode(LED, OUTPUT);       // pin como salida
}

void loop(){
  while(digitalRead(PULSADOR) == LOW){  // espero a que el pulsador se presione
  }

  ESTADO = digitalRead(LED);            // leo estado del LED
  digitalWrite(LED, !ESTADO);           // escribo valor contrario
  while(digitalRead(PULSADOR) == HIGH){ // antirebote
  }
}
