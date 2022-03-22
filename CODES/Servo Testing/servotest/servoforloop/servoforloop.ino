#include<Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;    
 
void setup() 
{ 
  servo_test.attach(22);      // attach the signal pin of servo to pin9 of arduino
  servo_test.write(0);
  delay(2000);
} 
  
void loop() 
{ 
  for(angle = 90; angle < 180; angle += 5)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(5);                       
  } 
 
  delay(1000);
  
  for(angle = 90; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
}
