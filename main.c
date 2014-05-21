/*
 * X10Reciever.c
 *
 * Created: 21.05.2014 18:30:49
 *  Author: betabot
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 3686400UL
#include <util/delay.h>
#include "main.h"
#include "X10recieve.h"
#include "led.h"
#include "helper.h"
#include "uart_int.h"
#include "uart_test.h"
int readycheck = 0;
char tmp2;

ISR(INT2_vect)
{
	_delay_ms(1);
	if(PIND & (1<<PD7)){
		tmp2 = '1';
	}
	else{
		tmp2 = '0';
	}

	SendChar(tmp2);
		if(readycheck == 0 && (PIND & (1<<PD7))){
		readycheck = 1;
		//SendString("ready 1");
	}
	if(readycheck == 1 && (PIND & (1<<PD7)))
	{
		readycheck = 2;
		//SendString("ready 2");
	}
	if(readycheck == 1 && !(PIND & (1<<PD7))){
		readycheck = 0;
		//SendString("ready fail");
	}
	if(readycheck == 2)
	{
		SendString("and go");
	flag++;	
		if(flag % 2 == 1)  // foerste cycel
		{
			tmp = (PIND & (1<<PD7));			
		}

		if(flag % 2 == 0) // anden cycel
		{
			if(tmp == 1 && !(PIND & (1<<PD7))){
				DataBuffer[sendcounter] = '1';
			}
			else if(tmp == 0 && (PIND & (1<<PD7))){
				DataBuffer[sendcounter] = '0';
			}
			else{
				//ERROR
			}
			sendcounter++;
		}
		
		if (sendcounter == 20)
		{
			DataBuffer[21] = '\0';
			char Buffer[4] = {'\0'};
			shortenstring(&Buffer, DataBuffer);
			changelight(Buffer);
			sendcounter = 0;
			SendString("done sending stuff");
			flag = 0;
			readycheck = 0;
		}
	}
}




int main(void)
{
	//void initatmel();
	DDRD |= (0<<PD7);
	DDRB = 0x00;
	MCUCSR |= (1 << ISC2);
	GICR |=(1 << INT2);
	void initLEDport();
	InitUART(9600, 8, 1);
	SendString("init done on reciever");
	sei();
	
	
    while(1)
    {
        
    }
}