#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root;
int length()
{
	int count=0;
	struct node* temp;
	temp=root;
	do
	{
		temp=temp->link;
		count++;
	}while(temp!=root);
	return count;
}
void insert()
{
	int size;
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
		temp->link=root;
	}
	else
	{
		size=length();
		printf("Enter location of insertion\n");
		int loc,i;
		scanf("%d",&loc);
		if(loc>size||loc<0)
		{
			printf("Invalid location\n");
		}
		else
		{
			struct node* p;
			p=root;
			for(i=1;i<loc;i++)
			{
				p=p->link;
			}
			temp->link=p->link;
			p->link=temp;
		}
	}
}
void display()
{
	struct node* temp;
	temp=root;
	do
	{
		printf("%d  ",temp->data);
		temp=temp->link;
	}while(temp!=root);
	printf("\n");
}
void delete()
{
	struct node* temp,*p;
	temp=root;
	int loc,i;
	printf("Enter location of element to delete\n");
	scanf("%d",&loc);
	for(i=1;i<loc;i++)
	{
		temp=temp->link;
	}
	p=temp->link;
	temp->link=p->link;
	free(p);
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
}
