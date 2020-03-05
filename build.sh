nasm -f elf32 src/bootloader.asm -o boot.o
i686-elf-gcc -ffreestanding -nostdlib -c src/kernel.c -o kernel.o
i686-elf-ld -T src/linker.ld -o bin/os.bin boot.o kernel.o
rm boot.o kernel.o

qemu-system-x86_64 -kernel bin/os.bin
