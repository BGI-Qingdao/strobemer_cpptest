.PHONY:all

all: example

example: ../strobemer.cpp ../strobemer.h example.cpp
	g++ -I../ -c ../strobemer.cpp -o strobemer.o
	g++ -I../  example.cpp strobemer.o -o example
	./example


clean:
	rm example strobemer.o 
