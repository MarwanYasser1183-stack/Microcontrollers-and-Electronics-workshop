/*
 * LED_BLINK.c
 *
 * Created: 5/5/2026 3:02:11 PM
 * Author : VICTUS
 */ 

#define F_CPU 1000000UL  // ← MUST be first line before any includes

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x01;

    while (1)
    {
        PORTB = 0x01;
        _delay_ms(1000);
        PORTB = 0x00;
        _delay_ms(1000);
    }
}
