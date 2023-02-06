#include <Wire.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

#define Total_Product 0x00 //Intail Address to Store Total Products Count 
#define Good_Product 0x0C //Intail Address to Store Bad Product Count 
#define Bad_Product 0x18 //Intail Address to Store Good Product Count

int bad_Count = 0;
int good_Count = 0;
int total_Count = 0;
int push_1=2;
int push_2=3;

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);//rs,en,d4,d5,d6,d7
const int eeprom_address = 0x50;   // I2C address of the 24LC256 EEPROM

void LCD_Display();
void Clear_EEPROM();


void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  for(int i=2 ; i<4 ; i++)
  {
    pinMode(i , INPUT);
  }

  pinMode(10 , INPUT);
  
  lcd.begin(20, 4);
  lcd.print("Product-Counter");
  lcd.setCursor(0, 1);
  lcd.print("By Venkata Krishnaiah");
  lcd.clear();

  for (int address = 0; address < 36; address++) //Reset all the Data of Total, Bad and Good Product Count that Program is loaded before Starting
  {
    EEPROM.write(Total_Product+address, 0xFF);
  }
}

void loop() 
{

  int clearROM = digitalRead(10); //If clear button is pressed it gives 0 else it returns 1
  
  if(!clearROM) //clears EEPROM when it returns 0
  {
    Clear_EEPROM(); //clear the EEPROM 
  }
  
  else
  {
    if(digitalRead(2))
    {
      good_Count++;
    }
    if(digitalRead(3))
    {
      bad_Count++;
    }
    total_Count = good_Count + bad_Count ;
    LCD_Display();
    
    byte i = 0x00 ;
    for(int num = total_Count ; num > 0 ; num = num/10)
    {
      int rem = num % 10 ;
      EEPROM.write(Total_Product+i, rem); // Writing Total Products Count Byte by Byte
      
      Serial.print(" Total Products ");
      Serial.print(Total_Product+i);
      Serial.print(" are ");
      Serial.println(rem);

      
      i++;
    }

    byte j = 0x00 ;
    for(int num = good_Count ; num > 0 ; num = num/10)
    {
      int rem = num % 10 ;
      EEPROM.write(Good_Product+j, rem); // Writing Good Products Count Byte by Byte
      
      Serial.print("Good Products  ");
      Serial.print(Good_Product+j);
      Serial.print(" are ");
      Serial.println(rem);
      
      j++;
    }
    
    byte k = 0x00 ;
    for(int num = bad_Count ; num > 0 ; num = num/10)
    {
      int rem = num % 10 ;
      EEPROM.write(Bad_Product+k, rem); // Writing Bad Products Count Byte by Byte
      
      Serial.print("Bad Products  ");
      Serial.print(Bad_Product+k);
      Serial.print(" are ");
      Serial.println(rem);
      
      k++;
    }               
  
    // Read data from the EEPROM
    byte data = EEPROM.read(j);
    Serial.print("Good Products: ");
    Serial.println(data);
    data = EEPROM.read(k);
    Serial.print("Bad Products: ");
    Serial.println(data); 
    
  }  
    
  delay(500); // Wait for 0.5 second before writing and reading the data again

}
void Clear_EEPROM()
{
   for (int address = 0; address < 32768; address++) 
   {
    Wire.beginTransmission(eeprom_address);
    Wire.write((int)(address >> 8));
    Wire.write((int)(address & 0xFF));
    Wire.write(0xFF);
    Wire.endTransmission();
  }

    Serial.println("EEPROM data cleared!");  
}
void LCD_Display()
{
  lcd.clear();
  
  lcd.setCursor(0, 2);
  lcd.print("BAD Products : ");
  lcd.print(bad_Count);

  lcd.setCursor(0, 3);
  lcd.print("GOOD Products : ");
  lcd.print(good_Count);
  
  lcd.setCursor(0, 0);
  lcd.print("TOTAL PRODUCTS : ");
  lcd.print(total_Count);
  lcd.setCursor(0, 1);
  lcd.print(total_Count);

}
/*
byte readEEPROM(int address) 
{
  byte data;
  Wire.beginTransmission(eeprom_address);
  Wire.write((int)(address >> 8));   // Send the high byte of the address
  Wire.write((int)(address & 0xFF)); // Send the low byte of the address
  Wire.endTransmission();
  Wire.requestFrom(eeprom_address, 1);
  if (Wire.available()) 
  {
    data = Wire.read();
  }
  return data;
}

void writeEEPROM(int address, byte data) {
  Wire.beginTransmission(eeprom_address);
  Wire.write((int)(address >> 8));   // Send the high byte of the address
  Wire.write((int)(address & 0xFF)); // Send the low byte of the address
  Wire.write(data);
  Wire.endTransmission();
  delay(5);  // wait for the EEPROM to complete the write
}
void Clear_EEPROM()
{
   for (int address = 0; address < 32768; address++) 
   {
    Wire.beginTransmission(eeprom_address);
    Wire.write((int)(address >> 8));
    Wire.write((int)(address & 0xFF));
    Wire.write(0xFF);
    Wire.endTransmission();
  }

    Serial.println("EEPROM data cleared!");  
}
*/
