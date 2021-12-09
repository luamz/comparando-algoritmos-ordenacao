#include<stdio.h>
#include <unistd.h> 
#include <sys/resource.h>

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
  long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
  struct rusage ptempo;

  getrusage(0,&ptempo);

  seg_CPU = ptempo.ru_utime.tv_sec;
  mseg_CPU = ptempo.ru_utime.tv_usec;
  seg_sistema = ptempo.ru_stime.tv_sec;
  mseg_sistema = ptempo.ru_stime.tv_usec;

 *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
 *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}

int main(){
    double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
    printf("abb");
    sleep(5);
    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

    printf ("Tempo de CPU total = %f\n", s_CPU_final - s_CPU_inicial);
}
