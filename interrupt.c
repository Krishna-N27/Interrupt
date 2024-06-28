
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000
unsigned char val;
void main()
{
    TRISB=0x0F;  //initalizing switch configuration
    OPTION_REG=0x7F;  //enable internal pull up
    TRISC=0x00;  //initalizing TRISC configuration
    TRISD=0x00;  //initalizing TRISD configuration
    PORTB=0x00;  //initalizing PORTB configuration
    PORTC=0x00;   //initalizing PORTC configuration
    PORTD=0x00;    //initalizing PORTD configuration
    INTCON=0x90;   //initalizing INTCON for GIE AND INTE
    
    while(1)
    {
        PORTD=~PORTD;   //enable PORTD blink alternating
        __delay_ms(200);
    }
}
void __interrupt() ISR()   //initialzing INTERRUPT
{
    if(INTCON & 0x02)  //enabling flag on INTF
    {
	val=PORTB;  // enable switch for PORTB
	PORTC=~PORTC;
	__delay_ms(5000);
    
	INTCON &=0xFD;  //Turn off the flag
    __delay_ms(5000);
    
    }
}