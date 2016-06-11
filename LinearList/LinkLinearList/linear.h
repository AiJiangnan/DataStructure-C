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
	datatype data;
	struct node* next;
} ListNode,*LinkList;

extern int InitList(LinkList *head);
extern int ListEmpty(LinkList head);
extern int ListLength(LinkList head);
extern int TraverseList(LinkList head);
extern int ListInsert(LinkList head,int i,datatype e);
extern int ListDelete(LinkList head,int i);
extern int ListFind(LinkList head,datatype e);
extern LinkList ListFindElem(LinkList head,datatype e);
extern int GetElem(LinkList head,int i,datatype *e);
extern int DestroyList(LinkList head);
#endif
