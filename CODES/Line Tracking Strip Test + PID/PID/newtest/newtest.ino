int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0;
float kp=15,ki=0.66;
int rightbasespeed=170;
int leftbasespeed=170;
float rightmotorspeed=0;
float leftmotorspeed=0;
 int error=0;
  float sped;
  float E=0 ;
  float currentpos;
void setup() {
  // put your setup code here, to run once:
//    analogWrite(13,rightbasespeed);
//  analogWrite(4,leftbasespeed);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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

if(s1>=660)
{
  s1=1;
}
else s1=0;
if(s2>=660)
{
  s2=1;
}
else s2=0;
if(s3>=660)
{
  s3=1;
}
else s3=0;
if(s4>=660)
{
  s4=1;
}
else s4=0;
if(s5>=660)
{
  s5=1;
}
else s5=0;
if(s6>=660)
{
  s6=1;
}
else s6=0;
if(s7>=660)
{
  s7=1;
}
else s7=0;
if(s8>=660)
{
  s8=1;
}
else s8=0;
pid();
  Serial.println("************************************");
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
  Serial.println(s8);
//  Serial.println(leftmotorspeed);
//  Serial.println(rightmotorspeed);
//  Serial.println(E);
//  Serial.println(error);
//  Serial.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
//Serial.print(currentpos);
}

void pid()
{
  
  int k;
  k=k+1;
  float setpoint=4;
 
//  if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
//  {
//    error=0;
//    
//  }

  
  
  if(s1>=1 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=1;
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
 
  if(s1>=1 && s2>=1 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=1;
  }
  if(s1>=0 && s2>=1 && s3>=1 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=2;
  }
    if(s1>=0 && s2>=0 && s3>=1 && s4>=1 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=3;
  }
    if(s1>=1 && s2>=1 && s3>=1 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=1;
  }
    if(s1>=1 && s2>=1 && s3>=1 && s4>=1 && s5>=0 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=1;
  }
    if(s1>=1 && s2>=1 && s3>=1 && s4>=1 && s5>=1 && s6>=0 && s7>=0 && s8>=0)
  {
    currentpos=0;
  }
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
    currentpos=6;
  }
   if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=0 && s8>=1)
  {
    currentpos=7;
  }
   if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=1 && s6>=1 && s7>=0 && s8>=0)
  {
    currentpos=5;
  }
     if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=1 && s7>=1 && s8>=0)
  {
    currentpos=6;
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





  
//  if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=1 && s6>=1 && s7>=1 && s8>=0)
//  {
//    currentpos=5;
//  }

 
//  if(s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0 && s6>=0 && s7>=1 && s8>=1)
//  {
//    currentpos=6;
//  }
//  if(s1>=0 && s2>=0 && s3>=0 && s4>=1 && s5>=1 && s6>=0 && s7>=0 && s8>=0)
//  {
//    currentpos=4;
//  }
 

  E=E+error*k;
  error=setpoint-currentpos;
  
//  for(float i=0;i<=(k-1);i++)
//  {
//    E[i] = error[i] + error[i-1];
//  }
if(E>12)
E=12;
if(E<-12)
E=-12;
 
  sped = kp*error + ki*(E);
  rightmotorspeed=rightbasespeed+sped;
  leftmotorspeed=leftbasespeed-sped;
   if(rightmotorspeed>=245)
  rightmotorspeed=245;
    if(leftmotorspeed>=245)
  leftmotorspeed=245;
    if(rightmotorspeed<=0)
  rightmotorspeed=0;
    if(leftmotorspeed<=0)
  leftmotorspeed=0;
    analogWrite(13,rightmotorspeed);
    analogWrite(4,leftmotorspeed);
}

