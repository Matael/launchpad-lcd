/*
 * lcd.h
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

#ifndef __lcd_h__
#define __lcd_h__

// Commands
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define ADDR_INC 0x06
#define ADDR_DEC 0x04

#define DISPLAY_CTRL 0x08 // base
#define DISPLAY_CTRL_D 0x04 // display enabled
#define DISPLAY_CTRL_C 0x02 // cursor visible
#define DISPLAY_CTRL_B 0x01 // cursor blinking

#define SHIFT_CTRL 0x10
#define SHIFT_DISP 0x08 // display shift -- if not, shift cursor
#define SHIFT_RIGHT 0x04 // shift right -- if not, shift left

#define FCT_SET 0x20
#define CTRL_4BITS 0x00
#define CTRL_8BITS 0x10
#define CTRL_1LINE 0x00
#define CTRL_2LINES 0x08
#define CTRL_MAT5x11 0x04
#define CTRL_MAT5x8 0x00

#define SET_CGRAM_ADDR 0x40
#define SET_DDRAM_ADDR 0x80

typedef struct {
    // pining
    unsigned char rs, e, d4, d5, d6, d7;
} LCD_CTRLR;

void LCD_init(
        LCD_CTRLR lcd,
        unsigned char function_flags = CTRL_2LINES,
        unsigned char display_flags = DISPLAY_CTRL_D
        );
void _e_toggle();
void _LCD_send(LCD_CTRLR lcd, unsigned char command);
void _LCD_writeChar(LCD_CTRLR lcd, char c);
void LCD_clear(LCD_CTRLR lcd);
void LCD_print(LCD_CTRLR lcd, char *string);
#endif /* !__lcd_h__ */

