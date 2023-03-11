#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1],R[n2];

	for (i=0;i<n1;i++)
		L[i] = arr[l+i];
	for (j=0;j<n2;j++)
		R[j] = arr[m+1+j];
	i=0;j=0;k=l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[j];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}
}

void mergesort(int arr[], int l, int r){
	if (l<r){
		int m = l+(r-l) / 2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
	srand(time(NULL));
	int *arr;
	int n,i;
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++){
		arr[i] = rand()%30;
	}
	printf("\n");
	printArray(arr,n);
	mergesort(arr,0,n-1);
	printArray(arr,n);
}
