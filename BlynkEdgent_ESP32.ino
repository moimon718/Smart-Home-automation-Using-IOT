/***************************************************
 * Platform: ESP32 + Blynk IoT Cloud
 ***************************************************/

#define BLYNK_TEMPLATE_ID "Your_ESP32_Template_ID"
#define BLYNK_TEMPLATE_NAME "Smart Home ESP32"
#define BLYNK_FIRMWARE_VERSION "2.0.0"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

// 🧩 Relay Pin Mapping (update if needed)
#define RELAY1 5
#define RELAY2 18
#define RELAY3 19
#define RELAY4 21
#define WIFI_LED 2

// Device state variables
bool relay1State = LOW;
bool relay2State = LOW;
bool relay3State = LOW;
bool relay4State = LOW;

// Blynk virtual pin assignments
#define VPIN_RELAY1 V1
#define VPIN_RELAY2 V2
#define VPIN_RELAY3 V3
#define VPIN_RELAY4 V4

void setup()
{
  Serial.begin(115200);
  delay(100);

  // Set GPIOs as outputs
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(WIFI_LED, OUTPUT);

  digitalWrite(RELAY1, relay1State);
  digitalWrite(RELAY2, relay2State);
  digitalWrite(RELAY3, relay3State);
  digitalWrite(RELAY4, relay4State);
  digitalWrite(WIFI_LED, LOW);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(WIFI_LED, HIGH);

  Blynk.begin(auth, ssid, pass);
  Serial.println("🚀 Connected to Blynk Cloud!");
}

/***************************************************
 * 🧠 Blynk Virtual Pin Controls
 ***************************************************/
BLYNK_WRITE(VPIN_RELAY1)
{
  relay1State = param.asInt();
  digitalWrite(RELAY1, relay1State);
}

BLYNK_WRITE(VPIN_RELAY2)
{
  relay2State = param.asInt();
  digitalWrite(RELAY2, relay2State);
}

BLYNK_WRITE(VPIN_RELAY3)
{
  relay3State = param.asInt();
  digitalWrite(RELAY3, relay3State);
}

BLYNK_WRITE(VPIN_RELAY4)
{
  relay4State = param.asInt();
  digitalWrite(RELAY4, relay4State);
}

/***************************************************
 * 🔁 Main Loop
 ***************************************************/
void loop()
{
  Blynk.run();

  // Optional: LED Blink to show WiFi status
  static unsigned long lastBlink = 0;
  if (millis() - lastBlink > 2000)
  {
    lastBlink = millis();
    digitalWrite(WIFI_LED, !digitalRead(WIFI_LED));
  }
}
