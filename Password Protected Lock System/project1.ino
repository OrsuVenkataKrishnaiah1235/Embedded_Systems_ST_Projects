#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int buzzer=11;
int Red_Led=10;
int Green_Led=12;
int a[4]={1,2,3,4};

LiquidCrystal_I2C lcd(0x20,16,2);
void setup()
{
for(int i=0;i<=9;i++)
{
  pinMode(i,INPUT);
}
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
lcd.init();
}

void loop()
{
if(digitalRead(0)==a[0])
{
  if((digitalRead(1)==a[1])
  {
  if(digitalRead(2)==a[2])
  {
    if(digitalRead(3)==a[3])
    {
      lcd.setCursor(0,1);
      lcd.print("Welcome");
      digitalWrite(12,HIGH);
      delay(1000);
    }
  }
  }
}
else
{
  lcd.print("Contact Manager/Retype the password");
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
  delay(1000);
}
}
