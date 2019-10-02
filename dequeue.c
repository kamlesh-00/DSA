#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define size 10

int arr[size];
int f=-1,r=-1;

void insertf(int ele)
{	if(f==-1 && r==-1)
	{	f=r=0;
		arr[f]=ele;
	}
	else if((f-1+size)%size==r)
		printf("Queue is full");
	else
	{	f=(f-1+size)%size;
		arr[f]=ele;
	}
}

void insertr(int ele)
{	if(f==-1 && r==-1)
	{	f=r=0;
		arr[r]=ele;
	}
	else if((f-1+size)%size==r)
		printf("Queue is full");
	else
	{	r=(r+1)%size;
		arr[r]=ele;
	}
}

int deletef()
{	int x;
	if (f==r==-1)
		printf("Queue is empty");
	else if(r==(f+1)%size)
	{	f=r=-1;
	}
	else
	{	x=arr[f];
		f=(f+1)%size;
		return x;
	}
}

int deleter()
{	int x;
	if (f==r==-1)
	{	printf("Queue is empty");
	}
	else if(f==r && f!=-1)
	{	f=r=-1;
	}
	else
	{	x=arr[r];
		r=(r-1+size)%size;
		return x;
	}
}

void display()
{	int ptr=f;
	if(r==f==-1)
		printf("Queue is empty");
	else
	{	while(ptr!=r)
		{	printf("%d\t",arr[ptr]);
			ptr=(ptr+1)%size;
		}
		printf("%d",arr[ptr]);
	}
}
void main()
{	int ch=0,x;
	while(ch!=6)
	{	printf("Enter 1.To insert at front end\n2.To insert at rear end\n3.To remove from front end\n4.To remove from rear end\n5.To display\n6.To exit\nEnter your option:");
		scanf("%d",&ch);
		switch(ch)
		{	case 1:printf("enter element:");
				scanf("%d",&x);
				insertf(x);
				break;
			case 2:printf("enter element:");
				scanf("%d",&x);
				insertr(x);
				break;
			case 3:printf("Deleted element: %d",deletef());
				break;
			case 4:printf("Deleted element: %d",deleter());
				break;
			case 5:display();
				break;
			case 6:printf("exitting....");
				break;
			default:printf("Wrong choice....");
		}
	}
}