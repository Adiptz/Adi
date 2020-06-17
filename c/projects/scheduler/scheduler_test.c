/***********************
 * Author   : Adi      *
 * Reviewer : Shieber  *
 * Status   : Sent     *
 ***********************/

#include <assert.h> /* assert */
#include <stdio.h> /* puts */
#include "scheduler.h"

#define UNUSED(x) (void)(x)


task_status PrintTestFunc(void *param)  
{
	UNUSED(param);
	puts("Vova The Queen");
	
	return SCHED_NO_REPEAT;
}

task_status PrintTestFirst(void *param)  
{
	UNUSED(param);
	puts("1");
	
	return SCHED_NO_REPEAT;
}

task_status PrintTestSecond(void *param)  
{
	UNUSED(param);
	puts("2");
	
	return SCHED_NO_REPEAT;
}

task_status PrintTestThird(void *param)  
{
	UNUSED(param);
	puts("3");
	
	return SCHED_NO_REPEAT;
}

task_status PrintTestRepeat(void *param)  
{
	UNUSED(param);
	puts("Vova The Queen");
	
	return SCHED_REPEAT;
}

task_status STOP(void *param)
{
	SchedulerStop(param);
	
	return SCHED_NO_REPEAT;
}



void CreateDestroy_test()
{
	scheduler_t *new_scheduler = SchedulerCreate();
	SchedulerDestroy(new_scheduler);

}


void AddTask_test()
{
	scheduler_t *new_scheduler = SchedulerCreate();
	
	assert(1 == SchedulerIsEmpty(new_scheduler));
	
	SchedulerAddTask(  new_scheduler,
					   NULL,
					   &PrintTestFunc,
					   time(NULL),
					   0	);
	
	assert(0 == SchedulerIsEmpty(new_scheduler));		   
					   
	SchedulerDestroy(new_scheduler);				   				 
}

void IsEmptySize_test()
{
	int i = 2; 
	
	scheduler_t *new_scheduler = SchedulerCreate();
	
	assert(1 == SchedulerIsEmpty(new_scheduler));
	assert(0 == SchedulerSize(new_scheduler));
	
	while(i--)
	{
		SchedulerAddTask(  new_scheduler,
						   NULL,
						   &PrintTestFunc,
						   time(NULL),
						   0	);
	}
	
	assert(2 == SchedulerSize(new_scheduler));
	assert(0 == SchedulerIsEmpty(new_scheduler));

	SchedulerDestroy(new_scheduler);
}

void RemoveTask_test()
{
	scheduler_t *scheduler = SchedulerCreate();
	task_uid_t task = BAD_UID;
	assert(1 == SchedulerIsEmpty(scheduler));
	
	task = SchedulerAddTask(  scheduler,
						      NULL,
					          &PrintTestFunc,
					          time(NULL),
					          0	);
		
	assert(1 == SchedulerSize(scheduler));
	
	SchedulerRemoveTask(scheduler, task);
	
	assert(0 == SchedulerSize(scheduler));

	SchedulerDestroy(scheduler);
}

void Run_test()
{
	scheduler_t *scheduler = SchedulerCreate();
	
	assert(1 == SchedulerIsEmpty(scheduler));
	
	
	/* no repeat tasks*/
	SchedulerAddTask(  scheduler,
				  	   NULL,
				       &PrintTestSecond,
				       time(NULL) + 1,
				       0	);
				          
  	SchedulerAddTask(  scheduler,
			  		   NULL,
			           &PrintTestThird,
			           time(NULL) + 2,
		          	   0	);
					          
	SchedulerAddTask(  scheduler,
					   NULL,
					   &PrintTestFirst,
					   time(NULL),
					   0	);
	
	/* repeat task */
	SchedulerAddTask(  scheduler,
				  	   NULL,
				       &PrintTestRepeat,
				       time(NULL),
				       4	);
				    
	/* stop task */
	SchedulerAddTask(  scheduler,
				  	   scheduler,
				       &STOP,
				       time(NULL) + 18,
				       0	);
				       
				       
	SchedulerRun(scheduler);

	assert(0 == SchedulerIsEmpty(scheduler));
		
	SchedulerDestroy(scheduler);


}

int main()
{
	CreateDestroy_test();
	IsEmptySize_test();
	AddTask_test();
	RemoveTask_test();
	Run_test();
	return 0;
}
