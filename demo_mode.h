#ifndef DEMO_MODE_H
#define DEMO_MODE_H

#ifdef DEMO_MODE
// Simulate 4 virtual relays
void simulateRelays() {
  static unsigned long lastToggle = 0;
  static bool state = false;
  if (millis() - lastToggle > 3000) { // every 3 sec
    state = !state;
    Serial.print("[Demo] Relay state: ");
    Serial.println(state ? "ON" : "OFF");
    lastToggle = millis();
  }
}
#endif

#endif
