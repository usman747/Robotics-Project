
int left_90,right_90,forw,s1,s2,s3,s4,s5,s6,s7,s8;
void setup() {
  // put your setup code here, to run once:

left_90=0,right_90=0;  
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

//if(s1>=650)
//{
//  s1=1;
//}
//else s1=0;
//if(s2>=650)
//{
//  s2=1;
//}
//else s2=0;
//if(s3>=650)
//{
//  s3=1;
//}
//else s3=0;
//if(s4>=650)
//{
//  s4=1;
//}
//else s4=0;
//if(s5>=650)
//{
//  s5=1;
//}
//else s5=0;
//if(s6>=650)
//{
//  s6=1;
//}
//else s6=0;
//if(s7>=650)
//{
//  s7=1;
//}
//else s7=0;
//if(s8>=650)
//{
//  s8=1;
//}
//else s8=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//forw//stop
if((s1>=0)&&(s2>=0)&&(s3>=0)&&(s4>=1)&&(s5>=1)&&(s6>=0)&&(s7>=0)&&(s8>=0))
{
forw=1;
}
if((s1>=0)&&(s2>=0)&&(s3>=0)&&(s4>=0)&&(s5>=0)&&(s6>=0)&&(s7>=0)&&(s8>=0))
{
analogWrite(13,255);
analogWrite(4,255);
}
if((s1>=1)&&(s2>=1)&&(s3>=1)&&(s4>=1)&&(s5>=1)&&(s6>=1)&&(s7>=1)&&(s8>=1))
{
forw=0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//90
//if((s1>=1)&&(s2>=1)&&(s3>=1)&&(s4>=1)&&(s5>=1)&&(s6>=0)&&(s7>=0)&&(s8>=0))
//{
//  while(!(s3>=0))
//  {
//    analogWrite(13,180);
//    analogWrite(4,75);
//  }
//}
//if((s1>=0)&&(s2>=0)&&(s3>=0)&&(s4>=1)&&(s5>=1)&&(s6>=1)&&(s7>=1)&&(s8>=1))
//{
//  while(!(s6>=0))
//  {
//    analogWrite(4,180);
//    analogWrite(13,75);
//   }
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions
if(forw>=1)
{
  analogWrite(13,180);
  analogWrite(4,180);
}

if(forw>=0)
{
  analogWrite(13,255);
  analogWrite(4,255);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Serial.println("************************************");
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
  Serial.println(s8);
  delay(1000);
}
