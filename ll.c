#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
struct node
{	int data;
	struct node *next;
};
struct node *head=NULL;

void insertb(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	if(head==NULL)
	{	head=temp;
	}
	else
	{	temp->next=head;
		head=temp;
	}
}

void inserte(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	if(head==NULL)
	{	head=temp;
	}
	else
	{	struct node *p;
		p=head;
		while(p->next!=NULL)
		{	p=p->next;
		}
		p->next=temp;
	}
}

void inserts(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
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
		{	p=p->next;
		}
		p2=p->next;
		p->next=temp;
		temp->next=p2;
	}
}

void traverse()
{	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{	printf("%d-->",temp->data);
		temp=temp->next;
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
		while(temp->next!=NULL)
		{	p=temp;
			temp=temp->next;
		}
		p->next=NULL;
		free(temp);
	}
}

void deleteb()
{	struct node *temp,*p;
	temp=head;
	if(head==NULL)
		printf("Linked list is empty");
	else
	{	head=temp->next;
		temp->next=NULL;
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
			p=p->next;
		}
		q->next=p->next;
		p->next=NULL;
		free(p);
	}
}

void main()
{	printf("****Single Linked List****");
	int ch=0,dat;
	while(ch!=8)
	{	printf("Enter 1. Insert at begin,\n2. Insert at end,\n3. Insert at specific position,\n4. Delete end,\n5. Delete begin,\n6. Delete at specific position,\n7. Traverse\n8. Exit\nEnter your option:");
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
			case 7:traverse();
				break;
			case 8:printf("Exitting...");
				break;
			default:printf("Wrong input");
		}
	}
}


