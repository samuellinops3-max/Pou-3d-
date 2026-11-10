all:
	@echo "A compilar o Pou para PS3..."
	ppu-gcc -O3 main.c -o pou_jogo.elf || gcc -O3 main.c -o pou_jogo.elf

clean:
	rm -f pou_jogo.elf
