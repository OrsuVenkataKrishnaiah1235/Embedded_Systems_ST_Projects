//Infra red sensor
//white  led Ir TXer
//Black Led IR PhotoDiode RXER 3pins output ground power
//Its Used For Object Detection

const int ir=8;//output pin 

void setup()
{
Serial.begin(9600);//9600 baud rate--->How many bits transfer for a Second
pinMode(ir,OUTPUT);
}

void loop()
{
int ir_read=digitalRead(ir);//if object near sensor prints 1 otherwise Prints 0
Serial.println(ir_read);
}


