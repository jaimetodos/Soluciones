all:
	g++ -fopenmp adveccionSerial.cpp -o adveccionSerial.x -std=c++11
	./adveccionSerial.x
	g++ -fopenmp adveccionParallel.cpp -o adveccionParallel.x -std=c++11
	./adveccionParallel.x
	python3 graph.py

clean:
	rm *.x
	rm *.dat
	rm *.pdf