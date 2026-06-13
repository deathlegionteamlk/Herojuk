#ifndef KERNEL_VFS_H
#define KERNEL_VFS_H
#include <stdint.h>
typedef struct vfs_node {
    char name[128];
} vfs_node_t;
void vfs_init(void);
#endif
