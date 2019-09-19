#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "mergesort.h"
#include "val.h"


int s=0; int c=0; // These are two global variables which will keep track of swap and comparsion 


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;     // size of left  array
    int n2 =  r - m;        // size of right array

    int *L=(int*)malloc(sizeof(int)*n1); // declaration of left array
    int *R=(int*)malloc(sizeof(int)*n2);    // declaration of right array

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];  // filling elements in left array
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];   // filling elements in right array

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    { c++;
        if (L[i] <= R[j])       // if left array has smaller element then we are copying it to main array
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];      // if right array has smaller element then we are copying it to main array
            j++; s++;
        }
        k++;
    }
    while (i < n1) // if any element is left in right array then we are copying it to main array
    {
        arr[k] = L[i];  
        i++;
        k++;
    }

    while (j < n2) // if any element is left in left array then we are copying it to main array
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

struct val mergeSort(int a[], int l, int r)
{
    clock_t start, end;
    double cpu_time;
    start = clock();                                    //program starts to measure time from here
    if (l < r)
    {
        int m = l+(r-l)/2;          
        mergeSort(a, l, m);         // recursively calling mergesort on left array
        mergeSort(a, m+1, r);       // recursively calling mergesort on right array
        merge(a, l, m, r);          // merging both sorted arrays
    }
    start=clock()-start;                                        //program stops to measure time here
    cpu_time=((double)(start));
    struct val re;                      
    re.time=cpu_time; re.swap=s; re.comp=c;     // We are storing the comparsion, cpu time and swap val type variable
    return re;

}
