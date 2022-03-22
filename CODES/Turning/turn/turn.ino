#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
int rev=0;
int counter=0;
float headingDegrees;
float currentheading;
/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup(void) 
{
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),count,RISING);
  Serial.begin(9600);
  analogWrite(10,230);
  analogWrite(9,230);
}

void loop(void) 
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
  if(rev==50)
{
  
    off(1);
    turn();
    off(1);
  detachInterrupt(digitalPinToInterrupt(2));
}
  
  Serial.print("Heading (degrees): "); 
  Serial.println(headingDegrees);
  Serial.print("Pulsecount "); 
  Serial.println(counter);
  Serial.print("Revolutions "); 
  Serial.println(rev);
  delay(500);
}

void count()
{
  counter=counter+1;
  if(counter==30)
  {
    rev=rev+1;
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
         currentheading=headingDegrees;
     while(!headingDegrees==currentheading+90)
     {
      analogWrite(10,255);
      analogWrite(9,190);
      }
  
  }
