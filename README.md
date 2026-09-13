# ESP8266 Blynk RC Car 🚗

A Wi-Fi controlled RC car built using **NodeMCU ESP8266**, **L298N motor driver**, and **4 DC motors**. The car can be controlled remotely through the **Blynk IoT mobile application**.

## 🚀 Features

- Wi-Fi based remote control
- Blynk mobile app control
- Forward and backward movement
- Left and right movement
- Stop control
- 4-wheel drive using 4 DC motors
- NodeMCU ESP8266 based control system

## 🛠️ Components Used

- NodeMCU ESP8266
- L298N Motor Driver
- 4 × DC Gear Motors
- RC Car Chassis
- Battery
- Jumper Wires
- Blynk IoT Platform

## 🔌 Working

The NodeMCU ESP8266 receives commands from the Blynk mobile application through Wi-Fi.

The ESP8266 processes these commands and sends control signals to the L298N motor driver. The L298N then controls the direction and movement of the four DC motors.

### Basic Working Flow

Blynk App → Wi-Fi → NodeMCU ESP8266 → L298N Motor Driver → DC Motors → RC Car

## 💻 Software

- Arduino IDE
- Blynk IoT
- ESP8266 Board Package

## 📂 Project Structure

```text
ESP8266-Blynk-RC-Car/
│
└── RC_Car/
    └── RC_Car.ino
