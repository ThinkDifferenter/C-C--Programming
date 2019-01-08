#include<stdio.h>
#define N 9
void Merge(int a[],int low,int m,int high);//两路归并 
void MergePass(int a[],int length);
void MergeSort(int a[]);//迭代归并 
void Merge_SortDC(int a[],int low,int high);   //递归归并 
int main()
{
	int i,a[N]={5,7,1,2,6,8,4,9,3};
	
	puts("The sequence you input is:\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",a[i]);
	}
	
	Merge_SortDC(a,0,N-1);
	
	puts("\n The sequence after merge_sortDC is:\n ");
	
	for(i=0;i<N;i++)
	{
		printf("%5d",a[i]);
	}	 
	printf("\n\n");
	
	return 0;
}
void Merge(int a[],int low,int m,int high)
{
	int b[N]={0};
	int i,j,k=low;
	
	i=low,j=m+1;
	while(i<=m&&j<=high)
	{
		b[k++]=(a[i]<=a[j]?a[k++]:a[j++]);
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}
}
void MergePass(int a[],int length)
{
	int i;
	for(i=1;i+2*length-1<=N;i=i+2*length)
	{
		Merge(a,i,i+length-1,i+2*length-1);
	}
	if(i+length-1<N)
	{
		Merge(a,i,i+length-1,N);
	}
}
void MergeSort(int a[])
{
	int length;
	for(length=1;length<N;length*=2)
	{
		MergePass(a,length);
	}
}

void Merge_SortDC(int R[],int low ,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		Merge_SortDC(R,low,high);
		Merge_SortDC(R,mid+1,high);
		Merge(R,low,mid,high);
	}
}