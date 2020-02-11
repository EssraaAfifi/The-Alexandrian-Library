#include <kipr/botball.h>
#include "Alexandria.h"

//The Definition
//Moving Wheels
void Vroom(int rspeed, int lspeed, int timer)
{//Begin Void
	mav(0, rspeed); //FUN FACT: MAV stand for 'Move at Velocity'
	mav(3, lspeed);
	msleep(timer);
}//End Void

//Follow Blackline
void Raven(int counter, int black)
{//Begin Void
	cmpc(0); //clears the motor position counter
	while (gmpc(0) < counter)
	{//Begin While
		while (analog(1)>black)
		{//Begin While 2
			Vroom(500,1000,100);//turn left if black
			printf("right\n");
		}//End While 2
		while(analog(1)<black)
		{//start while 3
			Vroom(1000,500,100);
			printf("left\n");
		}//end while 3
	}//End While
}//End Void

//Servo Movement
void Slapper(int servonum, int angle)
{//Begin
	enable_servos();
	set_servo_position(servonum, angle);
	disable_servos();
}//End

//Lower the Line
void Im(int count, int speed)
{//Begin
	cmpc(1);
	while(gmpc(1)<count)
	{//Start while
		motor(1,speed);
		msleep(500);
	}//End While
}//End

//Pull the line
void Imnot(int count2, int speed2)
{//Begin
	cmpc(1);
	while(gmpc(1)>count2)
	{//Start while
		motor(1,speed2);
		msleep(500);
	}//End While
}//End
