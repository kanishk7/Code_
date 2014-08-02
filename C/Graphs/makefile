GraphExec: driver.o graphOps.o Pqueue.o queue.o graphAlgos.o stack.o
	gcc -o GraphExec driver.o graphOps.o Pqueue.o queue.o graphAlgos.o stack.o

driver.o: driver.c
	gcc -c driver.c

graphOps.o: graphOps.c
	gcc -c graphOps.c

Pqueue.o: Pqueue.c
	gcc -c Pqueue.c

queue.o: queue.c
	gcc -c queue.c

graphAlgos.o: graphAlgos.c
	gcc -c graphAlgos.c

stack.o: stack.c
	gcc -c stack.c

clean:
	rm *.o
	rm GraphExec
	rm *.h~
	rm *.c~
