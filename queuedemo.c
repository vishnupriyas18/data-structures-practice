#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10
int queue[CAPACITY];
int front=0;
int rear=0;
void enqueue(int ele)
{
	if(rear==CAPACITY)
	{
		printf("Queue is full\n");
	}
	else
	{
		queue[rear]=ele;
		rear++;
	}
}
void dequeue()
{
	if(front==rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i;
		printf("%d dequeued\n",queue[front]);
		for(i=0;i<rear;i++)
		{
			queue[i]=queue[i+1];
		}
		rear--;
	}
}
void display()
{
	int i;
	if(front==rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=rear;i>=front;i--)
		{
			printf("%d",queue[i]);
		}
	}
}
void binary()
{
	int N,i,p;
	printf("Enter N\n");
	scanf("%d",&N);
	for(i=2;i<N;i++)
	{
		p=i;
		while(p!=0)
		{
			enqueue(p%2);
			p=p/2;
		}
		display();
		rear=0;
		printf("\n");
	}
}
int main()
{
	binary();
}
