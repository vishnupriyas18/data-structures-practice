#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root;
int arr[100];
int i=0,count=0;
void insert()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* parent;
		struct node* current;
		current=root;
		while(current)
		{
			parent=current;
			if(temp->data>current->data)
			{
				current=current->right;
			}
			else
			{
				current=current->left;
			}
		}
		if(temp->data>parent->data)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
	}
}
void delete()
{
	int ele;
	printf("Enter element to delete\n");
	scanf("%d",&ele);
	struct node *current,*parent;
	current=root;
	while(current->data!=ele)
	{
		parent=current;
		if(ele>current->data)
		{
			current=current->right;
		}
		else
		{
			current=current->left;
		}
	}
	if(current->left==NULL&&current->right==NULL)
	{
		if(parent->left==current)
		{
			parent->left=NULL;
		}
		else
		{
			parent->right=NULL;
		}
	}
	else if((current->left==NULL&&current->right!=NULL)||(current->left!=NULL&&current->right==NULL))
	{
		if(parent->right==current)
		{
			if(current->right!=NULL)
			{
				parent->right=current->right;
				current->right=NULL;
			}
			else
			{
				parent->right=current->left;
				current->left=NULL;
			}
		}
		else
		{
			if(current->right!=NULL)
			{
				parent->left=current->right;
				current->right=NULL;
			}
			else
			{
				parent->left=current->left;
				current->left=NULL;
			}
		}
	}
	else
	{
		
	}
}
void inorder(struct node* t)
{
	if(t->left)
	{
		inorder(t->left);
	}
	printf("%d ",t->data);
	if(t->right)
	{
		inorder(t->right);
	}
}
void function(struct node* t)
{
	if(t->left)
	{
		function(t->left);
	}
	arr[i++]=t->data;
	count++;
	if(t->right)
	{
		function(t->right);
	}
}
int main()
{
	int ch,k;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Inorder\n4.Function\n5.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				function(root);
				printf("Enter value of k\n");
				scanf("%d",&k);
				printf("k th smallest element is %d\n",arr[k-1]);
				printf("k th largest element is %d\n",arr[count-k]);
				i=0;count=0;
				break;
			case 5:
				exit(0);
		}
	}
}
