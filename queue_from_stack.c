#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100
int stack[CAPACITY];
int top=-1;
void enqueue()
{
	if(top==CAPACITY-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		int ele;
		printf("Enter element\n");
		scanf("%d",&ele);
		stack[++top]=ele;
		printf("%d enqueued\n",ele);
	}
}
void dequeue()
{
	if(top==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i;
		printf("%d dequeued\n",stack[0]);
		for(i=0;i<=top;i++)
		{
			stack[i]=stack[i+1];
		}
		top--;
	}
}
void display()
{
	if(top==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i;
		for(i=0;i<=top;i++)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
		}
	}
}
