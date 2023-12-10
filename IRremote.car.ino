#include <IRremote.h>

//InfraRed
#define IReceive 9

//Arrows
#define UP    70
#define RIGHT 67
#define LEFT  68
#define DOWN  21
#define OK   64


    int AIN = 8;
int PWMA = 5;
int bIN = 7 ;
int PWMB = 6;
int stby = 3;
int x;
void forward(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,1);
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x);
}
void backward(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,0);
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x);
}
void left(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,1);
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x);
}
void right(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,0);
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x);
}
void leftforward(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,1);
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x/2);
}
void leftbackward(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,0);
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x/2);
}
void rightforward(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,1);
analogWrite(5,x/2);
digitalWrite(7,1);
analogWrite(6,x);
}
void rightbackward(int x) {
  // put your main code here, to run repeatedly:
digitalWrite(8,0);
analogWrite(5,x/2);
digitalWrite(7,0);
analogWrite(6,x);
}
void stop(int x ) {
  // put your main code here, to run repeatedly:
digitalWrite(8,1);
analogWrite(5,0);
digitalWrite(7,1);
analogWrite(6,0);
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
digitalWrite(x,1);
digitalWrite (stby,2);

 //IRtest
  Serial.begin(9600);
  IrReceiver.begin(IReceive, ENABLE_LED_FEEDBACK);
}
void loop() 
{
//Control
 if (IrReceiver.decode()) 
 {
    Serial.println(IrReceiver.decodedIRData.command);
    if(IrReceiver.decodedIRData.command == OK)
    {
      stop(100);
    }
    else if(IrReceiver.decodedIRData.command == UP)
    {
      forward(100);
    }
    else if(IrReceiver.decodedIRData.command == RIGHT)
    {
      right(100);
      delay(450);
      stop(100);
    }
    else if(IrReceiver.decodedIRData.command == LEFT)
    {
      left(100);
      delay(450);
      stop(100);
    }
    else if(IrReceiver.decodedIRData.command == DOWN)
    {
      backward(100);
    }
    IrReceiver.resume();
 }
}
