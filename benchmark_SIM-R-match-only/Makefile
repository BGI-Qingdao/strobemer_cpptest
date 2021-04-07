
all: clean strobemer.o 
	g++ -std=c++11 random100k.cpp -o random100k
	g++ -std=c++11 rmutation100k.cpp -o  rmutation100k
	g++ -std=c++11 gen_kmer.cpp -o gen_kmer
	g++ -std=c++11 check_kmer.cpp -o check_kmer
	g++ -std=c++11 gen_minstrobe.cpp strobemer.o -o gen_minstrobe
	g++ -std=c++11 check_minstrobe.cpp strobemer.o -o check_minstrobe
	g++ -std=c++11 gen_randstrobe.cpp strobemer.o -o gen_randstrobe
	g++ -std=c++11 check_randstrobe.cpp strobemer.o -o check_randstrobe

strobemer.o:
	g++ -std=c++11 -c ../strobemer.cpp -o strobemer.o


clean:
	rm -rf strobemer.o
	rm -rf random100k rmutation100k 
	rm -rf gen_kmer check_kmer
	rm -rf gen_minstrobe check_minstrobe 
	rm -rf gen_randstrobe check_randstrobe
