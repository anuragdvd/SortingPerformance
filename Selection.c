#include<stdio.h>
#include<time.h>
#include "selectionhead.h"
#include "val.h"

int selc=0,sels=0;

struct val selectionsort(int array[],int n)
{

    int min,temp;
    clock_t start = clock();
    for(int i=0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++){
                selc++;
            if(array[j]<array[min])
                min=j;
        }
        if(min != i){
                 sels++;
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;

        }
    }
    clock_t end = clock();

    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);

    struct val res;
    res.time=time_spent; res.swap=sels; res.comp=selc;
    return res;
}
