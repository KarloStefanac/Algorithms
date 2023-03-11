#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//parni na pocetak liste, neparni na kraj, nula nista

typedef struct lista{
        int x;
        struct lista *next;
}LIST;

LIST* DodajPocetak(LIST *root, int value){
        LIST *temp;
        temp = (LIST*)malloc(sizeof(LIST));
        temp->x = value;
        temp->next = root;
        root = temp;

        return root;
}

void DodajKraj(LIST* root, int value){
        LIST *temp;
        temp = (LIST*)malloc(sizeof(LIST));
        temp = root;
        while (temp->next!=NULL){
                temp = temp->next;
        }
        LIST *novi;
        novi = (LIST*)malloc(sizeof(LIST));
        novi->x = value;
        novi->next = NULL;
        temp->next = novi;
}

int main(void){
        srand(time(NULL));
        LIST *root = NULL;
        int n,i,value;
        scanf("%d",&n);
        for (i = 0;i < n;i++){
                value = rand() % 24;
                if (root==NULL){
                        root = (LIST*)malloc(sizeof(LIST));
                        root->x = value;
                        root->next = NULL;
                }
                else if (value!=0){
                        if (value%2==0){
                                root = DodajPocetak(root,value);
                        }
                        else{
                                DodajKraj(root,value);
                        }
                }
        }
        LIST *temp;
        temp = (LIST*)malloc(sizeof(LIST));
        temp = root;
        while(temp->next!=NULL){
                printf("%d ",temp->x);
                temp = temp->next;
        }
        printf("%d",temp->x);
        printf("\n%d",root->x + temp->x);
        return 0;
}

