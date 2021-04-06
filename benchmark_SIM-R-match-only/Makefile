
all: clean strobemer.o 
	g++ random100k.cpp -o random100k
	g++ rmutation100k.cpp -o  rmutation100k
	g++ gen_kmer.cpp -o gen_kmer
	g++ check_kmer.cpp -o check_kmer
	g++ gen_minstrobe.cpp strobemer.o -o gen_minstrobe
	g++ check_minstrobe.cpp strobemer.o -o check_minstrobe
	g++ gen_randstrobe.cpp strobemer.o -o gen_randstrobe
	g++ check_randstrobe.cpp strobemer.o -o check_randstrobe

strobemer.o:
	g++ -c ../strobemer.cpp -o strobemer.o


clean:
	rm -rf strobemer.o
	rm -rf random100k rmutation100k 
	rm -rf gen_kmer check_kmer
	rm -rf gen_minstrobe check_minstrobe 
	rm -rf gen_randstrobe check_randstrobe
