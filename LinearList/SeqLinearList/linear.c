#include"linear.h"

/***初始化顺序表***/
int InitList(SeqList *list)
{
	list->elems = (datatype*)malloc(LIST_MAXSIZE*sizeof(datatype));
	if(!list->elems) return ERR_NOMEMORY;
	
	list->length = 0;
	list->size = LIST_MAXSIZE;	
	return 0;
}

/***判断顺序表是否为空***/
int ListEmpty(SeqList *list)
{
	if(!list) return ERR_INVALIDPARAM;
	return (list->length == 0);
}

/***求顺序表的元素个数***/
int ListLength(SeqList *list)
{
	if(!list) return ERR_INVALIDPARAM;
	return list->length;
}

/***遍历一个顺序表***/
int TraverseList(SeqList *list)
{
	int k;
	if(!list) return ERR_INVALIDPARAM;
	for(k=0;k<list->length;k++)
		printf("%d\t",list->elems[k]);
	return k;
}

/***在顺序表中插入一个元素***/
int ListInsert(SeqList *list,int i,datatype e)
{
	int j=i-1,k;
	if(!list) return ERR_INVALIDPARAM;
	
	if(list->length >= LIST_MAXSIZE) return ERR_OVERFLOW;
	if(i<1||i>list->length+1) return ERR_ILLEGALINDEX;
	
	for(k=list->length-1;k>=j;k--)
		list->elems[k+1] = list->elems[k];
	
	list->elems[j] = e;
	list->length++;
	return list->length;
}

/***从线性表中删除一个元素***/
int ListDelete(SeqList *list,int i)
{
	int j=i-1,k;
	if(!list) return ERR_INVALIDPARAM;
	
	if(list->length == 0) return 0;
	if(i<1||i>list->length) return ERR_ILLEGALINDEX;
	
	for(k=j+1;k<list->length;k++)
		list->elems[k-1] = list->elems[k];
	
	list->length--;
	return list->length;
}

/***在线性表中查找某一元素***/
int ListFind(SeqList *list,datatype e)
{
	int k;
	if(!list) return ERR_INVALIDPARAM;
	if(list->length == 0) return 0;
	
	for (k=0;k<list->length;k++)
		if(list->elems[k] == e) break;
	if (k<list->length) return k+1;
	return 0;
}

/***获取指定位置上的元素***/
datatype GetElem(SeqList *list,int i)
{
	if(!list) return ERR_INVALIDPARAM;
	if(i<1||i>list->length) return ERR_ILLEGALINDEX;
	
	return list->elems[i-1];
}
