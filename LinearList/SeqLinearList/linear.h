#ifndef __linear_h__
#define __linear_h__
#include<stdio.h>
#include<stdlib.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果

#define LIST_MAXSIZE 100				//顺序表的最大元素个数

typedef int datatype;					//顺序表元素的类型
typedef struct{
	datatype* elems;					//存储元素的起始地址
	int length;							//顺序表的长度
	int size;							//顺序表的大小
} SeqList;


extern int InitList(SeqList *list);
extern int ListEmpty(SeqList *list);
extern int ListLength(SeqList *list);
extern int TraverseList(SeqList *list);
extern int ListInsert(SeqList *list,int i,datatype e);
extern int ListDelete(SeqList *list,int i);
extern int ListFind(SeqList *list,datatype e);
extern datatype GetElem(SeqList *list,int i);
#endif
