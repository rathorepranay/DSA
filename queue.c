#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int back;
    int * arr;
};
int isEmpty(struct queue* q){
    if(q->back == q->front){
        return 1;
    }
    return 0;
}
int isFull(struct queue * q){
    if(q->back == q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue is  Full");
    }
    else{
        q->back++;
        q->arr[q->back] = val;
        printf("Element added is %d\n",val);
    }
}
int dequeue(struct queue* q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void traverse(struct queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        int i = q->front + 1;
        while(i <= q->back){
            printf("%d ", q->arr[i]);
            i++;
        }
        printf("\n");
    }
}
int main(){
    struct queue q;
    q.size = 10;
    q.front = q.back = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    enqueue(&q,5);
    traverse(&q);
    dequeue(&q);
    traverse(&q);

}