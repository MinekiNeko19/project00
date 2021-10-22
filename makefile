all: library.o linkedsongs.o
	gcc -o lib linkedsongs.o library.o

library.o: library.c library.h
	gcc -c library.c

linkedsongs.o: linkedsongs.c linkedsongs.h
	gcc -c linkedsongs.c
run:
	./lib

# for linkedsongs.c
# all:
# 	gcc -o linked linkedsongs.c
# run:
# 	./linked
