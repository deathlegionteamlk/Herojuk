#include <kernel/pmm.h>
static uint32_t* pmm_bitmap;
static uint32_t  pmm_max_blocks;
void pmm_init(size_t mem_size, uint32_t bitmap_addr) {
    pmm_max_blocks = mem_size / PMM_BLOCK_SIZE;
    pmm_bitmap = (uint32_t*)bitmap_addr;
    for (uint32_t i = 0; i < pmm_max_blocks / 32; i++) pmm_bitmap[i] = 0xFFFFFFFF;
}
void pmm_init_region(uint32_t base, size_t size) {
    uint32_t align = base / PMM_BLOCK_SIZE;
    uint32_t blocks = size / PMM_BLOCK_SIZE;
    for (; blocks > 0; blocks--) { pmm_bitmap[align / 32] &= ~(1 << (align % 32)); align++; }
}
void pmm_deinit_region(uint32_t base, size_t size) {
    uint32_t align = base / PMM_BLOCK_SIZE;
    uint32_t blocks = size / PMM_BLOCK_SIZE;
    for (; blocks > 0; blocks--) { pmm_bitmap[align / 32] |= (1 << (align % 32)); align++; }
}
void* pmm_alloc_block() {
    for (uint32_t i = 0; i < pmm_max_blocks / 32; i++) {
        if (pmm_bitmap[i] != 0xFFFFFFFF) {
            for (int j = 0; j < 32; j++) {
                if (!(pmm_bitmap[i] & (1 << j))) { pmm_bitmap[i] |= (1 << j); return (void*)((i * 32 + j) * PMM_BLOCK_SIZE); }
            }
        }
    }
    return (void*)0;
}
