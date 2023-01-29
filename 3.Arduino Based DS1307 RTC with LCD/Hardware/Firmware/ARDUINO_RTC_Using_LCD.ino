#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

RTC_DS1307 rtc;
const int rs=7,en=6,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // (rs, e, d4, d5, d6, d7)

char Days_per_Year_in_week[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup () 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(Year,Month,Date, Hours, Minutes, Seconds));// to set the time manualy 
  
}

void loop () 
{
    DateTime now = rtc.now();
    
    lcd.setCursor(0, 1);
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("   ");

    lcd.setCursor(0, 0);
    lcd.print(Days_per_Year_in_week[now.Days_per_Year_in_week()]);
    lcd.print(" ,");
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
   
}