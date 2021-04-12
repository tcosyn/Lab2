/*	Author: tco002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
<<<<<<< HEAD
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0X00;
    /* Insert your solution below */
    	unsigned char tmpA0 = 0x00;
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA2 = 0x00;
        unsigned char tmpA3 = 0x00;
	unsigned char count = 0x00;
    	unsigned char full = 0x80;
	while(1){
		count = 0x00;
		tmpA0 = PINA & 0x01;
		tmpA1 = (PINA & 0x02) >> 1;
		tmpA2 = (PINA & 0x04) >> 2;
		tmpA3 = (PINA & 0x08) >> 3;
		
		count = (tmpA0 + tmpA1 + tmpA2 + tmpA3);
		if(tmpA0 && tmpA1 && tmpA2 && tmpA3){
			PORTC = count + full;
		} else {
			PORTC = count;
		}
	}
	return 0;
=======
    
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
				// Initialize output on PORTB to 0x00
unsigned char temp_input = 0x00;
while(1) {
	temp_input = PINA;
	PORTB = temp_input;	// Writes port B's 8 pins with the values
				// on port A's 8 pins
}
return 1;
>>>>>>> 0f495bd59762d7e875f8596460628c7ad610582c
}
