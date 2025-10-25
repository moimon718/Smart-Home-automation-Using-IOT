#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <BlynkSimpleEsp32.h>

void checkSchedule(int relayPin, int startHour, int endHour) {
  time_t now = time(nullptr);
  struct tm *t = localtime(&now);
  int hour = t->tm_hour;
  if (hour >= startHour && hour < endHour) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
}

#endif
