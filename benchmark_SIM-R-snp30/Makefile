
all: clean strobemer.o 
	g++ random100k.cpp -o random100k
	g++ rmutation100k.cpp -o  rmutation100k
	g++ gensnp_kmer.cpp -o gensnp_kmer
	g++ checksnp_kmer.cpp -o checksnp_kmer
	g++ gensnp_minstrobe.cpp strobemer.o -o gensnp_minstrobe
	g++ checksnp_minstrobe.cpp strobemer.o -o checksnp_minstrobe
	g++ gensnp_randstrobe.cpp strobemer.o -o gensnp_randstrobe
	g++ checksnp_randstrobe.cpp strobemer.o -o checksnp_randstrobe

strobemer.o:
	g++ -c ../strobemer.cpp -o strobemer.o


clean:
	rm -rf strobemer.o
	rm -rf random100k rmutation100k 
	rm -rf gensnp_kmer checksnp_kmer
	rm -rf gensnp_minstrobe checksnp_minstrobe 
	rm -rf gensnp_randstrobe checksnp_randstrobe
