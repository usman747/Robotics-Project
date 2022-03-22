/*
Coded by Haider Iftikhar
Center for Advanced Studies in Engineering (C@SE)
*/
#include <Servo.h>

//Servo ma,mb;  //Ma>right  Mb>left



int error=0,p_error=0,kp=10;

const byte ma = 2;
const byte mb = 3;

const byte mad1 = 22;
const byte mad2 = 23;

const byte mbd1 = 26;
const byte mbd2 = 24;

float i_error=00.00,t_error=00.00,b_speed=35.00,ki=0.1,a,v_out=0.0,m1_speed=00.00,m2_speed=00.00;

float s_3_vol,s_2_vol,s_1_vol,s0_vol,s1_vol,s2_vol,s3_vol;
int s_3,s_2,s_1,s0,s1,s2,s3;  //when using ADC

void ini_sensors(void);
void read_sensors(void);
void adc(void);
void display_s(void);
void display_v(void);
void straight(void);
void right_first(void);
void left_first(void);
void u_turn(void);

void setup() 
{
  pinMode(mad1, OUTPUT);
  pinMode(mad2, OUTPUT);
  pinMode(mbd1, OUTPUT);
  pinMode(mbd2, OUTPUT);
  pinMode(ma, OUTPUT);
  pinMode(mb, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  adc();
  
  u_turn();  
  //left_first();
  right_first();
  straight();
}
void straight(void)
{
  adc();
  if(s_1==1&&s1==1)    //0 0 111 0 0
  {
    error=0;
  }
  if(s_1==1&&s0==1&&s1==0)    //0 0 110 0 0
  {
    error=-1;
  }
  if(s_1==0&&s0==1&&s1==1)    //0 0 011 0 0
  {
    error=1;
  }
  if(s_1==1&&s0==0&&s1==0)  //0 0 100 0 0
  {
    error=-2;
  }
  if(s_1==0&&s0==0&&s1==1)  //0 0 001 0 0
  {
    error=2;
  }
  if(s_2==1&&s_1==1) //0 1 1 0 0 0
  {
    error=-3;
  }
  if(s2==1&&s1==1) //0 0 0 1 1 0
  {
    error=3;
  }
  if(s_3==0&&s_2==1) //0 1 0 0 0 0
  {
    error=-4;
  }
  if(s3==0&&s2==1) //0 0 0 0 1 0
  {
    error=4;
  }
  if(s_3==1&&s_2==1) //1 1 0 0 0 0
  {
    error=-5;
  }
  if(s3==1&&s2==1) //0 0 0 0 1 1
  {
    error=5;
  }
  if(s_3==1&&s_2==0) //1 0 0 0 0 0
  {
    error=-6;
  }
  if(s3==1&&s2==0) //0 0 0 0 0 1
  {
    error=6;
  }
  if(s_3==0&&s_2==0&&s_1==0&&s0==0&&s1==0&&s2==0&&s3==0)
  {
    error=error;
  }
  

  p_error=kp*error;
  i_error=i_error+ki*error;
  if(i_error>=10)
    i_error=10;
  if(i_error<=-10)
    i_error=-10;

  t_error=p_error+i_error;

  m1_speed=b_speed-t_error;
  m2_speed=b_speed+t_error;
  
  if(m1_speed>=90)
    m1_speed=90;
  if(m1_speed<=0)
    m1_speed=0;

  if(m2_speed>=90)
    m2_speed=90;
  if(m2_speed<=0)
    m2_speed=0;

  pwm1(m1_speed,1);
  pwm2(m2_speed,1);
}

void right_first(void)
{
  if(s3==1&&s1==1&&s_3==0)
  {
    pwm1(30,1);
    pwm2(30,0);
    delay(300);
    while(s_2!=1)
    {
      adc();
      pwm1(30,1);
      pwm2(30,0);
    }
  }
  if(s_3==1&&s_1==1&&s3==0)
  {
    delay(100);
    adc();
    if(s_1==1||s1==1)
    {
      straight();
    }
    else
    {
      pwm1(30,0);
      pwm2(30,1);
      delay(200);
      while(s2!=1)
      {
        adc();
        pwm1(30,0);
        pwm2(30,1);
      } 
    }
  }
  if(s_3==1&&s_1==1&&s1==1&&s3==1)
  {
    pwm1(30,1);
    pwm2(30,0);
    delay(300);
    while(s_2!=1)
    {
      adc();
      pwm1(30,1);
      pwm2(30,0);
    }
  }
}

void left_first(void)
{
  if(s_3==1&&s_1==1&&s3==0)
  {
    pwm1(20,0);
    pwm2(20,1);
    delay(200);
    while(s1!=1)
    {
      adc();
      pwm1(30,0);
      pwm2(30,1);
    }
  }
  if(s3==1&&s1==1&&s_3==0)
  {
    delay(100);
    if(s_1==1&&s1==1)
    {
      straight();
    }
    else
    {
      pwm1(20,1);
      pwm2(20,0);
      delay(200);
      while(s_1!=1)
      {
        adc();
        pwm1(20,1);
        pwm2(20,0);
      }
    }
  }
}

void u_turn(void)
{
  if(s_3==0&&s_2==0&&s_1==0&&s0==0&&s1==0&&s2==0&&s3==0)
  {
    pwm1(20,1);
    pwm2(20,0);
    delay(200);
    while(s_2!=1)
    {
      adc();
      pwm1(20,1);
      pwm2(20,0);
    }
  }
}

void display_s(void)
{
  Serial.print(s_3);
  Serial.print(s_2);
  Serial.print(s_1);
  Serial.print(s0);
  Serial.print(s1);
  Serial.print(s2);
  Serial.print(s3);
  Serial.print("\n");
}

void pwm1(float speed, int dir)
{
  if(dir==1)
  {
    digitalWrite(mad1,HIGH);
    digitalWrite(mad2,LOW);
  }
  if(dir==0)
  {
    digitalWrite(mad1,LOW);
    digitalWrite(mad2,HIGH);
  }
 analogWrite(ma,speed*2.5);
}

void pwm2(float speed, int dir)
{
  if(dir==1)
  {
    digitalWrite(mbd1,HIGH);
    digitalWrite(mbd2,LOW);
  }
  if(dir==0)
  {
    digitalWrite(mbd1,LOW);
    digitalWrite(mbd2,HIGH);
  }
  analogWrite(mb,speed*2.5);
}

void adc(void)
{
  s_3_vol=analogRead(A0);
  s_2_vol=analogRead(A1);
  s_1_vol=analogRead(A2);
  s0_vol=analogRead(A3);
  s1_vol=analogRead(A4);
  s2_vol=analogRead(A5);
  s3_vol=analogRead(A6);

  s_3_vol=(s_3_vol/1024.00)*5;
  s_2_vol=(s_2_vol/1024.00)*5;
  s_1_vol=(s_1_vol/1024.00)*5;
  s0_vol=(s0_vol/1024.00)*5;
  s1_vol=(s1_vol/1024.00)*5;
  s2_vol=(s2_vol/1024.00)*5;
  s3_vol=(s3_vol/1024.00)*5;

  if(s_3_vol>3.0)
    s_3=1;
  else
    s_3=0;

  if(s_2_vol>3.0)
    s_2=1;
  else
    s_2=0;

  if(s_1_vol>4.0)
    s_1=1;
  else
    s_1=0;

  if(s0_vol>3.0)
    s0=1;
  else
    s0=0;

  if(s1_vol>3.0)
    s1=1;
  else
    s1=0;

  if(s2_vol>3.0)
    s2=1;
  else
    s2=0;

  if(s3_vol>4.0)
    s3=1;
  else
    s3=0;
}


