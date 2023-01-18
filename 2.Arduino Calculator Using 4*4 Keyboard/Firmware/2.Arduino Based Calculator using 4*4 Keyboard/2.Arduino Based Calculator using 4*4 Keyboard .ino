#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long Num1 = 0;
long Num2 = 0;
double Result = 0;

char Key;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {7,6,5,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,2,1,0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
lcd.begin(16, 2);// start lcd
lcd.setCursor(0,0);// in lcd Setcursor point at 0th column and 0th row
lcd.print("Calculator By");
lcd.setCursor(0,1);//in lcd Setcursor point at 0th column and 1th row
lcd.print("O.V.Krishnaiah");
delay(4000);//Wait the information until 4 milli seconds
lcd.clear();//clear the lcd Screen
lcd.setCursor(0, 0);////in lcd Setcursor point at 0th column and 0th row
}


void loop()
{

  Key = myKeypad.getKey();//getKey() instance method to Store the Pressed Key 
  switch(Key) 
  {
  case '0' ... '9': // This keeps collecting the first value until a operator is pressed "+-*/"
    lcd.setCursor(0,0);
    Num1 = Num1 * 10 + (Key - '0');
    lcd.print(Num1);
    break;

  case '+':
    Num1 = (Result != 0 ? Result : Num1);
    lcd.setCursor(0,1);
    lcd.print("+");
    Num2 = Number2(); // get the collected the second number
    Result = Num1 + Num2;
    lcd.setCursor(0,3);
    lcd.print(Result);
    Num1 = 0, Num2 = 0; // reset values back to zero for next use
    break;

  case '-':
    Num1 = (Result != 0 ? Result : Num1);
    lcd.setCursor(0,1);
    lcd.print("-");
    Num2 = Number2(); // get the collected the second number
    Result = Num1 - Num2;
    lcd.setCursor(0,3);
    lcd.print(Result);
    Num1 = 0, Num2 = 0; // reset values back to zero for next use
    break;

  case '*':
    Num1 = (Result != 0 ? Result : Num1);
    lcd.setCursor(0,1);
    lcd.print("*");
    Num2 = Number2(); // get the collected the second number
    Result = Num1 * Num2;
    lcd.setCursor(0,3);
    lcd.print(Result);
    Num1 = 0, Num2 = 0; // reset values back to zero for next use
    break;

  case '/':
    Num1 = (Result != 0 ? Result : Num1);
    lcd.setCursor(0,1);
    lcd.print("/");
    Num2 = Number2(); // get the collected the second number
    Result = Num1 / Num2;
    lcd.setCursor(0,3);
    lcd.print(Result);
    Num1 = 0, Num2 = 0; // reset values back to zero for next use
    break;

    Num2 == 0 ? lcd.print("Invalid Number") : Result = (float)Num1 / (float)Num2;

    lcd.print(Result);
    Num1 = 0, Num2 = 0;
    break;

  case 'C':
    Result = 0;//Cancle The Calculation
    lcd.clear();
    break;
  }
}

long Number2()
{
  while( 1 )
  {
    Key = myKeypad.getKey();
    if(Key >= '0' && Key <= '9')
    {
      Num2 = Num2* 10 + (Key - '0');
      lcd.setCursor(0,2);
      lcd.print(Num2);
    }

    if(Key == '=') break;  //return Num2;
  }
 return Num2; 
}
