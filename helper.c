#include "helper.h"
#include "led.h"
void changelight(char* buffer){
	
	if(buffer[0] == '!' || buffer[0] == '?'){
		if(buffer[2] == '0'){
			turnOffLED(string[1]);			
		}
		else if(buffer[2] == 'f'){
			turnOnLED(string[1]);			
		}		
	}	
}
void shortenstring(*char* buffer, char* databuffer){
	
	
	
	
	
	
}
