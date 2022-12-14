const int led=13;

void setup()
{
pinMode(led,OUTPUT);
}


void loop()
{
digitalWrite(led,HIGH);//On
delay(1000);
digitalWrite(led,LOW);//Off
delay(1000);
}

