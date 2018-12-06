#!/bin/bash
#PBS -l nodes=1:ppn=4,mem=1gb,walltime=00:10:00
#PBS -M cm.borja10@uniandes.edu.co
#PBS -m abe
#PBS -N CristianBorja_Ejercicio30
#PBS -j oe


module load anaconda/python3
module load gcc/4.9.4
module load openmpi/1.8.5
cd /hpcfs/home/fisi4028/cm.borja10/CristianBorja_Ejercicio30
set OMP_NUM_THREADS=4
cd ADVEC
make
cd ..
cd WALK
make
