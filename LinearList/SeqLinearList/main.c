/*顺序线性表*/
#include"linear.h"

int main()
{
	int cho,i;
	datatype e;
	SeqList *list;
	InitList(list);
	while(1)
	{
		printf(">>>1.List\n>>>2.Length\n>>>3.Insert\n>>>4.Delete\n>>>5.Find\n>>>6.GetElem\n>>>0.Exit\n");
		printf("Please input(0-3):");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:
				TraverseList(list);
				printf("\n");
				break;
			case 2:
				printf("%d\n",ListLength(list));
				break;
			case 3:
				printf("Input No:");
				scanf("%d",&i);
				printf("Input datatype:");
				scanf("%d",&e);
				ListInsert(list,i,e);
				break;
			case 4:
				printf("Input No:");
				scanf("%d",&i);
				ListDelete(list,i);
				break;
			case 5:
				printf("Input datatype:");
				scanf("%d",&e);
				printf("%d\n",ListFind(list,e));
				break;
			case 6:
				printf("Input No:");
				scanf("%d",&i);
				printf("%d\n",GetElem(list,i));
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("Input Error!\n");
				break;
		}
	}
	return 0;
}
