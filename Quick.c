#include<stdio.h>
#include<time.h>
int quicksort(int [],int,int);
int main()
{
      int number; // Takes the value of number of integer user want to enter
    scanf("%d",&number);
    int array[number];
    for(int i=0;i<number;i++){
        scanf("%d",&array[i]);
    }
    clock_t start = clock();
    quicksort(array,0,number-1);
    clock_t end = clock();
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);
    printf("The Sorted Order is: ");
    for(int i=0;i<number;i++){
        printf(" %d",array[i]);
    }
    printf("\nTime taken to sort the array = %lf",time_spent);
    return 0;
} 

int quicksort(int array[],int first,int last)
{
    int i,j,q,swap_count=0,temp;
    if(first<last){
        q=first;
        i=first;
        j=last;
        while(i<j){
            while(array[i]<=array[q] && i<last)
                i++;
            while(array[j]>array[q])
                j--;
            if(i<j){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                swap_count++;
            }
        }
        temp=array[q];
        array[q]=array[j];
        array[j]=temp;
        quicksort(array,first,j-1);
        quicksort(array,j+1,last);
    }
}