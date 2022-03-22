int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0;
float kp=6.5,ki=0.57; int k=0;
float rightbasespeed=162.5;
float leftbasespeed=160.8;
float rightmotorspeed=0;
float leftmotorspeed=0;
int error=0;
float sped;
float E=0 ;
float currentpos;
int counter=0;
int sonar_counter=0;
int junc_counter=0;
/******************************/

#define trigPin 22
#define echoPin 24
long distance1=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
    analogWrite(13,128);
  analogWrite(4,128);
 //Serial.begin (9600);
 delay(2000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  linetrack();
    //delay(100);
//    if(sonar_counter>=1)
//    {
  // sonar();
//    }
}
void linetrack()
{
  adc();
  pid();
}
void display_()
{
    Serial.println("************************************");
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s6);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
  Serial.println(s8);
  }
void adc()
{
  //1 black surface
//0 white surface 

s1=analogRead(A0);
s2=analogRead(A1);
s3=analogRead(A2);
s4=analogRead(A3);
s5=analogRead(A4);
s6=analogRead(A5);
s7=analogRead(A6);
s8=analogRead(A7);

if(s1<=680)
{
  s1=1;
}
else s1=0;
if(s2<=680)
{
  s2=1;
}
else s2=0;
if(s3<=680)
{
  s3=1;
}
else s3=0;
if(s4<=680)
{
  s4=1;
}
else s4=0;
if(s5<=680)
{
  s5=1;
}
else s5=0;
if(s6<=680)
{
  s6=1;
}
else s6=0;
if(s7<=680)
{
  s7=1;
}
else s7=0;
if(s8<=680)
{
  s8=1;
}
else s8=0;
//display_();
}
void pid()
{

  adc();
  //int k=0;
  k=k+1;
  float setpoint=4;

//  if(s1>=0 && s2>=0 && s3>=0 && s6>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
//  {
//    error=0;
//    
//  }

  //if(sonar_counter>=1)
 // {
    //sonar();
 // }
//  if(s1>=1 && s2>=1 && s3>=1 && s4>=1 && s5>=1 && s6>=1 && s7>=1 && s8>=1)
//  {
//    junc_counter++;
//    if(junc_counter>=1)
//    {
//        analogWrite(7,200);
//        analogWrite(6,80);
//        delay(500);
//        analogWrite(7,128);
//        analogWrite(6,128);
//        delay(1000);
//        analogWrite(7,162.5);
//        analogWrite(6,161.8);
//        delay(300);
//  
//       while(s6!=1)
//      {
//        adc();
//      } 
//    }
//  }
  if(s1>=1 && s4>=1)
  {
  //currentpos=3;
 //delay(100);
    analogWrite(13,200);
   analogWrite(4,80);
 delay(500);
      analogWrite(13,128);
   analogWrite(4,128);
   delay(1000);
         analogWrite(13,162.5);
   analogWrite(4,161.8);
   delay(300);
  
 while(s6!=1)
 {
  adc();
 }
// sonar();
 sonar_counter++;
 }
  if(s1>=0 && s2>=1 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=2;
  }
  if(s1>=0 && s2>=0 && s3>=1 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=3;
  }
   if(s1>=0 && s2>=0 && s3>=0 && s4>=1 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=3.5;
  }
 
//  if(s1>=1 && s2>=1 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
//  {
//  currentpos=2.5;
// //delay(100);
//    analogWrite(7,200);
//   analogWrite(6,80);
// delay(350);
// while(s6!=1)
// {
//  adc();
// }
// sonar_counter++;
// }
  if(s1>=0 && s2>=1 && s3>=1 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=2;
  }
    if(s1>=0 && s2>=0 && s3>=1 && s4>=1 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=3;
  }
//    if(s1>=1 && s2>=1 && s3>=1 && s6>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
//  {
//  currentpos=2.5;
// //delay(100);
//    analogWrite(7,200);
//   analogWrite(6,80);
// delay(350);
// while(s7!=1)
// {
//  adc();
// }
 //sonar_counter++;
// }
//    if(s1>=1 && s2>=1 && s3>=1 && s6>=1 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
//  {
//  currentpos=2.5;
// //delay(100);
//    analogWrite(7,200);
//   analogWrite(6,80);
// delay(350);
// while(s7!=1)
// {
//  adc();
// }
// sonar_counter++;
// }
//    if(s1>=1 && s2>=1 && s3>=1 && s6>=1 && s5>=1 && s6>=0 && s7>=0 && s8>=0) //right
//  {
//  currentpos=2.5;
// //delay(100);
//    analogWrite(7,200);
//   analogWrite(6,80);
// delay(350);
// while(s7!=1)
// {
//  adc();
// }
// sonar_counter++;
// }
    if(s1>=0 && s2>=0 && s3>=0 && s4>=1 && s5>=1 && s6>=0 && s7>=0 && s8>=0)
  {
   currentpos=4;
  }
    if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=1 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=4.5;
  }
  
  if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=1 && s7>=0 && s8>=0)
  {
    currentpos=5;
  }
    if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=1 && s8>=0)
  {
    currentpos=7;
  }
   if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=1)
  {
currentpos=8;
  }
   if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=1 && s6>=1 && s7>=0 && s8>=0)
  {
    currentpos=5;
  }
     if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=1 && s7>=1 && s8>=0)
  {
    currentpos=5;
  }
       if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=1 && s8>=1)
    {
      currentpos=7;
    }
       if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=1 && s7>=1 && s8>=1)
    {
      currentpos=7;
    }
       if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=1 && s6>=1 && s7>=1 && s8>=1)
    {
      currentpos=7;
    }
     if(s1>=0 && s2>=0 && s3>=0 && s4>=1 && s5>=1 && s6>=1 && s7>=1 && s8>=1)
  {
   currentpos=8; //90 degrees
  }





  
