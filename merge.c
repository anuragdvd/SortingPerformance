#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "mergesort.h"
#include "val.h"


int s=0; int c=0;


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int *L=(int*)malloc(sizeof(int)*n1); int *R=(int*)malloc(sizeof(int)*n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    { c++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++; s++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
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
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
    start=clock()-start;                                        //program stops to measure time here
    cpu_time=((double)(start));
    struct val re;
    re.time=cpu_time; re.swap=s; re.comp=c;
    return re;

}
