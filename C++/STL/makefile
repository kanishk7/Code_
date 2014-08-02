CC = g++
CFLAGS = -c -Wall
LDFLAGS = 
SOURCES = vector.cpp

all: VectorExec AlgorithmExec

VectorExec: vector.cpp
	$(CC) vector.cpp -o Vector

AlgorithmExec: algorithm.cpp
	$(CC) algorithm.cpp -o Algorithm

clean:
	echo "Cleaning up."
	rm *.o
