#define BLYNK_TEMPLATE_ID "TMPL6OV96IcUC"
#define BLYNK_TEMPLATE_NAME "RC car"
#define BLYNK_AUTH_TOKEN "-05q4aUa01i4vLFol7SLvFp93gXK0dYW"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>  // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Azad's house";
char pass[] = "Napa625682";

// Motor pins
const int enableAPin = D7; // Enable pin for Motor A
const int in1Pin = D8;
const int in2Pin = D3;
const int enableBPin = D4; // Enable pin for Motor B
const int in3Pin = D5;
const int in4Pin = D6;

// Buzzer pin
const int buzzerPin = D0;

// Define the I2C address of the LCD display
#define I2C_ADDR 0x27

// Define LCD size (16 columns and 2 rows)
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Create an LCD object
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

BlynkTimer timer;

bool isMovingBackward = false;

BLYNK_WRITE(V1) // Button Widget is writing to pin V1
{
  int btnState = param.asInt(); // Get value of button (1 for pressed, 0 for released)
  if (btnState == 1) {
    // Move forward
    moveForward();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Going Forward");
  } else {
    // Stop motors if button is released
    stopMotors();
    lcd.clear();
  }
}

BLYNK_WRITE(V2) // Button Widget is writing to pin V2
{
  int btnState = param.asInt(); // Get value of button (1 for pressed, 0 for released)
  if (btnState == 1) {
    // Move backward
    moveBackward();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Going Backward");
  } else {
    // Stop motors if button is released
    stopMotors();
    lcd.clear();
  }
}

BLYNK_WRITE(V3) // Button Widget is writing to pin V3
{
  int btnState = param.asInt(); // Get value of button (1 for pressed, 0 for released)
  if (btnState == 1) {
    // Turn left
    turnLeft();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Turning Left");
  } else {
    // Stop motors if button is released
    stopMotors();
    lcd.clear();
  }
}

BLYNK_WRITE(V4) // Button Widget is writing to pin V4
{
  int btnState = param.asInt(); // Get value of button (1 for pressed, 0 for released)
  if (btnState == 1) {
    // Turn right
    turnRight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Turning Right");
  } else {
    // Stop motors if button is released
    stopMotors();
    lcd.clear();
  }
}

BLYNK_WRITE(V5) // Button Widget is writing to pin V5
{
  int btnState = param.asInt(); // Get value of button (1 for pressed, 0 for released)
  if (btnState == 1) {
    // Turn on buzzer
    digitalWrite(buzzerPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Side den bhai");
  } else {
    // Turn off buzzer
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
  }
}

void setup() {
  Serial.begin(9600);
  
  // Initialize motor pins as outputs
  pinMode(enableAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enableBPin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  // Initialize buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  // Initialize LCD display
  lcd.init();
  lcd.backlight();

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();
}

void moveForward() {
  isMovingBackward = false;
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  
  // Set motor speed (adjust as necessary)
  analogWrite(enableAPin, 255);
  analogWrite(enableBPin, 255);
}

void moveBackward() {
  isMovingBackward = true;
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  
  // Set motor speed (adjust as necessary)
  analogWrite(enableAPin, 255);
  analogWrite(enableBPin, 255);
  
  // Start beeping the buzzer with a delay
  timer.setTimeout(1000, beepBuzzer);
}

void beepBuzzer() {
  // Check if V2 is on and the car is moving backward
  if (digitalRead(V2) && isMovingBackward) {
    // Toggle the buzzer state
    digitalWrite(buzzerPin, !digitalRead(buzzerPin));
    // Set the timer for the next beep
    timer.setTimeout(500, beepBuzzer);
  } else {
    // If V2 is off or the car is not moving backward, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }
}

void turnLeft() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  
  // Set motor speed (adjust as necessary)
  analogWrite(enableAPin, 255);
  analogWrite(enableBPin, 255);
}

void turnRight() {
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  
  // Set motor speed (adjust as necessary)
  analogWrite(enableAPin, 255);
  analogWrite(enableBPin, 255);
}

void stopMotors() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);
  
  // Stop motors by disabling PWM (speed control)
  analogWrite(enableAPin, 0);
  analogWrite(enableBPin, 0);
  
  // Turn off buzzer if moving backward has stopped and V2 is off
  if (!isMovingBackward && !digitalRead(V2)) {
    digitalWrite(buzzerPin, LOW);
  }
}
