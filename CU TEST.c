#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define R0 PORTC0 // OUTPUT RAM OUT
#define MI PORTC1 // OUTPUT MAR IN 
#define HLT PORTC2 // OUTPUT HALT
#define PCO PORTC3 // OUTPUT COUNTER OUT
#define IRO PORTC4 // OUTPUT INSTRUCTION REGISTER OUT
#define IRI PORTC5 // OUPUT INSTRUCTION RESGISTER IN
#define PCD PORTC6 // OUTPUT COUNTER DISABLE
#define PCI PORTC7 // OUTPUT COUNTER IN
#define RAI PORTB0 // OUTPUT REGISTER A ENABLE
#define RBI PORTB1 // OUTPUT REGISTER B ENABLE
#define AO PORTB2 // OUTPUT ALU OUT
#define SS PORTB3 // OUTPUT SUBSOM
#define S0 PORTB4 // INPUT STEP BIT0
#define S1 PORTB5 // INPUT STEP BIT1
#define S2 PORTB6 // INPUT STEP BIT2
#define FC PORTB7 // INPUT CARRY //
#define I0 PORTD0 // INPUT INSTRUCTION BIT0 //
#define I1 PORTD1 // INPUT INSTRUCTION BIT1 //
#define I2 PORTD2 // INPUT INSTRUCTION BIT2 //
#define I3 PORTD3 // INPUT INSTRUCTION BIT3 //
#define FZ PORTA0 // INPUT ZERO
#define FN PORTA1 // INPUT NEGATIVE

#define FETCH0 0b01001010
#define FETCH1 0b01100001
int ss = 0;
int value=0;
void fetch(int step);
void setup();
int read_inst();
void read_step();
void write(int step, int state);

int main() {
	setup();
	while(1) {
		read_step();
		if (value > 1) {
			write(value, read_inst());	
		}
	}
}
void setup() {
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF; // OUTPUTS
	PORTC = 0x44; // OUTPUTS
	DDRB = 0x0F; // 
	PORTB = 0xF0; // INPUTS PULL UP RESISTORS
	DDRD = 0x00; // INPUTS
	PORTD = 0x0F; //
}
int read_inst() {	// read INSTRUCTION
	if ((PIND & 0b00000111) == 0b00000111) { // JC			// JUMP IF CARRY
		return 7;
	} else if ((PIND & 0b000001001) == 0b00001001) { // SUI	
		return 9;
	} else if ((PIND & 0b00000110) == 0b00000110) { // HLT		// HLT
		return 6;
	} else if ((PIND & 0b00000101) == 0b00000101) { // SUB	
		return 5;
	} else if ((PIND & 0b00001010) == 0b00001010){  // JZ		// JUMP IF ZERO
		return 10;
	} else if ((PIND & 0b00001100) == 0b00001100){  // JN		// JUMP IF NEGATIVE
		return 12;
	} else if ((PIND & 0b00000011) == 0b00000011) { // JMP		// JMP
		return 3;
	} else if ((PIND & 0b00000001) == 0b00000001) { // LDA		// LOAD TO A
		return 1;
	} else if ((PIND & 0b00000010) == 0b00000010) { // ADD		// ADD TO B
		return 2;
	} else if ((PIND & 0b00000100) == 0b00000100) { // LDI	
		return 4;
	} else if ((PIND & 0b00001000) == 0b00001000) { // STB	
		return 8;
	} else return 0;
}
void read_step() { // read Step
	if ((PINB & (1<<S0)) && (PINB & (1<<S2))){ // 101
		value = 5;
	} else if ((PINB & (1<<S0)) && (PINB & (1<<S1))) { // 011
		value = 3;
	} else if ((PINB & (1<<S0))) { // 001
		fetch(1);
		value = 1;
	} else if ((PINB & (1<<S1))) { // 010
		value = 2;
	} else if ((PINB & (1<<S2))) { // 100
		value = 4;
	} else { 
		fetch(0); // 000
		value = 0;
	}
}
void write (int step, int state) {
	switch (step) {
		case 2:
			switch (state) {
				case 1:
					PORTC = 0b00010010; // PCE, IRO, MI	
					PORTB = 0x00;
					break;
				case 2:
					PORTC = 0b00010010;
					PORTB = 0x00; 
					ss = 0;
					break;
				case 3:
					PORTC = 0b11010000;
					break;
				case 4:
					PORTC = 0b00010000;
					PORTB = (1<<RAI);
					break;
				case 5:
					PORTC = 0b00010010;
					PORTB = 0x00;
					break;
				case 6:
						PORTC = 0x44;
						_delay_ms(100);
						ss=0;
						break;
				case 7:
					if (PINB & (1<<FC)) {
						PORTC = 0b11010000;
						PORTB = 0x00;
					} else {
						PORTC = 0x00;
						PORTB = 0x00;
					}
					break;
				case 8:
					PORTC = 0x00;
					PORTB |= (1<<RBI) | (1<<AO);
					_delay_us(650);
					PORTB = 0x00;
					break;
				case 9:
					PORTC = 0x00;
					PORTB |= (1<<RBI) | (1<<AO);
					_delay_us(650);
					PORTB = 0x00;
					break;
				case 10:
					if (PINA & (1<<FZ)) {
						PORTC = 0b11010000;
						PORTB = 0x00;
						} else {
						PORTC = 0x00;
						PORTB = 0x00;
					}
					break;
				case 12:
					if (PINA & (1<<FN)) {
						PORTC = 0b11010000;
						} else {
						PORTC = 0x00;
					}
					break;
				default:
					break;	
			}
			break;
			case 3:
				switch(state) {
					case 1:
						PORTC = 0b01000001; // RO
						PORTB = (1<<RAI); // RAI
						break;
					case 2:
						PORTC = 0b01000001;
						PORTB = (1<<RBI);
						break;
					case 3:
						PORTC = 0b01001010;
						break;
					case 4:
						PORTB &= ~((1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3));
						PORTC = 0b01000000;
						break;
					case 5:
						PORTC = 0b01000001;
						PORTB |= (1<<RBI) | (1<<SS);
						ss = 1;
						break;
					case 7:
						PORTC = 0x40;
						break;
					case 8:
						PORTC = 0x40;
						break;
					case 9:
						PORTC = 0x40;
						PORTB = (1<<SS);
						ss=1;
						break;
					case 10:
						PORTC = 0x40;
						break;
					case 12:
						PORTC = 0x40;
						break;
					default:
						break;
				}
			default:
				break;
		}
}
void fetch(int step) {
	if (ss == 0) {
		PORTB &= ~((1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3));
	} else {
		PORTB &= ~((1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2));
	}
	if (step == 0) {
		PORTC = FETCH0; // PCO, MI
	} else {
		PORTC = FETCH1; // RO, IRI
	}
}
