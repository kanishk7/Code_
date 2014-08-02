Exe: driver.o tree.o bstree.o
	gcc -o Exe driver.o bstree.o tree.o 

driver.o: driver.c
	gcc -c driver.c

tree.o: tree.c
	gcc -c tree.c

bstree.o: bstree.c
	gcc -c bstree.c

clean:	
	rm Exe
	rm *.o
	rm *.h~
	rm *.c~
	rm Exe~
