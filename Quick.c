#include<stdio.h>
#include<time.h>
#include "quicksort.h"
#include "val.h"

int qswap=0,qcomp=0; // qswap -> swap in Quick sort qcomp -> compare in quick sort

struct val quick(int array[],int n) //n is number of elements in array
{
    clock_t start = clock(); // clock start
    quicksort(array,0,n-1); 
    clock_t end = clock(); // clock ends
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);  // calculate CPU time used
    struct val qres;
    qres.time=time_spent; qres.swap=qswap; qres.comp=qcomp;

    return qres;
}

void quicksort(int array[],int first,int last)
{
    int i,j,q,swap_count=0,temp;
    if(first<last){
        q=first;
        i=first;
        j=last;
        while(i<j){
                qcomp++;
            while(array[i]<=array[q] && i<last)
                i++;
            while(array[j]>array[q])
                j--;
            if(i<j){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                qswap++;
            }
        }
        temp=array[q];
        array[q]=array[j];
        array[j]=temp;
        quicksort(array,first,j-1);
        quicksort(array,j+1,last);
    }
}
