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
#define FN PORTA1 // INPUT NEGATIVE

#define N_Outputs 14
int answersA[N_Outputs] = {
	74, 97, 208, 74, 16, 64, 18, 65, 68, 68, 208, 64, 0, 64
};
int answersB[N_Outputs] = {
	0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0
};
int stepAfterFetch = 0;
int ss = 0;
int value = 0;
void setup();
void read_inst();
void read_step();
void reset_pins();

int main() {
	unsigned int valorSS = 0;
	setup();
	while(1) {
		read_step();
		(value != -1 & value > 1 & stepAfterFetch == 1) && 
		(read_inst(),
		(PORTC = answersA[value]),
		(valorSS = (PORTB >> 3) & 1), reset_pins(),
		(PORTB |= answersB[value]),
		(PORTB |= (PORTB & ~(1 << PINB3)) | ((valorSS & !((value == 4) || (value == 5))) || (!valorSS & ((value == 6) || (value == 7)))) << PINB3)
		);
		(value != -1 & value > 1 & stepAfterFetch == 0) &&
		(read_inst(),
		(PORTC = answersA[value]),
		(valorSS = (PORTB >> 3) & 1),
		(PORTB |= answersB[value]),
		(PORTB |= (PORTB & ~(1 << PINB3)) | ((valorSS & !((value == 4) || (value == 5))) || (!valorSS & ((value == 6) || (value == 7)))) << PINB3)
		);
		(value != -1 & value <= 1) &&
		(reset_pins(),
		(PORTC = answersA[value]),
		(valorSS = (PORTB >> 3) & 1),
		(PORTB |= answersB[value]),
		(PORTB |= (PORTB & ~(1 << PINB3)) | ((valorSS & !((value == 4) || (value == 5))) || (!valorSS & ((value == 6) || (value == 7)))) << PINB3)
		);
	}
}
void setup() {
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF; // OUTPUTS
	PORTC = 0x00; // OUTPUTS
	DDRB = 0x0F; //
	PORTB = 0xF0; // INPUTS PULL UP RESISTORS
	DDRD = 0x00; // INPUTS
	PORTD = 0x0F;
}
void read_inst(){ // read INSTRUCTION
	if ((PIND & 0b00000110) == 0b00000110) { // HLT // HLT
		value = 8 + stepAfterFetch;
		} else if ((PIND & 0b00000101) == 0b00000101) { // SUB
		value = 6 + stepAfterFetch;
		ss=1;
		} else if ((PIND & 0b00001100) == 0b00001100){  // JN
		if (PINA & (1<<FN)) {
			value = 10 + stepAfterFetch;
			} else {
			value = 12 + stepAfterFetch;
		}
		} else if ((PIND & 0b00000011) == 0b00000011) { // JMP
		value = 2 + stepAfterFetch;
		} else if ((PIND & 0b00000100) == 0b00000100) { // LDI
		value = 4 + stepAfterFetch;
		ss=0;
	}
}
void read_step() { // read Step
	if ((PINB & (1<<S0)) && (PINB & (1<<S2))){ // 101 garbage
		value = -1;
		} else if ((PINB & (1<<S0)) && (PINB & (1<<S1))) { // 011
		stepAfterFetch = 1;
		value = 3;
		} else if ((PINB & (1<<S0))) { // 001
		value = 1;
		} else if ((PINB & (1<<S1))) { // 010
		stepAfterFetch = 0;
		value = 2;
		} else if ((PINB & (1<<S2))) { // 100 garbage
		value = -1;
		} else {
		value = 0;
	}
}
void reset_pins() {
	PORTB &= ~(1<<RAI) & ~(1<<RBI);
}
