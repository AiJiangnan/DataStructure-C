#ifndef __linear_h__
#define __linear_h__

#include <stdio.h>
#include <stdlib.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果

typedef int datatype;

typedef struct node
{
	struct node* prior;
	datatype data;
	struct node* next;
} DListNode,*DoubleList;

extern int InitList(DoubleList *head);
extern int ListEmpty(DoubleList head);
extern int ListLength(DoubleList head);
extern int TraverseList(DoubleList head);
extern int ListInsert(DoubleList head,int i,datatype e);
extern int ListDelete(DoubleList head,int i);
extern int ListFind(DoubleList head,datatype e);
extern DoubleList ListFindElem(DoubleList head,datatype e);
extern int GetElem(DoubleList head,int i,datatype *e);
extern int DestroyList(DoubleList head);
#endif
