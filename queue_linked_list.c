#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* f = NULL;
struct Node* r = NULL;

void enqueue(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r = n;
        }

    }
}
int dequeue(){
    int val = -1;
    struct Node* ptr = f;
    if(f == NULL){
        printf("Empty");
    }
    else{
    f = f->next;
    val = ptr->data;
    free(ptr);
    }
}
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    enqueue(5);
    enqueue(10);
    enqueue(51);
    enqueue(52);
    enqueue(54);
    linkedListTraversal(f);
    dequeue();
    linkedListTraversal(f);


}
