# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
	GBDK_HOME = ../../
endif

LCC_FLAGS_HUGEDRIVER = -Wl-lhUGEDriver.lib
LCC_FLAGS_GBC = -Wm-yc -Wl-yt0x1B $(LCC_FLAGS_HUGEDRIVER)
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

ASSETS = lankygitmono.c sframe7.c bg_road.c sp_cacti.c bg_store_owner.c sp_store_owner.c bg_cheri.c sp_cheri.c
GENERATED = gen_scene_inn.c gen_scene_customers.c gen_scene_intro.c
CHARACTERS = character_store_owner.c character_cheri.c character.c
SCENES = scene_dialog.c scene_intro_dialog.c scene_start_menu.c scene_road.c scene_inn.c scene_shop.c $(GENERATED)
SRCS = types.c text.c input.c sound.c animate.c $(ASSETS) $(CHARACTERS) $(SCENES)
OBJS = $(SRCS:.c=.o)

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.noi *.rst $(ASSETS)

scene_gen:
	python scene_gen.py

lankygitmono.c: lankygitmono.png
	$(PNG2ASSET) lankygitmono.png -noflip -bpp 1 -spr8x8 -sprite_no_optimize -b 1

sframe7.c: sframe7.png
	$(PNG2ASSET) sframe7.png -noflip -bpp 1 -spr8x8 -sprite_no_optimize -b 1

bg_road.c: bg_road.png
	$(PNG2ASSET) bg_road.png -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

# bg_fade.c: bg_fade.png
# 	$(PNG2ASSET) bg_fade.png -noflip -bpp 1 -spr8x8 -sprite_no_optimize

sp_cacti.c: sp_cacti.png
	$(PNG2ASSET) sp_cacti.png -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

bg_store_owner.c: bg_store_owner.png
	$(PNG2ASSET) bg_store_owner.png -noflip -bpp 2 -spr8x8 -max_palettes 7 -sprite_no_optimize -b 3

sp_store_owner.c: sp_store_owner.png
	$(PNG2ASSET) sp_store_owner.png -noflip -bpp 2 -spr8x8 -max_palettes 3 -sprite_no_optimize -b 3

bg_cheri.c: bg_cheri.png
	$(PNG2ASSET) bg_cheri.png -noflip -bpp 2 -spr8x8 -max_palettes 7 -sprite_no_optimize -b 4

sp_cheri.c: sp_cheri.png
	$(PNG2ASSET) sp_cheri.png -noflip -bpp 2 -spr8x8 -max_palettes 3 -sprite_no_optimize -b 4

# Link file, and write 0x80 at position 0x143 in header
compo25.gbc: $(OBJS) main.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o compo25.gbc $(OBJS) main.c

MGBA=c:\Users\jgens\Downloads\mGBA-0.10.5-win64\mGBA-0.10.5-win64\mGBA.exe
BGB=c:\Users\jgens\Downloads\bgbw64\bgb64.exe

run: compo25.gbc
	$(MGBA) compo25.gbc
	# $(BGB) compo25.gbc

usage: compo25.gbc
	$(ROMUSAGE) .\compo25.gbc