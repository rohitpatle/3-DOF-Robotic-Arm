// Gripper Robot Program

#include <Stepper.h>
//usd
#define trigPin 5
#define echoPin 4
//#define ledPin 3
//usd
//const int dir2=9;
//const int pulse2=8;
const int dir3=8;//base motor 
const int pulse3=3;//base motor
const int dir4=11;//upper motor
const int pulse4=10;//upper motor
int status = 0;
int i;
int a=0,b=1;
//int g1=4000; //claw open
//int g2=-4000; //claw close
int g3=-3500; //base motor left
int g4=3500; //base motor right
int g5=4000; //arm down
int g6=-4000; //arm up
long duration, distance;
//void gripper12(int );
void gripper34(int );//base motor
void gripper56(int );// arm motor
void setup()
{
// pinMode(dir2,OUTPUT);
//pinMode(pulse2,OUTPUT);
pinMode(dir3,OUTPUT);
pinMode(pulse3,OUTPUT);
pinMode(dir4,OUTPUT);
pinMode(pulse4,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
// usd
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
//pinMode(ledPin,OUTPUT);
// usd
//digitalWrite(dir2,LOW);
//digitalWrite(pulse2,LOW);
digitalWrite(dir3,LOW);
digitalWrite(pulse3,LOW);
digitalWrite(dir4,LOW);
digitalWrite(pulse4,LOW);
Serial.begin(9600);
}
void loop()
{
digitalWrite(7,LOW);// GRIPPER OPEN
digitalWrite(6,HIGH);
delay(200);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
gripper56(g6);
delay(2000);
digitalWrite(7,HIGH); //GRIPPER CLOSE
digitalWrite(6,LOW);
delay(200);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
gripper34(g4);
delay(3000);
//usd
digitalWrite(trigPin, LOW); // Added this line
delayMicroseconds(2); // Added this line
digitalWrite(trigPin, HIGH);
//`` delayMicroseconds(1000); //- Removed this line
delayMicroseconds(10); // Added this line
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance >= 200 || distance <= 0)
{
Serial.println("Out of range");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(4000);
if(distance>=30)
{
digitalWrite(7,LOW);
digitalWrite(6,LOW);
}
if(distance<=30)
{Serial.println("INSIDE range");
digitalWrite(7,LOW);
digitalWrite(6,HIGH);
delay(200);
digitalWrite(7,HIGH);
digitalWrite(6,LOW);
delay(200);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
}
gripper34(g3);
delay(3000);
gripper56(g5);
delay(3000);
// usd
}
//33333333333333333333333333333
void gripper34 (int g)
{
if (g<0){
digitalWrite(dir3,LOW);
delayMicroseconds(500);
}
else
{
digitalWrite(dir3,HIGH);
delayMicroseconds(500);
}
for(i=0;i<abs(g);i++)
{
digitalWrite(pulse3,HIGH);
delayMicroseconds(450);
digitalWrite(pulse3,LOW);
delayMicroseconds(450);
}
}
//44444444444444444 +444444444444
void gripper56 (int g)//-3500
{
if (g<0){
digitalWrite(dir4,LOW);
delayMicroseconds(500);
}
else
{
digitalWrite(dir4,HIGH);
delayMicroseconds(500);
}
for(i=0;i<abs(g);i++)
{
digitalWrite(pulse4,HIGH);
delayMicroseconds(450);
digitalWrite(pulse4,LOW);
delayMicroseconds(450);
}
}
