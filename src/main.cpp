#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>


const int pinDatos = 23; 
const int ledRojo = 21;
const int ledVerde = 22;
const int ledAzul =  19;

OneWire oneWire(pinDatos);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  Serial.println("Buscando sensor de temperatura...");
}

void loop() {
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0); 

  if(tempC != DEVICE_DISCONNECTED_C) {
    Serial.println("Temperatura: " + String(tempC) + " °C");

    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);

    if(tempC > 30){
      digitalWrite(ledRojo, HIGH); 
    }
    else if(tempC >= 25){
      digitalWrite(ledVerde, HIGH); 
    }
    else{
      digitalWrite(ledAzul, HIGH); 
    }

  } else {
    Serial.println("Error: No se detecta el sensor. Revisa cables y resistencia.");
  }

  delay(1000);
}