/*************************************************************************
 * Author    :  Muhammad Ali Nagra                                      
 * Code      :  Sampling time set(Timed events)
 * Platform  :  ArduinoMega(ATmega256)
 * Date/Time :  6th July,2016/ 0432 Hours
 * 
 * Note     : This piece of code is the property of Team Mola Jutt,C@SE
**************************************************************************/


#define encoder1 2// Encoder Input pin1
#define encoder2 3// Encoder Input pin2

#define pwm1_right 13 // Pwm pin for right side motor, clock wise movement
#define pwm1_left 12 // Pwm pin for right side motor, anti-clock wise movement

#define pwm2_right 11 // Pwm pin for left side motor, clock wise movement
#define pwm2_left 10   //Pwm pin for left side motor, anti-clock wise movement

#define sampling_interval 40 //setting a sampling interval in milliseconds
#define pulse_in 41  //pulses to inches conversion constant,1 inch=41 pulses on a tyre of radius 4cm
#define pulse_co 738 //pulses to field co-ordinate conversion constant, 1 box=18inches

int count1=0; // Variable which stores the number of pulses counted from encoder1
int count2=0; // Variable which stores the number of pulses counted from encoder2

float coar_mov=0;
double tot_pulses1=0;
double tot_pulses2=0;
double previous_mills=0; // Variable to store the time passed since the board was turned on
double current_mills=0;  // Variable to store the time passed since the board was turned on
void setup() {

// Setting The Pwm Pins As OutPuts
pinMode(pwm1_right,OUTPUT);
pinMode(pwm1_left,OUTPUT);
pinMode(pwm2_right,OUTPUT);
pinMode(pwm2_left,OUTPUT);

// Setting the encoder pins as inputs
pinMode(encoder1,INPUT);
pinMode(encoder2,INPUT);
  
// Setting Up the external interrupts for polling
attachInterrupt(digitalPinToInterrupt(encoder1),ISR1,RISING);
attachInterrupt(digitalPinToInterrupt(encoder2),ISR2,RISING);
Serial.begin(9600);
}

void loop() {
 current_mills=millis();

 
 // The Timed Event
 if((current_mills-previous_mills)>sampling_interval)
 {
  previous_mills=current_mills;
  
  //stoping the interrupts, so that they dont cause hindernce in the calculations
  detachInterrupt(digitalPinToInterrupt(encoder1));
  detachInterrupt(digitalPinToInterrupt(encoder2));

  //adding the total pulses counted thus far into variables
  tot_pulses1=tot_pulses1+count1;
  tot_pulses2=tot_pulses2+count2;
  
  //perform the timed calculations here...
  Serial.println(tot_pulses1);
  Serial.println(tot_pulses2);

  
  //clearing the counter variables
  count1=0;
  count2=0;
  
  //after you are finished enable the hardware interrupts for encoders again 
  attachInterrupt(digitalPinToInterrupt(encoder1),ISR1,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder2),ISR2,RISING);
 }



}

// Functions

void dis_co(void)
{
  float cor_r=0;
  float cor_l=0;

  cor_r=pulse_co*tot_pulses1;
  cor_l=pulse_co*tot_pulses2;
  coar_mov=(cor_r+cor_l)/2;
  
  
}
void pwm(int pin, int dut)
{
   analogWrite(pin,dut);
}
void ISR1(void)
{
  count1++;
}
void ISR2(void)
{
  count2++;
}

