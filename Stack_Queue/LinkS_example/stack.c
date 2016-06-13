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

/***当前位置是否可以通过***/
int CanPass(int map[][MAZE_MAXSIZE],position pos)
{
	return (map[pos.x][pos.y]==0);
}

/***用mark标记迷宫中的pos位置***/
int MarkMap(int map[][MAZE_MAXSIZE],position pos,int mark)
{
	map[pos.x][pos.y]=mark;
	return 0;
}

/***根据当前位置及方向，求得下一位置***/
int NextPos(int map[][MAZE_MAXSIZE],int dir,position *pos)
{
	position d[4] = {{0,1},{1,0},{0,-1},{-1,0}};
	(*pos).x += d[dir].x;
	(*pos).y += d[dir].y;
	return 0;
}

/***计算迷宫入口到出口的路径***/
int MazePath(int map[][MAZE_MAXSIZE],position entry,position exit)
{
	int location=1;
	position position = entry;
	datatype e;
	LinkStack S;
	InitStack(&S);
	
	do
	{
		if(CanPass(map,position))
		{
			MarkMap(map,position,location);
			e.passnum=location;
			e.location=position;
			e.direction=0;
			Push(S,e);
			
			if(position.x==exit.x&&position.y==exit.y)
				return location;
				
			location++;
			NextPos(map,e.direction,&position);
		}
		else
		{
			if(!StackEmpty(S))
			{
				Pop(S,&e);
				location--;
				
				while(e.direction==3&&!StackEmpty(S))
				{
					MarkMap(map,e.location,0);
					Pop(S,&e);
					location--;
				}
				
				if(e.direction<3)
				{
					e.direction++;
					Push(S,e);
					location++;
					position=e.location;
					NextPos(map,e.direction,&position);
				}
			}
		}
	}while(!StackEmpty(S));
	DestroyStack(S);
	return 0;
}

/***打印迷宫***/
void PrintMaze(int map[][MAZE_MAXSIZE],int row,int col)
{
	int i,j;
	
	printf("\n  ");
	for(i=0;i<row;i++) printf("%3d",i);
	printf("\n");
	
	for(i=0;i<row;i++)
	{
		printf("%3d",i);
		for(j=0;j<col;j++)
		{
			if(map[i][j]==0) printf("   ");
			else if(map[i][j]==1) printf(" # ");
			else printf("%3d",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
