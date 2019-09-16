#include<stdio.h>
#include<time.h>
#include "val.h"

int com=0,swa=0;

struct val Insertion(int array[],int n)   //This will sort our array
{

    clock_t start = clock();  //this is to start the time

    int i=1;
    for(i=1;i<n;i++)
    {
        int j=i-1;
        int key=array[i];
        com++;
        while(j>=0 && array[j]>key)  //this loop will set the unsorted element int their correct position
        {
            array[j+1]=array[j];
            j--;
            swa++;
        }
        array[j+1]=key;
    }
    
    
    clock_t end = clock();
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC); //here we are calc the time
    
    struct val res;
    res.time=time_spent;res.swap=swa;res.comp=com;
    
    return res;
}
