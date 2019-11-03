#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int stack[CAPACITY],top=-1;
int isFull()
{
	if(top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int ele)
{
	if(isFull())
	{
		printf("Stack is full!\n");
	}
	else
	{
		top++;
		stack[top]=ele;
		printf("%d pushed\n",ele);
	}
}
int pop()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		return stack[top--];
	}
}
int peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		return stack[top];
	}
}
void traverse()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		int i;
		printf("stack elements are\n");
		for(i=0;i<=top;i++)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int main()
{
	int ch,item;
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.traverse\n");
		printf("5.quit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element\n");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				item=pop();
				printf("popped item is %d\n",item);
				break;
			case 3:
				item=peek();
				printf("peek item is %d\n",item);
				break;
			case 4:
				traverse();
				break;
			case 5:
				exit(0);
			default :
				printf("Invalid input\n");
				break;
		}
	}
}
