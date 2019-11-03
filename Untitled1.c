#include<stdio.h>
int main()
{
	int arr[100],n,i,j,p,q,x,temp,z,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter number of elements to reverse\n");
	scanf("%d",&x);
	p=0;
	q=x-1;
	a=2*x;
	if(x>n)
	{
		printf("Invalid Input\n");
	}
	else if(n%a==0||n%a==n%x)
	{
		for(z=0;z<n/a;z++)
		{
			i=p;
			j=q;
			while(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				i++;
				j--;
			}
			p+=a;
			q+=a;
		}
	}
	else if((n%a!=0&&n%x==0))
	{
		for(z=0;z<(n/a)+1;z++)
		{
			i=p;
			j=q;
			while(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				i++;
				j--;
			}
			p+=a;
			q+=a;
		}
	}
	else if(n%a>n%x)
	{
		for(z=0;z<(n/a);z++)
		{
			i=p;
			j=q;
			while(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				i++;
				j--;
			}
			p+=a;
			q+=a;
		}
		q=q-(x-n%x);
		i=p;
		j=q;
		while(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
