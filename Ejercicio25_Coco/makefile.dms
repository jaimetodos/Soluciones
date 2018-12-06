sample.pdf: plots.py sample.dat
	python plots.py 

sample.dat: sample.x 
	./sample.x 2000 -4.5 1.8

sample.x: sample.c
	gcc sample.c -lm -o sample.x

clean:
rm -f sample.pdf sample.x sample.dat
