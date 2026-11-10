# Makefile básico para PSL1GHT (PS3)
target := pou_jogo

all: $(target).elf

$(target).elf: main.c
	ppu-gcc -O3 main.c -o $(target).elf -llv2 -lio -lgfx -lm

clean:
	rm -f $(target).elf
