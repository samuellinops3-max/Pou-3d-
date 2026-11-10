TARGET = PouPS3
OBJS = src/main.o

CFLAGS = -O3 -Wall
LIBS = -lm

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(OBJS) $(TARGET).elf