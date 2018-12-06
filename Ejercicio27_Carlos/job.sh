#PBS -l nodes=1:ppn=16,mem=1gb,walltime=00:10:00
#PBS -M cf.navarrete969@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
cd /hpcfs/home/fisi4028/cf.navarrete969/CarlosNavarrete_Ejercicio27/
rm -f *.dat
mpicc sample.c -o sample.x
mpirun -np 10 ./sample.x 10000 0.0 1.0
