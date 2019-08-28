current_dir = $(shell pwd)
CCFLAGS = -Wa-l -Wl-m -Wl-j

export GBDKDIR=$(current_dir)/lib/gbdk/

all:
	$(shell mkdir -p dist)
	$(current_dir)/lib/gbdk/bin/lcc $(CCFLAGS) -c -o main.o src/main.c
	$(current_dir)/lib/gbdk/bin/lcc $(CCFLAGS) -o ./dist/main.gb main.o
