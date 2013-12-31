all: output

output: main.c tictactoe.o
	gcc -Wall -o output main.c tictactoe.o

tictactoe.o: tictactoe.c tictactoe.h
	gcc -c -Wall -o tictactoe.o tictactoe.c

clean: 
	rm -rf output tictactoe.o
