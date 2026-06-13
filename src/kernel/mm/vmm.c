#include <kernel/vmm.h>
#include <kernel/pmm.h>
void vmm_init() {
    uint32_t* pd = (uint32_t*)pmm_alloc_block();
    uint32_t* pt = (uint32_t*)pmm_alloc_block();
    for (int i = 0; i < 1024; i++) pt[i] = (i * 4096) | 3;
    pd[0] = (uint32_t)pt | 3;
    for (int i = 1; i < 1024; i++) pd[i] = 0;
    __asm__ volatile("mov %0, %%cr3" : : "r"(pd));
    uint32_t cr0;
    __asm__ volatile("mov %%cr0, %0" : "=r"(cr0));
    cr0 |= 0x80000000;
    __asm__ volatile("mov %0, %%cr0" : : "r"(cr0));
}
