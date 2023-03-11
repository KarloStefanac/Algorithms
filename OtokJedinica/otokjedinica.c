#include <stdio.h>

#define M 5
#define N 5
int A[M][N] = {
    0, 1, 0, 1, 1,
    0, 0, 1, 0, 1,
    1, 1, 0, 0, 1,
    0, 1, 1, 1, 1,
    0, 0, 0, 0, 0
};

int pov;

void povrsina(int x, int y) {
  if (A[x][y]==1) {
      pov++;
      A[x][y] = 2;
  } else return;
  if (x-1>=0) povrsina(x-1,y);
  if (x+1<M) povrsina(x+1,y);
  if (y-1>=0) povrsina(x,y-1);
  if (y+1<N) povrsina(x,y+1);
}

int main() {
    int maxpov = 0, i, j;
    for (i=0; i<M; i++)
      for (j=0; j<N; j++)
        if (A[i][j]==1) {
            pov = 0;
            povrsina(i,j);
            if (pov>maxpov) maxpov = pov;
        }
    printf("%d\n",maxpov);
    return 0;
}

