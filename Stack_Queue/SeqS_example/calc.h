#ifndef __calc_h__
#define __calc_h__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

extern int ComparePriority(char op1,char op2);
extern int InfixToSuffix(char *infix,char *suffix);
extern int Operate(int a,char op,int b);
extern int CalculateExpressionBySuffix(char *suffix);

#endif
