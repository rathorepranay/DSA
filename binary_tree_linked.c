#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int data){
    struct node* n  = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n-> right = NULL;
    return n;
}
void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->data);
    }
}
void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node* p = createNode(7);
    struct node* p1 = createNode(2);
    struct node* p2 = createNode(1);
    struct node* p3 = createNode(0);
    struct node* p4 = createNode(4);


    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("Preorder traversal: ");
    preOrder(p);
    printf("\n");
    printf("Postorder traversal: ");
    postOrder(p);
    printf("\n");
    printf("Inorder traversal: ");
    inOrder(p);
    

}