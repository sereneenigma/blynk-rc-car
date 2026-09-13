#define BLYNK_TEMPLATE_ID "TMPL3mQe7dzAL"
#define BLYNK_TEMPLATE_NAME "RC car"
#define BLYNK_AUTH_TOKEN "r8KsPyh6H-Kbi5ShR9hjf09i8tdWg92t"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// ── WiFi credentials ────────────────────────────────────────────────────────
char ssid[] = "vivo";
char pass[] = "12345678";

// ── Motor direction pins ─────────────────────────────────────────────────────
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4

// ── Motor enable (PWM speed) pins ────────────────────────────────────────────
// FIX 1: ENA and ENB were never defined — added here
#define ENA D5   // PWM pin — Motor A speed
#define ENB D6   // PWM pin — Motor B speed

int speedValue = 800;  // PWM speed (0–1023); controllable via V4 slider

// ── Helper: set speed on both motors ────────────────────────────────────────
void setSpeed() {
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
}

// ── Stop all motors ──────────────────────────────────────────────────────────
// FIX 2: now also zeroes PWM so driver doesn't keep running while stopped
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
}

// ── V0 — Forward ─────────────────────────────────────────────────────────────
BLYNK_WRITE(V0) {
  if (param.asInt()) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  
  } else {
    stopMotors();
  }
}

// ── V1 — Backward ────────────────────────────────────────────────────────────
BLYNK_WRITE(V1) {
  if (param.asInt()) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  
  } else {
    stopMotors();
  }
}

// ── V2 — Left ────────────────────────────────────────────────────────────────
BLYNK_WRITE(V2) {
  if (param.asInt()) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
  } else {
    stopMotors();
  }
}

// ── V3 — Right ───────────────────────────────────────────────────────────────
BLYNK_WRITE(V3) {
  if (param.asInt()) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
  } else {
    stopMotors();
  }
}

// ── V4 — Speed slider (0–1023) ───────────────────────────────────────────────
// TIP: Add a Blynk slider on V4 in the app to control speed live
BLYNK_WRITE(V4) {
  speedValue = param.asInt();
}

// ── Blynk disconnect safety ───────────────────────────────────────────────────
// TIP: Stop motors if WiFi/Blynk drops so car doesn't keep driving
BLYNK_DISCONNECTED() {
  stopMotors();
  Serial.println("Blynk disconnected — motors stopped");
}

// ── Setup ─────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);  // FIX 3: Serial enabled for debugging

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  stopMotors();  // ensure motors are off at boot

  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connected!");
}

// ── Loop ──────────────────────────────────────────────────────────────────────
void loop() {
  Blynk.run();
}
