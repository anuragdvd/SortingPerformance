#include<stdio.h>
#include<time.h>
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
	int n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
    int a[n];
	printf("Enter array elements:");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	clock_t start = clock();
	mergesort(a,0,n-1);
	clock_t end = clock();
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);
    printf("\nTime taken to sort the array = %lf",time_spent);
	return 0;
}
 
void mergesort(int a[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[j2];	//array used for merging
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;
	
	while(i<=j1 && j<=j2)	//while elements in both lists
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	//copy remaining elements of the first list
		temp[k++]=a[i++];
		
	while(j<=j2)	//copy remaining elements of the second list
		temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}