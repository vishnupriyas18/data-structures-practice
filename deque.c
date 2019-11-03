//double ended queue
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* before;
	struct node* after;
};
struct node* root=NULL;
void enqueue_front()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to enqueue\n");
	scanf("%d",&temp->data);
	temp->before=NULL;
	temp->after=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->after=root;
		root->before=temp;
		root=temp;
	}
}
void enqueue_rare()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to enqueue\n");
	scanf("%d",&temp->data);
	temp->before=NULL;
	temp->after=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->after!=NULL)
		{
			p=p->after;
		}
		p->after=temp;
		temp->before=p;
	}
}
void dequeue_front()
{
	struct node* temp;
	temp=root;
	printf("%d dequeued\n",temp->data);
	root=temp->after;
	root->before=NULL;
	temp->after=NULL;
	free(temp);
}
void dequeue_rare()
{
	struct node* temp;
	temp=root;
	while(temp->after!=NULL)
	{
		temp=temp->after;
	}
	printf("%d dequeued\n",temp->data);
	struct node* p;
	p=temp->before;
	p->after=NULL;
	temp->before=NULL;
	free(temp);
}
void display()
{
	struct node* temp;
	temp=root;
	while(temp->after!=NULL)
	{
		printf("%d<->",temp->data);
		temp=temp->after;
	}
	printf("%d\n",temp->data);
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.Enqueue front\n");
		printf("2.Enqueue rare\n");
		printf("3.Dequeue front\n");
		printf("4.Dequeue rare\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue_front();
				break;
			case 2:
				enqueue_rare();
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_rare();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
		}
	}
}
