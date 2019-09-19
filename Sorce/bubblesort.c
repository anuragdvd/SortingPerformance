//program for bubble sort

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "bubble.h"
#include "val.h"


int swap=0,compare=0;

struct val bubblesort(int array[],int n)  //n is number of elements in the array
{
    clock_t start, end;
    double cpu_time;
    int l=0,temp=0;                          //defining variables

    start = clock();                                    //program starts to measure time from here
    for(int k=0;k<n-1;k++){                                  //sorting the array
        for (int j=0;j<n-k-1;j++){
            compare++;
            if (array[j]>array[j+1] ){                       //swapping the elements in array which are not in order
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swap++;
            }
        }
    }

    end=clock();                                        //program stops to measure time here
    cpu_time=((double)(end-start))/CLOCKS_PER_SEC;      //calculating CPU time used
    struct val re;
    re.time=cpu_time; re.swap=swap; re.comp=compare;
    return re;
}
