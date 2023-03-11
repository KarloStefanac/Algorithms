#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heapSize = 10;


void heapify(int arr[],int i,int size){
    int max;
    int l = i*2 + 1;
    int d = i*2 + 2;
    if (l<size && arr[i] < arr[l])
        max = l;
    else max = i;
    if (d<size && arr[max] < arr[d])
        max = d;
    if (max!=i){
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr,max,size);
    }
}

void heapsort(int arr[]){
    int i;
    int size = heapSize - 1;
    for (i = (size - 1) / 2; i >=0; i--) heapify(arr,i,heapSize);
    for (i=size; i > 0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr,0,i);
    }
}

int main(){
    srand(time(NULL));
    int i;
    scanf("%d",&heapSize);
    int *arr;
    arr = (int*)malloc(heapSize*sizeof(int));
    for (i=0;i<heapSize;i++){
        arr[i] = rand()%101 - 1;
    }
    for (i=0;i<heapSize;i++){
        if (i == heapSize - 1)
            printf("%d",arr[i]);    
        else printf("%d,",arr[i]);
    }
    heapsort(arr);
    printf("\n");
    for (i=0;i<heapSize;i++){
        if (i == heapSize - 1)
            printf("%d",arr[i]);    
        else printf("%d,",arr[i]);
    }
    printf("\n");
    return 0;
}
