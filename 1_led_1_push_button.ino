const int led=13;
const int push_button=12;
int push_button_status=0;


void setup()
{
pinMode(led,OUTPUT);
pinMode(push_button,INPUT);
}


void loop()
{
push_button_status=analogRead(push_button);


if(push_button_status==HIGH)
{
digitalWrite(led,HIGH);
delay(1000);
}

else
{
digitalWrite(led,LOW);
delay(1000);
}
}
