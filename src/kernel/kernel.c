#include <kernel/vga.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/pmm.h>
#include <kernel/vmm.h>
#include <kernel/task.h>
#include <kernel/vfs.h>
void kernel_main(void) {
	vga_init();
	kprintf("Herojuk Kernel v0.0.1 Loaded!\n");
    gdt_init();
    kprintf("GDT Initialized\n");
    idt_init();
    kprintf("IDT Initialized\n");
    pmm_init(128 * 1024 * 1024, 0x200000);
    pmm_init_region(0, 128 * 1024 * 1024);
    pmm_deinit_region(0, 0x400000);
    kprintf("PMM Initialized\n");
    vmm_init();
    kprintf("VMM Initialized\n");
    task_init();
    kprintf("Tasking Initialized\n");
    vfs_init();
    kprintf("VFS Initialized\n");
    kprintf("Herojuk is ready.\n");
	while (1);
}
