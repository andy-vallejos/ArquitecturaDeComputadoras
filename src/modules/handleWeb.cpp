#include "handleWeb.h"

void handleRoot(WebServer& server) {
  File file = LittleFS.open("/index.html", "r");
  if (!file) {
    server.send(404, "text/plain", "Archivo no encontrado");
    return;
  }
  server.streamFile(file, "text/html");
  file.close();
}

void handleTemp(WebServer& server) {
  float t = leerTemperatura();
  server.send(200, "text/plain", String(t));
}

void setupWebServer(WebServer& server) {
  server.on("/", [&]() { handleRoot(server); });
  server.on("/temp", [&]() { handleTemp(server); });
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}