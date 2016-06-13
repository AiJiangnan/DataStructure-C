#include"stack.h"

int main()
{
	int steps=0;
	position entry,exit;
	
	int maze[MAZE_MAXSIZE][MAZE_MAXSIZE]=
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,1,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,1,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	
	printf("迷宫的结构图如下:\n");
	PrintMaze(maze,10,10);
	
	printf("请输入入口的行和列(row,col):");
	scanf("%d %d",&entry.x,&entry.y);
	
	printf("请输入出口的行和列(row,col):");
	scanf("%d %d",&exit.x,&exit.y);
	
	steps = MazePath(maze,entry,exit);
	if(steps==0) printf("迷宫没有从入口到达出口的路径！\n");
	else printf("从入口(%d,%d)到出口(%d,%d)经%2d步可达.\n",entry.x,entry.y,exit.x,exit.y,steps);
	PrintMaze(maze,10,10);
	return 0;
}
