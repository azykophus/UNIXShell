#include <linux/syscalls.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/sched.h>

#define __NR_process_info 255

SYSCALL_DEFINE1(process_info, pid_t, pid)
{
   
  struct task_struct *task;

  task = pid_task(find_vpid(pid), PIDTYPE_PID);
  printk("command path: %s\n", task->comm);
  printk("pgid: %d\n", task->group_leader->pid);
  printk("pid : %d\n", task->pid);
  printk("user_id : %d\n", task->cred->uid.val);

}