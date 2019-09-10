//program for bubble sort

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main ()
{
    clock_t start, end;
    double cpu_time;
    int n , i, j,k,l=0,temp=0;                          //defining variables
    printf("Enter the number of elements you want to sort\nUsing Bubble Sort Algorithm \t :");
    scanf("%d", &n);                                    //asking user for number of entries in the array
    int arr[n];                                         //declaring the array
    fflush(stdin);
    for (i=0;i<n;i++)
        {
            printf("ENTER %d element \t:\t" , i+1);
            scanf("%d", &arr[i]);
        }                                               //asking for values from user
    start = clock();                                    //program starts to measure time from here
    for(k=0;k<n-1;k++)                                  //sorting the array
    {
        for (j=0;j<n-k-1;j++)
        {
            if (arr[j]>arr[j+1] )                       //swapping the elements in array which are not in order
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    end=clock();                                        //program stops to measure time here
   for(l=0;l<n;l++)
        {
            printf("%d \n" , arr[l]);                    //printing the array

        }                                              
    cpu_time=((double)(end-start))/CLOCKS_PER_SEC;      //calculating CPU time used
    printf("time taken in sorting the array is %lf sec", cpu_time);
    return 0;

}
