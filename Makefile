# Makefile for SlightX

export CC = gcc
export AS = nasm
export LD = ld

export CFLAGS = -fno-builtin -m32 -Wall -nostartfiles -nostdlib -nostdinc -g -c
export ASFLAGS = -f elf32
export LDFLAGS = -melf_i386 -T linker.ld

.PHONY: all clean install run doc

all:
	@make all -C kernel
	@make all -C libc
	@make all -C apps

clean:
	@make clean -C kernel
	@make clean -C libc
	@make clean -C apps
	@make clean -C bin

install:
	@if [ ! -d mnt/ ] ; then mkdir mnt ; fi
	@losetup -o 32256 /dev/loop0 disk.img
	@mount -t xfs /dev/loop0 mnt
	@make install -C boot
	@make install -C bin
	@umount mnt
	@losetup -d /dev/loop0

make_initrd: make_initrd.c
	$(CC) $^ -o $@


run:
	@qemu -hda disk.img -m 512

doc:
	@doxygen doc/Doxyfile
