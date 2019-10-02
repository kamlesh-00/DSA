#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size],f=0,r=-1;
void insert(int ele)
{
    if(f==size)
        printf("Queue is full");
    else
    {
        queue[f]=ele;
        f++;
    }
}
int remov()
{
    if(r==f)
        printf("Queue is empty");
    else if(r==f-1)
    {
        int x=queue[r];
        f=0;r=-1;
        return x;
    }
    else
    {
        r++;
        return (queue[r]);
    }
}
void display()
{
    if(f==0)
        printf("Queue is empty");
    else if(f==r)
        printf(" %d\t",queue[f]);
    else
    {
        int ptr=++r;
        while(ptr!=f)
        {
            printf(" %d\t",queue[ptr]);
            ptr++;
        }
        printf("\n");
    }
}
void main()
{
    int ch,x;
    printf("****Queue****\n");
    printf("1.To enqueue\n2.To dequeue\n3.To display entire queue\n4.To exit\nEnter your options:");
    scanf("%d",&ch);
    while(ch!=4){
        switch(ch)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&x);
            insert(x);
            break;

        case 2:
            printf("%d\n",remov());
            break;
        case 3:
            printf("Queue is as follows:");
            display();
            break;
        default:printf("Wrong choice entered\n");
        break;
        }
        printf("Enter your option:");
        scanf("%d",&ch);
    }
}
