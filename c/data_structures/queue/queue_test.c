/**********************
 * Author : Adi       *
 * Reviewer : Shieber *
 * Status : Sent      *
 **********************/

#include <assert.h> /* assert */

#include "queue.h"

/* function decleration */
void CreateDestroy_test();
void EnQueue_test();
void DeQueue_test();
void Size_test();
void IsEmpty_test();
void Peek_test();
void Append_test();


/******************************** -- MAIN -- **********************************/
int main()
{
	CreateDestroy_test();
	EnQueue_test();
	DeQueue_test();
	Size_test();
	IsEmpty_test();
	Peek_test();
	Append_test();	
	
	return 0;
}
/******************************************************************************/





				    /* ------ TESTING FUNCTIONS ------ */


/************************** -- CREATE / DESTROY -- ****************************/
void CreateDestroy_test()
{
	queue_t *q_test = QueueCreate();
	QueueDestroy(q_test);
}


/****************************** -- ENQUEUE -- *********************************/
void EnQueue_test()
{
	
	/* create queue */
	queue_t *q_test = QueueCreate();
	int i = 5;
	int j = 9;
	int k = 10;
	
	/* insert 3 nodes */
	QueueEnqueue(q_test, &i); 
	QueueEnqueue(q_test, &j);
	QueueEnqueue(q_test, &k);
	
	/* checking head remain the first node insert - i */
	assert(5 == *(int *)QueuePeek(q_test)); 
	
	QueueDestroy(q_test);
}

/****************************** -- DEQUEUE -- *********************************/
void DeQueue_test()
{		
	/* create queue */
	queue_t *q_test = QueueCreate();
	int i = 5;
	int j = 9;
	int k = 10;
	
	/* insert 3 nodes */
	QueueEnqueue(q_test, &i); 
	QueueEnqueue(q_test, &j);
	QueueEnqueue(q_test, &k);
	
	/*checking head remain the first node insert - i */
	assert(5 == *(int *)QueuePeek(q_test)); 
	
	/* remove one to check if head is now the next node - j */
	QueueDequeue(q_test); 
	assert(9 == *(int *)QueuePeek(q_test)); 
			
	QueueDestroy(q_test);
}

/******************************** -- SIZE -- **********************************/
void Size_test()
{
	queue_t *q_test = QueueCreate();
	
	int i = 5;
	int j = 10;
	
	assert(0 == QueueSize(q_test));
		
	QueueEnqueue(q_test, &i); 
	assert(1 == QueueSize(q_test));
	
	QueueEnqueue(q_test, &j); 
	assert(2 == QueueSize(q_test));
	
	QueueDequeue(q_test);
	assert(1 == QueueSize(q_test));
	
	QueueDequeue(q_test); 
	assert(0 == QueueSize(q_test));
	
	QueueDestroy(q_test);
}

/****************************** -- IS EMPTY -- ********************************/
void IsEmpty_test()
{
	/* create queue */
	queue_t *q_test = QueueCreate();
	
	int i = 5;
	int j = 10;
	
	assert(1 == QueueIsEmpty(q_test));

	/* insert 2 nodes */
	QueueEnqueue(q_test, &i);
	QueueEnqueue(q_test, &j); 
	assert(0 == QueueIsEmpty(q_test));
	
	/* take out 2 nodes */
	QueueDequeue(q_test);
	QueueDequeue(q_test); 
	assert(1 == QueueIsEmpty(q_test));
	
	/* destroy queue */
	QueueDestroy(q_test);
	
}

/******************************** -- PEEK -- **********************************/
void Peek_test()
{	
	/* create queue */
	queue_t *q_test = QueueCreate();
	
	/* insert 2 nodes */
	int i = 5;
	int j = 10;
	QueueEnqueue(q_test, &i);
	QueueEnqueue(q_test, &j); 
	
	assert(5 == *(int *)QueuePeek(q_test));
	
	/* destroy queue */
	QueueDestroy(q_test);
}

/******************************* -- APPEND -- *********************************/
void Append_test()
{
	queue_t *dest = QueueCreate();
	queue_t *src = QueueCreate();
		
	/* insert 2 nodes to each list */
	int i = 5;
	int j = 10;
	
	QueueEnqueue(dest, &i);
	QueueEnqueue(dest, &j); 
	
	QueueEnqueue(src, &i);
	QueueEnqueue(src, &j);
	QueueEnqueue(src, &j);

	assert(2 == QueueSize(dest));
	assert(3 == QueueSize(src));
	
	/* Append src to dest */
	QueueAppend(dest, src);
	
	/* checking dest is bigger */
	assert(5 == QueueSize(dest));
	
	/* checking src is empty */
	assert(0 == QueueSize(src));
	assert(NULL == QueuePeek(src));
	
	/* destroy 2 lists  */
	QueueDestroy(dest);
	QueueDestroy(src);
}
