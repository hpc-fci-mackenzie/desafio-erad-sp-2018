#include <stdio.h>
#include <stdlib.h>

#define RANDNUM_W 521288629;
#define RANDNUM_Z 362436069;

unsigned int randum_w = RANDNUM_W;
unsigned int randum_z = RANDNUM_Z;

void srandnum(int seed) {
    unsigned int w, z;
    w = (seed * 104623) & 0xffffffff;
    randum_w = (w) ? w : RANDNUM_W;
    z = (seed * 48947) & 0xffffffff;
    randum_z = (z) ? z : RANDNUM_Z;
}

unsigned int randnum(void) {
    unsigned int u;
    randum_z = 36969 * (randum_z & 65535) + (randum_z >> 16);
    randum_w = 18000 * (randum_w & 65535) + (randum_w >> 16);
    u = (randum_z << 16) + randum_w;
    return (u);
}

int n, m, seed, **a, **b, **sum;

void allocMatrix();
void deallocMatrix();
void loadMatrix();
void calcNumMagico();

int main() {
  int i, j;
  scanf("%d %d %d", &n, &m, &seed);
  
  allocMatrix();

  loadMatrix();

  for(i=0; i<n; i++)
    for(j=0; j<m; j++)
      sum[i][j] = a[i][j] + b[i][j];

  calcNumMagico();

  deallocMatrix();
  return 0;
}

void loadMatrix() {
  int i, j;

  srandnum(seed);

  for(i=0; i<n; i++) 
    for(j=0; j<m; j++)
      a[i][j] = randnum()%100;
  
  for(i=0; i<n; i++) 
    for(j=0; j<m; j++)
      b[i][j] = randnum()%100;

  for(i=0; i<n; i++) 
    for(j=0; j<m; j++)
      sum[i][j] = 0.0;

}

void allocMatrix() {
  int i;

  a = (int **) malloc(sizeof(int *)*n);
  for(i=0; i<n; i++)
    a[i] = (int *) malloc(sizeof(int)*m);

  b = (int **) malloc(sizeof(int *)*n);
  for(i=0; i<n; i++)
    b[i] = (int *) malloc(sizeof(int)*m);

  sum = (int **) malloc(sizeof(int *)*n);
  for(i=0; i<n; i++)
    sum[i] = (int *) malloc(sizeof(int)*m);

}

void deallocMatrix() {
  int i;
  
  for(i=0; i<n; i++) 
    free(a[i]);
  free(a);

  for(i=0; i<n; i++) 
    free(b[i]);
  free(b);

  for(i=0; i<n; i++) 
    free(sum[i]);
  free(sum);

}

void calcNumMagico() {
  int j;
  double numMag, ma = 0.0, mb = 0.0 , ms1 = 0.0, ms2 = 0.0;
  for(int j=0; j<m; j++) {
    ma += a[0][j];
    mb += b[n-1][j];
  }
  ma = ma/m;
  mb = mb/m;
  for(int j=0; j<m/2; j++) {
    ms1 += sum[0][j];
  }
  for(int j=m/2; j<m; j++) {
    ms2 += sum[n-1][j];
  }
  ms1 /= m;
  ms2 /= m;

  numMag = (ms1*ms2)/1000;
  printf("%.5lf\n", numMag);
}
