#include "stack.h"
#include "Queue.h"
#include <cstdlib>

typedef struct node {
    int x;
    struct node *left;
    struct node *right;
} Node;

Node* addNode(int x){
    Node* newNode = (Node *)malloc(sizeof(struct node));
    newNode->x = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Preorder(Node* node){
    if (node == NULL) return;
    printf("%d, ", node->x);
    if (node->left != NULL) { Preorder(node->left); }
    if (node->right != NULL) {Preorder(node->right); }
}

void Inorder(Node* node){
    if (node == NULL) return;
    if (node->left != NULL) { Inorder(node->left); }
    printf("%d, ", node->x);
    if (node->right != NULL) { Inorder(node->right); }
}

void Postorder(Node* node){
    if (node==NULL) return;
    if (node->left != NULL) { Postorder(node->left); }
    if (node->right != NULL) { Postorder(node->right); }
    printf("%d,", node->x);
}

Node* makeTree(){
    Node* root = NULL;
    Node* temp = NULL;
    root = addNode(50);
    root->left = addNode(25);
    root->right = addNode(100);
    temp = root->left;
    temp->left = addNode(12);
    temp->right = addNode(37);
    temp->left->left = addNode(6);
    temp = root->right;
    temp->right = addNode(150);
    temp->right->left = addNode(125);
    temp->right->right = addNode(175);
    return root;
}

int searchTree(Node* node, int val, Node **parent){
    if (node==NULL) return 0;
    if (node->x == val) return 1;
    *parent = node;
    if (val < node->x) {
        return searchTree(node->left, val, parent);
    }
    else { return searchTree(node->right, val, parent); }
}

Node* Insert(Node* root, int val){
    Node *node = root;
    Node *parent = NULL, *newNode;
    if (searchTree(node, val, &parent)) { return node; }
    else{
        newNode = (Node*)malloc(sizeof(struct node));
        newNode->x = val;
        newNode->left = NULL;
        newNode->right = NULL;
        if (parent==NULL) return newNode;
        else{
            if(val < parent->x) { parent->left = newNode; }
            else { parent->right = newNode; }
        }
    }
    return root;
}

Node* SmallestNode(Node* node){
    Node* t = node;
    while (t != NULL){
        t = t->left;
    }
    return t;
}

Node* DeleteNode(Node* node, int val){
    Node *t;
    if (node==NULL) {return node;}
    if (node->x > val) {
        node->left = DeleteNode(node->left, val);
    }
    else if (node->x < val) {
        node->right = DeleteNode(node->right, val);
    }
    else {
        if (node->left == NULL){
            t = node->right;
            free(node);
            return t;
        }else if (node->right == NULL){
            t = node->left;
            free(node);
            return t;
        }
        t = SmallestNode(node->right);
        node->x = t->x;
        node->right = DeleteNode(node->right,  t->x);
    }
    return node;
}

int main(){
    Node* root = makeTree();
    Stack *s = (Stack *)malloc(sizeof(struct stack));
    Queue *q = (Queue *)malloc(sizeof(struct queue));
    //Inorder(root);
    //printf("\n");
    //Preorder(root);
    //printf("\n");
    //Postorder(root);
    //printf("\n");

    Node* parent = NULL;
    root = Insert(root, 13);
    root = Insert(root, 26);
    root = Insert(root, 180);
    Inorder(root);
    printf("\n");

    root = DeleteNode(root, 26);
    Inorder(root);
    printf("\n");
    return 0;
}
