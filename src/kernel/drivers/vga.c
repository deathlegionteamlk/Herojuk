#include <kernel/vga.h>
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;
static size_t terminal_row;
static size_t terminal_column;
void vga_init(void) {
	terminal_row = 0;
	terminal_column = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			VGA_MEMORY[index] = (uint16_t) ' ' | (uint16_t) 7 << 8;
		}
	}
}
static void vga_putchar(char c) {
    if (c == '\n') { terminal_column = 0; if (++terminal_row == VGA_HEIGHT) terminal_row = 0; return; }
	const size_t index = terminal_row * VGA_WIDTH + terminal_column;
	VGA_MEMORY[index] = (uint16_t) c | (uint16_t) 7 << 8;
	if (++terminal_column == VGA_WIDTH) { terminal_column = 0; if (++terminal_row == VGA_HEIGHT) terminal_row = 0; }
}
void kprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    for (const char* p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            if (*p == 's') { const char* s = va_arg(args, char*); while(*s) vga_putchar(*s++); }
        } else vga_putchar(*p);
    }
    va_end(args);
}
