int rightmotorspeed=0;
int leftmotorspeed=0;
int rbs=150,lbs=150;
long distance1=0;
long distance2=0;
long distance=0;
float kp=1.1;
float ki=0.09;
//int k=0;
  int currentposition=0;
  float error=0;
  int sped=0;
  float E=0;

#define trigPin 220
#define echoPin 24

#define trigPin1 26
#define echoPin1 28


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin1, INPUT);
  delay(1000); //For testing 
}

void loop() {
distance1=sonar(trigPin,echoPin);  //forward
 delay(60);
distance2=sonar(trigPin1,echoPin1); //backward
delay(60);
  if(distance1>=80  )
  {
    distance1=80;
  }
    if(distance2>=80  )
  {
    distance2=80;
  }
pid();

//  Serial.println("**********");
//  Serial.println(distance1);
//Serial.println(distance2);
//Serial.println(error);
Serial.println(currentposition);
//    Serial.println("**********");
 }
 
 void pid()
 {
  int setpoint=25;
 // currentposition=distance1-distance2;
 if(distance1>=setpoint && distance2>=setpoint) //equal
  {
    currentposition=distance1-distance2;
  }
  if(distance1>setpoint && distance2>=setpoint)  //1st sonar greater than setpoint
  {
    currentposition=distance1 ;
  }
    if(distance1>=setpoint && distance2>setpoint) //2nd sonar greater than setpoint
  {
    currentposition=distance2;
  }
   if(distance1<setpoint && distance2>=setpoint)   //1st sonar is at less distance than setpoint
  {
    currentposition=distance1;
  }
   if(distance1>=setpoint && distance2<setpoint)    //2nd sonar is at less distance than setpoint
  {
    currentposition=distance2;
  } 
  
   if(distance1<setpoint && distance2<setpoint)   //both have less dist
  {
  if(distance1<distance2)
  {
    currentposition=distance1;
    }
    else
    currentposition=distance2;
  }
   if(distance1>setpoint && distance2>setpoint)   //both have greater dist
  {
     if(distance1>distance2)
  {
    currentposition=distance1;
    }
    else
    currentposition=distance2;
  } 



  
  E=E+error*ki;
  error=setpoint-currentposition;
if(E>120)
E=120;
if(E<-120)
E=-120;
   
  sped= kp*error + E;

  rightmotorspeed=rbs-sped;
  leftmotorspeed=lbs+sped;
 
     if(rightmotorspeed>=245)
  rightmotorspeed=160;
    if(leftmotorspeed>=245)
  leftmotorspeed=160;
    if(rightmotorspeed<=0)
  rightmotorspeed=15;
    if(leftmotorspeed<=0)
  leftmotorspeed=15;



  analogWrite(13,rightmotorspeed);
  analogWrite(4,leftmotorspeed);
  }
  


long sonar(int a,int b)
{
    long duration;
  digitalWrite(a, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(a, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(a, LOW);
  duration = pulseIn(b, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}
