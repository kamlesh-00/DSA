#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

struct node
{	char ques[500];
	char ans1[200];
	char ans2[200];
	char ans3[200];
	char ans4[200];
	int correct;
	struct node *next;
};
struct node *head=NULL;

void insert(char *q,char *a1,char *a2,char *a3,char *a4,int ch)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	strcpy(temp->ques,q);
	strcpy(temp->ans1,a1);
	strcpy(temp->ans2,a2);
	strcpy(temp->ans3,a3);
	strcpy(temp->ans4,a4);
	temp->correct=ch;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{	struct node * p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}

void answer()
{	int corr,sum=0;
	struct node *p=head;
	while(p!=NULL)
	{	printf("Ques. %s\n\n\n",p->ques);
		printf("Opt1. %s\n",p->ans1);
		printf("Opt2. %s\n",p->ans2);
		printf("Opt3. %s\n",p->ans3);
		printf("Opt4. %s\n\n",p->ans4);
		printf("Enter your option:");
		scanf("%d",&corr);
		if(corr==p->correct)
		{	sum=sum+500000;
			printf("Entered option is correct and your total earning is Rs.%d\n\n\n\n\n\n\n\n",sum);
		}
		else
			printf("Wrong option, you lost Rs.500000\n\n\n\n\n\n\n\n");
		p=p->next;
	}
	printf("Total amount won is Rs. %d",sum);
}

void queslist()
{	char q1[500]="What is common in three different types of traversals (Inorder, Preorder and Postorder)?\0";
	char a11[200]="Root is visited before right sub-tree\0";
	char a21[200]="Left subtree is always visited before right subtree\0";
	char a31[200]="Root is visited after left subtree\0";
	char a41[200]="None of the above.\0";
	int ch1=2;
	insert(q1,a11,a21,a31,a41,ch1);
	char q2[500]="Which of the following points is/are true about Linked List data structure when it is compared with array??";
	char a12[200]="Array has better cache locality that can make them better in terms of performance";
	char a22[200]="It is easy to insert and delete elements in Linked list";
	char a32[200]="Random access is not allowed in a typical implementation of Linked lists";
	char a42[200]="All of the above.";
	int ch2=4;
	insert(q2,a12,a22,a32,a42,ch2);
	char q3[500]="Which one of the following is an application of Queue Data Structure?";
	char a13[200]="When a resource is shared among multiple consumers.";
	char a23[200]="When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes";
	char a33[200]="Load Balancing";
	char a43[200]="All of the above";
	int ch3=4;
	insert(q3,a13,a23,a33,a43,ch3);
	char q4[500]="In a worst case, a binary search tree will take how much time to search an element?";
	char a14[200]="O(n)";
	char a24[200]="O(log n)";
	char a34[200]="O(n^2)";
	char a44[200]="O(n(log n))";
	int ch4=1;
	insert(q4,a14,a24,a34,a44,ch4);
	char q5[500]="Reverse polish notation is a other name of _______?";
	char a15[200]="Infix Expression";
	char a25[200]="Prefix Expression";
	char a35[200]="Postfix Expression";
	char a45[200]="Algebraic Expression";
	int ch5=3;
	insert(q5,a15,a25,a35,a45,ch5);
	char q6[500]="Which of the following technique deals with sorting the data stored in the computer's memory??";
	char a16[200]="Insertion Sort";
	char a26[200]="Internal Sort";
	char a36[200]="External Sort";
	char a46[200]="Radix Sort";
	int ch6=2;
	insert(q6,a16,a26,a36,a46,ch6);
}

void main()
{	queslist();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome to the game of \n***Kaun Banega Crorepati***\nEach right answer has prize money of Rs.5,00,000.\nToh Chaliye shuru karte hai!!!\n\n");
	answer();
}