#include <avr/io.h>
#include "X10recieve.h"

void initatmel(void){
	DDRD = (0<<PD7);
	DDRB = (0<<PB2);
		
}