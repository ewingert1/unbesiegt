make clean
make kernel.elf
arm-none-eabi-objcopy -O binary "kernel.elf" "kernel.img"
