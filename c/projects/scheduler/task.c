/***********************
 * Author   : Adi      *
 * Reviewer : Shieber  *
 * Status   : Sent     *
 ***********************/

#include <assert.h> /* assert */
#include <time.h> /* time */
#include <stdlib.h> /* malloc, free */

#include "task.h"

#define UNUSED(x) ((void)(x))



struct task
{
	void *param;
	task_func func;
	time_t time;
	time_t interval;
	task_uid_t task_uid; 
};


/******************************************************************************/
task_t *TaskCreate(void *param, task_func func, time_t time, time_t interval)
{
	task_t *new_task = (task_t *)malloc(sizeof(task_t));
	if (NULL == new_task)
	{
		return NULL;
	}
	
	assert(NULL != func);
	
	new_task->param = param;
	new_task->func = func;
	new_task->time = time;
	new_task->interval = interval;
	
	new_task->task_uid = UIDCreate();
	if (UIDIsSame(BAD_UID, new_task->task_uid))
	{
		free(new_task); new_task = NULL;
		return NULL;	
	}
	
	return new_task;
}

/******************************************************************************/
task_status TaskExec(task_t *task)
{
	assert(NULL != task);

	return (task->func(task->param));
}

/******************************************************************************/
int TaskIsMatch(void *task, const void *task_uid, void *param)
{
	UNUSED(param);

	assert(NULL != task);
	
	return UIDIsSame(TaskGetUID((task_t *)task), *((task_uid_t *)task_uid));
}

/******************************************************************************/
task_uid_t TaskGetUID(const task_t *task)
{
	assert(NULL != task);
	
	return (task->task_uid);
}

/******************************************************************************/
time_t TaskGetTime(const task_t* task)
{
	assert(NULL != task);
	
	return (task->time);
}

/******************************************************************************/
int TaskIsBefore(const task_t *new_task, const task_t *scheduled_task, 
					void *param)
{
	UNUSED(param);
	
	assert(NULL != new_task);
	assert(NULL != scheduled_task);
	
	return(TaskGetTime(new_task) < TaskGetTime(scheduled_task));	
}

/******************************************************************************/
void TaskUpdateTime(task_t *task)
{
	assert(NULL != task);
	
	task->time += task->interval;
}

/******************************************************************************/
void TaskDestroy(task_t *task)
{
	assert(NULL != task);
	
	free(task); task = NULL;
}

