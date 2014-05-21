#include "helper.h"
#include "led.h"
void changelight(char buffer[4]){
	
	if(buffer[0] == '!' || buffer[0] == '?'){
		if(buffer[2] == '0'){
			turnOffLED(buffer[1]);			
		}
		else if(buffer[2] == 'f'){
			turnOnLED(buffer[1]);			
		}		
	}	
}
void shortenstring(char** buffer, char* DataBuffer){
	if(DataBuffer[0] == 0 && DataBuffer[1] == 0 && DataBuffer[2] == 0 && DataBuffer[3] == 0 && DataBuffer[4] == 0) 
	*buffer[0] = '?';// '?'
	if(DataBuffer[0] == 0 && DataBuffer[1] == 0 && DataBuffer[2] == 0 && DataBuffer[3] == 0 && DataBuffer[4] == 1) 
	*buffer[0] = '!';// '!'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 0 && DataBuffer[7] == 0 && DataBuffer[3] == 1 && DataBuffer[5] == 0) 
	*buffer[1] = '0';
	if(DataBuffer[5] == 0 && DataBuffer[6] == 0 && DataBuffer[7] == 0 && DataBuffer[3] == 1 && DataBuffer[5] == 1) 
	*buffer[1] = '1';
	if(DataBuffer[5] == 0 && DataBuffer[6] == 0 && DataBuffer[7] == 0 && DataBuffer[8] == 0 && DataBuffer[9] == 0) 
	*buffer[1] = '2';// '2'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 0 && DataBuffer[7] == 1 && DataBuffer[8] == 0 && DataBuffer[9] == 1) 
	*buffer[1] = '3';// '3'7
	if(DataBuffer[5] == 0 && DataBuffer[6] == 0 && DataBuffer[7] == 1 && DataBuffer[8] == 1 && DataBuffer[9] == 0) 
	*buffer[1] = '4';// '4'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 0 && DataBuffer[7] == 1 && DataBuffer[8] == 1 && DataBuffer[9] == 1) 
	*buffer[1] = '5';// '5'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 1 && DataBuffer[8] == 0 && DataBuffer[9] == 0) 
	*buffer[1] = '6';// '6'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 0 && DataBuffer[8] == 0 && DataBuffer[9] == 1) 
	*buffer[1] = '7';
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 0 && DataBuffer[8] == 1 && DataBuffer[9] == 0) 
	*buffer[1] = '8';// '8'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 0 && DataBuffer[8] == 1 && DataBuffer[9] == 1) 
	*buffer[1] = '9';// '9'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 0 && DataBuffer[8] == 0 && DataBuffer[9] == 0) 
	*buffer[1] = 'a';// 'a'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 1 && DataBuffer[8] == 0 && DataBuffer[9] == 1) 
	*buffer[1] = 'b';// 'b'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 1 && DataBuffer[8] == 1 && DataBuffer[9] == 0) 
	*buffer[1] = 'c';// 'c'
	if(DataBuffer[5] == 0 && DataBuffer[6] == 1 && DataBuffer[7] == 1 && DataBuffer[8] == 1 && DataBuffer[9] == 1) 
	*buffer[1] = 'd';// 'd'
	if(DataBuffer[5] == 1 && DataBuffer[6] == 0 && DataBuffer[7] == 1 && DataBuffer[8] == 0 && DataBuffer[9] == 0) 
	*buffer[1] = 'e';// 'e'
	if(DataBuffer[5] == 1 && DataBuffer[6] == 0 && DataBuffer[7] == 0 && DataBuffer[8] == 0 && DataBuffer[9] == 1) 
	*buffer[1] = 'f';// 'f'
	if(DataBuffer[10] == 0 && DataBuffer[11] == 0 && DataBuffer[12] == 0 && DataBuffer[13] == 1 && DataBuffer[14] == 0) 
	*buffer[2] = 'f'; // on
	if(DataBuffer[10] == 1 && DataBuffer[11] == 0 && DataBuffer[12] == 0 && DataBuffer[13] == 0 && DataBuffer[14] == 1) 
	*buffer[2] = '0';// off
	if(DataBuffer[15] == 1 && DataBuffer[16] == 0 && DataBuffer[17] == 0 && DataBuffer[18] == 1 && DataBuffer[19] == 0) 
	*buffer[3] = '\r';// '\r'
	*buffer[4] = '\0';
}
