#ifndef __stack_h__
#define __stack_h__

#include<stdio.h>
#include<stdlib.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node* next;
} StackNode,*LinkStack;

extern int InitStack(LinkStack *top);
extern int StackEmpty(LinkStack top);
extern int GetTop(LinkStack top,datatype *e);
extern int Push(LinkStack top,datatype e);
extern int Pop(LinkStack top,datatype *e);
extern int DestroyStack(LinkStack top);

#endif
