#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin definitions
#define ONE_WIRE_BUS 2       // DS18B20 data pin
const int potPin = A0;       // Potentiometer connected here
const int RelayPin = 5;      // Relay pin connected here

// DS18B20 setup
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// LCD setup
LiquidCrystal_I2C lcd(0x27, A4, A5); // Use working LCD address and pins

void setup() {
  sensors.begin();             // Initialize DS18B20 sensor
  pinMode(RelayPin, OUTPUT);   // Set relay pin as output
  digitalWrite(RelayPin, LOW); // Ensure relay is off initially

  Serial.begin(9600);          // Initialize serial communication for debugging

  lcd.init();                  // Initialize the LCD
  lcd.backlight();             // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Temp Fan Control");
  lcd.setCursor(0, 1);
  lcd.print("by Your Name");
  delay(2000);                 // Display splash screen
  lcd.clear();
}

void loop() {
  // Read the potentiometer and map its value to a temperature range
  int threshold = map(analogRead(potPin), 0, 1023, 20, 40);

  // Request and read the temperature from the DS18B20
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  // Debugging: Print values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Threshold: ");
  Serial.println(threshold);

  // Control the relay based on the temperature and threshold
  if (temperature > threshold) {
    digitalWrite(RelayPin, HIGH); // Turn on the fan
    Serial.println("Relay: ON");
  } else {
    digitalWrite(RelayPin, LOW);  // Turn off the fan
    Serial.println("Relay: OFF");
  }

  // Update the LCD with current temperature and threshold
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  if (temperature == DEVICE_DISCONNECTED_C) {
    lcd.print("Error");           // Display error if sensor is disconnected
    Serial.println("Sensor Error");
  } else {
    lcd.print(temperature, 1);    // Display temperature with 1 decimal place
    lcd.print("C");
  }

  lcd.setCursor(0, 1);
  lcd.print("SetTemp: ");
  lcd.print(threshold);
  lcd.print("C");

  delay(1000); // Refresh every second
}
