#ifndef __linear_h__
#define __linear_h__

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果

typedef struct
{
	char name[8];
	int number;
} datatype;

typedef struct node
{
	datatype data;
	struct node* next;
} ListNode,*CircleList;

extern int InitList(CircleList *head);
extern int ListEmpty(CircleList head);
extern int ListLength(CircleList head);
extern int TraverseList(CircleList head);
extern int ListInsert(CircleList head,int i,datatype e);
extern int ListDelete(CircleList head,int i);
extern int ListFind(CircleList head,datatype e);
extern CircleList ListFindElem(CircleList head,datatype e);
extern int GetElem(CircleList head,int i,datatype *e);
extern int DestroyList(CircleList head);
#endif
