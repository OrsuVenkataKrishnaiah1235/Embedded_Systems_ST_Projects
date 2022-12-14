//piezo Buzzer positive(pin3) and negative Terminal(Ground)
const int buzzer=3;
const int ir=13;

void setup()
{
pinMode(ir,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}


void loop()
{
int ir_read=digitalRead(ir);
Serial.println(ir_read);
if(ir_read==HIGH)
{
digitalWrite(buzzer,HIGH);
Serial.println("Buzzer On");
}
else
{
digitalWrite(buzzer,LOW);
Serial.println("Buzzer Off");
}
}
