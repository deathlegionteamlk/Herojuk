#ifndef KERNEL_TASK_H
#define KERNEL_TASK_H
#include <stdint.h>
typedef struct task {
    uint32_t esp;
    struct task* next;
} task_t;
void task_init(void);
void schedule(void);
#endif
