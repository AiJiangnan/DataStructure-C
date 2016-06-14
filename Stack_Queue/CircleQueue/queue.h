#ifndef __queue_h__
#define __queue_h__

#include<stdio.h>
#include<stdlib.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果
#define ERR_UNDERFLOW -6


#define QUEUE_MAXSIZE 50

typedef struct
{
	char name[32];
} datatype;
typedef struct
{
	datatype* elems;
	int front;
	int rear;
	int tag;
} CircleQueue;

extern int InitQueue(CircleQueue *queue);
extern int QueueEmpty(CircleQueue *queue);
extern int QueueLength(CircleQueue *queue);
extern int EnQueue(CircleQueue *queue,datatype e);
extern int DeQueue(CircleQueue *queue,datatype *e);

#endif
