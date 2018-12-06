#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#define PI 3.14159265358979323846264338327

int main(int argc, char **argv){
  /* Inicializamos variables*/
  long n_points;
  double x, y, r;
  double gauss_1, gauss_2;
  double *list;
  float mu, sigma;
  long long i;
  FILE *out;
  int rank, number;
  int n_points_proc;
  char filename[128];

  /*Esta es la seccion importante para paralelizar*/
  MPI_Init (&argc, &argv); /*Para inicializar*/
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);/*Para pedir el rango actual*/
  MPI_Comm_size (MPI_COMM_WORLD, &number);/*Para pedir el numero total de procesos*/

  /*Para leer los par[ametros y convertirlos al formato que corresponde*/
  n_points = atoi(argv[1]);
  mu = atof(argv[2]);
  sigma = atof(argv[3]);

  /*Este es el numero de puntos que asignamos a cada proceso*/
  n_points_proc = n_points / number;

  /*Para manejar problemas alocando memoria en la lista donde guardaremos los num aleatorios*/
  if(!(list=malloc(n_points_proc * sizeof(double)))){
    fprintf(stderr, "Problema con la reserva de memoria\n");
    exit(1);
  }
   
  /*Aca generamos los numeros aleatorios que le corresponden a cada proceso*/
  srand48(rank);/*El seed es diferente para cada proceso(rank)*/
  for(i=0;i<n_points_proc;i++){    
      x = drand48();
y = drand48();
      gauss_1 = sqrt(-2.0 * log(x)) * cos(2.0* PI * y);
      gauss_2 = sqrt(-2.0 * log(x)) * sin(2.0* PI * y);
      
      gauss_1 = gauss_1*sigma + mu;
      list[i] = gauss_1;
  }

  /*El nombre del archivo lleva el numero del proceso*/
  sprintf(filename, "sample_%d.dat", rank);
  /*Intentamos abrir el archivo*/
  if(!(out = fopen(filename, "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }
  /*Imprimimos los numeros en el archivo correspondiente*/
  for(i=0;i<n_points_proc;i++){
    fprintf(out, "%f\n", list[i]);
  }

  fclose(out);/*Cerramos el archivo*/
  
  MPI_Barrier(MPI_COMM_WORLD);/*Esto bloquea hasta que todos los procesos terminan su rutina*/
  MPI_Finalize(); /*Finaliza MPI*/
  return 0;
}
