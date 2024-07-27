#include <SoftwareSerial.h>

// Piny dla Bluetooth
int rxPin = 10; // RX Pin
int txPin = 11; // TX Pin

// Piny dla silników
int motorRightPin1 = 5;
int motorRightPin2 = 6;
int motorLeftPin1 = 9;
int motorLeftPin2 = 10;

// Utwórz instancję SoftwareSerial
SoftwareSerial myBluetooth(rxPin, txPin);

void setup() {
  // Ustaw prędkość transmisji dla komunikacji z Bluetooth
  myBluetooth.begin(9600);
  
  // Ustaw piny silników jako wyjście
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
}

void loop() {
  if (myBluetooth.available()) {
    // Odczytaj komendę z Bluetooth
    char command = myBluetooth.read();
    controlMotors(command);
  }
}

void controlMotors(char command) {
  switch (command) {
    case 'F': // Przód
      digitalWrite(motorRightPin1, HIGH);
      digitalWrite(motorRightPin2, LOW);
      digitalWrite(motorLeftPin1, HIGH);
      digitalWrite(motorLeftPin2, LOW);
      break;
    case 'B': // Tył
      digitalWrite(motorRightPin1, LOW);
      digitalWrite(motorRightPin2, HIGH);
      digitalWrite(motorLeftPin1, LOW);
      digitalWrite(motorLeftPin2, HIGH);
      break;
    case 'L': // Lewo
      digitalWrite(motorRightPin1, HIGH);
      digitalWrite(motorRightPin2, LOW);
      digitalWrite(motorLeftPin1, LOW);
      digitalWrite(motorLeftPin2, HIGH);
      break;
    case 'R': // Prawo
      digitalWrite(motorRightPin1, LOW);
      digitalWrite(motorRightPin2, HIGH);
      digitalWrite(motorLeftPin1, HIGH);
      digitalWrite(motorLeftPin2, LOW);
      break;
    case 'S': // Stop
      digitalWrite(motorRightPin1, LOW);
      digitalWrite(motorRightPin2, LOW);
      digitalWrite(motorLeftPin1, LOW);
      digitalWrite(motorLeftPin2, LOW);
      break;
  }
}
