#include "handleLeds.h"

void iniciarLeds(){
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
}

void actualizarLeds(float temperatura){
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);

  if(temperatura > 30){
    digitalWrite(LED_ROJO, HIGH);
  }
  else if(temperatura >= 25){
    digitalWrite(LED_VERDE, HIGH);
  }
  else{
    digitalWrite(LED_AZUL, HIGH);
  }

}