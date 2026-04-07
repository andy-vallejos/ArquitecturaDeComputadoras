#ifndef HANDLE_TEMP_H
#define HANDLE_TEMP_H
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DallasTemperature.h>

void iniciarSensorTemp(int pin);
float leerTemperatura();
#endif