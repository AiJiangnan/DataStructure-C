#include"queue.h"

/***初始化循环队列***/
int InitQueue(CircleQueue *queue)
{
	if(!queue) return ERR_INVALIDPARAM;
	
	queue->elems=(datatype*)malloc(QUEUE_MAXSIZE*sizeof(datatype));
	if(!queue->elems) return ERR_NOMEMORY;
	
	queue->front=0;
	queue->rear=0;
	queue->tag=0;
	return 0;
}

/***判断队列是否为空***/
int QueueEmpty(CircleQueue *queue)
{
	if(!queue) return ERR_INVALIDPARAM;
	return (queue->tag==0&&queue->rear==queue->front);
}

/***循环队列的长度***/
int QueueLength(CircleQueue *queue)
{
	if(!queue) return ERR_INVALIDPARAM;
	
	if(queue->tag&&queue->rear==queue->front) return QUEUE_MAXSIZE;
	return (queue->rear-queue->front+QUEUE_MAXSIZE)%QUEUE_MAXSIZE;
}

/***将元素入队***/
int EnQueue(CircleQueue *queue,datatype e)
{
	if(!queue) return ERR_INVALIDPARAM;
	if(queue->tag&&queue->rear==queue->front)
		return ERR_UNDERFLOW;
	
	queue->elems[queue->rear]=e;
	queue->rear=(queue->rear+1)%QUEUE_MAXSIZE;
	queue->tag=1;
	return 0;
}

/***将元素出队***/
int DeQueue(CircleQueue *queue,datatype *e)
{
	if(!queue) return ERR_INVALIDPARAM;
	if(queue->tag&&queue->rear==queue->front)
		return ERR_UNDERFLOW;
		
	*e=queue->elems[queue->front];
	queue->front=(queue->front+1)%QUEUE_MAXSIZE;
	queue->tag=0;
	return 0;
}















