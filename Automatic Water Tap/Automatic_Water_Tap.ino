const int count=2,reset=3,start=4;
int count_status=0,reset_status=0,start_status=0;
int led=13;
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(count,INPUT);
pinMode(reset,INPUT);
pinMode(start,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
count_status=digitalRead(count);
if(count_status==HIGH)
{
  counter=counter+1;
}
reset_status=digitalRead(reset);
if(reset_status==HIGH)
{
  counter=0;
}
start_status=digitalRead(start);
if(start_status==HIGH)
{
  for(int bli=0;bli<4;bli++)
  {
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
    counter=counter-1;
    
  }
}
}
