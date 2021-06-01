comp: main.o sortalgs.o hashsort.o bstree.o rbtree.o
	gcc -g -Wall -pedantic main.o sortalgs.o hashsort.o bstree.o rbtree.o -o comp
main.o: main.c
	gcc -c -Wall -pedantic main.c -o main.o
sortalgs.o: sortalgs.c
	gcc -c -Wall -pedantic sortalgs.c -o sortalgs.o
hashsort.o: hashsort.c
	gcc -c -Wall -pedantic hashsort.c -o hashsort.o
bstree.o: bstree.c
	gcc -c -Wall -pedantic bstree.c -o bstree.o
rbtree.o: rbtree.c
	gcc -c -Wall -pedantic rbtree.c -o rbtree.o