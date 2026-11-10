# Makefile para PS3 (PSL1GHT)
TARGET = pou_jogo
OBJS = main.o
CFLAGS = -O3 -Wall -I$(PS3DEV)/ppu/include
LDFLAGS = -L$(PS3DEV)/ppu/lib

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	ppu-gcc $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET).elf -llv2 -lio -lm

%.o: %.c
	ppu-gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET).elf $(OBJS)
