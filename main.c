/*
 * X10Reciever.c
 *
 * Created: 21.05.2014 18:30:49
 *  Author: betabot
 */ 

#include "main.h"
#include "X10recieve.h"
#include "led.h"
#include "helper.h"
#include <avr/io.h>
//move to main.h
int tmp;
char DataBuffer[21] = {'\0'};
volatile uint8_t flag = 0;
int ready = 0;
int sendcounter = 0;

ISR(INT2_vect)
{
	flag++;
	if(ready == 1)
	{
		if(flag % 2 == 1)  // foerste cycel
		{
			tmp = PIND0;			
		}

		if(flag % 2 == 0) // anden cycel
		{
			if(tmp == 1 && PIND0 == 0){
				DataBuffer[sendcounter] = '1';
			}
			else if(tmp == 0 && PIND0 == 1){
				DataBuffer[sendcounter] = '0';
			}
			else{
				//ERROR
			}
			sendcounter++;
		}
		
		if (sendcounter == 20)
		{
			char Buffer[4] = {/0};
			shortenstring(&Buffer, DataBuffer);
			changelight(Buffer);
			sendcounter = 0;
			SendString("done sending stuff");
			ready = 0;
		}
	}
}




int main(void)
{
	void initatmel();
	void initLEDport();
	
	
    while(1)
    {
        
    }
}