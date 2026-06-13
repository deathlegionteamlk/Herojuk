#ifndef KERNEL_PMM_H
#define KERNEL_PMM_H
#include <stdint.h>
#include <stddef.h>
#define PMM_BLOCK_SIZE 4096
void pmm_init(size_t mem_size, uint32_t bitmap_addr);
void pmm_init_region(uint32_t base, size_t size);
void pmm_deinit_region(uint32_t base, size_t size);
void* pmm_alloc_block(void);
#endif
