histograms.pdf: parallel.dat serial.dat
	python graph.py
parallel.dat:  parallel.x
	./parallel.x > parallel.dat
serial.dat: serial.x
	./serial.x > serial.dat
serial.x parallel.x: 
	gcc walkSerial.c -o serial.x 
	gcc -fopenmp walkParallel.c -o parallel.x 



clean:
	rm *.x
	rm *.dat
	rm *.pdf