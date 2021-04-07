.PHONY:all

all: example

example: ../strobemer.cpp ../strobemer.h example.cpp
	g++ -I../ -std=c++11 -c ../strobemer.cpp -o strobemer.o
	g++ -I../ -std=c++11 example.cpp strobemer.o -o example
	./example


clean:
	rm example strobemer.o 
