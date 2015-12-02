#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>

#include "main.h"
#include "uart.h"

int
main (void)
{
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    DDRB |= _BV(DDB0); 
    
    while(1) 
    {
	puts("Hello World!");
        PORTB ^= _BV(PB0);
        _delay_ms(1000);
    }
}
