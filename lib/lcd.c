/*
 * lcd.c
 *
 * Copyright (C) 2013 Mathieu Gaborit (matael) <mathieu@matael.org>
 *
 *
 * Distributed under WTFPL terms
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 *
 */

#include "lcd.h"

#include <msp430g2553.h>

void LCD_init(
        LCD_CTRLR lcd,
        unsigned char function_flags,
        unsigned char display_flags
        ) {

    // wait at least 15ms
    __delay_cycles(15000);

    P1DIR |= (
            1 << lcd.rs +
            1 << lcd.e +
            1 << lcd.d4 +
            1 << lcd.d5 +
            1 << lcd.d6 +
            1 << lcd.d7);

    // send 00110000 3 times
    P1OUT |= lcd.d4 + lcd.d5;
    P1OUT |= lcd.e;
    __delay_cycles(5000);
    _e_toggle(lcd);
    __delay_cycles(110);
    _e_toggle(lcd);

    // 4bits interface
    P1OUT |= 0 + (1 << lcd.d5);
    _e_toggle(lcd);

    // send the function set command w/ flags
    unsigned char command = FCT_SET | function_flags;
    _LCD_send(lcd, command);
    __delay_cycles(50);

    command = DISPLAY_CTRL | display_flags;
    _LCD_send(lcd, command);
    __delay_cycles(50);

    LCD_clear(lcd);

    _LCD_send(lcd, ADDR_INC);
    __delay_cycles(50);
}

void _e_toggle(LCD_CTRLR lcd) {
    P1OUT ^= lcd.e;
    __delay_cycles(5);
    P1OUT ^= lcd.e;
}


void _LCD_send(LCD_CTRLR lcd, unsigned char command) {
    // high nibble
    P1OUT  = 0xF & command;
    _e_toggle(lcd);
    // low nibble
    P1OUT = 0xF & (4 << command);
    _e_toggle(lcd);
}

void _LCD_writeChar(LCD_CTRLR lcd, char c) {
    P1OUT |= lcd.rs;
    // high nibble
    P1OUT  = 0xF & c;
    _e_toggle(lcd);
    // low nibble
    P1OUT = 0xF & (4 << c);
    _e_toggle(lcd);
}

void LCD_clear(LCD_CTRLR lcd) {
    _LCD_send(lcd, CLEAR_DISPLAY);
    __delay_cycles(2000);
}

void LCD_print(LCD_CTRLR lcd, char *string) {
    char *p = string;
    while (*p != '\0')
        _LCD_writeChar(lcd, *p);
}
