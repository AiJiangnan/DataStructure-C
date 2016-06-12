#include"stack.h"
#include"calc.h"


int main()
{
	char infix[80]={0};
	char suffix[80]={0};
	int result=0;
	
	printf("请输入算术表达式:");
	scanf("%s",infix);
	
	InfixToSuffix(infix,suffix);
	printf("转换为后缀表达式:%s\n",suffix);
	
	result = CalculateExpressionBySuffix(suffix);
	printf("表达式的计算结果:%d\n",result);
	return 0;
}
