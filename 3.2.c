#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define size 50
int stack[size];
int top=-1;
void push(char ele)
{	if(top==size-1)
		printf("Stack overflow");
	else
		stack[++top]=ele;
}
char pop()
{	if(top==-1)
		printf("Stack Underflow");
	else
		return (stack[top--]);
}
int prec(char ele)
{	if(ele=='+'||ele=='-')
		return 1;
	else if(ele=='*'||ele=='%'||ele=='/')
		return 2;
	else if(ele=='^')
		return 3;
	else
		return 0;
}
void infixtopostfix(char exp[size])
{	int i=0;
	while(exp[i]!='\0')
	{	if(exp[i]=='(')
			push(exp[i]);
		else if(isalnum(exp[i]))
			printf("%c",exp[i]);
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%'||exp[i]=='^')
		{	while(prec(exp[i])<=prec(stack[top]) && top!=-1)
				printf("%c",pop());
			push(exp[i]);
		}
		else if(exp[i]==')')
		{	while(stack[top]!='(')
				printf("%c",pop());
			pop();
		}
		i++;
	}
	while(top!=-1)
		printf("%c",pop());
}
void postfixevaluation(char exp[size])
{	int i=0;
	int val;
	while(exp[i]!='\0')
	{	if(isalnum(exp[i]))
			push(exp[i]-'0');
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%'||exp[i]=='^')
		{	int a=pop();
			int b=pop();
			switch(exp[i])
			{	case '+':val=a+b;
					break;
				case '-':val=b-a;
					break;
				case '*':val=a*b;
					break;
				case '/':val=b/a;
					break;
				case '%':val=b%a;
					break;
				case '^':val=b^a;
					break;
				default:printf("Wrong operator");
			}
			push(val);
		}
		i++;
	}
	printf("%d",pop());
}
void main()
{	int ch;
	char exp[size];
	printf("Enter your expression:");
	scanf("%s",exp);
	printf("1.Infix to postfix\n2.Postfix evaluation\nEnter your option:");
	scanf("%d",&ch);
	switch(ch)
	{	case 1:infixtopostfix(exp);
		break;
		case 2:postfixevaluation(exp);
		break;
		default:printf("Wrong choice entered");
	}
}