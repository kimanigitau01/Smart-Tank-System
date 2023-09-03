#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define TEST_PROTOTYPE // for testing purposes comment if done testing

const int water_sensor_pin {A0};
const int water_sensor_power_pin {2};
const int relay_pump_pin {3};
const int red_led {4};
const int yellow_led {5};
const int green_led {6};

const int num_of_cols {16};
const int num_of_rows {2};

int water_value = 0;

LiquidCrystal_I2C lcd(0x27, num_of_cols, num_of_rows);

// function prototypes
int getSensorReading();
void printReading(int value);

bool isEmpty(int value);
bool isLow(int value);
bool isMedium(int value);
bool isFull(int value);
bool isExcess(int value);

void empty(bool state, int value);
void low(bool state, int value);
void medium(bool state, int value);
void full(bool state, int value);
void excess(bool state, int value);

void setup() {

  pinMode(water_sensor_pin, INPUT);
  pinMode(relay_pump_pin, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.println("Smart Water Tank");
  lcd.setCursor(0, 1);
  lcd.println("Welcome :)"); 

  #ifdef TEST_PROTOTYPE
  Serial.begin(9600);
  Serial.println("Smart Water Tank");
  Serial.println("Welcome :)"); 
  #endif

  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = getSensorReading();
  empty(isEmpty(sensorValue), sensorValue);
  low(isLow(sensorValue), sensorValue);
  medium(isMedium(sensorValue), sensorValue);
  full(isFull(sensorValue), sensorValue);
  excess(isExcess(sensorValue), sensorValue);

  delay(1000);
}

int getSensorReading()
{
  digitalWrite(water_sensor_power_pin, HIGH); // for power management
  delay(10);
  water_value = analogRead(water_sensor_pin);
  digitalWrite(water_sensor_power_pin, LOW); // for power management
  return water_value;
}


void printReading(int value)
{
  lcd.setCursor(0, 0);
  lcd.print("Reading: ");
  lcd.println(value);
}

// to be modified
bool isEmpty(int value)
{
  bool isEmpty = false;
  if (value <= 0)
  {
    isEmpty = true;
  }
  return isEmpty;
}

bool isLow(int value)
{
  bool isLow = false;
  if (value <= 200)
  {
    isLow = true;
  }
  return isLow;
}
bool isMedium(int value)
{
  bool isMedium = false;
  if (value > 200 && value <= 435)
  {
    isMedium = true;
  }
  return isMedium;
}

bool isFull(int value)
{
  bool isFull = false;
  if (value > 435 && value <= 450)
  {
    isFull = true;
  }
  return isFull;
}

bool isExcess(int value)
{
  bool isExcess = false;
  if (value > 450)
  {
    isExcess = true;
  }
  return isExcess;
}

void empty(bool state, int value)
{
  if (state)
  {
    printReading(value);
    lcd.setCursor(0, 1);
    lcd.println("Empty");
    digitalWrite(relay_pump_pin, HIGH);
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, LOW);
  }
}

void low(bool state, int value)
{
  if (state)
  {
    printReading(value);
    lcd.setCursor(0, 1);
    lcd.println("low");
    digitalWrite(relay_pump_pin, HIGH);
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, LOW);
  }
}

void medium(bool state, int value)
{
  if (state)
  {
    printReading(value);
    lcd.setCursor(0, 1);
    lcd.println("medium");
    digitalWrite(relay_pump_pin, HIGH);
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(green_led, LOW);
  }
}

void full(bool state, int value)
{
  if (state)
  {
    printReading(value);
    lcd.setCursor(0, 1);
    lcd.println("full");
    digitalWrite(relay_pump_pin, HIGH);
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(green_led, HIGH);
  }
  else if (value >= 524)
  {
    digitalWrite(relay_pump_pin, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(green_led, HIGH); 
  }
}

void excess(bool state, int value)
{
  if (state)
  {
    printReading(value);
    lcd.setCursor(0, 1);
    lcd.println("Excess");
    digitalWrite(relay_pump_pin, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led,HIGH);
    digitalWrite(green_led, HIGH);
    delay(1000);
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led,LOW);
    digitalWrite(green_led, LOW);
  }
}