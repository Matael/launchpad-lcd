#
# Makefile
# matael, 2013-04-26 23:22
#

# compilation
CC=msp430-gcc
CC_OPTS= -Os
MMCU_TYPE=msp430g2553

CUSTOM_LIB_DIR=lib/

# programming
MSPDBG=mspdebug
MSPDBG_LK=rf2500

all: lcd
	$(CC) $(CC_OPTS) -mmcu=$(MMCU_TYPE) -L$(CUSTOM_LIB_DIR) -c main.c
	$(CC) -mmcu=$(MMCU_TYPE) -o main.elf *.o

lcd:
	$(CC) $(CC_OPTS) -mmcu=$(MMCU_TYPE) -c lib/lcd.c

upload:
	$(MSPDBG) $(MSPDBG_LK) "prog main.elf"

