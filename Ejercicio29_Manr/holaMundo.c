#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
    //Inicia el espacio en paralelo
    #pragma omp parallel
    {
        //A cada hilo le manda el comando
        int thread_id = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
        //Imprime hola desde cada hilo
	printf("Hello from thread number: %d out of: %d\n",thread_id, thread_count);
    }
    return 0;

}
