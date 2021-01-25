#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define MAX 10005

typedef struct Ponto{
  double X, Y;
} Ponto;

Ponto a[MAX];

double distancia(Ponto p1, Ponto p2) {
  double dx = p1.X - p2.X;
  double dy = p1.Y - p2.Y;
  return sqrt((dx * dx) + (dy * dy));
}

int cmp_x(const void *a, const void *b) {
  Ponto *p1 = (Ponto *) a;
  Ponto *p2 = (Ponto *) b;
  return (p1->X - p2->X);
}

int cmp_y(const void *a, const void *b) {
  Ponto *p1 = (Ponto *) a;
  Ponto *p2 = (Ponto *) b;
  return (p1->Y - p2->Y);
}

double CPP_FB(Ponto *Px, long i, long f){
  double d = 999999, dist;
  for (int k = i; k < f-1; k++) {
    for (int x = k + 1; x < f; x++) {
      dist = distancia(Px[k], Px[x]);
      if (dist < d)
        d = dist;
    }
  }
  return d;
}

double CPP(Ponto *Px, long i, long f){
  if ((f - i) < 3)
    return CPP_FB(Px, i, f);

  int m = (i + f) / 2, cont = 0;
  double dist;
  double d1 = CPP(Px, i, m);
  double d2 = CPP(Px, m + 1, f);
  double d = min(d1, d2);
  Ponto front[MAX];
  double xm = Px[m].X;

  for (int k = i; k < f; k++){
    if (abs(Px[k].X - xm) < d){
      front[cont] = Px[k];
      cont++;
    }
  }

  qsort(front, cont, sizeof(Ponto), cmp_y);

  for (int k = 0; k < cont-1; k++){
    for (int x = k + 1; x < cont; x++){
      if (abs(front[x].Y - front[k].Y) > d)
        break;

      dist = distancia(front[k], front[x]);
      if (dist < d)
        d = dist;
    }
  }
  return d;
}

int main() {
  int N;
  while (1){
    scanf("%d", &N);
    if (N <= 0)
      break;

    for (int i = 0; i < N; i++){
      scanf("%lf %lf", &a[i].X, &a[i].Y);
    }

    qsort(a, N, sizeof(Ponto), cmp_x);

    double d = CPP(a, 0, N-1);
    if (d > 10000)
      printf("INFINITY\n");
    else
      printf("%.4f\n", d);
  }
  return 0;
}