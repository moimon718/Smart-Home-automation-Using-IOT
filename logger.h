#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

void logEvent(const String &msg) {
  Serial.print("[LOG] ");
  Serial.println(msg);
}

#endif
