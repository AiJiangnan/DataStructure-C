#include"calc.h"

/***比较两运算符的优先关系***/
int ComparePriority(char op1,char op2)
{
	int priority1=0,priority2=0;
	
	if(op1=='+'||op1=='-') priority1 = 1;
	else if(op1=='*'||op1=='/') priority1 = 2;
	
	if(op2=='+'||op2=='-') priority2 = 1;
	else if(op2=='*'||op2=='/') priority2 = 2;
	
	return (priority1-priority2);
}

/***中缀表达式转换为后缀表达式***/
int InfixToSuffix(char *infix,char *suffix)
{
	char c,*pInfix = infix,*pSuffix = suffix;
	int t = 0;
	
	SeqStack optr;
	InitStack(&optr);
	
	while(*pInfix != '\0')
	{
		c = *pInfix;
		if(c>='0'&&c<='9')
		{
			*pSuffix = c;
			pSuffix++;
		}
		else if(c=='(')
		{
			Push(&optr,c);
		}
		else if(c==')')
		{
			Peek(&optr,&t);
			while(t!='(')
			{
				*pSuffix=t;
				pSuffix++;
				Pop(&optr,&t);
				Peek(&optr,&t);
			}
			Pop(&optr,&t);
		}
		else
		{
			if(StackEmpty(&optr))
				Push(&optr,c);
			else
			{
				Peek(&optr,&t);
				if(ComparePriority(c,t)>0)
					Push(&optr,c);
				else
				{
					while(!StackEmpty(&optr)&&ComparePriority(c,t)<=0)
					{
						*pSuffix=t;
						pSuffix++;
						Pop(&optr,&t);
						Peek(&optr,&t);
					}
					Push(&optr,c);
				}
			}
		}
		pInfix++;
	}
	while(!StackEmpty(&optr))
	{
		Pop(&optr,&t);
		*pSuffix=t;
		pSuffix++;
	}
	free(optr.base);
	return 0;
}

/***计算两个操作数的值***/
int Operate(int a,char op,int b)
{
	switch(op)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/(b==0?1:b);
	}
	return 0;
}

/***计算后缀表达式的值***/
int CalculateExpressionBySuffix(char *suffix)
{
	char c;
	int a=0,b=0,s=0;
	const char *pSuffix = suffix;
	
	SeqStack opnd;
	InitStack(&opnd);
	
	while(pSuffix != '\0')
	{
		c=*pSuffix;
		if(c>='0'&&c<='9')
			Push(&opnd,c-48);
		else
		{
			Pop(&opnd,&b);
			Pop(&opnd,&a);
			s=Operate(a,c,b);
			Push(&opnd,s);
		}
		pSuffix++;
	}
	Pop(&opnd,&s);
	free(opnd.base);
	return s;
}
