#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

int read_proc(char* buf, char** start, off_t offset, int count, int* eof, void* data) {
  int len = 0;
  struct task_struct* task;
  struct list_head* list;

  printk(KERN_INFO "In read_proc");
  printk(KERN_INFO "head: %p", &current->children);
  list_for_each(list, &current->children) {
    printk(KERN_INFO "list: %p, list->next: %p, list->prev: %p", list, list->next, list->prev);
    task = list_entry(list, struct task_struct, sibling);
    printk(KERN_INFO "%s %d", task->comm, task->pid);
    len += sprintf(buf + len, "%s %d\n", task->comm, task->pid);
  }
  return len;
}

int function_init(void) {
  printk(KERN_INFO "In init");
  create_proc_read_entry("ps_children_list", 0, NULL, read_proc, NULL);
  return 0;
}

void function_cleanup(void) {
  printk(KERN_INFO "In cleanup");
  remove_proc_entry("ps_children_list", NULL);
}

module_init(function_init);
module_exit(function_cleanup);
