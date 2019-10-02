#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct node
{	int data;
	struct node *left,*right;
};

struct node *root=NULL;

void insert(int ele)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
		root=temp;
	else
	{	struct node *current=root;
		struct node *present;
		while(current!=NULL)
		{	present=current;
			if(temp->data>current->data)
				current=current->right;
			else
				current=current->left;
		}
		if(temp->data>present->data)
			present->right=temp;
		else
			present->left=temp;
	}
}

int search(struct node *root1,int ele)
{	int flag=1;
	if(root1!=NULL)
	{	if(root1->data==ele)
			printf("Node found\n");
		else if(root1->data<ele)
			search(root1->right,ele);
		else if(root1->data>ele)
			search(root1->left,ele);

	}
	else
	{	printf("Node not found\n");
		flag=0;
	}
	return flag;
}

void inorder(struct node *root1)
{	if(root1!=NULL)
	{	inorder(root1->left);
		printf("%d\t",root1->data);
		inorder(root1->right);
	}
}

void preorder(struct node *root1)
{	if(root1!=NULL)
	{	printf("%d\t",root1->data);
		preorder(root1->left);
		preorder(root1->right);
	}
}

void postorder(struct node *root1)
{	if(root1!=NULL)
	{	postorder(root1->left);
		postorder(root1->right);
		printf("%d\t",root1->data);
	}
}

int leafcount(struct node *root1)
{	if(root1==NULL)
		return 0;
	else if(root1->left==NULL && root1->right==NULL)
		return 1;
	else
		return(leafcount(root1->left)+leafcount(root1->right));
}

int intcount(struct node *root1)
{	if((root1->left==NULL && root1->right==NULL) || root==NULL)
		return 0;
	return 1+intcount(root1->left)+intcount(root1->right);
}

struct node * delete(struct node * root,int x)
{
	if(search(root,x)==0)
	{
		return root;
	}
  	else
	{
 		struct node * q;
		struct node * tmp=root;
		int flag=0;
		while(tmp!=NULL)
		{
        		if(x==tmp->data)
			{
				flag=1;
        			break;
        		}
       			else if(x<tmp->data)
			{
	        		q=tmp;
	        		tmp=tmp->left;
        		}
	        	else
			{
        			q=tmp;
       				tmp=tmp->right;
       			}
      		}
      		if(flag==1)
		{	if(tmp->left==NULL && tmp->right==NULL)
			{	if(tmp==q->left)
        		        	q->left=NULL;
        		    	else
        		        	q->right=NULL;
        	   	}
     			else if(tmp->left!=NULL && tmp->right==NULL)
			{
			        if(tmp==q->left)
        		        	q->left=tmp->left;
        		    	else
        		        	q->right=tmp->left;
        		}
        		else if(tmp->right!=NULL && tmp->left ==NULL)
			{
        			if(tmp==q->right)
        		      		q->right=tmp->right;
        		    	else
        		    		q->left=tmp->right;
        		}
        		else
			{
			        struct node * p=tmp->right;
        		  	while(p->left!=NULL)
				{	p=p->left;
        		    		int n=p->data;
        		    		delete(root,p->data);
        		    		tmp->data=n;
        		  	}
        		}
      		}
      	return root;
   	}
}

void main()
{	int ch,ele;
	printf("*****BINARY SEARCH TREE*****\n");
	do
	{	printf("Enter 1.To insert node in tree\n2.Delete any node\n3.Preorder Traverse\n4.Inorder Traverse\n5.Postorder Traverse\n6.Search the node is present or not\n7.Count total no. of nodes\n8.Count total interior nodes\n9.Count total leaf nodes\n10.Inorder Traversal without recursion\n11..Exit\nEnter your option:");
		scanf("%d",&ch);
		switch(ch)
		{	case 1:printf("Enter element:");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:printf("Enter node to be deleted:");
				scanf("%d",&ele);
				root=delete(root,ele);
				break;
			case 3:preorder(root);
				break;
			case 4:inorder(root);
				break;
			case 5:postorder(root);
				break;
			case 6:printf("Enter the node to be searched :");
				scanf("%d",&ele);
				int a=search(root,ele);
				break;
			case 7:printf("No. of total nodes : %d\n",leafcount(root)+intcount(root));
				break;
			case 8:printf("No. of interior nodes : %d\n",intcount(root));
				break;
			case 9:printf("No. of leaf nodes : %d\n",leafcount(root));
				break;
			case 10:inorderr(root);
				break;
			case 11:break;
			default:printf("Wrong choice");
		}
	}while(ch!=11);
}








/*struct node * delete(struct node *root1,int ele)
{	struct node *current=root1,*parent;
	int flag=0;
	if(root1==NULL)
		printf("Tree is empty");
	else if(current->data==ele)
	{	while(current->data==ele)

		{	parent=current;
			if(ele>current->data)

			{	current=current->right;
				flag=0;

			}
			else

			{	current=current->left;
				flag=1;
			}

		}
		if(current->left==NULL && current->right==NULL)
		{	if(flag==1)
			{	parent->left=NULL;
				free(current);
			}
			else if(flag==0)
			{	parent->right=NULL;
				free(current);
			}
		}
		else if(current->left==NULL || current->right==NULL)
		{	if(flag==1 && current->left!=NULL)
			{	parent->left==current->left;
				free(current);
			}
			else if(flag==1 && current->right!=NULL)
			{	parent->right==current->right;
				free(current);
			}
			else if(flag==0 && current->left!=NULL)
			{	parent->left==current->left;
				free(current);
			}
			else if(flag==0 && current->left!=NULL)
			{	parent->left==current->left;
				free(current);
			}
		}
		else if(current->left!=NULL && current->right!=NULL)
		{	struct node *child=current->left;
			struct node *new;
			while(new->data<ele)
			{	if(ele>current->data)
					current=current->right;
				else
					current=current->left;
			}
			if(flag==0)
				parent->right=current;
			else
				parent->left=current;
			free(current);
		}
	}
	return root1;
}*/
