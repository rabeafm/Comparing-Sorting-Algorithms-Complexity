comp: main.o algorithms.o hash.o bstree.o rbtree.o utils.o
	gcc -g -Wall -pedantic main.o algorithms.o hash.o bstree.o rbtree.o utils.o -o comp
	rm -f *.o
main.o: main.c header.h
	gcc -c -Wall -pedantic main.c -o main.o
algorithms.o: algorithms.c
	gcc -c -Wall -pedantic algorithms.c -o algorithms.o
hash.o: hash.c
	gcc -c -Wall -pedantic hash.c -o hash.o
bstree.o: bstree.c
	gcc -c -Wall -pedantic bstree.c -o bstree.o
rbtree.o: rbtree.c
	gcc -c -Wall -pedantic rbtree.c -o rbtree.o
utils.o: utils.c
	gcc -c -Wall -pedantic utils.c -o utils.o