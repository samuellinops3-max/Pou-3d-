# Makefile Pou PS3 BR
ifeq ($(strip $(PSL1GHT)),)
$(error "PSL1GHT nao definido. Rode no docker ps3dev/ps3toolchain")
endif

include $(PSL1GHT)/ppu_rules

TITLE		:= POU PS3 BR
APPID		:= POUBR001
CONTENTID	:= UP0001-POUBR001_00-POUBR00000000001

TARGET		:= $(APPID)
BUILD		:= build
SOURCES		:= .
INCLUDES	:= .

CFILES		:= $(foreach dir,$(SOURCES), $(notdir $(wildcard $(dir)/*.c)))
OFILES		:= $(CFILES:.c=.o)

INCLUDE		:= $(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
				-I$(PSL1GHT)/ppu/include \
				-I$(PORTLIBS)/include

LIBDIRS		:= -L$(PSL1GHT)/ppu/lib -L$(PORTLIBS)/lib
LIBS		:= -ltiny3d -lrsx -lgcm_sys -lsysutil -lio -lsysmodule -lm

CFLAGS		:= -O2 -Wall -mcpu=cell $(INCLUDE)
LDFLAGS		:= $(LIBDIRS) $(LIBS)

all: $(TARGET).elf $(TARGET).self

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OFILES)
	$(CC) $^ $(LDFLAGS) -o $@

$(TARGET).self: $(TARGET).elf
	$(SELF) $< $@

clean:
	rm -f $(OFILES) $(TARGET).elf $(TARGET).self

pkg: $(TARGET).self
	$(SFO) --title "$(TITLE)" --appid "$(APPID)" PARAM.SFO
	$(PKG) --contentid $(CONTENTID) $(APPID).pkg PARAM.SFO $(TARGET).self