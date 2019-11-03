#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root;
struct queue
{
	struct node* data;
	struct queue* link;
};
struct queue* qroot;
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
void enqueue(struct node* p)
{
	struct queue* temp;
	temp=(struct queue*)malloc(sizeof(struct queue));
	temp->data=p;
	if(qroot==NULL)
	{
		qroot=temp;
	}
	else
	{
		struct queue* q;
		q=qroot;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link=temp;
	}
}
struct node* dequeue()
{
	struct queue* temp;
	temp=qroot;
	qroot=qroot->link;
	temp->link=NULL;
	return temp->data;
}
void levelorder()
{
	if(root==NULL)
		return;
	struct node* temp;
	enqueue(root);
	while(qroot!=NULL)
	{
		temp=dequeue();
		printf("%d  ",temp->data);
		if(temp->left!=NULL)
		{
			enqueue(temp->left);
		}
		if(temp->right!=NULL)
		{
			enqueue(temp->right);
		}
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
	levelorder();
}
