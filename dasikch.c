#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
int stack[100];
int top=-1;
void push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	return stack[top--];
}
int queue[100];
int back=0,front=0;
void enqueue(int ele)
{
	queue[back++]=ele;
}
int dequeue()
{
	return queue[front++];
}
void BSTinsert(struct node* root,int ele)
{
	struct node *parent,*current,*p;
	current=root;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=ele;
	p->left=NULL;
	p->right=NULL;
	if(root==NULL)
	{
		root=p;
	}
	else
	{
		while(current)
		{
			parent=current;
			if(current->data>ele)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}
		}
		if(parent->data>ele)
		{
			parent->left=p;
		}
		else if(parent->data<ele)
		{
			parent->right=p;
		}
	}
}
struct node* BTnew(int ele)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void levelorder(struct node* root)
{
	struct node* temp;
	temp=root;
	while(temp)
	{
		printf("%d ",temp->data);
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
		temp=dequeue();
	}
	front=0;
}
void inorder(struct node* root)
{
	struct node* temp;
	temp=root;
	while(1)
	{
		if(temp)
		{
			push(temp);
			temp=temp->left;
		}
		else
		{
			if(top!=-1)
			{
				temp=pop();
				printf("%d  ",temp->data);
				temp=temp->right;
			}
			else
				break;
		}
	}
}
void preorder(struct node* root)
{
	struct node *temp;
	temp=root;
	push(temp);
	while(top!=-1)
	{
		temp=pop();
		printf("%d  ",temp->data);
		if(temp->right)
			push(temp->right);
		if(temp->left)
			push(temp->left);
	}
	while(top!=-1)
	{
		temp=pop();
		printf("%d  ",temp->data);
	}
}
void halfnodes(struct node* root)
{
	int count=0;
	struct node* temp;
	temp=root;
	while(temp)
	{
		if(temp->left==NULL&&temp->right!=NULL)
		{
			count++;
		}
		else if(temp->left!=NULL&&temp->right==NULL)
		{
			printf("%d",temp->data);
			count++;
		}
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
		temp=dequeue();
	}
	front=0;
	printf("Number of half nodes is %d\n",count);
}
int main()
{
	struct node* root;
	root=BTnew(1);
	root->left=BTnew(2);
	root->right=BTnew(3);
	root->left->left=BTnew(4);
	root->left->right=BTnew(5);
	root->right->left=BTnew(6);
	levelorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	halfnodes(root);
}
