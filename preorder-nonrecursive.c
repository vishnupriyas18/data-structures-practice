#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tnode
{
	int data;
	struct tnode* left;
	struct tnode* right;
};
struct tnode* troot;
struct snode
{
	struct tnode data;
	struct snode* link;
};
struct snode* sroot;
void insert()
{
	struct tnode* temp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(troot==NULL)
	{
		troot=temp;
	}
	else
	{
		struct tnode* parent;
		struct tnode* current;
		current=troot;
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
void push(struct tnode* a)
{
	struct snode* temp;
	temp=(struct snode*)malloc(sizeof(struct snode));
	temp->data=*a;
	if(sroot==NULL)
	{
		sroot=temp;
	}
	else
	{
		temp->link=sroot;
		sroot=temp;
	}
}
struct tnode* pop()
{
	struct snode* temp;
	temp=sroot;
	sroot=sroot->link;
	temp->link=NULL;
	return &temp->data;
}
void preorder(struct tnode* p)
{
	struct tnode* temp;
	push(p);
	while(sroot!=NULL)
	{
		temp=pop();
		printf("%d  ",temp->data);
		if(temp->right!=NULL)
		{
			push(temp->right);
		}
		if(temp->left!=NULL)
		{
			push(temp->left);
		}
	}
	while(sroot!=NULL)
	{
		temp=pop();
		printf("%d  ",temp->data);
	}
}
int main()
{
	int ch;
	while(1)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			insert();
		}
		else
			break;
	}
	preorder(troot);
}
