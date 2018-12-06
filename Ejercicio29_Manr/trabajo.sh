#PBS -l nodes=1:ppn=1,mem=16gb,walltime=00:00:30
#PBS -M n.manrique10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio26

#Quitar los comentarios de module para correr en el cluster
#module load anaconda/python3
#module load gcc/4.9.4


#Compila holaMundo.c (en openmp)
gcc -fopenmp holaMundo.c -o holaMundo.x

./holaMundo.x

#Compila holaMundo.c (en openmp)
gcc -fopenmp burgers.c -o burgers.x

#Redirige los datos al archivo burgers.dat
./burgers.x > burgers.dat

#Grafica
python3 burgers.py
