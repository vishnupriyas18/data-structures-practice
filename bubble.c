#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void bubblesort(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				swap(arr+j,arr+j+1);
			}
		}
	}
}
void insertionsort(int *arr,int n)
{
	int j,i,key;
	for(i=1;i<n;i++)
	{
		key=*(arr+i);
		j=i-1;
		while(j>=0&&*(arr+j)>key)
		{
			*(arr+j+1)=*(arr+j);
			j--;
		}
		*(arr+j+1)=key;
	}
}
void selectionsort(int *arr,int n)
{
	int i,j,key;
	for(i=0;i<n;i++)
	{
		key=i;
		for(j=i+1;j<n;j++)
		{
			if(*(arr+j)<*(arr+key))
			{
				key=j;
			}
		}
		swap((arr+i),(arr+key));
	}
}
void merge(int *arr,int l,int m,int r)
{
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[20],R[20];
	for(i=0;i<n1;i++)
		L[i]=*(arr+i+l);
	for(j=0;j<n2;j++)
		R[j]=*(arr+m+1+j);
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			*(arr+k)=L[i];
			i++;
		}
		else
		{
			*(arr+k)=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		*(arr+k)=L[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		*(arr+k)=R[j];
		j++;
		k++;
	}
}
void mergesort(int *arr,int l,int r)
{
	if(l<r)
	{
		int m;
		m=(r+l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int partition(int *arr,int l,int r)
{
	int i,j,pivot;
	pivot=*(arr+r);
	i=l-1;
	for(j=l;j<r;j++)
	{
		if(*(arr+j)<pivot)
		{
			i++;
			swap(arr+i,arr+j);
		}
	}
	swap(arr+i+1,arr+r);
	return i+1;
}
void quicksort(int *arr,int l,int r)
{
	if(l<r)
	{
		int part;
		part=partition(arr,l,r);
		quicksort(arr,l,part-1);
		quicksort(arr,part+1,r);
	}
}
int main()
{
	int a[100],size,i;
	scanf("%d",&size);
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,size);
	for(i=0;i<size;i++)
		printf("%d  ",a[i]);
}
