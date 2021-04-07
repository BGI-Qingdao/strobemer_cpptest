
all: clean strobemer.o 
	g++ -std=c++11 random100k.cpp -o random100k
	g++ -std=c++11 rmutation100k.cpp -o  rmutation100k
	g++ -std=c++11 gensnp_kmer.cpp -o gensnp_kmer
	g++ -std=c++11 checksnp_kmer.cpp -o checksnp_kmer
	g++ -std=c++11 gensnp_minstrobe.cpp strobemer.o -o gensnp_minstrobe
	g++ -std=c++11 checksnp_minstrobe.cpp strobemer.o -o checksnp_minstrobe
	g++ -std=c++11 gensnp_randstrobe.cpp strobemer.o -o gensnp_randstrobe
	g++ -std=c++11 checksnp_randstrobe.cpp strobemer.o -o checksnp_randstrobe

strobemer.o:
	g++ -std=c++11 -c ../strobemer.cpp -o strobemer.o


clean:
	rm -rf strobemer.o
	rm -rf random100k rmutation100k 
	rm -rf gensnp_kmer checksnp_kmer
	rm -rf gensnp_minstrobe checksnp_minstrobe 
	rm -rf gensnp_randstrobe checksnp_randstrobe
