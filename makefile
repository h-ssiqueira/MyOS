CC = i686-linux-gnu-gcc-10
CCa = i686-linux-gnu-as
NASM = nasm
NASMFLAGS = -f elf32
CFLAGS = -c -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -ffreestanding -O2 -nostdlib -lgcc

###############################################################
all: bin myos.iso

# Folder for binaries
bin:
	mkdir -p bin

boot.o : src/boot.s
	${CCa} src/boot.s -o bin/boot.o

commands : src/command.c
	${CC} src/command.c -o bin/command.o ${CFLAGS}

drivers : src/video.c src/keyboard.c
	${CC} src/video.c -o bin/video.o ${CFLAGS}
	${CC} src/keyboard.c -o bin/keyboard.o ${CFLAGS}

kernel.o : src/kernel.c
	${CC} src/kernel.c -o bin/kernel.o ${CFLAGS}

interrupts :  src/exception_handler.asm
	${NASM} -o bin/exception_handler.o src/exception_handler.asm ${NASMFLAGS}

math : src/math.c
	${CC} src/math.c -o bin/math.o ${CFLAGS}

string : src/string.c
	${CC} src/string.c -o bin/string.o ${CFLAGS}

myos.bin : src/linker.ld boot.o kernel.o drivers commands string interrupts math
	${CC} -T src/linker.ld -o bin/myos.bin bin/*.o ${LDFLAGS}

myos.iso : myos.bin
	mkdir -p isodir/boot/grub
	cp bin/myos.bin isodir/boot/myos.bin
	cp src/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir
	qemu-system-x86_64 -boot d -cdrom myos.iso -m 32

################################################################
install:
	sudo apt-get install gcc-10-i686-linux-gnu
	sudo apt install nasm
	sudo apt install xorriso
	sudo apt install qemu-system-x86

clean:
	rm -rf bin/*.o

run:
	qemu-system-x86_64 -boot d -cdrom myos.iso -m 32