#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

struct node
{	int data;
	struct node *left;
	struct node *right;
};

struct node *head=NULL;

void insertb(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
	{	head=temp;
	}
	else
	{	temp->right=head;
		head->left=temp;
		head=temp;
	}
}

void inserte(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->right=NULL;
	temp->left=NULL;
	if(head==NULL)
	{	head=temp;
	}
	else
	{	struct node *p;
		p=head;
		while(p->right!=NULL)
		{	p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}

void inserts(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->right=NULL;
	temp->left=NULL;
	if(head==NULL)
	{	head=temp;
	}
	else
	{	printf("Enter data after which new node has to be added:");
		int loc;
		scanf("%d",&loc);
		struct node *p,*p2;
		p=head;
		while(p->data!=loc)
		{	p=p->right;
		}
		p2=p->right;
		p->right=temp;
		temp->left=p;
		temp->right=p2;
		p2->left=temp;
	}
}

void traversef()
{	struct node *temp;
	temp=head;
	while(temp->right!=NULL)
	{	printf("%d-->",temp->data);
		temp=temp->right;
	}
	printf("%d\n",temp->data);
}

void traverser()
{	struct node *temp;
	temp=head;
	while(temp->right!=NULL)
	{	temp=temp->right;
	}
	while(temp->left!=NULL)
	{	printf("%d-->",temp->data);
		temp=temp->left;
	}
	printf("%d\n",temp->data);
}

void deletee()
{	struct node *temp,*p;
	temp=head;
	if(head==NULL)
		printf("Linked list is empty");
	else
	{
		while(temp->right!=NULL)
		{	p=temp;
			temp=temp->right;
		}
		p->right=NULL;
		temp->left=NULL;
		free(temp);
	}
}

void deleteb()
{	struct node *temp,*p;
	temp=head;
	if(head==NULL)
		printf("Linked list is empty");
	else
	{	head=temp->right;
		temp->left=NULL;
		temp->right=NULL;
		free(temp);
	}
}

void deletes()
{	struct node *temp,*p;
	temp=head;
	if(head==NULL)
		printf("Linked list is empty");
	else
	{	printf("enter data to be deleted:");
		int loc;
		scanf("%d",&loc);
		struct node *p=head,*q;
		while(p->data!=loc)
		{	q=p;
			p=p->right;
		}
		q->left=p->left;
		q->right=p->right;
		p->right=NULL;
		p->left=NULL;
		free(p);
	}
}

void main()
{	printf("****Single Linked List****");
	int ch=0,dat;
	while(ch!=9)
	{	printf("Enter 1. Insert at begin,\n2. Insert at end,\n3. Insert at specific position,\n4. Delete end,\n5. Delete begin,\n6. Delete at specific position,\n7. Traverse forward\n8. Traverse backward\n9. Exit\nEnter your option:");
		scanf("%d",&ch);
		switch(ch)
		{	case 1:printf("Enter data:");
				scanf("%d",&dat);
				insertb(dat);
				break;
			case 2:printf("Enter data:");
				scanf("%d",&dat);
				inserte(dat);
				break;
			case 3:printf("Enter data:");
				scanf("%d",&dat);
				inserts(dat);
				break;
			case 4:deletee();
				break;
			case 5:deleteb();
				break;
			case 6:deletes();
				break;
			case 7:traversef();
				break;
			case 8:traverser();
				break;
			case 9:printf("Exitting...");
				break;
			default:printf("Wrong input");
		}
	}
}


