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
struct snode* sroot1;
struct snode* sroot2;
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
void push(struct snode* root,struct tnode* a)
{
	struct snode* temp;
	temp=(struct snode*)malloc(sizeof(struct snode));
	temp->data=*a;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}
struct tnode* pop(struct snode* root)
{
	struct snode* temp;
	temp=root;
	root=root->link;
	temp->link=NULL;
	return &temp->data;
}
void postorder(struct tnode* p)
{
	if(p==NULL)
		return;
	struct tnode* temp;
	temp=p;
	push(sroot1,p);
	while(sroot1!=NULL)
	{
		temp=pop(sroot1);
		push(sroot2,temp);
		if(temp->left!=NULL)
		{
			push(sroot1,temp->left);
		}
		if(temp->right!=NULL)
		{
			push(sroot1,temp->right);
		}
	}
	while(sroot2!=NULL)
	{
		temp=pop(sroot2);
		printf("%d  ",temp->data);
	}
}
int main()
{
	int ch;
	while(1)
	{
		scanf("%d",&ch);
		if(ch)
		{
			insert();
		}
		else
			break;
	}
	postorder(troot);
}
