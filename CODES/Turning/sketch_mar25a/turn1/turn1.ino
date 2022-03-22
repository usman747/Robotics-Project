#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

float headingDegrees;
float currentheading;

int rev=0;
int counter=0;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup() {
  // put your setup code here, to run once:
   if(!mag.begin())
  {
     /*There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while(1);
  }
pinMode(2,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2),count,RISING);
Serial.begin(9600);
  analogWrite(10,230);
  analogWrite(9,230);
}

void loop() {
  // put your main code here, to run repeatedly:
/*if(rev==50)
{
  detachInterrupt(digitalPinToInterrupt(2));
  turn();
  off(1);

}*/
magno();
  if(counter >= 30)
  {
    
   rev=rev+1; 
   counter=0;
  }
  else
  counter=counter;

 if(rev >= 15)
  
{
  Serial.println("IFIFIFIF");
  detachInterrupt(digitalPinToInterrupt(2));
  turn();
 off(1);
}
else
rev=rev;

//revo();
//chk();  
Serial.print("PULSE ");
Serial.println(counter);
Serial.print("REV ");
Serial.println(rev);
 Serial.print("Heading (degrees): "); 
 Serial.println(headingDegrees);
  delay(100);
}

void count()
{
  counter=counter+1;
 // revo();
 //chk();
}
void revo()
{    
  if(counter==30)
  {
   rev=rev+1; 
   counter=0;
  }
  
}
void chk()
{
       if(rev==50)
{//detachInterrupt(digitalPinToInterrupt(2));
  turn();
 off(1);
}
}

void off(int a)
{
  if(a==1)
  {
      analogWrite(10,255);
      analogWrite(9,255);
  }
  else
  {
    analogWrite(10,230);
    analogWrite(9,230);
  }
}
void turn()
{ 
          rev=0;
         currentheading=headingDegrees;
          Serial.print("Current");
          Serial.println(currentheading);
         float cf=currentheading+90;
         Serial.print(cf);
     while(!(headingDegrees >= cf))
     {
            sensors_event_t event; 
    mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  /*float declinationAngle = 0.22;
  heading += declinationAngle;*/
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
   headingDegrees = heading * 180/M_PI;
       Serial.print("Heading (degrees): "); 
       Serial.println(headingDegrees);
       analogWrite(10,255);
       analogWrite(9,170);
     }
     off(1);
}
void magno()
{
    sensors_event_t event; 
    mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  /*float declinationAngle = 0.22;
  heading += declinationAngle;*/
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
   headingDegrees = heading * 180/M_PI;
   Serial.print("HAHAHAHA");
}

