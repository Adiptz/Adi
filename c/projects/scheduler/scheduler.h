#ifndef __OL71_SCHEDULER_H
#define __OL71_SCHEDULER_H

#include <stddef.h> /* size_t */
#include <time.h> /* time_t */

#include "uid.h" /* uid */

typedef ilrd_uid_t task_uid_t;
typedef struct scheduler scheduler_t;

typedef enum task_status {
	SCHED_REPEAT,
	SCHED_NO_REPEAT
} task_status;

typedef enum sched_status {
	SCHED_SUCCESS,
	SCHED_FAIL
} sched_status;

/* returns SCHED_REPEAT for repeating, SCHED_NO_REPEAT for no repeating */
typedef task_status (*task_func)(void *param);

/*
 * Create scheduler
 * Return: pointer to created scheduler
 * Errors: return NULL if failed
 */
scheduler_t *SchedulerCreate(void);

/*
 * Destroy scheduler
 * Param scheduler : scheduler to destroy
 * Return: none
 * Errors: none
 */
void SchedulerDestroy(scheduler_t *scheduler);

/*
 * Add task to scheduler
 * Param scheduler : scheduler
 * Param func_param: task_func param
 * Param task_func : func to exec (returns task_status)
 * Param time : time to execute task (in seconds, since epoch)
 * Param interval : seconds to add to next time task is executed
 * Return: new tasks task_uid
 * Note: if current time is after new task time, task will be executed first
 * Errors: return BAD_UID if adding task failed
 *         if task time is not unique, task position is undefined
 */
task_uid_t SchedulerAddTask(scheduler_t *scheduler, void *func_param,
                   task_status (*task_func)(void *param), time_t time_in_sec,
                   time_t interval_in_sec);

/*
 * Remove task from schedule 
 * Param scheduler : scheduler
 * Param task_uid : uid of task to remove
 * Return: SCHED_SUCCESS if remove succeed, SCHED_FAIL otherwise
 * Errors: if no task with task_uid in scheduler, return SCHED_FAIL
 */
sched_status SchedulerRemoveTask(scheduler_t *scheduler, task_uid_t task_uid);

/*
 * Stops executing tasks
 * Param scheduler : scheduler
 * Return: none
 * Errors: none
 */
void SchedulerStop(scheduler_t *scheduler);

/*
 * Start executing tasks
 * Param scheduler : scheduler
 * Return: SCHED_SUCCESS for success, SCHED_FAIL otherwise
 * Errors: if rescheduling failed, stops and returns SCHED_FAIL
 */
sched_status SchedulerRun(scheduler_t *scheduler);

/*
 * Check if scheduler is empty
 * Param scheduler : scheduler
 * Return: 1 if there are no tasks in scheduler, 0 otherwise
 * Errors: none
 */
int SchedulerIsEmpty(const scheduler_t *scheduler);

/*
 * Returns amount of tasks in scheduler
 * Param scheduler : scheduler
 * Return: number of tasks in scheduler, including currently running task
 * Errors: none 
 */
size_t SchedulerSize(const scheduler_t *scheduler);

/*
 * remove all tasks in scheduler
 * Param scheduler : scheduler
 * Return: none
 * Errors: none
 */
void SchedulerClear(scheduler_t *scheduler);

#endif /* __OL71_SCHEDULER_H */

