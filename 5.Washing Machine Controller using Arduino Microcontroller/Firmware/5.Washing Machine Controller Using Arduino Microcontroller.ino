#include <LiquidCrystal.h>

const int drainSwitch = 8;
const int waterTank = 9;
const int drainValve = 10;
const int washingMotor = 11;
const int buzzer = 12;
const int timerSetting = A0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int timerValue;

void setup() {
  pinMode(drainSwitch, INPUT);
  pinMode(waterTank, INPUT);
  pinMode(drainValve, OUTPUT);
  pinMode(washingMotor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(20, 4);
}

void loop() {
  // Check for drain switch
  if (digitalRead(drainSwitch) == HIGH) {
    // Wait for water to drain out
    delay(3000);
    // Check for empty water tank
    if (digitalRead(waterTank) == HIGH) {
      // Close drain valve
      digitalWrite(drainValve, LOW);
      lcd.clear();
      lcd.print("Drain valve closed");
      delay(1000);
      // Ask for timer setting
      lcd.clear();
      lcd.print("Set washing timer:");
      timerValue = analogRead(timerSetting);
      // Convert timer value to minutes
      timerValue = map(timerValue, 0, 1023, 0, 60);
      lcd.setCursor(0, 1);
      lcd.print(timerValue);
      lcd.print(" mins");
      delay(1000);
      // Start washing
      lcd.clear();
      lcd.print("Washing...");
      digitalWrite(washingMotor, HIGH);
      delay(timerValue * 60000);
      digitalWrite(washingMotor, LOW);
      // Open drain valve
      digitalWrite(drainValve, HIGH);
      lcd.clear();
      lcd.print("Drain valve opened");
      delay(3000);
      // Buzzer beeps until drain valve closed
      while (digitalRead(drainSwitch) == HIGH) {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(500);
      }
      // Close drain valve and indicate washing completed
      digitalWrite(drainValve, LOW);
      lcd.clear();
      lcd.print("Washing completed!");
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
  }
}

