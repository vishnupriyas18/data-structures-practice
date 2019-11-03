//stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* top=NULL;
void push()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->link=top;
	top=temp;
}
void pop()
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d\n",temp->data);
		top=top->link;
		temp->link=NULL;
		free(temp);
	}
}
void traverse()
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Traverse\n");
		printf("4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(0);
				break;
			default :
				printf("Invalid input\n");
		}
	}
}
