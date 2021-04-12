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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0X00;
    /* Insert your solution below */
    	unsigned char tmpA0 = 0;
	unsigned char tmpA1 = 0;
	unsigned char tmpA2 = 0;
        unsigned char tmpA3 = 0;
	unsigned char count = 0x00;
	unsigned char max = 0x04;
    	while (1) {
		count = 0x00;
		tmpA0 = PINA & 0x01;
		tmpA1 = (PINA & 0x02) >> 1;
		tmpA2 = (PINA & 0x04) >> 2;
		tmpA3 = (PINA & 0x08) >> 3;
		
		count = (tmpA0 + tmpA1 + tmpA2 + tmpA3);
		PORTC = max - count;
	}
	return 0;
}
