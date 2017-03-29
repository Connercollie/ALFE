#include <Servo.h>
Servo Lmotor;    //Makes L and R Servo
Servo Rmotor;
const int joypiny = A0;    //attaches x and y to pin A1 and A2
const int joypinx = A4;
float Xaxis = 0;
float Yaxis = 0;
float axisY = 0;
float axisX = 0;



void setup() {
   Serial.begin(9600);
   Lmotor.attach(5);
   Rmotor.attach(3);
   pinMode(joypinx, INPUT);
   pinMode(joypiny, INPUT);
}

void loop() {
  
  Xaxis = analogRead(joypinx);
  Yaxis = analogRead(joypiny);
  axisX = map(Xaxis, 0, 1023, 0, 180);
  axisY = map(Yaxis, 0, 1023, 0, 180);
  

  //pause DEAD ZONE
  if (axisX < 100 && axisX > 80 && axisY < 100 && axisY > 80)
  {
    Rmotor.write(95);
    Lmotor.write(95);
  }

 
  else if (axisX > 100 && axisY < 115 && axisY > 70)
  {
    Lmotor.write(112.2);
    Rmotor.write(78);         //add one to make even motors
    Serial.print("FORWARD ");
  }  

   
  else if (axisX < 80 && axisY < 110 && axisY > 70)
  {
    Lmotor.write(80.2);                          
    Rmotor.write(112);
    Serial.print("BACKWARD ");
  }
 
  else if (axisX > 100 && axisY > 100)
  {
    Lmotor.write(114);
    Rmotor.write(78.2);
    Serial.print("Upper right ");
  }

  else if (axisX > 100 && axisY < 80)
  {
    Lmotor.write(112);
    Rmotor.write(76.2);
    Serial.print("Upper left ");
  }

  else if (axisX > 80 & axisX < 100 && axisY < 80)
  {
    Lmotor.write(83);
    Rmotor.write(83);  
    Serial.print("LEFT ");
  }
  
  
  else if (axisX > 80 & axisX < 100 && axisY > 100)
  {
    Lmotor.write(107);
    Rmotor.write(107);
    Serial.print("RIGHT ");   
  }
  
  else if (axisX < 80 && axisY < 80)
  {
    Lmotor.write(78.8);
    Rmotor.write(115);
    Serial.print("Lower Left ");
   }

  
  else if (axisX < 80 && axisY > 100)
  {
    Lmotor.write(75.8);
    Rmotor.write(112);
    Serial.print("Lower Right "); 
  }

  
  analogRead(joypinx);   //monitor joystick values
  Serial.print("X ");
  Serial.print(Xaxis);
  Serial.print("/ ");
  Serial.print(axisX);
  analogRead(joypiny);
  Serial.print(" Y ");
  Serial.print(Yaxis);
  Serial.print("/ ");
  Serial.println(axisY);

}

