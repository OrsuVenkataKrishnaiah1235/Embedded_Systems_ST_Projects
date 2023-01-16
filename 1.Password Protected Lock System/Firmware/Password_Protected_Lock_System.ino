#include <LiquidCrystal.h>

int buzzer=10;
int Red_Led=11;
int Green_Led=12;

int Default_Password[4]={2,3,3,4};

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

  for(int i=0;i<=9;i++)
  {
    pinMode(i,INPUT);//PUSH BUTTONS 0-9
  }
pinMode(Red_Led,OUTPUT);
pinMode(Green_Led,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop()
{
if(digitalRead(Default_Password[0])==HIGH)
{
  if(digitalRead( Default_Password[1])==HIGH)
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
  digitalWrite(11,HIGH);
  delay(1000);
}
}
/*#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_PCF8574.h>
Adafruit_PCF8574 pcf;

int buzzer=0;
int Red_Led=1;
int Green_Led=2;
int push_9=3;
int Default_Password[4]={1,2,3,4};

LiquidCrystal lcd(8,9,10,11,12,13);//Rs,Enable,D0,D1,D2,D3
void setup()
{
  for(int i=0;i<=8;i++)
  {
    pcf.pinMode(i,INPUT);//PUSH BUTTONS 0-7
  }
  if(!pcf.begin(0x20,&Wire))'
  {
    while(1);
  }
pinMode(Red_Led,OUTPUT);
pinMode(Green_Led,OUTPUT);
pinMode(Buzzer,OUTPUT);
pinMode(push_9,INPUT);
lcd.init();
}

void loop()
{
if(pcf.digitalRead(Default_Password[0])==HIGH)
{
  if(pcf.digitalRead( Default_Password[1])==HIGH)
  {
  if(pcf.digitalRead( Default_Password[2])==HIGH)
  {
    if(pcf.digitalRead( Default_Password[3])==HIGH)
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
*/
