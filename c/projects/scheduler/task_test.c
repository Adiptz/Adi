/***********************
 * Author   : Adi      *
 * Reviewer : Shieber  *
 * Status   : Sent     *
 ***********************/
 
#include <assert.h> /* assert */
#include <unistd.h> /* sleep */
#include <stdio.h> /* puts */
#include <time.h> /* time(NULL) */

#include "task.h"

#define UNUSED(x) (void)(x)


task_status PrintTestFunc(void *param)  
{
	UNUSED(param);
	puts("VOVA THE QUEEN");
	
	return SCHED_NO_REPEAT;
}

task_t *CreateTask()
{
	task_t *test_task = NULL;
	
	time_t task_time = time(NULL);
	time_t interval = 0;
	
	test_task = TaskCreate(NULL, PrintTestFunc, task_time, interval);

	return test_task;
}

task_t *CreateTaskWithInterval5()
{
	task_t *test_task = NULL;
	
	time_t task_time = time(NULL);
	time_t interval = 5;
	
	test_task = TaskCreate(NULL, PrintTestFunc, task_time, interval);

	return test_task;
}

void CreateDestroy_test()
{
	task_t *test_task = CreateTask();
	
	TaskDestroy(test_task);	
}

void Exec_test()
{
	task_t *task = CreateTask();
	
	TaskExec(task);

	TaskDestroy(task);	
}


void IsMatch_test()
{
	task_t *task1 = CreateTask();
	task_t *task2 = CreateTask();
	const task_uid_t uid2 = TaskGetUID(task2);
	const task_uid_t uid1 = TaskGetUID(task1);
	
	assert(0 == TaskIsMatch(task1, &uid2, NULL));
	assert(1 == TaskIsMatch(task1, &uid1, NULL));

	TaskDestroy(task1);
	TaskDestroy(task2);	
}

void GetUID_test()
{
	task_t *task1 = CreateTask();
	task_t *task2 = CreateTask();
	
	assert(0 == UIDIsSame(TaskGetUID(task1), TaskGetUID(task2)));
	assert(1 == UIDIsSame(TaskGetUID(task1), TaskGetUID(task1)));
	
	TaskDestroy(task1);
	TaskDestroy(task2);	
}

void GetTime_test()
{
	time_t curr_time = time(NULL);
	
	task_t *task = CreateTask();

	assert(curr_time == TaskGetTime(task));
	
	TaskDestroy(task);
}



void IsBefore_test()
{
	task_t *task1 = NULL;
	task_t *task2 = NULL;

	sleep(1);
	
	task1 = CreateTask();
	sleep(1);
	task2 = CreateTask();
	
	assert(1 == TaskIsBefore(task1, task2, NULL));
	assert(0 == TaskIsBefore(task2, task1, NULL));
	
	TaskDestroy(task1);
	TaskDestroy(task2);		
}

void UpdateTime()
{
	task_t *task = CreateTaskWithInterval5();
	time_t current_time = TaskGetTime(task);
	time_t future_time = 0;
	
	TaskUpdateTime(task);
	
	future_time = TaskGetTime(task);
	
	assert(current_time + 5 == future_time);
	
	TaskDestroy(task);
}

int main()
{
	CreateDestroy_test();
	Exec_test();
	IsMatch_test();
	GetUID_test();
	GetTime_test();
	IsBefore_test();
	UpdateTime();

	return 0;
}
