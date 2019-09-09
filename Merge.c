#include<stdio.h>
#include<time.h>
int mergesort(int [],int,int);
int merging(int [],int,int,int);
int main()
{
    int number;
    scanf("%d",&number);
    int array[number];
    for(int i=0;i<number;i++){
        scanf("%d",&array[i]);
    }
    clock_t start = clock();
    mergesort(array,0,number);
    clock_t end = clock();
    printf("Sorted Array :  ");
    for(int i=0;i<number;i++){
        printf("%d , ",array[i]);
    }
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);
    printf("\nTime taken to sort the array = %lf",time_spent);
    return 0;
}

int mergesort(int array[],int first,int last){
    if(first<last){
        int dwon_to_1=(first+last)/2;
        mergesort(array,first,dwon_to_1);
        mergesort(array,dwon_to_1+1,last);
        merging(array,first,dwon_to_1,last);
    }
}

int merging(int array[],int first,int down_to_1,int last){
    int n1,n2;
    n1=down_to_1-first+1;
    n2=last-down_to_1;
    int left[n1+1],right[n2+1];
    for(int i=0;i<n1;i++){
        left[i]=array[first+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=array[down_to_1+j+1];
    }
    left[n1]=9999;
    right[n2]=9999;
    int i=0,j=0;
    for(int k=first;k<last;k++){
        if(left[i]<right[j]){
            array[k]=left[i];
            i++;
        }
        else{
            array[k]=right[j];
            j++;
        }
    }
}