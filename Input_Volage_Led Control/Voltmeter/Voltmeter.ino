int voltageReading = 0;
float voltmeter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltageReading = analogRead(A2);
  voltmeter = voltageReading * (5.0 / 1023.0);//0-5V and 10bit 0-1023 
  Serial.print(voltmeter);
  if (voltmeter > 0 && voltmeter <= 1)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  if (voltmeter >= 1 && voltmeter < 2)
  {
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
  }
  if (voltmeter >= 2 && voltmeter < 3)
  {
    digitalWrite(11, HIGH);
  }
  else
  {
    digitalWrite(11, LOW);
  }
  if (voltmeter >= 3 && voltmeter < 4)
  {
    digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
  }
}
