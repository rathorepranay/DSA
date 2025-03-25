#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int front;
    int back;
    int * arr;
};
int isEmpty(struct circularQueue*q){
    if(q->front == q->back){
        return 1;
    }
    return 0;
}
int isFull(struct circularQueue*q){
    if((q->back+1)%q->size == q->front){
        return 1;
    }
    return 0;
}
void enqueue(struct circularQueue*q,int val){
    if(isFull(q)){
        printf("Queue is Full");
    }
    else{
        q->back = (q->back+1)%q->size;
        q->arr[q->back] = val;
        printf("Added element is %d\n",val);
    }
}
int dequeue(struct circularQueue*q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty");
    }
    else{
        q->front = (q->front+1)%q->size;
        a = q->arr[q->front];
    }
    return a;
}
void traverse(struct circularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    
    int i = (q->front + 1) % q->size; // Start from front+1 since front points to the last dequeued element
    printf("Queue elements: ");
    
    while (i != (q->back + 1) % q->size) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size; // Move circularly
    }
    printf("\n");
}

int main(){
    struct circularQueue q;
    q.size = 10;
    q.front = q.back = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q,20);
    enqueue(&q,2);
    enqueue(&q,0);
    enqueue(&q,10);
    traverse(&q);
    dequeue(&q);
    traverse(&q);


}