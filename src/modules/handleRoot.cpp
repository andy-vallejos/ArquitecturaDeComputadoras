#include "handleRoot.h"

void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");

  if(!file){
    server.send(500, "text/plain", "Error cargando index.html");
    return;
  }

  server.streamFile(file, "text/html");
  file.close();
}
