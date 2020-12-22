const int button1 = 2; //interrupt button pin:2
int RedSignal = 13;
int YellowSignal = 12;
int GreenSignal = 11;
int Pedestrianstop = 10;
int Pedestriango = 9;
bool buttonPedestrian = false;
void setup()
{
//declaring RedSignal, YellowSignal, GreenSignal, Pedestriango,Pedestrianstop as outputs
pinMode(RedSignal, OUTPUT);
pinMode(GreenSignal, OUTPUT);
pinMode(YellowSignal, OUTPUT);
pinMode(Pedestriango, OUTPUT);
pinMode(Pedestrianstop, OUTPUT);
Serial.begin(9600); // setting up serial communication
pinMode(button1, INPUT); // declaring the pushbutton pin as an input
attachInterrupt(digitalPinToInterrupt(button1), buttonPedestrian_InterruptServiceRoutine, HIGH);
}
void loop()
{
digitalWrite(RedSignal, HIGH);
digitalWrite(Pedestrianstop, HIGH);
if (buttonPedestrian == true)
{
Serial.println("Button Pushed");
//RedSignal for the drivers
digitalWrite(RedSignal, HIGH);
delay(3000);
digitalWrite(Pedestrianstop, LOW);
digitalWrite(Pedestriango, HIGH); // Pedestrians Can Cross
delay(15000); // on for 15 seconds
digitalWrite(Pedestriango, LOW);
digitalWrite(Pedestrianstop, HIGH); // Pedestrian Can't Cross 
delay(3000); // 3000 millisecond delay
buttonPedestrian = false;
}
else
{
digitalWrite(RedSignal, HIGH); // RedSignal is on 
delay(7000); 
digitalWrite(RedSignal, LOW); // RedSignal turns off
digitalWrite(GreenSignal, HIGH); // GreenSignal turns on
delay(7000); 
digitalWrite(GreenSignal, LOW); // GreenSignal turns off
digitalWrite(YellowSignal, HIGH); // YellowSignal is on
delay(3000); 
digitalWrite(YellowSignal, LOW); //YellowSignal is off
}
}
void buttonPedestrian_InterruptServiceRoutine()
{
buttonPedestrian=true;
}