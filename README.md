# About this small project

1. this project implement an c++ version of the strobemer ( W=k+n*w ) with small difference (the window will not shrink at the end of sequence).
2. there small benchmark were attached. (Ignore them if your don't care)

# The implementation of strobemer

## How to use the c++ implemention of strobemer ? See toy_example 

* first copy strobemer.h and strobemer.cpp into your project.

* then write your code like :

```
#include "strobemer.h"

int main() {
     char seq[101]="ATGGGCAGAGTTTGACGTAGTCAATGCTTATGAACGAACGCTCCAATATGAATCAGCTCGTGATTTTTGCTGTAAAAATCGTAGCATACTGTTTGATAAA";
     //strobemer::init(3,13,20,strobemer_type::minstrobe); // n=3,k=13,w1=w2=20,type=minstrobe
     strobemer::init(3,13,20,strobemer_type::randstrobe);  // n=3,k=13,w1=w2=20,type=randstrobe
     int number = 100-strobemer::strobmer_span()+1;
     strobemer * buff = new strobemer[number];
     strobemer::chop_strobemer(seq,100,buff);
     for(int i = 0 ; i< number ; i++ ){
         if(buff[i].valid)
             std::cout<<buff[i].to_string()<<'\n'; // or do whatever you want ...
     }
     delete [] buff;
     return 0;
}
```

then compile and link it like

```
g++  -c strobemer.cpp -o strobemer.o
g++  example.cpp strobemer.o -o example
```

# There benchmarks

## the test date

* random sequence with length=100,000 nt.
* mutation rates are 0.01, 0.05 and 0.1. 
* random mutaion.
* equal probability of sub/ins/del.
* each test run 100 times.

## benchmark_SIM-R-match-only

* compare the match number of all kmer/strobemer.
* compare k30, randstrobe(2,15,50) and minstrobe(2,15,50). 

## benchmark_SIM-R-snp30

* compare the match number of all kmer/strobemer snp markers.
* assign one snp for each 1000bp ( total 99 snps for 100,000bp because I drop the snp at the sequence end ).
* compare k30, randstrobe(2,15,50) and minstrobe(2,15,50).
* for k30, one snp generate 30 kmer markers.
* for strobemer(2,15,50), each snp generate 65 strobemer markers.

## benchmark_SIM-R-snp20

* compare the match number of all kmer/strobemer snp markers.
* assign one snp for each 1000bp ( total 99 snps for 100,000bp because I drop the snp at the sequence end ).
* compare k20, k40, randstrobe(2,10,30) and minstrobe(2,10,30).
* for K20, one snp generate 20 kmer markers.
* for K40, one snp generate 40 kmer markers.
* for strobemer(2,10,30), each snp generate 40 strobemer markers.


Enjoy ~~
