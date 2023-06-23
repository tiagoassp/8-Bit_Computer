#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/io.h>

void setup();
int write(int n);
int read();

typedef unsigned char BYTE;
BYTE data[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0X82, 0xF8, 0x80, 0x90};

int main () {
	setup();
	while (1) {
	}
}
ISR(TIMER0_COMPA_vect){
	write(read());
}
void setup () {
	DDRB = 0; // INPUTS
	DDRD = 255; // OUTPUTS
	DDRC = 255; // OUTPUTS
	PORTC = 255; // PULL UP RESISTORS
	PORTD = 255;
	PORTB = 255; // PULL UP RESISTORS
	OCR0A = 0; // CLK = 500KHz
	TIMSK0 = (1 << OCIE0A);
	TCCR0A = (1 << WGM01); // CTC							Fi/o / (2 * PRESCAread * (1 + OCR0A))
	TCCR0B = (1 << CS01); //PRESCAread 8
	sei();
}
int write (int n) {
	PORTC = data[n/1000];
	PORTD |= (1 << PORTD1);
	_delay_ms(0.5);
	PORTD &= ~(1<<PORTD1);
	
	PORTC = data[(n/100)%10];
	PORTD |= (1 << PORTD2);
	_delay_ms(0.5);
	PORTD &= ~(1<<PORTD2);
	
	PORTC = data[(n/10)%10];
	PORTD |= (1 << PORTD3);
	_delay_ms(0.5);
	PORTD &= ~(1<<PORTD3);
	
	PORTC = data[n%10]; // Right most digit
	PORTD |= (1 << PORTD4);
	_delay_ms(0.5);
	PORTD &= ~(1<<PORTD4);
}
int read() {
	int sum = 0;
	if((PINB & (1 << PINB0))){
		sum = sum + 1;
	}
	if((PINB & (1 << PINB1))){
		sum = sum + 2;
	}
	if((PINB & (1 << PINB2))){
		sum = sum + 4;
	}
	if((PINB & (1 << PINB3))){
		sum = sum + 8;
	}
	if((PINB & (1 << PINB4))){
		sum = sum + 16;
	}
	if((PINB & (1 << PINB5))){
		sum = sum + 32;
	}
	if((PINB & (1 << PINB6))){
		sum = sum + 64;
	}
	if((PINB & (1 << PINB7))){
		sum = sum + 128;
	}
	return sum;
}
