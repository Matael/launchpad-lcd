/*
 * main.c
 *
 * Copyright (C) 2013 Mathieu Gaborit (matael) <mathieu@matael.org>
 *
 *
 * Distributed under WTFPL terms
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004 *
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

#include <msp430g2553.h>

#include "lib/lcd.h"


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    LCD_CTRLR lcd;
    lcd.rs = BIT7;
    lcd.e = BIT6;
    lcd.d4 = BIT0;
    lcd.d5 = BIT1;
    lcd.d6 = BIT2;
    lcd.d7 = BIT3;

    LCD_init(
            lcd,
            CTRL_2LINES,
            DISPLAY_CTRL_D
            );
    LCD_print(lcd, "Hello, world!");

}

