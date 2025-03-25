#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    else{return 0;}
}
int isFull(struct Node* top){
    struct Node*n = (struct Node*)malloc(sizeof(struct Node));
    if(n == NULL){return 1;}
    else{return 0;}
}
struct Node* push(struct Node* top,int val){
    if(isFull(top)){printf("Stack overflow\n");}
    else{
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = val;
        new->next = top;
        top = new;
        return top;
    }
}
struct Node* pop(struct Node* top){
    if(isEmpty(top))
    {
        printf("Stack underflow");
        }
    else{
        struct Node*n = top;
        top = top->next;
        printf("Popped value is:%d\n",n->data); 
        free(n);
        return top;
    }
}
int peek(struct Node* top,int pos){
    if(isEmpty(top)){
        printf("Stack is empty");
    }
    else{
        struct Node* p = top;
        for(int i =0; (i<pos-1&&p!=NULL);i++){
            p=p->next;
        }
        if(p!=NULL){
            return p->data;
        }
        else{
            return -1;
        }
    }
}
int stackTop(struct Node* top){
    return top->data;
}
int stackBottom (struct Node*top) {
    struct Node*ptr=top;
    while (ptr->next!=NULL) {
        ptr=ptr->next;
    }
    return ptr->data;
}
void traverse(struct Node* top){
    if(isEmpty(top)){printf("Stack is empty");}
    else{
        struct Node* p = top;
        int i = 0;
        while(p!=NULL){
            printf("Element at %d is : %d\n",i+1,p->data);
            p=p->next;
            i++;
        }
    }
}
int main(){
    struct Node* top = NULL;

    int size;
    printf("Enter elements you want to store in Stack :");
    scanf("%d",&size);
    for(int i = 0; i<size; i++){
        int value;
        printf("Enter element %d : ",i+1);
        scanf("%d",&value);
        top=push(top,value);
    }
    printf("Stack after pushing elements\n");
    printf("------------------------------------\n");
    traverse(top);
    printf("Stack after poppong elements\n");
    printf("------------------------------------\n");
    top = pop(top);
    traverse(top);
    printf("Element at position is: %d\n",peek(top,4));
    printf("Bottom Element is : %d\t",stackBottom(top));
        printf("Top Element is : %d",stackTop(top));



}