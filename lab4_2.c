#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int row;
	int column;
	struct node* link;
};
struct node* root;
void insert(int ele,int r,int c)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->row=r;
	temp->column=c;
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
		printf("ROW   COLUMN   VALUE\n");
		while(temp!=NULL)
		{
			printf(" %d       %d        %d\n",temp->row,temp->column,temp->data);
			temp=temp->link;
		}
	}
}
int main()
{
	int r,c,i,j,a[20][20];
	printf("Enter number of rows and columns\n");
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("a%d%d=",i+1,j+1);
			scanf("%d",&a[i][j]);
			printf("\n");
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				insert(a[i][j],i,j);
			}
		}
	}
	printf("The sparse matrix representation is\n");
	display();
}
