comp: main.o algorithms.o hash.o bstree.o rbtree.o utils.o
	gcc -g -Wall -pedantic main.o algorithms.o hash.o bstree.o rbtree.o utils.o -o comp -lm
	rm -f *.o
main.o: main.c header.h
	gcc -c -Wall -pedantic -lm main.c -o main.o
algorithms.o: algorithms.c
	gcc -c -Wall -pedantic algorithms.c -o algorithms.o
hash.o: hash.c header.h
	gcc -c -Wall -pedantic -lm hash.c -o hash.o
bstree.o: bstree.c header.h
	gcc -c -Wall -pedantic bstree.c -o bstree.o
rbtree.o: rbtree.c header.h
	gcc -c -Wall -pedantic rbtree.c -o rbtree.o
utils.o: utils.c header.h
	gcc -c -Wall -pedantic utils.c -o utils.o