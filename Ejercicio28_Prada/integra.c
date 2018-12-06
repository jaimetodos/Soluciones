#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"

/* git commit -m "Second commit" */

/* COMPILO CON mpicc integra.c -o integra.x -lm Y EJECUTO CON mpiexec -n 4 ./integra.x N */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#define PI 3.14159265358979323846264338327

int main(int argc, char **argv)
{
	int n_points;
	float mu, sigma; /* promedio y desv.estandar */
	int i;
	int j;
	int deg = 10; /* grado de la funcion a integrar */
	int rank, number;
	int n_points_proc;
	char filename[128];
	double sum, myintegral, integral;

	/* Comienza el MPI */
	MPI_Init (&argc, &argv);
	/* Comunica el rank del proceso actual */
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	/* Comunica el numero de procesos en total */
	MPI_Comm_size (MPI_COMM_WORLD, &number);

	/* es el N que recibe por parametro como string y lo convierte en int */
	n_points = atoi(argv[1]);
	/* numero de puntos que se le va a pasar a cada procesador */
	n_points_proc = n_points/number;

	myintegral = 0.0;
	srand48(rank); 
	
	/* Calcula la integral */
	for( i = 0; i < n_points_proc; i++)
	{    
		sum = 0.0;
		for( j = 0; j < deg; j++)
		{
			sum += drand48();
		}
		sum = pow(sum,2);
		myintegral +=sum;
	}

	myintegral /= n_points_proc; /* eq myintegral = myintegral / n_points_proc */

	/* Aplica un operador de reduccion sobre todos los trabajos en el comunicador y pone el resltado del trabajo del proceso en el buffer */
	MPI_Reduce(&myintegral, &integral, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	/* el procesador de rango cero toma los resultados de los demas procesadores , los promedia y devuelve el resultado de la integral */
	if( rank == 0 )
	{
		integral /= number;
		fprintf(stdout, "%d %e %e\n", n_points, integral, fabs(integral - 155.0/6.0));
	}
	
	/* Termina el MPI */
	MPI_Finalize(); 

	return 0;
}
