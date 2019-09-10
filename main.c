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


    printf(" Input type \n \n 1. Array from keyboard \n \n 2. Random Array \n \n");
    int val;
    scanf("%d",&val);
    int n;

    FILE *fptr;
    fptr = fopen("out.txt","w");
    struct val res;


    int i;
    switch(val)
    {
    case 1: system("cls");
            printf ("Enter number of elements");
            scanf("%d",&n);
            printf("\n \n Enter elements of array \n");
            int *a=(int*)malloc(n*sizeof(int));
            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
            fflush(stdin);
            system("cls");
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n");
            char ch; scanf("%c",&ch);

            switch(ch)
            {
                case 'B': res=bubblesort(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);
                          break;
                case 'Q': res=quick(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);
                          break;
                case 'M': res=mergeSort(a,0,n-1);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);
                          break;
                case 'C': res=countingsort(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);
                          break;
                case 'S': res=selectionsort(a,n);
                          fprintf(fptr,"Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",res.time,res.swap,res.comp);
                          break;
                default: system("cls"); printf("Wrong Choice");
            }
            break;
    case 2:
            fflush(stdin);
            system("cls");
            printf("Enter the sort you want to perform \n \n \n B -> Bubble sort \n \n Q -> Quicksort \n \n M -> MergeSort \n \n C -> CountSort \n \n S -> SelectionSort \n");
            char che; scanf("%c",&che);
            switch(che)
            {
                case 'B':
                          i=10;
                          while(i<100)
                          {
                          int *ar=(int*)malloc(i*sizeof(int));
                          for(int k=0;k<i;k++)
                            ar[i]=rand() %100;
                          struct val re=bubblesort(ar,i);
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d \n",i,re.time,re.swap,re.comp);
                          i*=10;
                          }
                          break;
                case 'Q':  i=10;
                          while(i<100)
                          {
                          int *a=(int*)malloc(i*sizeof(int));
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;
                          res=quick(a,i);

                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                          break;
                case 'M':  i=10;
                          while(i!=100)
                          {
                          int *a=(int*)malloc(i*sizeof(int));
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;
                          res=mergeSort(a,0,i-1);
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                           break;
                case 'C':  i=10;
                          while(i!=100)
                          {
                          int *a=(int*)malloc(i*sizeof(int));
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;
                          res=countingsort(a,i);
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                          break;
                case 'S':  i=10;
                          while(i!=100)
                          {
                          int *a=(int*)malloc(i*sizeof(int));
                          for(int k=0;k<i;k++)
                            a[i]=rand()%i;
                          res=selectionsort(a,i);
                          fprintf(fptr,"For %d elements \n \n Time taken for execution : %f \n Number of swaps made : %d \n Number of comparison made : %d",i,res.time,res.swap,res.comp);
                          i*=10;
                          }
                           break;
                default: system("cls"); printf("Wrong Choice");
            }
            break;
    default: system("cls");
            printf("Wrong Choice");


    }
}
