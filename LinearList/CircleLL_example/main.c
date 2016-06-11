#include"linear.h"

/***约瑟夫问题***/
void Josephus(CircleList head,int m)
{
	int k=1;
	ListNode *p,*s;
	
	while(ListLength(head)>1)
	{
		s=head,p=s->next;
		while(p!=head)
		{
			p->data.number = k;
			printf("-->%s:%d",p->data.name,p->data.number);
			if(p->data.number==m)
			{
				printf("\t\t(%s:%d)出列！\n",p->data.name,p->data.number);
				s->next = p->next;
				free(p),p=s;
			}
			k=(k==m)?1:k+1;
			s=p,p=p->next;
		}
	}
	printf("\n> 最后剩余的为:");
	TraverseList(head);
}

int main()
{
	int i,k=0;
	datatype e;
	
	CircleList josephus;
	InitList(&josephus);
	
	printf("                 约瑟夫问题                 \n");
	printf("    编号为1,2,……，n的n个人围成一个圈，从第一个\n");
	printf("开始依次报数，第M个将被踢除，下一个人重新开始报\n");
	printf("数。循环该过程，直到最后只剩一个人。\n");
	printf("\n");
	
	printf(">输入将要参与的人数:");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		memset(e.name,0,8*sizeof(char));
		e.number = i+1;
		e.name[0] = 'A'+i;
		ListInsert(josephus,i+1,e);
	}
	
	printf(">参与的%d人及它们的编号:\n",ListLength(josephus));
	TraverseList(josephus);
	
	printf(">输入将被踢除的报数m:");
	scanf("%d",&k);
	
	printf(">开始报数，报数为%d的将被踢除:\n",k);
	Josephus(josephus,k);
	
	DestroyList(josephus);
	return 1;
}





























