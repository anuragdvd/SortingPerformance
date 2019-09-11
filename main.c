#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "merge.c"
#include "bubblesort.c"
#include "Selection.c"
#include "Quick.c"
#include "CountingSort.c"
#include "val.h"


int main()
{
    printf(" Input type \n \n 1. Array from keyboard \n \n 2. Random Array \n \n"); // Giving Choice to user
    int val;
    scanf("%d",&val);
    int n;
    FILE *fptr;
    fptr = fopen("out.txt","w");    // opening file to write output 
    struct val res;
    int i;
    switch(val) 
    {
    case 1: 
            printf ("Enter number of elements");
            scanf("%d",&n);
            printf("\n \n Enter elements of array \n");
            int *a=(int*)malloc(n*sizeof(int));     // creating user array of size n
            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);      // filling elements
            fflush(stdin);  // making sure that buffer is empty
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n");
            char c; scanf("%c",&c);
            char ch; scanf("%c",&ch); 
            switch(ch)
            {
                case 'B': res=bubblesort(a,n);  // Bubble Sort 
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp); // writing in file
                          break;
                case 'Q': res=quick(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'M': res=mergeSort(a,0,n-1);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'C': res=countingsort(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'S': res=selectionsort(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                default: printf("Wrong Choice"); // Wrong choice by user
            }
            break;
    case 2:
            fflush(stdin);      // Clearing input buffer
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n");
            char c; scanf("%c",&c);
            char che; scanf("%c",&che);     // Asking user for choice
            switch(che)
            {
                case 'B':
                          i=10;
                          while(i<100)
                          {
                          int *ar=(int*)malloc(i*sizeof(int));      // Creating array of size i
                          for(int k=0;k<i;k++)
                            ar[i]=rand() %100;              // Inserting random elements
                          struct val re=bubblesort(ar,i);       // varriable to store result 
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d \n",i,re.time,re.swap,re.comp);
                          i*=10;
                          }
                          break;
                case 'Q':  i=10;
                          while(i<100)
                          {
                          int *a=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;                       // Inserting random elements
                          res=quick(a,i);                        // varriable to store result 

                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                          break;
                case 'M':  i=10;
                          while(i!=100)
                          {
                          int *a=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;               // Inserting random elements
                          res=mergeSort(a,0,i-1);            // varriable to store result 
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                           break;
                case 'C':  i=10;
                          while(i!=100)
                          {
                          int *a=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;                 // Inserting random elements
                          res=countingsort(a,i);             // varriable to store result 
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                          break;
                case 'S':  i=10;
                          while(i!=100)
                          {
                          int *a=(int*)malloc(i*sizeof(int));   // Creating array of size i
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;               // Inserting random elements
                          res=selectionsort(a,i);        // varriable to store result 
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                           break;
                default: printf("Wrong Choice");
            }
            break;
    default: 
      printf("Wrong Choice");


    }
}
