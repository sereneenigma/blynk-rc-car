# ESP8266 Blynk RC Car 🚗

![RC Car Project](rccar.jpg)

A Wi-Fi controlled RC car built using **NodeMCU ESP8266**, **L298N motor driver**, and **four DC motors**. The car is controlled remotely through the **Blynk IoT mobile application**.

## 🚀 Features

- Wi-Fi based remote control
- Blynk mobile application control
- Forward and backward movement
- Left and right movement
- Stop control
- Four-wheel drive
- NodeMCU ESP8266 based control system
- L298N motor driver for motor control

## 🛠️ Components Used

| Component | Quantity | Purpose |
|---|---:|---|
| NodeMCU ESP8266 | 1 | Main controller and Wi-Fi communication |
| L298N Motor Driver | 1 | Controls motor direction |
| DC Gear Motors | 4 | Drives the four wheels |
| RC Car Chassis | 1 | Supports the complete assembly |
| Battery | 1 | Provides power |
| Jumper Wires | As required | Electrical connections |
| Blynk IoT | 1 | Mobile control interface |

## ⚙️ Working

The Blynk mobile application sends movement commands over Wi-Fi to the NodeMCU ESP8266.

The ESP8266 processes the received commands and sends signals to the L298N motor driver. The motor driver controls the direction of the four DC motors, allowing the car to move forward, backward, left, right, or stop.

### Working Flow

```text
Blynk Mobile App
       ↓
     Wi-Fi
       ↓
NodeMCU ESP8266
       ↓
L298N Motor Driver
       ↓
  4 DC Motors
       ↓
    RC Car
