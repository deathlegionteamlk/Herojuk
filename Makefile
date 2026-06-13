CC = gcc
AS = as
LD = ld

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra -Iinclude
ASFLAGS = --32
LDFLAGS = -m elf_i386 -T linker.ld

KERNEL_BIN = herojuk.bin

SRCS = src/kernel/kernel.c \
       src/kernel/arch/i386/boot.s \
       src/kernel/arch/i386/gdt.c \
       src/kernel/arch/i386/idt.c \
       src/kernel/arch/i386/interrupt.s \
       src/kernel/arch/i386/switch.s \
       src/kernel/drivers/vga.c \
       src/kernel/mm/pmm.c \
       src/kernel/mm/vmm.c \
       src/kernel/task/task.c \
       src/kernel/fs/vfs.c

OBJS = $(patsubst %.c,%.o,$(patsubst %.s,%.o,$(SRCS)))

all: $(KERNEL_BIN)

$(KERNEL_BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(KERNEL_BIN)
