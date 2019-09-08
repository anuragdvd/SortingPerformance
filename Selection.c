#include<stdio.h>
#include<time.h>
int main()
{
    int number;
    scanf("%d",&number);
    int array[number],min,temp;
    for(int i=0;i<number;i++){
        scanf("%d",&array[i]);
    }
    clock_t start = clock();
    for(int i=0;i<number-1;i++){
        min = i;
        for(int j=i+1;j<number;j++){
            if(array[j]<array[min])
                min=j;
        }
        if(min != i){
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
    clock_t end = clock();
    for(int i=0;i<number;i++){
        printf("%d, ",array[i]);
    }
    double time_spent = (double)(end - start)/(CLOCKS_PER_SEC);
    printf("\n%lf",time_spent);
    return 0;
}