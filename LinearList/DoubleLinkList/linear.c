#include"linear.h"

/***初始化双向链表***/
int InitList(DoubleList *head)
{
	DListNode *h=NULL;
	if(!head) return ERR_INVALIDPARAM;
	
	h=(DListNode*)malloc(sizeof(DListNode));
	if(!h) return ERR_NOMEMORY;
	
	h->prior = NULL;
	h->next = NULL;
	(*head) = h;
	return 0;
}

/***判断双向链表是否为空***/
int ListEmpty(DoubleList head)
{
	if(!head) return ERR_INVALIDPARAM;
	return (head->next == NULL);
}

/***求双向链表的长度***/
int ListLength(DoubleList head)
{
	int k=0;
	DListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p;p=p->next) k++;
	return k;
}

/***遍历双向链表***/
int TraverseList(DoubleList head)
{
	DListNode *p=NULL;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p;p=p->next)
		printf("%3d",p->data);
	printf("\n");
	return 0;
}

/***向双向链表插入新元素***/
int ListInsert(DoubleList head,int i,datatype e)
{
	int k = 1;
	DListNode *p,*s;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head;p&&k<i;p=p->next) k++;
	if(!p||k>i) return ERR_ILLEGALINDEX;
	
	s=(DListNode*)malloc(sizeof(DListNode));
	if(!s) return ERR_NOMEMORY;
	
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 0;
}

/***从双向链表中删除元素***/
int ListDelete(DoubleList head,int i)
{
	int k = 1;
	DListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p&&k<i;p=p->next) k++;
	if(!p||k>i) return ERR_ILLEGALINDEX;
	
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 0;
}

/***在双向链表中查找元素的位置***/
int ListFind(DoubleList head,datatype e)
{
	int k = 0;
	DListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p;p=p->next,k++)
		if(p->data == e) return k+1;
	return 0;
}

/***在双向链表中查找元素***/
DoubleList ListFindElem(DoubleList head,datatype e)
{
	DListNode *p;
	if(!head) return NULL;
	
	for(p=head->next;p;p=p->next)
		if(p->data == e) return p;
	return NULL;
}

/***获取某个位置上的元素***/
int GetElem(DoubleList head,int i,datatype *e)
{
	int k=1;
	DListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	for(p=head->next;p&&k<i;p=p->next) k++;
	if(!p||k<i) return ERR_ILLEGALINDEX;
	
	*e = p->data;
	return 0;
}

/***销毁双向链表***/
int DestroyList(DoubleList head)
{
	DListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	while(head)
	{
		p = head;
		head = head->next;
		free(p);
	}
	return 0;
}

