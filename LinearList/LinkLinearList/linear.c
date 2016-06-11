#include"linear.h"

/***初始化单链表***/
int InitList(LinkList *head)
{
	ListNode *h;
	if(!head) return ERR_INVALIDPARAM;
	
	h=(ListNode*)malloc(sizeof(ListNode));
	if(!h) return ERR_NOMEMORY;
	
	h->next = NULL;
	(*head) = h;
	return 0;
}

/***判断单链表是否为空***/
int ListEmpty(LinkList head)
{
	if(!head) return ERR_INVALIDPARAM;
	return (head->next == NULL);
}

/***求单链表的长度***/
int ListLength(LinkList head)
{
	int k=0;
	ListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p;p=p->next) k++;
	return k;
}

/***遍历单链表***/
int TraverseList(LinkList head)
{
	ListNode *p=NULL;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p;p=p->next)
		printf("%3d",p->data);
	printf("\n");
	return 0;
}

/***向单链表插入新元素***/
int ListInsert(LinkList head,int i,datatype e)
{
	int k = 1;
	ListNode *p,*s;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head;p&&k<i;p=p->next) k++;
	if(!p||k>i) return ERR_ILLEGALINDEX;
	
	s=(ListNode*)malloc(sizeof(ListNode));
	if(!s) return ERR_NOMEMORY;
	
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;
}

/***从单链表中删除元素***/
int ListDelete(LinkList head,int i)
{
	int k = 1;
	ListNode *p,*q;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head;p&&k<i;p=p->next) k++;
	if(!p||k>i) return ERR_ILLEGALINDEX;
	
	q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}

/***在单链表中查找元素的位置***/
int ListFind(LinkList head,datatype e)
{
	int k = 0;
	ListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	
	for(p=head->next;p;p=p->next,k++)
		if(p->data == e) return k+1;
	return 0;
}

/***在单链表中查找元素***/
LinkList ListFindElem(LinkList head,datatype e)
{
	ListNode *p;
	if(!head) return NULL;
	
	for(p=head->next;p;p=p->next)
		if(p->data == e) return p;
	return NULL;
}

/***获取某个位置上的元素***/
int GetElem(LinkList head,int i,datatype *e)
{
	int k=1;
	ListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	for(p=head->next;p&&k<i;p=p->next) k++;
	if(!p||k<i) return ERR_ILLEGALINDEX;
	
	*e = p->data;
	return 0;
}

/***销毁单链表***/
int DestroyList(LinkList head)
{
	ListNode *p;
	if(!head) return ERR_INVALIDPARAM;
	while(head)
	{
		p = head;
		head = head->next;
		free(p);
	}
	return 0;
}

