# 🏠 Smart IoT Home Automation with Blynk & NodeMCU ESP8266

**Platform:** Arduino & Blynk Cloud  

![Made with Arduino](https://img.shields.io/badge/Made%20with-Arduino-blue?logo=arduino)
![Uses Blynk](https://img.shields.io/badge/IoT-Blynk-green?logo=blynk)


---

## ⚡ Overview
Build your own **smart home automation system** using a **NodeMCU ESP8266** and the **Blynk IoT platform**.  
This project allows you to control lights, fans, or any appliances via smartphone — from anywhere.  
It’s simple to set up, modular, and expandable for future IoT enhancements.

---

## 📚 Table of Contents
1. [✨ Features](#-features)  
2. [🧰 Required Components](#-required-components)  
3. [🔌 Circuit Diagram & Connections](#-circuit-diagram--connections)  
4. [☁️ Setting Up Blynk Cloud](#️-setting-up-blynk-cloud)  
5. [🧪 Installing Arduino IDE & Uploading Code](#-installing-arduino-ide--uploading-code)  
6. [📲 Connecting Device to Blynk App](#-connecting-device-to-blynk-app)  
7. [🧩 Optional Features](#-optional-features)  
8. [🧠 How to Run Without Hardware (Demo Mode)](#-how-to-run-without-hardware-demo-mode)  
9. [❓ Troubleshooting](#-troubleshooting)  
10. [👥 Contributing](#-contributing)  


---

## ✨ Features
✅ Control up to **4 devices** via smartphone  
✅ **Remembers relay states** after reboot (cloud sync)  
✅ **OTA-ready** modular firmware structure  
✅ **Wi-Fi provisioning** for easy setup  
✅ **Simple wiring and beginner-friendly**  
✅ Works with **Blynk Cloud** (free tier)

---

## 🧰 Required Components

| Component | Qty | Description |
|------------|-----|-------------|
| NodeMCU ESP8266 | 1 | Wi-Fi-enabled microcontroller |
| 4-Channel Relay Module | 1 | Controls appliances |
| Jumper Wires | As needed | For module connections |
| Power Supply (5 V 2 A) | 1 | Powers NodeMCU & relay board |
| AC Appliances | 1–4 | Fan, Light, etc. |

💡 *Optional:* Add an LED on **D0** to indicate Wi-Fi status.

---

## 🔌 Circuit Diagram & Connections

| Relay Pin | Connect to NodeMCU |
|------------|-------------------|
| VCC | VIN (5 V) |
| GND | G |
| IN1 | D1 |
| IN2 | D2 |
| IN3 | D3 |
| IN4 | D4 |

---

## ☁️ Setting Up Blynk Cloud
1. Go to [https://blynk.cloud](https://blynk.cloud)  
2. Log in or sign up → Create a new **template**  
3. Configure virtual pins:  
   - **V0** → State Memory  
   - **V1–V4** → Device controls  
4. Copy these details into your Arduino sketch:
   ```cpp
   #define BLYNK_TEMPLATE_ID "Your_Template_ID"
   #define BLYNK_TEMPLATE_NAME "Your_Template_Name"
   #define BLYNK_FIRMWARE_VERSION "1.0.0"
