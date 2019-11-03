#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int V;
	int E;
	int **adj;
};
struct graph* G;
struct stack
{
	int data;
	struct stack* link;
};
struct stack* root;
void push(int x)
{
	struct stack* temp;
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=x;
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
int pop()
{
	int x;
	struct stack *p;
	p=root;
	root=p->link;
	p->link=NULL;
	x=p->data;
	free(p);
	return x;
}
void creategraph()
{
	int u,v,i;
	G=(struct graph*)malloc(sizeof(struct graph));
	printf("Enter number of vertices and edges\n");
	scanf("%d%d",&G->V,G->E);
	G->adj=malloc(sizeof(G->V*G->V));
	for(u=0;u<G->V;u++)
		for(v=0;v<G->V;v++)
			G->adj[u][v]=0;
	printf("Enter edges\n");
	for(i=0;i<G->V;i++)
	{
		scanf("%d%d",&u,&v);
		G->adj[u][v]=1;
		G->adj[v][u]=1;
	}
}
void DFS()
{
	int x,v=0;
	int *visited;
	visited=malloc(sizeof(G->V));
	push(0);
	visited[0]=1;
	while(v<G->V)
	{
		x=pop();
		printf("%d  ",x);
		while(G->adj[x][v]==1&&visited[x]==0)
		{
			push(v);
			visited[v]=1;
		}
	}
	while(root!=NULL)
	{
		printf("%d",pop());
	}
}
int main()
{
	creategraph();
	DFS();
}
