    int AIN = 8;
int PWMA = 5;
int bIN = 7 ;
int PWMB = 6;
int stby = 3;
int x;
// define the pin
void forward(int x) {
  // create a function for movment
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
void stop( ) {
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
pinMode(8,OUTPUT);//define the pin as an output
pinMode(5,OUTPUT);//define the pin as an output
pinMode(7,OUTPUT);//define the pin as an output
pinMode(6,OUTPUT);//define the pin as an output
digitalWrite(x,1);
digitalWrite (stby,2);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0 ; 1 ; 2:
  int sensorValueR = analogRead(A0);
  int sensorValueM = analogRead(A1);
  int sensorValueL = analogRead(A2);

  // print out the value you read:
  if (sensorValueM >= 40 && sensorValueM <= 400 ){ // read the value 
    forward(100); // do this if the value is true
   Serial.print("forward ");
   Serial.println(sensorValueM);
   
  }
 
  else if (sensorValueL >= 40 &&  sensorValueL  <= 800 ){
    right(90);
    Serial.print("Turn Left");
    Serial.println(sensorValueL);
    
  }
   else if (sensorValueR >= 40 &&  sensorValueR  <= 800 ){
    left(90);
    Serial.print("Turn right");
    Serial.println(sensorValueR);
    
   }
   else if (sensorValueL <=400 &&  sensorValueR  <= 800 &&  sensorValueM  <= 800  ){
    Serial.print("Scanning");
    right(60);    
   
   }

else if (sensorValueM, sensorValueR, sensorValueL  <= 400  && sensorValueM, sensorValueR, sensorValueL >= 40){
  stop();
  Serial.print("Stop ");
  delay(100);
  }
    // delay in between reads for stability
}
