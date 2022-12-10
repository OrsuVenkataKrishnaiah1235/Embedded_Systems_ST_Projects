//This Sensor used to Measure the Distance
// pins 1.vcc 2.trig 3.Echo 4.Ground
const int trig=7;
const int echo=8;
int distance,duration;

void setup()
{
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(115200);
}

void loop()
{
//We are creating a pulse
digitalWrite(trig,LOW);
delay(2);
digitalWrite(trig,HIGH);
delay(10);
digitalWrite(trig,LOW);

dur=pulseIn(echo,HIGH);//Read The Time 

dis=dur*0.342/2;

Serial.println("Distance");

Serial.println(dis);
}
