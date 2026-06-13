#ifndef KERNEL_VGA_H
#define KERNEL_VGA_H
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
void vga_init(void);
void kprintf(const char* format, ...);
#endif
