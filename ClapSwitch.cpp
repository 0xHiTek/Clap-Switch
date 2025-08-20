// Week 5: Clap Switch (Sound Sensor → Toggle LED)
// Author: 0xHitek

#define SOUND_PIN 2
#define LED_PIN 8

int ledState = LOW;    // current LED state
int clapDetect = 0;    // sound input

void setup() {
  pinMode(SOUND_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
  Serial.begin(9600);
}

void loop() {
  clapDetect = digitalRead(SOUND_PIN);  // HIGH when clap/noise detected

  if (clapDetect == HIGH) {
    // Toggle LED state
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    Serial.println("Clap detected! LED toggled.");
    delay(300); // debounce delay (prevents double-detection)
  }
}
