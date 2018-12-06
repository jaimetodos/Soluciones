#!/bin/bash
#PBS -l nodes=1:ppn=1, mem=1gb,walltime=00:05:00
#PBS -M jd.prada11@uniandes.edu.co
#PBS -m abe
#PBS -N JuanPrada_Ejercicio27

# COMPILO CON chmod u+x torque2.sh Y EJECUTO CON ./torque2.sh 

# Borro los archivos que no me sirven, en particular el .txt para no sobreescribir
rm -f *.txt integra

# Compilo el .c 
mpicc integra.c -o integra -lm

# Ejecuto el .c en un for para cada valor de N y escribo los datos en txt .el
for i in 1000 10000 100000 1000000 10000000 100000000; 
do 
	mpiexec -n 4 ./integra $i >> data.txt 
done 

# Lee los datos y grafica el error porcentual de la integral numerica respecto a la analitica
python plots.py 

rm integra
 
