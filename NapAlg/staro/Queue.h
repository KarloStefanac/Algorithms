typedef struct queue{
    int x[100];
    int front = 0;
    int back = 0;
} Queue;

void Enqueue(Queue* q, int x){
    q->x[q->back] = x;
    q->back++;
}

int Dequeue(Queue* q){
    int res = q->x[q->front];
    if (q->front < q->back)
        q->front++;
    return res;
}
