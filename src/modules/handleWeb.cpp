#include "handleWeb.h"

void handleTemp(WebServer& server) {
  float t = leerTemperatura();
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", String(t));
}

void setupWebServer(WebServer& server) {
  server.on("/temp", [&]() { handleTemp(server); });
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}