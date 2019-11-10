
CC = arm-none-eabi-gcc
INC = -Iinclude -Iinclude/bsp
SRC = src/*.c src/*.S src/bsp/rpi0w/*.c
CLAGS = -c fmessage-length=0 -mcpu=arm1176jzf-s -mfpu=vfp
LDFLAGS = -nostartfiles -T memmap.ld

kernel.elf :
	$(CC) $(INC) $(CFLAGS) $(SRC) -o kernel.elf $(LDFLAGS)

clean :
	rm kernel*
