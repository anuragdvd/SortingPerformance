#include<stdio.h>
int quicksort(int [],int,int);
int main()
{
    int number;
    scanf("%d",&number);
    int array[number];
    for(int i=0;i<number;i++){
        scanf("%d",&array[i]);
    }
    quicksort(array,0,number-1);
    printf("The Sorted Order is: ");
    for(int i=0;i<number;i++)
        printf(" %d",array[i]);
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