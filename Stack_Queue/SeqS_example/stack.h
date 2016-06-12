#ifndef __stack_h__
#define __stack_h__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果

#define STACK_MAXSIZE 100

typedef int datatype;
typedef struct
{
	datatype* base;
	datatype* top;
	int size;
} SeqStack;

extern int InitStack(SeqStack *stack);
extern int StackEmpty(SeqStack *stack);
extern int ClearStack(SeqStack *stack);
extern int GetTop(SeqStack *stack,datatype *e);
extern int Push(SeqStack *stack,datatype e);
extern int Pop(SeqStack *stack, datatype *e);

#endif
