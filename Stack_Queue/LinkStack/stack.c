#include"stack.h"

/***初始化链栈***/
int InitStack(LinkStack *top)
{
	StackNode *t=NULL;
	if(!top) return ERR_INVALIDPARAM;
	
	t=(StackNode*)malloc(sizeof(StackNode));
	if(!t) return ERR_NOMEMORY;
	
	t->next=NULL;
	(*top)=t;
	return 0;
}

/***栈是否为空***/
int StackEmpty(LinkStack top)
{
	if(!top) return ERR_INVALIDPARAM;
	return (top->next==NULL);
}

/***获取栈顶元素***/
int GetTop(LinkStack top,datatype *e)
{
	if(!top) return ERR_INVALIDPARAM;
	if(!top->next) return ERR_EMPTYRESULT;
	
	*e=top->next->data;
	return 0;
}

/***将元素入栈***/
int Push(LinkStack top,datatype e)
{
	StackNode *p=NULL;
	if(!top) return ERR_INVALIDPARAM;
	
	p=(StackNode*)malloc(sizeof(StackNode));
	if(!p) return ERR_NOMEMORY;
	
	p->data=e;
	p->next=top->next;
	top->next=p;
	return 0;
}

/***将元素出栈***/
int Pop(LinkStack top,datatype *e)
{
	StackNode *p=NULL;
	if(!top) return ERR_INVALIDPARAM;
	if(!top->next) return ERR_EMPTYRESULT;
	
	p=top->next;
	top->next=p->next;
	*e=p->data;
	free(p);
	return 0;
}

/***销毁链栈***/
int DestroyStack(LinkStack top)
{
	StackNode *p=NULL;
	if(!top) return ERR_INVALIDPARAM;
	
	while(top)
	{
		p=top;
		top=top->next;
		free(p);
	}
	return 0;
}
