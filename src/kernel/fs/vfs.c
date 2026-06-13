#include <kernel/vfs.h>
#include <kernel/pmm.h>
vfs_node_t* vfs_root;
void vfs_init() {
    vfs_root = (vfs_node_t*)pmm_alloc_block();
}
