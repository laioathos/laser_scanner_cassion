#include <Stepper.h> 

const int stepsPerRevolution = 500; 
Stepper myStepper(stepsPerRevolution, 8,10,9,11); // data to motor

int sensValue = 0;
int distValue = 0;
int sensPin = A0;
float Deg = 0;
float DegRad = 0;
float Xvalue = 0;
float Yvalue = 0;
int pulseStep = 0;
float Cos = 0;
float Sin = 0;

//note: 1 degree = 0,0174533 RAD 
//01pulse = 0,17578125º
 
void setup() 
{ 

 myStepper.setSpeed(64);// vel. start
 pinMode(sensPin, INPUT);
 Serial.begin(9600);
} 
 
void loop() 
{ 
  while(Deg<360){
 pulseStep = 128; //2048pulses = 360º
 myStepper.step(pulseStep); //100Pul
 sensValue = analogRead(sensPin);
 distValue = (6762/(sensValue-9))-4;
 Deg = Deg + (pulseStep*0.17578125); 
 DegRad =  0.0174533 * Deg;
    Cos = cos(DegRad);
    Sin = sin(DegRad);  
 Yvalue = distValue * sin(DegRad);
 Xvalue = distValue * cos(DegRad);
 // Serial.print(";");
 Serial.print(Xvalue);
 Serial.print(" , ");
 Serial.print(Yvalue);
 Serial.println(", 0");
 delay(2000);}
}




