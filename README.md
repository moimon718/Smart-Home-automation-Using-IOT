# 🔌 Smart IoT Home Automation (ESP32 + Blynk)

> Control your home appliances from anywhere using **ESP32** and the **Blynk IoT Cloud**.  
> Improved version of the original ESP8266-based project — faster, modular, and ready for real or simulated hardware.

---

## ✨ Features
✅ Works with **ESP32 Dev Module**  
✅ Control up to **4 appliances** via smartphone  
✅ Uses **Blynk Cloud** for IoT connectivity  
✅ Built-in **Wi-Fi status LED**  
✅ Optional **Demo Mode** (no hardware needed)  
✅ Optional **Scheduler**, **Logger**, and **Web UI** modules  
✅ Fully open-source & modular for learning and projects

---

## 🧰 Required Components

| Component | Quantity | Description |
|------------|-----------|-------------|
| ESP32 Dev Module | 1 | Wi-Fi + Bluetooth MCU |
| 4-Channel Relay | 1 | Controls appliances |
| Jumper Wires | As needed | For connections |
| Power Supply (5V, 2A) | 1 | Stable power |
| AC Appliances | 1–4 | Fan, Light, etc. |
| LED (optional) | 1 | Wi-Fi status indicator |

---

## ⚙️ Circuit Diagram & Connections

| ESP32 Pin | Relay Input | Description |
|------------|--------------|-------------|
| GPIO 5 | IN1 | Relay 1 |
| GPIO 18 | IN2 | Relay 2 |
| GPIO 19 | IN3 | Relay 3 |
| GPIO 21 | IN4 | Relay 4 |
| GPIO 2 | LED | Wi-Fi indicator |
| 5V | VCC | Power to relay |
| GND | GND | Common ground |

💡 Tip: You can add more relays by defining new GPIO pins in `BlynkEdgent_ESP32.ino`.

---

## ☁️ Setting Up Blynk Cloud

1. Go to [Blynk.Cloud](https://blynk.cloud)
2. Create a **new Template** for ESP32:
   - **Virtual Pins:** V1–V4 → Control relays  
   - (Optional) V0 → Memory Sync
3. Copy your:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_TEMPLATE_NAME`
   - Auth Token
4. Paste them inside your `.ino` file.

---

## 🧪 Installing Arduino IDE & Uploading Code

1. **Install Arduino IDE**
2. Go to: `File → Preferences → Additional Boards Manager URLs`
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
3. Open **Boards Manager** → search `esp32` → Install  
4. Install the **Blynk** library from Library Manager  
5. Open `BlynkEdgent_ESP32.ino`
6. Replace Wi-Fi credentials and Blynk details:
```cpp
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
char auth[] = "Your_Blynk_Auth_Token";

Click Upload

📱 Connecting Device to Blynk App

Open Blynk IoT App (Android/iOS)

Log in → Add Device → “Discover Nearby”

Connect to your ESP32 Wi-Fi hotspot

Add 4 Switches → assign to V1–V4

Toggle to control your relays in real time 🚀
