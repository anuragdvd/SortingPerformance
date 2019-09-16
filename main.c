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
    fclose(fptr);
    fptr=fopen("out.txt","a");
    struct val res;
    int i;
    int *array;
    switch(val) 
    {
    case 1: 
            printf ("Enter number of elements");
            scanf("%d",&n);
            printf("\n \n Enter elements of array \n");
            array=(int*)malloc(n*sizeof(int));     // creating user array of size n
            for(int i=0;i<n;i++)
                scanf("%d",&array[i]);      // filling elements
            fflush(stdin);  // making sure that buffer is empty
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n");
            char c; scanf("%c",&c);
            char ch; scanf("%c",&ch); 
            switch(ch)
            {
                case 'B': res=bubblesort(array,n);  // Bubble Sort 
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp); // writing in file
                          break;
                case 'Q': res=quick(array,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'M': res=mergeSort(array,0,n-1);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'C': res=countingsort(array,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'S': res=selectionsort(array,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                default: printf("Wrong Choice"); // Wrong choice by user
            }
            break;
    case 2:
            fflush(stdin);      // Clearing input buffer
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n");
            char x; scanf("%c",&x);
            char che; scanf("%c",&che);     // Asking user for choice
            
            switch(che)
            {
                case 'B':
                        {
                          i=10;
                          while(i<10001)
                          {
                            printf("i = %d\n", i);
                            array=(int*)malloc(i*sizeof(int));      // Creating array of size i
                            printf("Success");
                            for(int k=0;k<i;k++)
                              array[k]=rand() %100;              // Inserting random elements
                            struct val re=bubblesort(array,i);       // varriable to store result 
                            fprintf(fptr,"For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d \n\n",i,re.time,re.swap,re.comp);
                            i*=10;
                            free(array);
                          }
                          break;
                        }
                case 'Q':  i=10;
                          while(i<10001)
                          {
                          int *array=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            array[k]=rand()%i;                       // Inserting random elements
                          res=quick(array,i);                        // varriable to store result 

                          fprintf(fptr,"For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                          i*=10;
                          free(array);
                          }
                          break;
                case 'M':  i=10;
                          while(i<10001)
                          {
                          int *array=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            array[k]=rand()%i;               // Inserting random elements
                          res=mergeSort(array,0,i-1);            // varriable to store result 
                          fprintf(fptr,"For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                          i*=10;
                          free(array);
                          }
                           break;
                case 'C':  i=10;
                          while(i<10001)
                          {
                          int *array=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            array[k]=rand()%i;                 // Inserting random elements
                          res=countingsort(array,i);             // varriable to store result 
                          fprintf(fptr,"For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                          i*=10;
                          free(array);
                          }
                          break;
                case 'S':  i=10;
                          while(i<10001)
                          {
                            int *array=(int*)malloc(i*sizeof(int));   // Creating array of size i
                            for(int k=0;k<i;k++)
                              array[k]=rand()%i;               // Inserting random elements
                            res=selectionsort(array,i);        // varriable to store result 
                            fprintf(fptr,"For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                            i*=10;
                            free(array);
                          }
                           break;
                default: printf("Wrong Choice");
            }

            break;
    default: 
      printf("Wrong Choice");


    }
}
    