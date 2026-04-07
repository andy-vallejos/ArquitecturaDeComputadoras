#ifndef HANDLE_ROOT_H
#define HANDLE_ROOT_H
#include <FS.h>
#include <SPIFFS.h>
#include <WebServer.h>

extern WebServer server;

void handleRoot();

#endif