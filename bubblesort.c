//program for bubble sort

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "bubble.h"
#include "val.h"


int sw=0,cm=0;

struct val bubblesort(int a[],int n)
{
    clock_t start, end;
    double cpu_time;
    int i, j,k,l=0,temp=0;                          //defining variables

    start = clock();                                    //program starts to measure time from here
    for(k=0;k<n-1;k++)                                  //sorting the array
    {
        for (j=0;j<n-k-1;j++)
        {
            cm++;
            if (a[j]>a[j+1] )                       //swapping the elements in array which are not in order
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                sw++;
            }
        }
    }

    end=clock();                                        //program stops to measure time here
    cpu_time=((double)(end-start))/CLOCKS_PER_SEC;      //calculating CPU time used
    struct val re;
    re.time=cpu_time; re.swap=sw; re.comp=cm;
    return re;
}
