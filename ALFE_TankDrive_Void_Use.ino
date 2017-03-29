#include <Servo.h>
#define joypinX A0   //attaches joysticks to pins
#define joypinX1 A1
#define KillBpin 8
#define SpeedBpin 12
Servo Lmotor;    //declares that they are motors/servo
Servo Rmotor;
float Xaxis = 0;   
float X1axis = 0;    //sets all to zero and declares them 
float axisX1 = 0;    //X1axis blue
float axisX = 0;
float KillB = 0;
float SpeedB = 0;

void setup() {
   Serial.begin(9600);
   Lmotor.attach(5);     //motor Pins
   Rmotor.attach(3);
   pinMode(joypinX, INPUT);  //sets joysticks to read
   pinMode(joypinX1, INPUT);
   pinMode(KillBpin, INPUT);  //sets joysticks to read
   pinMode(SpeedBpin, INPUT);
}

void loop() {
  digitalRead(KillBpin);
  if (KillBpin == 1){delay(750); KillB++;}
  if (KillB == 1){
    Speed;
  }
}

void Speed(){
  if (KillBpin == 1){delay(450); KillB--;}
  if (SpeedBpin == 1){SpeedB++;}
  if (SpeedB == 0){
    LowSpeed;
  }
  if (SpeedB == 1){
    HighSpeed;
  }
}

void LowSpeed(){
  Xaxis = analogRead(joypinX);    //joypin = pin plug in
  X1axis = analogRead(joypinX1);
  axisX = map(Xaxis, 0, 1023, 0, 180);  //Xaxis 0-1023
  axisX1 = map(X1axis, 0, 1023, 78, 112); //axisX 0-180
  Drive;
}

void HighSpeed(){
  if (SpeedBpin == 1){SpeedB--;}
  Xaxis = analogRead(joypinX);    //joypin = pin plug in
  X1axis = analogRead(joypinX1);
  axisX = map(Xaxis, 0, 1023, 0, 180);  //Xaxis 0-1023
  axisX1 = map(X1axis, 0, 1023, 60, 130); //axisX 0-180
  Drive;
}

void Drive(){
  //pause DEAD ZONE
  if (axisX < 100 && axisX > 80 && axisX1 < 100 && axisX1 > 80)
  {
    Rmotor.write(95);
    Lmotor.write(95);
  }
  //moving  
  else if (axisX > 100 && axisX1 < 115 && axisX1 > 70)
  {
    Lmotor.write(axisX);
    Rmotor.write(axisX1);         //add one to make even motors
    Serial.print("Movement ");
  }  
 
  analogRead(joypinX);   //monitor joystick values
  Serial.print("X ");
  Serial.print(Xaxis);
  Serial.print("/ ");
  Serial.print(axisX);
  analogRead(joypinX1);
  Serial.print("  1X ");
  Serial.print(X1axis);
  Serial.print("/ ");
  Serial.println(axisX1);
}

