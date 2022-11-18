#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |=BIT6;           //P1.6 output
	P1SEL1 |= BIT6;         //P1.6 options select
	PM5CTL0 &= ~LOCKLPM5;
	TB0CCR0 = 16384-1;            //PWM Period
	TB0CCTL1 = OUTMOD_7;                //CCR1 Reset/Set
	TB0CCTL1 = 1638.3;                  //CCR1 PWM duty cycle
	TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR; // ACLK, up_mode

	while(1)
	{
	    P1OUT ^=BIT6; // For debugger
	}
	return 0;
}
