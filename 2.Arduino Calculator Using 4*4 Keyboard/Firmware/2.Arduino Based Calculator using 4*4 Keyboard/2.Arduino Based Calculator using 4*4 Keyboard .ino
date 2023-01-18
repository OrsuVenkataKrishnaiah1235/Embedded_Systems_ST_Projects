#include <LiquidCrystal.h> 
#include <Keypad.h> 
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
long Num1,Num2,Number;//Num1 and Num2 Upto  2 Decimal points only allowed
char key,action;
boolean result = false;

// Defining  the Keymap
char keys[ROWS][COLS] = {{'7','8','9','D'},{'4','5','6','C'},{'1','2','3','B'},{'*','0','#','A'}};
byte rowPins[ROWS] = { 0, 1, 2, 3 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
//Keypad(char *userKeymap, byte *row, byte *col, byte numRows, byte numCols);
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad Constructor

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
lcd.begin(16, 2); //We are using a 16*2 LCD display
lcd.print("2 Digits Calculator"); //Display a intro message
lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
delay(2000); //Wait for display to show info
lcd.clear(); //Then clean it
}

void loop() 
{
key = kpd.getKey(); //storing pressed key value in a char getKey() is a Instance Method 
if (key!=NO_KEY)
DetectButtons();
if (result==true)
CalculateResult();
DisplayResult();   
}

void DetectButtons()
{ 
lcd.clear(); //Blank LCD
//For Key 0
if (key == '0')
{
Serial.println ("Button 0"); //Button 0 is Pressed
if (Number==0)
  Number=0;
else
  Number = (Number*10) + 0; //Pressed twice
}
//For Key 1
if (key == '1') //If Button 1 is pressed
{
Serial.println ("Button 1"); 
if (Number==0)
  Number=1;
else
  Number = (Number*10) + 1; //Pressed twice 11
}
 //For Key 2
  if (key == '2') //Button 2 is Pressed

    {Serial.println ("Button 2"); 

     if (Number==0)

    Number=2;

    else

    Number = (Number*10) + 2; //Pressed twice 22

    }
  //For Key 3
    if (key == '3')

    {
      Serial.println ("Button 3"); 

     if (Number==0)

    Number=3;

    else

    Number = (Number*10) + 3; //Pressed twice 33

    }

//For Key 4    

     if (key == '4') 

    {
    Serial.println ("Button 4"); 

    if (Number==0)

    Number=4;

    else

    Number = (Number*10) + 4; //Pressed twice 44

    }
  //For Key 5

     if (key == '5')

    {
    Serial.println ("Button 5"); 

    if (Number==0)

    Number=5;

    else

    Number = (Number*10) + 5; //Pressed twice 55

    }
  //For Key 6
    if (key == '6')

    {
    Serial.println ("Button 6"); 

    if (Number==0)

    Number=6;

    else

    Number = (Number*10) + 6; //Pressed twice 66

    }
 //For Key 7
    
     if (key == '7') 

    {
    Serial.println ("Button 7");

    if (Number==0)

    Number=7;

    else

    Number = (Number*10) + 7; //Pressed twice 77

    } 

  //For Key 8

    if (key == '8')

    {
    Serial.println ("Button 8"); 

    if (Number==0)

    Number=8;

    else

    Number = (Number*10) + 8; //Pressed twice 88

    }   
  //For Key 9
  
    if (key == '9')

    {
    Serial.println ("Button 9");

    if (Number==0)

    Number=9;

    else

    Number = (Number*10) + 9; //Pressed twice 99

    }  
  //For Key *
  
  if (key=='*') // cancel Button

    {
    Serial.println ("Button Cancel");
    Number=Num1=Num2=0; 
    result=false;
  }
  
//For Key #

    if (key == '#')

    {Serial.println ("Button Equal"); 

    Num2=Number;

    result = true;

    }
 

if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4

  {

    Num1 = Number;    

    Number =0;

    if (key == 'A')

    {
      Serial.println ("Addition");
      action = '+';
    }

     if (key == 'B')

    {
       Serial.println ("Subtraction");
       action = '-'; 
     }

     if (key == 'C')

    {
       Serial.println ("Multiplication"); 
       action = '*';
     }

     if (key == 'D')

    {
       Serial.println ("Devesion"); 
       action = '/';
     }  


    delay(100);

  }

  

}


void CalculateResult()

{

  if (action=='+')

    Number = Num1+Num2;


  if (action=='-')

    Number = Num1-Num2;


  if (action=='*')

    Number = Num1*Num2;


  if (action=='/')

    Number = Num1/Num2; 

}


void DisplayResult()

{

  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1

  lcd.print(Num1); 
  lcd.print(action); 
  lcd.print(Num2); 

  

  if (result==true)

  {
    lcd.print(" ="); 
    lcd.print(Number);
} //Display the result

  

  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1

  lcd.print(Number); //Display the result

}
