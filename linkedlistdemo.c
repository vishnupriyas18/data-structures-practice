#include<stdio.h>
#include<stdlib.h>
int len;
struct node
{
	int data;
	struct node* link;
};
struct node* root=NULL;
void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int length()
{
	int count=0;
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
void display()
{
	struct node* temp;
	temp=root;
	if(root==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
void add_at_begin()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->link=root;
	root=temp;
}
void add_at_after()
{
	struct node* temp,*p;
	int loc,i=1;
	printf("Enter location\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Invalid location\n");
	}
	else if(loc==length())
	{
		append();
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data\n");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
	}
}
void delete()
{
	struct node* temp;
	int loc;
	printf("Enter location to delete\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Invalid location\n");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node* p,*q;
		p=root;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.Append\n");
		printf("2.Add at beginning\n");
		printf("3.Add at after\n");
		printf("4.Length of list\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				append();
				break;
			case 2:
				add_at_begin();
				break;
			case 3:
				add_at_after();
				break;
			case 4:
				len=length();
				printf("%d\n",len);
				break;
			case 5:
				display();
				break;
			case 6:
				delete();
				break;
			case 7:
				exit(0);
			default:
				printf("Invalid input\n"); 
		}
	}
}