//  if(s1>=0 && s2>=0 && s3>=0 && s6>=0 && s5>=1 && s6>=1 && s7>=1 && s8>=0)
//  {
//    currentpos=5;
//  }

 
//  if(s1>=0 && s2>=0 && s3>=0 && s6>=0 && s5>=0 && s6>=0 && s7>=1 && s8>=1)
//  {
//    currentpos=6;
//  }
//  if(s1>=0 && s2>=0 && s3>=0 && s6>=1 && s5>=1 && s6>=0 && s7>=0 && s8>=0)
//  {
//    currentpos=6;
//  }
 

  error=setpoint-currentpos;
  E=E+error*k;
  
  
//  for(float i=0;i<=(k-1);i++)
//  {
//    E[i] = error[i] + error[i-1];
//  }
if(E>15)
E=15;
if(E<-15)
E=-15;
   counter++;
  if(counter<=5)
  {
    error=0;
  }
  sped = kp*error + ki*(E);
  rightmotorspeed=rightbasespeed+sped;
  leftmotorspeed=leftbasespeed-sped;
   if(rightmotorspeed>=245)
  rightmotorspeed=245;
    if(leftmotorspeed>=245)
  leftmotorspeed=245;
    if(rightmotorspeed<=0)
  rightmotorspeed=15;
    if(leftmotorspeed<=0)
  leftmotorspeed=15;
    analogWrite(13,rightmotorspeed);
    analogWrite(4,leftmotorspeed);
}
//void sonarlib()
//{
//      delay(50);                    
//  Serial.print("Ping: ");
//  Serial.print(sonar.ping_cm()); 
//  Serial.println("cm");
//  if(sonar.ping_cm()<=5)
//  {
//    analogWrite(4,255);
//    analogWrite(4,255);
//    delay(5000);
//        analogWrite(4,20);
//    analogWrite(4,20);
//    delay(3000);
//  }
//}
// void pid_sonar()
// {
//  int setpoint=5;
//  int currentposition=distance1;
//  int error;
//  int sped_sonar;
//  int k;
//  k=k+1;
//  int E;
//  E=E+error*k;
//  error=currentposition-setpoint;
//if(E>12)
//E=12;
//if(E<-12)
//E=-12;
//   
//  sped_sonar= kp*error + ki*E;
//
//  rightmotorspeed=rbs_sonar+sped_sonar;
//  leftmotorspeed=lbs_sonar+sped_sonar;
// 
//     if(rightmotorspeed_sonar>=265)
//  rightmotorspeed_sonar=265;
//    if(leftmotorspeed_sonar>=265)
//  leftmotorspeed_sonar=265;
//    if(rightmotorspeed_sonar<=0)
//  rightmotorspeed_sonar=15;
//    if(leftmotorspeed_sonar<=0)
//  leftmotorspeed_sonar=15;
//
//
//
//  analogWrite(4,rightmotorspeed_sonar);
//  analogWrite(6,leftmotorspeed_sonar);
//  }
  
void sonar()
{
  long duration1;

  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration1 = pulseIn(echoPin, HIGH);
  distance1 = (duration1/2) / 29.1;
Serial.println(distance1);
  if(distance1<=5)
  {
    analogWrite(13,128);
    analogWrite(4,128);
    delay(5000);
        analogWrite(13,200);
    analogWrite(4,128);
    delay(2000);
  }
}

