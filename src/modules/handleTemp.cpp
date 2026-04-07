#include "handleTemp.h"

OneWire oneWire;
DallasTemperature sensors(&oneWire);

void iniciarSensorTemp(int pin) {
  oneWire.begin(pin);
  sensors.begin();
}

float leerTemperatura() {
  sensors.requestTemperatures();
  float t = sensors.getTempCByIndex(0);
  return (t == DEVICE_DISCONNECTED_C) ? -999.0 : t;
}