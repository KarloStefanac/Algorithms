#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size = 20;
typedef struct Stack_{
	int sp;
	int array[20];
}Stack;
int IsEmpty(Stack *s){
	if (s->sp<0) return 1;
	return 0;
}
void ClearStack(Stack *s){
	s->sp = 0;
}
int Pop(Stack *s){
	if (IsEmpty(s)) printf("Illegal pop! Aborting...");
	int x = s->array[s->sp];
	s->sp=(s->sp)-1;
	return x;
}

void Push(Stack *s, int value){
	if (s->sp > size) {printf("Illegal push! Aborting...");}
	s->sp = s->sp + 1;
	s->array[s->sp] = value;
}

int main(){
	Stack *s = NULL;
	s = (Stack*)malloc(sizeof(Stack));
	ClearStack(s);
	int n, **matrix;
	int i;
	scanf("%d",&n);
	matrix = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++){
		matrix[i] = (int*)malloc(n*sizeof(int));
	}int j;
	for (i = 0; i < n; i++){
		for (j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);
		}	
	}
	int start,*visited;
	visited = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++){
		visited[i] = 0;
	}
	scanf("%d",&start);
	visited[start-1] = 1;
	Push(s,start-1);
	while(!IsEmpty(s)){
		int node = Pop(s);
		printf("%d ",node+1);
		for (i=0;i<n;i++){
			if (matrix[node][i] == 1 && visited[i]==0){
				Push(s,i);
				visited[i] = 1;
			}
		}
	}

	return 0;
}
