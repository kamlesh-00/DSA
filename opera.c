#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

struct node
{	int data;
	struct node *next;
};

struct node *head1=NULL,*head2=NULL;

void traverse(struct node *head)
{	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{	printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

struct node* inserte(int ele,struct node *head)
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
	return head;
}

void copy(struct node *h1,struct node *h2)
{	printf("Linked list 1 is \n");
	traverse(h1);
	h2=h1;
	printf("After copying linked list 1 to 2. Linked list 2 is \n");
	traverse(h2);
}

void concat(struct node *h1, struct node *h2)
{	struct node *temp;
	temp=h1;
	while(temp->next!=NULL)
	{	temp=temp->next;
	}
	temp->next=h2;
	printf("New linked list 1 is \n");
	traverse(h1);
}

void split(struct node *h1)
{	printf("Linked list 1 is \n");
	traverse(h1);
	int loc;
	struct node *h2=NULL;
	printf("Enter end value for new linked list:");
	scanf("%d",&loc);
	struct node *p=h1;
	while(p->data!=loc)
		p=p->next;
	struct node *q=p->next;
	p->next=NULL;
	h2=q;
	printf("New linked list 1 ");
	traverse(h1);
	printf("New linked list 2 ");
	traverse(h2);
}

void reverse(struct node *h1)
{	struct node *temp=h1,*next=NULL,*prev=NULL;
	while(temp!=NULL)
	{	next=temp->next;
		temp->next=prev;
		prev=temp;
		temp=next;
	}
	h1=prev;
	traverse(h1);
}

void count(struct node *h1)
{	struct node *temp=h1;
	int count=1;
	while(temp->next!=NULL)
	{	count++;
		temp=temp->next;
	}
	printf("No. of nodes in the linked list is %d\n",count);
}

void main()
{	int ch=0;
	printf("****OPERATIONS ON LINKED LISTS****\n");
	while(ch!=6)
	{	printf("Enter 1.To copy linked list 1 to list 2\n2.To concatenate both lists\n3.Split the linked list 1\n4.Reverse linked list 1\n5.Count no. of nodes\n6.Exit\nEnter your options:");
		scanf("%d",&ch);
		printf("Start entering data for linked list 1 and to stop enter -11:");
		int a[100],b[100];
		head1=head2=NULL;
		for(int i=0; a[i]!=-11;i++)
		{	scanf("%d",&a[i]);
			if(a[i]==-11)
				break;
		head1=inserte(a[i],head1);
		}
		switch(ch)
		{	case 1:copy(head1,head2);
				break;
			case 2:printf("Start entering data for linked list 2 and to stop enter -11:");
				for(int i=0; b[i]!=-11;i++)
				{	scanf("%d",&b[i]);
					if(b[i]==-11)
						break;
					head2=inserte(b[i],head2);
				}
				concat(head1,head2);
				break;
			case 3:split(head1);
				break;
			case 4:reverse(head1);
				break;
			case 5:count(head1);
				break;
			case 6:exit(1);
				break;
			default:printf("Wrong choice.Enter again!!");
				break;
		}
	for(int j=0;j<100;j++)
	{	a[j]=0;
		b[j]=0;
	}
	}
}