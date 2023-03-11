#include <stdio.h>

#define NMAX 100

int S[100][100];

int main() {
    int N, U, V, K, i, j;
    scanf("%d",&N);
    for (i=0; i<N; i++)
      for (j=0; j<N; j++) scanf("%d",&S[i][j]);
    scanf("%d%d%d",&U,&V,&K);
    U--; V--;
    int k,l;
    // ZA NAPRAVITI: izračunati broj puteva od U do V duljine K.
    
    for (i=0; i<N; i++){
      for (j=0; j<N; j++) printf("%d ",temp[i][j]);
    printf("\n");}
    return 0;
}
