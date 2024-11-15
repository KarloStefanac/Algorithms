#include <stdio.h>

typedef struct stack{
    int x[100];
    int sp = 0;
} Stack;

void Push(Stack* s, int val){
    s->x[s->sp] = val;
    s->sp++;
    printf("Pushed %d\n", val);
}

int Pop(Stack* s){
    int result = s->x[s->sp];
    if (s->sp>0){
        s->sp--;
    }else{
        printf("Stack underflow");
        return -1;
    }
    printf("Popped %d\n", result);
    return result;
}
