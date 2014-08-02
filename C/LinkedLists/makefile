List: driver.o LinkedList.o LinkedListOps.o
	gcc -o List driver.o LinkedList.o LinkedListOps.o

driver.o: driver.c
	gcc -c driver.c

LinkedList.o: LinkedList.c
	gcc -c LinkedList.c

LinkedListOps.o: LinkedListOps.c
	gcc -c LinkedListOps.c

clean:
	rm *.o
	rm *.h~
	rm *.c~
	rm List

reinstall:
	make clean
	make -f makefile
