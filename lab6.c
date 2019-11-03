#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
	int height;
};
int max(int a,int b)
{
	return (a>b)?a:b;
}
int height(struct node* N)
{
	if(N==NULL)
		return 0;
	return N->height;
}
struct node* newnode(int key)
{
	struct node* Node=(struct node*)malloc(sizeof(struct node));
	Node->data=key;
	Node->left=NULL;
	Node->right=NULL;
	Node->height=1;
	return Node;
}
int bal(struct node* N)
{
	if(N==NULL)
		return 0;
	return (height(N->left)-height(N->right));
}
struct node* right_rotate(struct node* y)
{
	struct node* x=y->left;
	struct node* T=x->right;
	x->right=y;
	y->left=T;
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}
struct node* left_rotate(struct node* x)
{
	struct node* y=x->right;
	struct node* T=y->left;
	y->left=x;
	x->right=T;
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return y;
}
struct node* insert(struct node* Node,int key)
{
	if(Node==NULL)
		return (newnode(key));
	
	if(Node->data>key)
		insert(Node->left,key);
	else if(Node->data<key)
		insert(Node->right,key);
	else
		return Node;
	Node->height=max(height(Node->left),height(Node->right))+1;
	int balance=bal(Node);
	if(balance>1&&key<Node->left->data)
		return right_rotate(Node);
	else if(balance>1&&key>Node->left->data)
	{
		Node->left=left_rotate(Node->left);
		return right_rotate(Node);
	}
	else if(balance<-1&&key>Node->right->data)
		return left_rotate(Node);
	else if(balance<-1&&key<Node->right->data)
	{
		Node->right=right_rotate(Node->right);
		return left_rotate(Node);
	}
	return Node;
}
void preorder(struct node* p)
{
	if(p==NULL)
		return;
	printf("%d",p->data);
	preorder(p->left);
	preorder(p->right);
}
int main()
{
	int ch,ele;
	struct node* root;
	root=NULL;
	while(1)
	{
		printf("1.Insert\n2.Display\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to insert\n");
				scanf("%d",&ele);
				insert(root,ele);
				break;
			case 2:
				preorder(root);
				break;				
		}
	}
}
