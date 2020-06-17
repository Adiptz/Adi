/***********************
 * Author   : Adi      *
 * Reviewer : Shieber  *
 * Status   : Sent     *
 ***********************/

#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <unistd.h> /* sleep */

#include "pqueue.h"
#include "scheduler.h"
#include "task.h"

#define UNUSED(x) (void)(x)

struct scheduler
{
	pqueue_t *pqueue;
	task_t *running_task;
	int should_stop;
};

/*adapter for PQ IsBefore */
int CmpPriority(void *data1, void *data2, const void *param)
{
	UNUSED(param);
	
	assert(NULL != data1);
	assert(NULL != data2);
	
	data1 = (task_t *)data1;
	data2 = (task_t *)data2;
	
	return (TaskGetTime(data2) - TaskGetTime(data1));  
}

/* help function for SchedulerRun */
static void SleepTillNextExec(time_t time_to_sleep);

/******************************* -- CREATE -- *********************************/
scheduler_t *SchedulerCreate(void)
{
	scheduler_t *scheduler = (scheduler_t *)malloc(sizeof(scheduler_t));
	if (NULL == scheduler)
	{
		return NULL;
	}
	
	scheduler->pqueue = PQueueCreate(CmpPriority, NULL);
	if (NULL == scheduler->pqueue)
	{
		free(scheduler); scheduler = NULL;
		return NULL;
	}
	
	scheduler->running_task = NULL;
	scheduler->should_stop = 0;
	
	return scheduler;
}

/****************************** -- DESTROY -- *********************************/
void SchedulerDestroy(scheduler_t *scheduler)
{
	assert(NULL != scheduler);

	SchedulerClear(scheduler);
	PQueueDestroy(scheduler->pqueue); scheduler->pqueue = NULL;
	free(scheduler); scheduler = NULL;
}

/****************************** -- ADD TASK -- ********************************/
task_uid_t SchedulerAddTask(scheduler_t *scheduler,
						    void *func_param,
                 		    task_status (*task_func)(void *param),
                 		    time_t time_in_sec,
                   			time_t interval_in_sec)
{
	int check = PQUEUE_FAILED; 
	task_t *new_task = NULL;
	
	assert(NULL != scheduler);
	assert(NULL != task_func);
	
	new_task = TaskCreate(func_param, task_func, time_in_sec, interval_in_sec);
	if (NULL == new_task)
	{
		return BAD_UID;
	}
	
	check = PQueueEnqueue(scheduler->pqueue,new_task);
	if (PQUEUE_FAILED == check)
	{
		TaskDestroy(new_task); new_task = NULL;
		return BAD_UID;
	}
	
	return TaskGetUID(new_task);
}
                   					
/***************************** -- REMOVE TASK -- ******************************/
sched_status SchedulerRemoveTask(scheduler_t *scheduler, task_uid_t task_uid)
{
	task_t *removed_task = NULL;
	
	assert(NULL != scheduler);

	if (NULL != scheduler->running_task &&
	   TaskIsMatch(scheduler->running_task, &task_uid, NULL))
	{
		TaskDestroy(scheduler->running_task);
		scheduler->running_task = NULL;
	}
	else
	{
		removed_task = PQueueErase(scheduler->pqueue,
							       TaskIsMatch,
							       &task_uid,
							       NULL);
		if (NULL == removed_task)
		{
			return SCHED_FAIL;
		}
	
		TaskDestroy(removed_task); removed_task = NULL;
	}
	
	return SCHED_SUCCESS;
}

/********************************* -- RUN -- **********************************/
sched_status SchedulerRun(scheduler_t *scheduler)
{
	time_t time_to_sleep = 0;
	
	assert(NULL != scheduler);
	
	while (!SchedulerIsEmpty(scheduler) && 0 == scheduler->should_stop)
	{
		task_status status = SCHED_NO_REPEAT;
	
		/* save first task in running_task and remove node from pqueue */
		scheduler->running_task = PQueuePeek(scheduler->pqueue);
		PQueueDequeue(scheduler->pqueue); 
		
		
		/* sleep till it's your time to shine */
		time_to_sleep = TaskGetTime(scheduler->running_task) - time(NULL);
		SleepTillNextExec(time_to_sleep);
		
		status = TaskExec(scheduler->running_task);
		if (NULL != scheduler->running_task) /* in case task destroyed itself */
		{
			if (SCHED_REPEAT == status)
			{
				TaskUpdateTime(scheduler->running_task);		
		
				if (PQUEUE_FAILED == PQueueEnqueue(scheduler->pqueue,
									              scheduler->running_task))
				{
					TaskDestroy(scheduler->running_task);
					scheduler->running_task = NULL;
					scheduler->should_stop = 0;
					return SCHED_FAIL;
				}
			}
			else
			{
				TaskDestroy(scheduler->running_task);
			}
		
			scheduler->running_task = NULL;	
		}
	}
	
	scheduler->should_stop = 0;
	
	return SCHED_SUCCESS;
}

/********************************* -- STOP -- *********************************/
void SchedulerStop(scheduler_t *scheduler)
{
	assert(NULL != scheduler);
	scheduler->should_stop = 1;
}

/****************************** -- IS EMPTY -- ********************************/
int SchedulerIsEmpty(const scheduler_t *scheduler)
{
	assert(NULL != scheduler);
	return PQueueIsEmpty(scheduler->pqueue) && NULL == scheduler->running_task;
}

/******************************** -- SIZE -- **********************************/
size_t SchedulerSize(const scheduler_t *scheduler)
{
	assert(NULL != scheduler);	

	return PQueueSize(scheduler->pqueue) + (NULL != scheduler->running_task);
}

/******************************** -- CLEAR -- **********************************/
void SchedulerClear(scheduler_t *scheduler)
{
	void *task_to_remove = NULL;
	
	assert(NULL != scheduler);
	
	if (NULL != scheduler->running_task)
	{
		TaskDestroy(scheduler->running_task);
		scheduler->running_task = NULL;
	}
	
	for (;
			!SchedulerIsEmpty(scheduler)
		 ;
		 	task_to_remove = PQueuePeek(scheduler->pqueue),
			TaskDestroy(task_to_remove), task_to_remove = NULL,
			PQueueDequeue(scheduler->pqueue)
		)
	{/* empty body */}
	
	PQueueClear(scheduler->pqueue);
}

/***************************** -- SLEEP -- ************************************/
static void SleepTillNextExec(time_t time_to_sleep)
{	
	while (time_to_sleep > 0)
	{
		time_to_sleep = sleep(time_to_sleep);
	}
}	
