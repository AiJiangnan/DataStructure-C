#include"queue.h"

int main()
{
	int i=0,length=0;
	datatype e,docs[4]=
	{
		{"第1章  绪论.doc"},
		{"第2章  线性表.doc"},
		{"第3章  栈和队列.doc"},
		{"第4章  串.doc"},
	};
	
	CircleQueue queue;
	InitQueue(&queue);
	
	printf(">待打印的文档:\n");
	for(i=0;i<4;i++)
		printf("\t%d:%s\n",i+1,docs[i].name);
		
	printf(">将文档入队:\n");
	for(i=0;i<4;i++)
	{
		EnQueue(&queue,docs[i]);
		length=QueueLength(&queue);
		printf("\t文档%d已入队，队列长度为:%d\n",i+1,length);
	}
	
	printf(">准备打印文档:\n");
	for(i=0;i<4;i++)
	{
		DeQueue(&queue,&e);
		printf("\t打印文档:%s\n",e.name);
	}
	
	return 0;
}
