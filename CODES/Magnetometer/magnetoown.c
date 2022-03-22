#include<p18f4520.h>
#include<i2c.h>
#include<math.h>

#pragma config OSC = HS
#pragma config LVP = OFF
#pragma config WDT = OFF
#pragma config DEBUG = OFF

#define read_sensor 0x3D
#define write_sensor 0x3C
#define pi 3.14159265359

void init_compass(void);
void get_value(void);

int x,y,z;
float heading;
char ack;
void delay();

void main()
{
	unsigned char cr[3];
	char a=0b00010000;
	int k;
	TRISD=0;
	PORTD=0;
	SSPSTAT = 0x00;
	SSPCON1 = 0x00;
	SSPCON2 = 0x00;

	SSPCON1 = 0x28; 
	SSPADD = 0x06;	//Baud Rate 400k
	
	TRISCbits.TRISC3 = 1;	//SCL
	TRISCbits.TRISC4 = 1;	//SDA
	init_compass();
	IdleI2C();
	StartI2C();
	WriteI2C(write_sensor);
	WriteI2C(0x03);			//address pointer to 0x03
	StopI2C();
	
	IdleI2C();
	StartI2C();
	WriteI2C(read_sensor);
	SSPCON2bits.RCEN=1;
	getsI2C(cr,'3');		//reading 6 bytes/registers from 0x03-0x08
	StopI2C();
	SSPCON2bits.RCEN=0;
	while(1)
	{
		get_value();
PORTD=heading;
		delay();
	}
}

void init_compass()
{
	IdleI2C();
	StartI2C();
	ack = WriteI2C(write_sensor);
	ack = WriteI2C(0x00);	//address pointer register
	ack = WriteI2C(0x10);	//CRA
	ack = WriteI2C(0x20);	//CRB
	ack = WriteI2C(0x00);	//Status register
	StopI2C();
}



void get_value()
{
	unsigned char array[6];
	IdleI2C();
	StartI2C();
	WriteI2C(write_sensor);
	WriteI2C(0x03);			//address pointer to 0x03
	StopI2C();
	
	IdleI2C();
	StartI2C();
	WriteI2C(read_sensor);
	SSPCON2bits.RCEN=1;
	getsI2C(array,'6');		//reading 6 bytes/registers from 0x03-0x08
	StopI2C();
	SSPCON2bits.RCEN=0;
	x = (int)(array[0] * 256) | (int)array[1];
	z = (int)(array[2] * 256) | (int)array[3];
	y = (int)(array[4] * 256) | (int)array[5];
	x= ~x + 1;
	y= ~y + 1;
	z= ~z + 1;
	heading = atan2(y, x)*180.0/pi +180.0;
}
void delay()
{
	T0CON=0b00000111;
	TMR0H=0xFD;
	TMR0L=0x70;
	T0CONbits.TMR0ON=1;
	while(!INTCONbits.TMR0IF);
	INTCONbits.TMR0IF=0;
	T0CONbits.TMR0ON=0;
}