// difine the pin
int AIN = 8;
int PWMA = 5;
int bIN = 7 ;
int PWMB = 6;
int stby = 3;
int x=100;
void forward() {
  // function for movement
digitalWrite(8,1);
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x);
}
void backward() {
  // function for movement
digitalWrite(8,0);
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x);
}
void left() {
  //function for movement
digitalWrite(8,1);
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x);
}
void right() {
  //function for movement
digitalWrite(8,0);
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x);
}
void leftforward() {
  //function for movement
digitalWrite(8,1);
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x/2);
}
void leftbackward() {
  // function for movement
digitalWrite(8,0);
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x/2);
}
void rightforward() {
  //function for movement
digitalWrite(8,1);
analogWrite(5,x/2);
digitalWrite(7,1);
analogWrite(6,x);
}
void rightbackward() {
  //function for movement
digitalWrite(8,0);
analogWrite(5,x/2);
digitalWrite(7,0);
analogWrite(6,x);
}
void stop( ) {
  //function for movement
digitalWrite(8,1);
analogWrite(5,0);
digitalWrite(7,1);
analogWrite(6,0);
}

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
const int trigPin = 13;  // Trig pin of the ultrasonic sensor
const int echoPin = 12; // Echo pin of the ultrasonic sensor
int distance;
long duration;
int detectFront = 0, detectRight = 0, detectLeft = 0;
void setup() {
  //set up the pin to run
 pinMode(8,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
digitalWrite(x,1);
digitalWrite (stby,2);

 
  myservo.attach(10);  // Attach the servo to pin 10
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  int detectFront = 0, detectRight = 0, detectLeft = 0;
  }


void moveServo(int degrees) {
  // Map the degrees to the servo limits
  int mappedDegrees = map(degrees, 0, 180, 0, 180);

  myservo.write(mappedDegrees); // Move the servo to the specified position
}
int sensorRead(){
 long duration, distance;
   digitalWrite(13, LOW);   
  delayMicroseconds(2);
  digitalWrite(13, HIGH);  
  delayMicroseconds(20);
  digitalWrite(13, LOW);   
  float Fdistance = pulseIn(12, HIGH);  
  Fdistance= Fdistance / 58;  
   Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
     
  return (int)Fdistance;
  // Print the distance value to the Serial Monitor
 

  delay(500); // Wait for a second before taking another measurement

}
  void loop(){
  moveServo(99);
  delay(500);
  detectFront = sensorRead();

  if (detectFront <= 30){
    stop();
    delay(500);
    moveServo(0);
    delay(1000);
    detectRight = sensorRead();
   
   
    
   
   if (detectRight > detectLeft){
    left();
    delay(150);
   }
    delay(500);
    moveServo(99);
    delay(1000);
    moveServo(180);
    delay(1000);
    detectLeft = sensorRead();

   delay(500);
   moveServo(99);
   delay(1000);
   else if (detectRight < detectLeft){
    right();
    delay(150);
   } 
   else if ((detectRight <= 30) && ( detectLeft <= 30)){
    backward();
    delay(180);
   }
   else {
    forward();
   }
  }
  else{
   forward();
  }
}
  
