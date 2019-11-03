#include<stdio.h>
#include<stdlib.h>
char stack[100];
int top=-1;
void push(char ele)
{
	stack[++top]=ele;
}
void traverse()
{
	while(top!=-1)
	{
		printf("%c",stack[top]);
		top--;
	}
}
void rev_str()
{
	int i=0;
	char str[100];
	printf("Enter a string\n");
	scanf("%s",str);
	while(str[i]!='\0')
	{
		push(str[i]);
		i++;
	}
	traverse();
}
int main()
{
	rev_str();
}
