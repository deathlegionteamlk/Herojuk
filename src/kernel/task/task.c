#include <kernel/task.h>
#include <kernel/pmm.h>
static task_t* current_task;
void task_init() {
    current_task = (task_t*)pmm_alloc_block();
    current_task->esp = 0;
    current_task->next = current_task;
}
void schedule() {}
