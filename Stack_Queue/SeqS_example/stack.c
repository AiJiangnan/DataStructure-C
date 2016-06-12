#include"stack.h"

/***初始化顺序栈***/
int InitStack(SeqStack *stack)
{
	if(!stack) return ERR_INVALIDPARAM;
	
	stack->base=(datatype*)malloc(STACK_MAXSIZE*sizeof(datatype));
	if(!stack->base) return ERR_NOMEMORY;
	
	stack->top=stack->base;
	stack->size=STACK_MAXSIZE;
	return 0;
}

/***栈是否为空***/
int StackEmpty(SeqStack *stack)
{
	if(!stack) return ERR_INVALIDPARAM;
	
	return (stack->top==stack->base);
}

/***清空栈***/
int ClearStack(SeqStack *stack)
{
	if(!stack) return ERR_INVALIDPARAM;
	stack->top=stack->base;
	return 0;
}

/***取得栈顶元素***/
int GetTop(SeqStack *stack,datatype *e)
{
	if(!stack) return ERR_INVALIDPARAM;
	if(stack->top==stack->base)	return ERR_EMPTYRESULT;
	
	*e = *(stack->top-1);
	return 0;
}

/***将元素入栈***/
int Push(SeqStack *stack,datatype e)
{
	if(!stack) return ERR_INVALIDPARAM;
	if(stack->top > stack->base + stack->size - 1)
		return ERR_OVERFLOW;
	
	*(stack->top) = e;
	stack->top++;
	return 0;
}

/***将元素出栈***/
int Pop(SeqStack *stack, datatype *e)
{
	if(!stack) return ERR_INVALIDPARAM;
	if(stack->top==stack->base)	return ERR_EMPTYRESULT;
	
	stack->top--;
	*e = *(stack->top);
	return 0;
}
