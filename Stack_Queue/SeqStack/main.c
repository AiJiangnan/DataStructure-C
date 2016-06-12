#include"stack.h"

int main()
{
	int cho;
	datatype e;
	SeqStack *stack;
	InitStack(stack);
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Gettop\n4.Clear\n0.Exit\n");
		printf("Please input(0-4):");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:
				printf("Input data:");
				scanf("%d",&e);
				Push(stack,e);
				break;
			case 2:
				Pop(stack,&e);
				printf("%d\n",e);
				break;
			case 3:
				GetTop(stack,&e);
				printf("%d\n",e);
				break;
			case 4:
				ClearStack(stack);
				break;
			case 0:
				exit(1);
			default:
				printf("Input error!\n");
				break;
		}
	}
	return 0;
}
