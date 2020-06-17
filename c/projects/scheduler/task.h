#ifndef __OL71_TASK_H
#define __OL71_TASK_H

#include "../../ds/uid/uid.h" /* uid */
#include "scheduler.h"

typedef struct task task_t;

/*
 * Create new task
 * Param param : parameter for task_func
 * Param func : function to execute
 * Param time : time in seconds from Epoch when to execute the task
 * Param interval : interval between the executions of the task
 * Return: pointer to new task
 * Errors: returns NULL if task creation fails
 */
task_t *TaskCreate(void *param, task_func func, time_t time, time_t interval);

/*
 * Execute a task.
 * Param task: a task to be executed.
 * Return: return value of executed function.
 */
task_status TaskExec(task_t *task);

/*
 * Check if task match uid
 * Param task: task to compare
 * Param task_uid: task uid to match
 * Param param: irrelevant param
 * Return : 1 if same, 0 otherwise
 * Errors : none
 */
int TaskIsMatch(void *task, const void *task_uid, void *param);

/*    
 * Get UID of given task
 * Param task : pointer to task
 * Return : UID of given task
 * Errors : none.
 */
task_uid_t TaskGetUID(const task_t *task);

/*
 * Get the time (in seconds) for the task execution
 * Param task: get task
 * Return: time of task (in seconds since epoch)
 * Errors: none
 */
time_t TaskGetTime(const task_t *task);

/*
 * check if new_task is before the timestamp of scheduled_task 
 * Param new_task: new task to check.
 * Param scheduled_task: task in queue of the scheduler.
 * Param param: user-defined param. 
 * Return: 1 if before and zero otherwise.
 * Errors: none
 */
int TaskIsBefore(const task_t *new_task, const task_t *scheduled_task, 
				 void *param);

/*
 * Update time for next executaion
 * Param task: task to update time
 * Returns: none.
 * Errors: none.
 */
void TaskUpdateTime(task_t *task);

/*
 * Destroy the task
 * Param task: pointer to task to destroy
 * Return: none
 * Errors: none
 */
void TaskDestroy(task_t *task);

#endif /* __OL71_TASK_H */



