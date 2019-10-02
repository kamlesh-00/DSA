#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node
{	int data;
	struct node *left;
	struct node *right;
	struct node *prev;
}

struct node *root=NULL;

void inorder(struct node *root)
{	if(root!=NULL)
	{	inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

struct node* et(struct node *root, char postfix[50])
{	len=strlen(postfix);
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	for(int i=len-1; i>=0; i++)
	{	temp->data=a[i];
		temp->left=temp->right=NULL;
		if(root==NULL)
		{	root=temp;
			par=root;
		}
		else
		{	if(a[i]=='+'||a[i]=='%'||a[i]=='-'||a[i]=='/'||a[i]=='*')
			{	if(par->right==NULL)
				{	par->right=temp;
					
				}
			}
		}
	}
}

void infixtopostfix(char exp[size])
{	int i=0;
	postfix[50];
	k=0;
	while(exp[i]!='\0')
	{	if(exp[i]=='(')
			push(exp[i]);
		else if(isalnum(exp[i]))
		{	printf("%c",exp[i]);
			postfix[k]=exp[i];
			k++;
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%'||exp[i]=='^')
		{	while(prec(exp[i])<=prec(stack[top]) && top!=-1)
			{	printf("%c",pop());
				postfix[k]=exp[i];
				k++;
			}
			push(exp[i]);
		}
		else if(exp[i]==')')
		{	while(stack[top]!='(')
			{	printf("%c",pop());
				postfix[k]=exp[i];
				k++;
			}
			pop();
		}
		i++;
	}
	while(top!=-1)
	{	printf("%c",pop());
		postfix[k]=exp[i];
		k++;
	}
	et(root,postfix)
}





void main()
{	printf("Enter expression");
	char exp[50];
	scanf("%s",exp);
	infixtopostfix(exp);
}