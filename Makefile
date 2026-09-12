all: run

run: build
	@./main

build: main.o checkers.o
	@gcc -o main main.o checkers.o

main.o: main.c
	@gcc -o main.o main.c -c -W -Wall -ansi -pedantic

checkers.o: checkers.c
	@gcc -o checkers.o checkers.c -c -W -Wall -ansi -pedantic

clean:
	@rm -rf main main.o checkers.o
