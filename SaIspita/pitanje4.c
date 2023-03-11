#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista_{
	int x;
	struct Lista_ *next;
}Lista;

Lista* StvoriListu(Lista* root, int x){
	root = (Lista*)malloc(sizeof(Lista));
	root->x = x;
	root->next = NULL;
	return root;
}
void NaKraj(Lista* root, int x){
	Lista *temp = NULL;
	temp = (Lista*)malloc(sizeof(Lista));
	temp = root;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	Lista *novi = NULL;
	novi = (Lista*)malloc(sizeof(Lista));
	novi->x = x;
	novi->next = NULL;
	temp->next = novi;
}
void IspisListe(Lista *root){
	Lista *temp = NULL;
	temp = (Lista*)malloc(sizeof(Lista));
	temp = root;
	while(temp!=NULL){
		printf("%d ",temp->x);
		temp = temp->next;
	}
	printf("\n");
}
void UrediListu(Lista *root){
	Lista *temp = NULL;
	temp = (Lista*)malloc(sizeof(Lista));
	Lista *cuva = NULL;
	cuva = (Lista*)malloc(sizeof(Lista));
	temp = root;
	while(temp!=NULL){
		Lista *novi = NULL;
		novi = (Lista*)malloc(sizeof(Lista));
		novi->x = temp->x + temp->next->x;
		temp = temp->next;
		cuva = temp->next;
		temp->next = novi;
		novi->next = cuva;
		temp = temp->next->next;
	}
}
int main(){
	srand(time(NULL));
	Lista *root = NULL;
	root = (Lista*)malloc(sizeof(Lista));
	root = StvoriListu(root,rand()%30-5);
	int i;
	for(i=0;i<5;i++){
		NaKraj(root,rand()%30-5);
	}
	IspisListe(root);
	UrediListu(root);
	IspisListe(root);
	return 0;
}
