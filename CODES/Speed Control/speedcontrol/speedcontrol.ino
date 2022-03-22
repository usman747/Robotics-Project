int Rpm=200;
int rbs=0,lbs=0 ;
int cur_rpm_rt=0,cur_rpm_lt=0;
int error1,error2;
int rightmotorspeed=0,leftmotorspeed=0;
int kp=0,ki=0;
int sped_rt=0,sped_lt=0;
volatile unsigned long pcount=0;
volatile unsigned long p1count=0;
volatile unsigned long p=0;
volatile unsigned long p1=0;
float rev=0,rpm=0,RPM=0,pps=0,rps=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
// delay(5000);   //delay for testing
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),p_isr,RISING);
  attachInterrupt(digitalPinToInterrupt(3),p1_isr,RISING);
 // analogWrite(13,190);      //rightmotor
 // analogWrite(4,167);      //left motor 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(20);
Serial.println(pcount);
  cur_rpm_rt=rpm_cal(pcount);
  pcount=0;
  cur_rpm_lt=rpm_cal(p1count);
  p1count=0;
  pid();
  //  Serial.println(rightmotorspeed);
  //  Serial.println(leftmotorspeed);
 /* Serial.print(cur_rpm_rt);
  Serial.print(',');
  Serial.println(cur_rpm_lt);*/


}
 void pid()
 {
  
  int E1,E2;
  E1=E1+error1;
  E2=E2+error2;
  
  error1=Rpm-cur_rpm_rt;
  error2=Rpm-cur_rpm_lt;
if(E1>=200)
E1=200;
if(E1<=0)
E1=0;
/****************/
if(E2>=200)
E2=200;
if(E2<=0)
E2=0;
   
  sped_rt= (kp*error1) + (ki*E1);
  sped_lt= (kp*error2) + (ki*E2);
  
if(sped_rt>=245 ) 
{
  sped_rt=245;
}
if( sped_rt<=160)
{
  sped_rt=170;
}
///******************/
if(sped_lt>=245) 
{
  sped_lt=245;
}
if( sped_lt<=160)
{
  sped_lt=170;
}

  rightmotorspeed=sped_rt;
  leftmotorspeed=sped_lt;
 
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
  void p_isr() {  
            // pulse ISR for interrupt
  pcount=pcount+1;
}
  void p1_isr() {  
            // pulse ISR for interrupt
  p1count=p1count+1;
}


float rpm_cal(long p) 
{
  
  pps=p/0.02;   // pulsespersec
  rps=pps/400;
  rpm=rps*60;
  //rpm=rev*3000;   // 1 min=3000-->> 20ms's
  return rpm;
}
