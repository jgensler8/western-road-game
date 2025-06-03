# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
	GBDK_HOME = ../../
endif

LCC_FLAGS_HUGEDRIVER = -Wl-lhUGEDriver.lib
LCC_FLAGS_GBC = -Wl-yt0x1B -autobank $(LCC_FLAGS_HUGEDRIVER)
LCCFLAGS = -Wl-j -Wm-yoA -Wm-ya4 -Wb-ext=.rel -Wb-v $(LCC_FLAGS_GBC)
LCC = $(GBDK_HOME)bin/lcc.exe
PNG2ASSET = $(GBDK_HOME)bin/png2asset.exe
ROMUSAGE = $(GBDK_HOME)bin/romusage.exe

# GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif

# CFLAGS	=

BINS	= compo25.gbc

all:	$(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ -p\/mkdir\/ | grep -v make >> compile.bat

%.o:	%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

%.o:	%.s
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

%.s:	%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -S -o $@ $<

%.gb:	%.o
	$(LCC) $(LCCFLAGS) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.noi *.rst

lankygitmono.c:
	$(PNG2ASSET) lankygitmono.png -noflip -bpp 1 -spr8x8 -sprite_no_optimize

sframe7.c:
	$(PNG2ASSET) sframe7.png -noflip -bpp 1 -spr8x8 -sprite_no_optimize

bg_road.c:
	$(PNG2ASSET) bg_road.png -noflip -bpp 2 -spr8x8 -sprite_no_optimize

# Link file, and write 0x80 at position 0x143 in header
compo25.gbc:	lankygitmono.o sframe7.o bg_road.o single_beep.o main.o
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o compo25.gbc lankygitmono.o sframe7.o bg_road.o single_beep.o main.o

MGBA=c:\Users\jgens\Downloads\mGBA-0.10.5-win64\mGBA-0.10.5-win64\mGBA.exe

run: compo25.gbc
	$(MGBA) compo25.gbc

usage: compo25.gbc
	$(ROMUSAGE) .\compo25.gbc