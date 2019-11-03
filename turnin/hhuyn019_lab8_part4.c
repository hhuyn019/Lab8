/*	Author: hhuyn019
 *  Partner(s) Name: Badr Asi
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

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

unsigned short ADC_result = 0x00;
unsigned short MAX = 0x0C7;
unsigned short temp = 0x00;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	//DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	temp = (MAX / 8);
	ADC_init();
    while (1) {
	ADC_result = ADC;
	if (ADC_result <= temp) {
		PORTC = 0x01;
	} else if (ADC_result <= (2*temp)) {
		PORTC = 0x03;
	} else if (ADC_result <= (3*temp)) {
		PORTC = 0x07;
	} else if (ADC_result <= (4*temp)) {
		PORTC = 0x0F;
	} else if (ADC_result <= (5*temp)) {
		PORTC = 0x1F;
	} else if (ADC_result <= (6*temp)) {
		PORTC = 0x3F;
	} else if (ADC_result <= (7*temp)) {
		PORTC = 0x7F;
	} else {
		PORTC = 0xFF;
	}
    }
}
