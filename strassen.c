#include <stdio.h>
#include <sys/resource.h>
#include <math.h>
#include <stdlib.h>
// #include <malloc.h>

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
    int seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
    struct rusage ptempo;

    getrusage(0, &ptempo);

    seg_CPU = ptempo.ru_utime.tv_sec;
    mseg_CPU = ptempo.ru_utime.tv_usec;
    seg_sistema = ptempo.ru_stime.tv_sec;
    mseg_sistema = ptempo.ru_stime.tv_usec;

    *seg_CPU_total = (seg_CPU + 0.000001 * mseg_CPU);
    *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}

void strassen(int L1, int M1[L1][L1], int M2[L1][L1], int MF[L1][L1]){

}

int main()
{

  double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;

  int tam = 100;
  int coef;
  printf("Digite o coeficiente que ficará dentro das matrizes: ");
  scanf("%d",&coef);

  int M1[tam][tam];
  int M2[tam][tam];
  for (int i = 0; i < tam; i++ )
    for (int j = 0; j < tam; j++ )
    {
      M1[i][j] = coef;
      M2[i][j] = coef;
    }
  int MF[tam][tam];


  Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

  strassen(tam, M1, M2, MF);

  Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

  printf("\nTempo de CPU total = %f\n", s_CPU_final - s_CPU_inicial);

    return 0;
}