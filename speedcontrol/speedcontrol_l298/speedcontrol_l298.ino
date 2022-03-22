 /*************************************************************************
 * Author    :  Muhammad Ali Nagra                                      
 * Code      :  Speed Control_L298(Timed events)
 * Platform  :  ArduinoMega(ATmega256)
 * Date/Time :  12th July,2016/ 0948 Hours
 * 
 * Note     : This piece of code is the property of Team Mola Jutt,C@SE
**************************************************************************/
#define encoder1 2// Encoder Input pin1
#define encoder2 3// Encoder Input pin2

#define pwm_right 13 // Pwm pin for right side motor
#define en1_right  12 // enable pin 1 , right side L298
#define en2_right   11 // enable pin 2 , right side L298

#define pwm_left 10 // Pwm pin for left side motor
#define en1_left 9  // enable pin 1, left side L298
#define en2_left  8  // enable pin 2, left side L298

#define pulse_constant 400  // The encoder is 400 ppr
#define box_constant   728  // To move one box, The controller must count 728 pulses

#define sampling_interval 10// Define sampling time

#define rpm 200


int count1=0;
int count2=0;

int dut1=250; //setting initial duty cycle
int dut2=250; //setting initial duty cycle

double tot_pulses1=0;
double tot_pulses2=0;

double current_mills=0;
double previous_mills=0;

float kp=10000.0;
float ki=0.05;

int cur_speed1=0;
int cur_speed2=0;

int error1=0;
int error2=0;
int acc_error1=0;
int acc_error2=0;

uint8_t flag=0;
void setup()
{
 pinMode(pwm_right,OUTPUT); 
 pinMode(en1_right,OUTPUT);
 pinMode(en2_right,OUTPUT);
 
 pinMode(pwm_left,OUTPUT); 
 pinMode(en1_left,OUTPUT);
 pinMode(en2_left,OUTPUT);
 
// Setting the encoder pins as inputs
pinMode(encoder1,INPUT);
pinMode(encoder2,INPUT);

// Setting Up the external interrupts for polling
attachInterrupt(digitalPinToInterrupt(encoder1),ISR1,RISING);
attachInterrupt(digitalPinToInterrupt(encoder2),ISR2,RISING);
}

void loop() 
{
  while(flag!=1)
  {
  box(1);
  current_mills=millis();

 
 // The Timed Event
 if((current_mills-previous_mills)>sampling_interval)
 {
  previous_mills=current_mills;
  tot_pulses1=tot_pulses1+count1;
  tot_pulses2=tot_pulses2+count2;
  //stoping the interrupts, so that they dont hindernce in the calculations
  detachInterrupt(digitalPinToInterrupt(encoder1));
  detachInterrupt(digitalPinToInterrupt(encoder2));

  //adding the total pulses counted thus far into variables

  
  //perform the timed calculations here...
  speed_cntrl();
 
  //clearing the counter variables
  count1=0;
  count2=0;
  
  //after you are finished enable the hardware interrupts for encoders again 
  attachInterrupt(digitalPinToInterrupt(encoder1),ISR1,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder2),ISR2,RISING);

 }
  
}
stop_r();
}
void ISR1(void)
{
  count1++;
}
void ISR2(void)
{
  count2++;
}

void stop_r()
{
  analogWrite(pwm_right,0);
  analogWrite(pwm_left,0);

  digitalWrite(en1_right,LOW);
  digitalWrite(en2_right,LOW);
  digitalWrite(en1_left,LOW);
  digitalWrite(en2_left,LOW);

}
void frwrd()
{
  analogWrite(pwm_right,dut1);
  analogWrite(pwm_left,dut2);

  digitalWrite(en1_right,HIGH);
  digitalWrite(en2_right,LOW);
  digitalWrite(en1_left,HIGH);
  digitalWrite(en2_left,LOW);

}
void speed_cntrl()
{
  cur_speed1=3.75*count1;
  cur_speed2=3.75*count2;

  error1=rpm-cur_speed1;
  error2=rpm-cur_speed2;

  acc_error1=acc_error1+error1;
  acc_error2=acc_error2+error2;

  
  dut1=(kp*error1)+(ki*acc_error1);
  dut2=(kp*error2)+(ki*acc_error2);
}
void box(uint8_t x)
{

  if((tot_pulses1<(x*box_constant))||(tot_pulses2<(x*box_constant)))
  {
    flag=0;
    frwrd();
  }
  else
    flag=1;
}
