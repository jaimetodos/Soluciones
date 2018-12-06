#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{

  double L=4;
  double tmax=0.5;
  double dx=0.01;
  double dt=0.01;
  int nx,nt,n,i;
  nx=L/dx+1;
  nt=tmax/dt+1;
  double F[nx];
  //inicializa u
  double u[nx];
  //Copia de u
  double cu[nx];
  for(n=0;n<nx;n++)
  {
    if(n<200) 
    {
      u[n]=1;
    }
    else
    {
      u[n]=0;
    }
    cu[n]=u[n];
    //Se imprime la condicion inicial espacial (a la terminal)
    printf("%lf\n",cu[n]);
  }
  //Desarrollo temporal
  for(i=0;i<nt;i++)
  {
    //Se inicia un for en paralelo, no hay competencia por sobreescribir variables
    #pragma omp parallel for shared(cu)
    for(n=1;n<nx-1;n++)
    {
      //Se encuentra u para t+1 por medio de ecuacion de adveccion
      cu[n] =0.5*(u[n+1]+u[n-1])-0.25*dt*(u[n+1]*u[n+1]-u[n-1]*u[n-1])/dx;
    }
    //Se inicia un for en paralelo, no hay competencia por sobreescribir variables
    #pragma omp parallel for shared(u)
    for(n=1;n<nx-1;n++)
    {
      //Se escribe en u los valores de la copia de u
      u[n] = cu[n];
    }
  }
  //Se imprime u para un desarrollo temporal de tmax=5
  for(n=0;n<nx;n++)
  {
    printf("%lf\n",u[n]);
  }
  return 0;
}
