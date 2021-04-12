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
	DDRB = 0x00; PORTB = 0XFF;
  DDRC = 0x00; PORTC = 0XFF;
  DDRD = 0xFF; PORTD = 0X00;
    /* Insert your solution below */
	unsigned char totalWeight = 0x00;
  unsigned char out0 = 0x00;
  unsigned char out1 = 0x00;
  unsigned char out2to7 = 0x00;
  unsigned char returnMe = 0x00;
  unsigned char outMax0 = 0x8C; //140 kg
  unsigned char outMax1 = 0x50; // 80kg
	while(1){
		totalWeight = PINA +  PINB + PINC;
    if(totalWeight > outMax0){
      out0 = 0x01;
    } 
    if((PINA - PINC) > outMax1){
      out1 = 0x02;    
    }
    out2to7 = (totalWeight & 0xF0) >> 2;
    returnMe = out2to7 + out1 + out0;
    PORTD = returnMe;
    }
	return 0;
}
