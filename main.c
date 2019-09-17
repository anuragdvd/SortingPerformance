#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "val.h"
#include "mergesort.c"
#include "bubblesort.c"
#include "selectionsort.c"
#include "quicksort.c"
#include "countingsort.c"
#include "insertionsort.c"

int main(int argc, char **argv)
{
    int val;
    if(argc == 2){
      val = atoi(argv[1]);
    }
    else{
      printf(" Input type \n \n 1. Array from keyboard \n \n 2. Random Array \n \n"); // Giving Choice to user 
      scanf("%d",&val);
    }
    int n;
    FILE *fptr;
    fptr = fopen("out.txt","w");    // opening file to write output
    fclose(fptr);
   // fptr = fopen("executionout.txt","w");    // opening file to write output
   // fclose(fptr);
   // fptr = fopen("compout.txt","w");    // opening file to write output
   // fclose(fptr);
   // FILE *swaptr,*compptr,*exeptr;
    fptr=fopen("out.txt","a");    // file to write swap data
   // compptr=fopen("compout.txt","a");   // file to write compare data
   // exeptr=fopen("executionout.txt","a");   // file to write execution data
    struct val res;
    int i;
    int *array;
    switch(val)
    {
    case 1:
            printf ("Enter number of elements");
            fflush(stdin);
            scanf("%d",&n);
            printf("\n \n Enter elements of array \n");
            array=(int*)malloc(n*sizeof(int));     // creating user array of size n
            for(int i=0;i<n;i++)
                scanf("%d",&array[i]);      // filling elements
            fflush(stdin);  // making sure that buffer is empty
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n \n I -> InsertionSort \n");
            char ch; scanf(" %c",&ch);
            switch(ch)
            {
                case 'B': res=bubblesort(array,n);  // Bubble Sort
                          printf("Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp); // writing in file
                          break;
                case 'Q': res=quick(array,n);
                          printf("Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'M': res=mergeSort(array,0,n-1);
                          printf("Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'C': res=countingsort(array,n);
                          printf("Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'S': res=selectionsort(array,n);
                          printf("Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                case 'I': res=Insertion(array,n);
                          printf("Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);  // writing in file
                          break;
                default: printf("Wrong Choice"); // Wrong choice by user
            }
            break;
    case 2:
           // fflush(stdin);      // Clearing input buffer
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n \n I -> InsertionSort \n");
            char che; scanf(" %c",&che);     // Asking user for choice

            switch(che)
            {
                case 'B':
                        {
                          i=10;
                          while(i<20001)
                          {
                            printf("i = %d\n", i);
                            array=(int*)malloc(i*sizeof(int));      // Creating array of size i
                            printf("Success");
                            for(int k=0;k<i;k++)
                              array[k]=rand() %100;              // Inserting random elements
                            struct val re=bubblesort(array,i);       // varriable to store result
                            printf("For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d \n\n",i,re.time,re.swap,re.comp);
                            fprintf(fptr,"%d,%d,%d,%f\n",i,re.swap,re.comp,re.time);
                         //   fprintf(compptr,"%d,%d\n",i,re.comp);
                          //  fprintf(exeptr,"%d,%f\n",i,re.time);
                            i+=1000;
                            free(array);
                          }
                          break;
                        }
                case 'Q':  i=10;
                          while(i<20001)
                          {
                          int *array=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            array[k]=rand()%i;                       // Inserting random elements
                          res=quick(array,i);                        // varriable to store result

                          printf("For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                            fprintf(fptr,"%d,%d,%d,%f\n",i,res.swap,res.comp,res.time);
                         //   fprintf(compptr,"%d,%d\n",i,re.comp);
                          //  fprintf(exeptr,"%d,%f\n",i,re.time);
                           i+=500;
                          free(array);
                          }
                          break;
                case 'M':  i=10;
                          while(i<20001)
                          {
                          int *array=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            array[k]=rand()%i;               // Inserting random elements
                          res=mergeSort(array,0,i-1);            // varriable to store result
                          printf("For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                           fprintf(fptr,"%d,%d,%d,%f\n",i,res.swap,res.comp,res.time);
                         //   fprintf(compptr,"%d,%d\n",i,re.comp);
                          //  fprintf(exeptr,"%d,%f\n",i,re.time);
                          i+=500;
                          free(array);
                          }
                           break;
                case 'C':  i=10000;
                          while(i<20001)
                          {
                          int *array=(int*)malloc(i*sizeof(int)); // Creating array of size i
                          for(int k=0;k<i;k++)
                            array[k]=rand()%i;                 // Inserting random elements
                          res=countingsort(array,i);             // varriable to store result
                          printf("For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                           fprintf(fptr,"%d,%d,%d,%f\n",i,res.swap,res.comp,res.time);
                         //   fprintf(compptr,"%d,%d\n",i,re.comp);
                          //  fprintf(exeptr,"%d,%f\n",i,re.time);
                          i+=1000;
                          free(array);
                          }
                          break;
                case 'S':  i=10;
                          while(i<20001)
                          {
                            int *array=(int*)malloc(i*sizeof(int));   // Creating array of size i
                            for(int k=0;k<i;k++)
                              array[k]=rand()%i;               // Inserting random elements
                            res=selectionsort(array,i);        // varriable to store result
                            printf("For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                             fprintf(fptr,"%d,%d,%d,%f\n",i,res.swap,res.comp,res.time);
                         //   fprintf(compptr,"%d,%d\n",i,re.comp);
                          //  fprintf(exeptr,"%d,%f\n",i,re.time);
                            i+=500;
                            free(array);
                          }
                           break;
                case 'I' :   i=10;
                          while(i<20001)
                          {
                            int *array=(int*)malloc(i*sizeof(int));   // Creating array of size i
                            for(int k=0;k<i;k++)
                              array[k]=rand()%i;               // Inserting random elements
                            res=Insertion(array,i);        // varriable to store result
                            printf("For %d elements \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d\n\n",i,res.time,res.swap,res.comp);
                             fprintf(fptr,"%d,%d,%d,%f\n",i,res.swap,res.comp,res.time);
                         //   fprintf(compptr,"%d,%d\n",i,re.comp);
                          //  fprintf(exeptr,"%d,%f\n",i,re.time);
                            i+=500;
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

