#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root=NULL;
void add_beg()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to add\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}
void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to add\n");
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
void display()
{
	struct node* temp;
	temp=root;
	while(temp->link!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d\n",temp->data);
}
void add_loc()
{
	int loc,i;
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter location\n");
	scanf("%d",&loc);
	printf("Enter element to add\n");
	scanf("%d",&temp->data);
	struct node* p;
	p=root;
	for(i=1;i<loc;i++)
	{
		p=p->link;
	}
	temp->link=p->link;
	p->link=temp;
}
void reverse_list(int n, struct node *K)
{
	int i,j,k,temp;
	struct node *p,*q,*r;
	p=K;
	r=p;
	i=0;
	j=n-1;
	while(i<j)
	{
		k=0;
		q=r;
		while(k<j&&q->link!=NULL)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		p=p->link;
		i++;
		j--;
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
void Easierway()
{
	int n,i=0,j;
	struct node *temp;
	printf("Enter k:");
	scanf("%d",&n);
	temp=root;
	while(temp!=NULL)
	{
		if(i%(2*n)==0)
		{
			reverse_list(n,temp);
			for(j=0;j<2*n&&temp!=NULL;j++,i++,temp=temp->link);
		} 
	}
	display();
}
int main()
{
	int ch,n;
	while(1)
	{
		printf("1.Add at beginning\n2.Add at end\n3.Add at location\n4.Reverse list\n5.Function\n6.Display\n7.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_beg();
				break;
			case 2:
				append();
				break;
			case 3:
				add_loc();
				break;
			case 4:
				printf("Enter number of elements to reverse\n");
				scanf("%d",&n);
				reverse_list(n,root);
				break;
			case 5:
				Easierway();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
		}
	}
}
