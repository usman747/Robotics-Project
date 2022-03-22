//colorsensing

/*Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
const int S0 = 50;  
const int S1 = 51;  
const int S2 = 52;  
const int S3 = 53;  
const int out = 48; 
const int led=49;  
// LED pins connected to Arduino

int redLed = 2;  
int greenLed = 3;  
int blueLed = 4;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
int white=0;
#include<Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;  


void setup() {
  // put your setup code here, to run once:
servo_test.attach(22);      // attach the signal pin of servo to pin9 of arduino
  servo_test.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void servo_1()
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


  //color sensor initialization
  void color_start()
{

   pinMode(S0, OUTPUT);  
  pinMode(S1, OUTPUT);  
  pinMode(S2, OUTPUT);  
  pinMode(S3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT); 
  pinMode(blueLed, OUTPUT);  
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);

  
  digitalWrite(S0, HIGH);  
  digitalWrite(S1, HIGH); 
}

//colorsensing


void color_sense()  
{    
color_start();
 digitalWrite(S2, LOW);  
  digitalWrite(S3, LOW);  
   
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
   
  digitalWrite(S3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   
  digitalWrite(S2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  
digitalWrite(S2,HIGH);
digitalWrite(S3,LOW);
white=pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 

//    Serial.print("R Intensity:");  
//  Serial.print(red);  
//  Serial.print(" G Intensity: ");  
//  Serial.print(green);  
//  Serial.print(" B Intensity : ");  
//  Serial.print(blue);  
//  //Serial.println();  

  if (red < blue && red < green &&red>500 && red<6400)
  {  
   Serial.println(" - (Red Color)"); 
    servo_1();
   digitalWrite(redLed, HIGH); // Turn RED LED ON 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, LOW);  
  }  

  else if (blue < red && blue < green&&blue>400 && blue<6400)   
  {  
   Serial.println(" - (Blue Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
  }  

  else if (green < red && green < blue && green<6400)  
  {  
   Serial.println(" - (Green Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  } 
  else if(red<blue&&green<blue&&red<400)
  {
   Serial.println(" - (yellow Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  }
  else if(red<300&&blue<300&&green<300)
  {
    Serial.println(" - (white Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  }
  else if(white<red&&white<blue&&white<green&&white>500)
  {
    Serial.println(" - (white Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  }
  else{
  Serial.println();  
  }
  delay(300);   
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  
  digitalWrite(blueLed, LOW);
}



