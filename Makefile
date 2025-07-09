# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
	GBDK_HOME = ../../
endif

LCC_FLAGS_HUGEDRIVER = -Wl-lsrc/3p/hUGEDriver.lib
LCC_FLAGS_GBC = -Wm-yc -Wl-yt0x1B -debug $(LCC_FLAGS_HUGEDRIVER)
LCCFLAGS = -Wl-j -Wm-yoA -Wm-ya4 -Wb-ext=.rel -Wb-v $(LCC_FLAGS_GBC)
LCC = $(GBDK_HOME)bin/lcc.exe
PNG2ASSET = $(GBDK_HOME)bin/png2asset.exe
ROMUSAGE = $(GBDK_HOME)bin/romusage.exe

# GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif

CFLAGS	= -Isrc

BINS	= compo25.gbc

all:	$(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ -p\/mkdir\/ | grep -v make >> compile.bat

build/%.o:	src/%.c
	@mkdir -p $(dir $@)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# assembly
build/%.o:	src/%.s
	@mkdir -p $(dir $@)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# build/%.s:	src/%.c
# 	$(LCC) $(LCCFLAGS) $(CFLAGS) -S -o $@ $<

# %.gb:	%.o
# 	$(LCC) $(LCCFLAGS) -o $@ ./build/$<

# FONT = lankygitmono.c
FONT = lankygitmono_short.c
ASSETS = $(FONT) sframe7.c bg_road.c sp_cacti.c bg_store_owner.c sp_store_owner.c bg_cheri.c sp_cheri.c bg_veronica.c sp_veronica.c sp_inn.c sp_shack.c sp_rock.c
METASPRITE_FIX_SOURCE = $(addprefix src/gen/metasprite_fix/,$(ASSETS))
METASPRITE_FIX_HEADER = $(patsubst %.c,%.h,$(METASPRITE_FIX_SOURCE))
CHARACTERS = character_store_owner.c character_cheri.c character_veronica.c character_simple.c character.c
SCENES_GENERATED = gen_scene_inn.c gen_scene_customers.c gen_scene_intro.c gen_scene_shack.c
SCENES_CORE = scene_dialog.c scene_intro_dialog.c scene_start_menu.c scene_road.c scene_shop.c
SCENES = $(addprefix src/,$(SCENES_CORE)) $(addprefix src/gen/scene/,$(SCENES_GENERATED))
SRCS_CORE = data.c text.c input.c sound.c animate.c
SRCS = $(addprefix src/,$(SRCS_CORE)) $(addprefix src/gen/png2asset/,$(ASSETS)) $(addprefix src/,$(CHARACTERS)) $(METASPRITE_FIX_SOURCE) $(SCENES)
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))
ASSET_OUT = src/gen/png2asset
METASPRITE_FIX_OUT = src/gen/metasprite_fix
ASSET_IN = assets

clean:
	# rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.noi *.rst *.rel $(ASSETS)
	# rmdir build
	@powershell.exe Remove-Item -Force -Recurse -Confirm build
	mkdir build

scene_gen:
	python src/sg/scene_gen.py

$(ASSET_OUT)/lankygitmono.c: $(ASSET_IN)/lankygitmono.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 1

$(ASSET_OUT)/lankygitmono_short.c: $(ASSET_IN)/lankygitmono_short.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 1

$(ASSET_OUT)/sframe7.c: $(ASSET_IN)/sframe7.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 1

$(ASSET_OUT)/bg_road.c: $(ASSET_IN)/bg_road.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

$(ASSET_OUT)/sp_cacti.c: $(ASSET_IN)/sp_cacti.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

$(ASSET_OUT)/sp_rock.c: $(ASSET_IN)/sp_rock.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

$(ASSET_OUT)/sp_inn.c: $(ASSET_IN)/sp_inn.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

$(ASSET_OUT)/sp_shack.c: $(ASSET_IN)/sp_shack.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -sprite_no_optimize -b 2

$(ASSET_OUT)/bg_store_owner.c: $(ASSET_IN)/bg_store_owner.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -max_palettes 7 -sprite_no_optimize -b 3

$(ASSET_OUT)/sp_store_owner.c: $(ASSET_IN)/sp_store_owner.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -max_palettes 3 -sprite_no_optimize -b 3

$(ASSET_OUT)/bg_cheri.c: $(ASSET_IN)/bg_cheri.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -max_palettes 7 -sprite_no_optimize -b 4

$(ASSET_OUT)/sp_cheri.c: $(ASSET_IN)/sp_cheri.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -max_palettes 3 -sprite_no_optimize -b 4

$(ASSET_OUT)/bg_veronica.c: $(ASSET_IN)/bg_veronica.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -max_palettes 7 -sprite_no_optimize -b 4

$(ASSET_OUT)/sp_veronica.c: $(ASSET_IN)/sp_veronica.png
	$(PNG2ASSET) $< -o $@ -noflip -bpp 2 -spr8x8 -max_palettes 3 -sprite_no_optimize -b 4

$(METASPRITE_FIX_OUT)/%.c: $(ASSET_OUT)/%.c
	@mkdir -p $(METASPRITE_FIX_OUT)
	@echo "#include <gbdk/platform.h>" > $@
	@echo "const uint8_t $(notdir $*_palette_map)[] = {" >> $@
	@cat $< | grep 'METASPR_ITEM' | sed 's/METASPR_ITEM.*S_PAL(//g' | sed 's/))//g' >> $@
	@echo "};" >> $@

$(METASPRITE_FIX_OUT)/%.h: $(ASSET_OUT)/%.c
	@mkdir -p $(METASPRITE_FIX_OUT)
	@echo "#include <gbdk/platform.h>" > $@
	@echo "extern const uint8_t $(notdir $*_palette_map)[];" >> $@

# Mark generated source files as secondary so they are not deleted by make
.SECONDARY: $(ASSET_SOURCES_C) $(METASPRITE_FIX_SOURCE) $(METASPRITE_FIX_HEADER)

# Link file, and write 0x80 at position 0x143 in header
compo25.gbc: $(METASPRITE_FIX_HEADER) $(OBJS) src/main.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o compo25.gbc $(OBJS) src/main.c

MGBA=c:\Users\jgens\Downloads\mGBA-0.10.5-win64\mGBA-0.10.5-win64\mGBA.exe
BGB=c:\Users\jgens\Downloads\bgbw64\bgb64.exe

run: compo25.gbc
	# $(MGBA) compo25.gbc
	$(BGB) compo25.gbc

usage: compo25.gbc
	$(ROMUSAGE) .\compo25.gbc