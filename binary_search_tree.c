#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right ;
    struct node* left ;

};
//creating node
struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node* search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key == root->data){
        return root;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else if( key > root->data){
        return search(root->right,key);
    }
}
int main(){
    struct node* root = createNode(8);
    struct node* p1 = createNode(7);                    
    struct node* p2= createNode(9);
    struct node* p3 = createNode(5);
    struct node* p4 = createNode(10);
    struct node* p5 = createNode(12);
    //linking nodes
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p2->right = p4;
    p4->right = p5;
    if(isBST(root)){
        printf("It is a binary search tree\n");
    }
    else{
        printf("It is not a binary search tree\n");

    }
    struct node * s = search(root,7);
    if(s!=NULL){
        printf("Found: %d ",s->data);
    }
    else{
        printf("Not Found");
    }




}

