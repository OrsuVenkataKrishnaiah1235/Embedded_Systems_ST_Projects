#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_PCF8574.h>
Adafruit_PCF8574 pcf;

int buzzer=1;
int Red_Led=0;
int Green_Led=2;
int push_8=3;
int push_9=4;
int Default_Password[4]={1,2,3,4};

LiquidCrystal lcd(8,9,10,11,12,13);
void setup()
{
  for(int i=0;i<=7;i++)
  {
    pinMode(i,INPUT);//PUSH BUTTONS 0-7
  }
  if(!pcf.begin(0x20,&Wire))'
  {
    while(1);
  }
pcf.pinMode(Red_Led,OUTPUT);
pcf.pinMode(Green_Led,OUTPUT);
pcf.pinMode(Buzzer,OUTPUT);
pcf.pinMode(push_8,INPUT);
pcf.pinMode(push_9,INPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
lcd.init();
}

void loop()
{
if(digitalRead(Default_Password[0])==HIGH)
{
  if((digitalRead( Default_Password[1])==HIGH)
  {
  if(digitalRead( Default_Password[2])==HIGH)
  {
    if(digitalRead( Default_Password[3])==HIGH)
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
