#ifndef __stack_h__
#define __stack_h__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERR_NOMEMORY -1					//内存分配错误
#define ERR_INVALIDPARAM -2				//输入参数无效
#define ERR_OVERFLOW -3					//溢出
#define ERR_ILLEGALINDEX -4				//非法的索引位置
#define ERR_EMPTYRESULT -5				//空的返回结果

#define MAZE_MAXSIZE 50


typedef struct
{
	int x,y;
} position;

typedef struct
{
	int passnum;
	position location;
	int direction;
} datatype;

typedef struct node
{
	datatype data;
	struct node* next;
} StackNode,*LinkStack;

extern int InitStack(LinkStack *top);
extern int StackEmpty(LinkStack top);
extern int GetTop(LinkStack top,datatype *e);
extern int Push(LinkStack top,datatype e);
extern int Pop(LinkStack top,datatype *e);
extern int DestroyStack(LinkStack top);
extern int CanPass(int map[][MAZE_MAXSIZE],position pos);
extern int MarkMap(int map[][MAZE_MAXSIZE],position pos,int mark);
extern int NextPos(int map[][MAZE_MAXSIZE],int dir,position *pos);
extern int MazePath(int map[][MAZE_MAXSIZE],position entry,position exit);
extern void PrintMaze(int map[][MAZE_MAXSIZE],int row,int col);

#endif
