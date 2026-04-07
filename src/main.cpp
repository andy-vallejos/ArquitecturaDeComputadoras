#include "config.h"
#include "modules/handleNetwork.h"
#include "modules/handleTemp.h"
#include "modules/handleLeds.h"
#include "modules/handleWeb.h"

WebServer server(80);
unsigned long lastCheck = 0;
const unsigned long interval = 1000; 

void setup() {
  Serial.begin(115200);
  iniciarLeds();
  iniciarSensorTemp(PIN_DATOS);

  if(!LittleFS.begin(true)){
    Serial.println("Error en LittleFS");
    return;
  }
  setupWiFi(WIFI_SSID, WIFI_PASS);
  setupWebServer(server);
}

void loop() {
  server.handleClient();

  if (millis() - lastCheck >= interval) {
    float temp = leerTemperatura();
    if (temp != -999.0) {
      actualizarLeds(temp);
    }
    lastCheck = millis();
  }
}