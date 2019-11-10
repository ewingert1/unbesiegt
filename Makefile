
CC = arm-none-eabi-gcc
INC = -Iinclude -Iinclude/bsp
SRC = src/*.c src/*.S src/bsp/rpi0w/*.c
CLAGS = -c fmessage-length=0 -v
RPI0FLAGS = -mfloat-abi=hard -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s
RPI3FLAGS = -march=armv8-a -mfpu=neon-fp-armv8 -mtune=cortex-a53
LDFLAGS = -nostartfiles -nostdlib -T memmap.ld

kernel.elf :
	$(CC) $(CFLAGS) $(RPI0FLAGS) $(INC) $(SRC) -o kernel.elf $(LDFLAGS)

clean :
	rm kernel*
