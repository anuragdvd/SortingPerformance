#include<stdio.h>
#include<time.h>
#include "counting.h"
#include "val.h"

void countsort(int ar[],int n,int max)      //This function will sort the arrray
{
	int i=0;
    int count[max+1];						//Created this array to count the occurance of each element in the main array
    int b[n];								//This array will store the sorted element of main array
   	for(i=0;i<=max;i++)						//This is loop to initialize each array to zero
		count[i]=0;
	for(i=0;i<n;i++)						//Here it is counting the occurance of each element
		count[ar[i]]++;
	for(i=1;i<=max;i++)						//This loop is for adding current element of count to is previous one
		count[i]+=count[i-1];
	for(i=n-1;i>=0;i--)						//This loop will sort the element of main array
		b[--count[ar[i]]]=ar[i];
	for(i=0;i<n;i++)						//Here we are coping sorted element to the main array
		ar[i]=b[i];


}

struct val countingsort(int ar[], int n)
{
    int max=0;
    for(int i=0;i<n;i++){						//Here this loop is to take input from user
        if(max<ar[i])   					//Here we are finding the maximum value to identify the range of our array
            max=ar[i];
    }
    //Here we are calculating the time execution
    clock_t start = clock();
    countsort(ar,n,max);   					//Here we are calling countsort function to sort elements
    clock_t end = clock();
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);
    struct val cres;
    cres.time=time_spent; cres.swap=0; cres.comp=0;
    return cres;

}
