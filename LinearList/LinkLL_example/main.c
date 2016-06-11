#include"linear.h"

int main()
{
	LinkList student;
	int cho,i,res;
	char choice='\0';
	datatype e;
	InitList(&student);
	while(1)
	{
		printf("\n          学生信息管理            \n");
		printf("1.建立 2.插入 3.查找 4.删除 5.输出 0.退出\n");
		printf(">请选择(0-5):");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:
				for(i=1,cho=0;choice!='n'&&choice!='N';i++)
				{
					printf(">请依次输入:<学号><姓名><性别><成绩>\n");
					scanf("%s %s %c %d",e.num,e.name,&(e.sex),&(e.score));
					getchar();
					res = ListInsert(student,i,e);
					if(res==ERR_OVERFLOW) printf(">错误：单链表已满！\n");
					if(res==ERR_ILLEGALINDEX) printf(">错误：插入位置不正确！\n");
					
					printf(">是否继续添加学生信息(Y/N):\n");
					scanf("%c",&choice);
				}
				break;
			case 2:
				printf(">请依次输入:<学号><姓名><性别><成绩>\n");
				scanf("%s %s %c %d",e.num,e.name,&(e.sex),&(e.score));
				getchar();
				printf("请输入插入的位置:\n");
				i=getchar()-48;
				
				res = ListInsert(student,i,e);
				if(res==ERR_OVERFLOW) printf(">错误：单链表已满！\n");
				if(res==ERR_ILLEGALINDEX) printf(">错误：插入位置不正确！\n");
				break;
			case 3:
				printf("请输入要查找学生的学号:\n");
				scanf("%s",e.num);
				if((i=ListFind(student,e))<=0)
					printf(">没有找到学号为%s的学生信息！\n",e.num);
				else if(!GetElem(student,i,&e))
				{
					printf("学号\t姓名\t性别\t成绩\n");
					printf("%s\t%s\t%c\t%d\n",e.num,e.name,e.sex,e.score);
				}
				break;
			case 4:
				printf("请输入要删除学生的学号:\n");
				scanf("%s",e.num);
				if((i=ListFind(student,e))<=0)
					printf(">没有找到学号为%s的学生信息！\n",e.num);
				else if(ListDelete(student,i)<0)
				{
					printf("错误:删除学号为%s的学生信息失败！\n",e.num);
				}
				break;
			case 5:
				i = ListLength(student);
				printf(">所有学生信息(共有%d条信息):\n",i);
				TraverseList(student);
				break;
			case 0:
				printf("欢迎再次访问学生管理系统！\n");
				DestroyList(student);
				exit(1);
				break;
			default:
				printf("选择错误，请重选!\n");
				break;
		}
	}
	DestroyList(student);
	return 0;
}
