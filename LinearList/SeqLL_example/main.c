#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ERR_NOMEMORY -1
#define ERR_INVALIDPARAM -2
#define ERR_OVERFLOW -3
#define ERR_ILLEGALINDEX -4
#define ERR_EMPTYRESULT -5

#define LIST_MAXSIZE 54

typedef struct
{
	char type;
	int face;
} datatype;

typedef struct
{
	datatype* elems;
	int length;
	int size;
} SeqList;

/***初始化顺序表***/
int InitList(SeqList *list)
{
	list->elems = (datatype*)malloc(LIST_MAXSIZE*sizeof(datatype));
	if(!list->elems) return ERR_NOMEMORY;
	
	list->length = 0;
	list->size = LIST_MAXSIZE;	
	return 0;
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

/***显示一张扑克牌***/
void DispPokerCard(datatype card)
{
	switch(card.face)
	{
		case 11:
			printf("%c%c",card.type,'J');
			break;
		case 12:
			printf("%c%c",card.type,'Q');
			break;
		case 13:
			printf("%c%c",card.type,'K');
			break;
		case 14:
			printf("%c%c",card.type,'A');
			break;
		case 15:
			printf("%c%d",card.type,2);
			break;
		case 16:
		case 17:
		    printf("%c",card.type);
		default:
			printf("%c%d",card.type,card.face);
			break;
	}
}

/***遍历顺序表中所有元素***/
int TraverseList(SeqList *list)
{
	int i=0;
	if(!list) return ERR_INVALIDPARAM;
	
	for(i=0;i<list->length;i++)
		DispPokerCard(list->elems[i]);
	printf("\n");
	return i;
}

/***初始化54张扑克牌***/
void InitPokerCards(datatype cards[])
{
	int i = 0;
	for(i=0;i<13;i++)
	{
		cards[i].type='b';
		cards[i].face=i+3;
		
		cards[i+13].type='r';
		cards[i+13].face=i+3;
		
		cards[i+26].type='m';
		cards[i+26].face=i+3;
		
		cards[i+39].type='f';
		cards[i+39].face=i+3;
	}
	cards[52].type='s';
	cards[52].face=16;
	
	cards[53].type='b';
	cards[53].face=17;
}

int main(void)
{
	int i,k=0,exist[54];
	datatype cards[54],e;
	SeqList players[3];
	
	InitPokerCards(cards);
	for(i=0;i<54;i++)
		exist[i]=1;
	
	for(i=0;i<3;i++)
		InitList(&players[i]);
	
	printf("               扑克牌游戏              \n");
	printf(">54张扑克牌为:\n");
	for(i=0;i<54;i++)
	{
		DispPokerCard(cards[i]);
		if ((i+1)%13==0) printf("\n");
	}
	
	printf("\n>开始发牌，每人17张牌:\n");
	srand(time(0));
	for(i=0;i<17;i++)
	{
		k=rand()%54;
		while (exist[k]!=1) k=rand()%54;
		ListInsert(&players[0],1,cards[k]);
		exist[k]=0;
		
		while (exist[k]!=1) k=rand()%54;
		ListInsert(&players[1],1,cards[k]);
		exist[k]=0;
		
		while (exist[k]!=1) k=rand()%54;
		ListInsert(&players[2],1,cards[k]);
		exist[k]=0;
	}
	printf("	A的牌为:\n");TraverseList(&players[0]);
	printf("	B的牌为:\n");TraverseList(&players[1]);
	printf("	C的牌为:\n");TraverseList(&players[2]);
	
	printf(">A拿剩余的三张牌:\n");
	for(i=0;i<54;i++)
	{
		if (exist[i]==0) continue;
		DispPokerCard(cards[i]);
		ListInsert(&players[0],1,cards[i]);
	}
	printf("\nA的牌为:");TraverseList(&players[0]);
	
	ListDelete(&players[0],1);
	printf("\n    A剩余的牌为:");TraverseList(&players[0]);
	
	ListDelete(&players[1],3);
	printf("\n    B剩余的牌为:");TraverseList(&players[1]);
	
	ListDelete(&players[2],5);
	printf("\n    C剩余的牌为:");TraverseList(&players[2]);
	
	for(i=0;i<3;i++)
		free(players[i].elems);
	return 0;
}
