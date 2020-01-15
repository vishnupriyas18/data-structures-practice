#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100
char stack[CAPACITY];
int top=-1;
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
void push(char ele)
{
	if(isFull())
	{
		printf("Stack is full\n");
	}
	else
	{
		stack[++top]=ele;
	}
}
char pop()
{
	return stack[top--];
}
char peek()
{
	return stack[top];
}
void traverse()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		while(top!=-1)
		{
			printf("%c",stack[top]);
			top--;
		}
	}
}
int priority(char op)
{
	switch(op)
	{
		case '+':
			return 0;
			break;
		case '-':
			return 0;
			break;
		case '*':
			return 1;
			break;
		case '/':
			return 1;
			break;
		case '^':
			return 2;
			break;
		default:
			return -1;
			break;
	}
}
void postfix()
{
	int i;
	char exp[100],x,p;
	printf("Enter the infix expression\n");
	scanf("%s",exp);
	i=0;
	while(exp[i]!='\0')
	{
		if((exp[i]>='a'&&exp[i]<='z')||(exp[i]>='A'&&exp[i]<='Z'))
		{
			printf("%c",exp[i]);
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
		{
			x=peek();
			if(priority(exp[i])>=priority(x))
			{
				push(exp[i]);
			}
			else
			{
				while((priority(x)>priority(exp[i]))&&(priority(x)>=0))
				{
					p=pop();
					printf("%c",p);
					x=peek();
				}
				push(exp[i]);
			}
		}
		else if(exp[i]='('||exp[i]=='['||exp[i]=='{')
		{
			push(exp[i]);
		}
		else if(exp[i]=')'||exp[i]=='}'||exp[i]==']')
		{
			x=peek();
			while(x!='('||x!='{'||x!='[')
			{
				p=pop();
				printf("%c",p);
				x=peek();
			}
			top--;
		}
		i++;
	}
	traverse();
}
int main()
{
	postfix();
}
