#include<Servo.h>
int servopin=22;
Servo Servo1;
void setup() {
  // put your setup code here, to run once:
Servo1.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
Servo1.write(0);
delay(1000);
Servo1.write(180);
delay(1000);
//  digitalWrite(22,HIGH);
//  delay(1);
//  digitalWrite(22,LOW);
// delay(10);
//analogWrite(13,13);

 //delay(1000); 
}


