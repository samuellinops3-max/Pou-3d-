ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif
include $(PSL1GHT)/ppu_rules
TITLE:=POU_PS3_BR
APPID:=POUBR001
CONTENTID:=UP0001-POUBR001_00-POUBR00000000001
TARGET:=$(APPID)
CFILES:=main.c
OFILES:=$(CFILES:.c=.o)
INCLUDE:=-I$(CURDIR) -I$(PSL1GHT)/ppu/include -I$(PORTLIBS)/include
LIBDIRS:=-L$(PSL1GHT)/ppu/lib -L$(PORTLIBS)/lib
LIBS:=-ltiny3d -lrsx -lgcm_sys -lsysutil -lio -lsysmodule -lm
CFLAGS:=-O2 -Wall -mcpu=cell $(INCLUDE)
LDFLAGS:=$(LIBDIRS) $(LIBS)
SFOXML:=sfo.xml
ICON0:=ICON0.PNG
all:$(TARGET).pkg
$(TARGET).pkg:$(TARGET).self $(SFOXML) $(ICON0)
	$(PKG) --contentid $(CONTENTID) $(TARGET).pkg $(SFOXML) $(ICON0) $(TARGET).self
$(TARGET).self:$(TARGET).elf
	$(SELF) $< $@
$(TARGET).elf:$(OFILES)
	$(CC) $^ $(LDFLAGS) -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OFILES) $(TARGET).elf $(TARGET).self $(TARGET).pkg