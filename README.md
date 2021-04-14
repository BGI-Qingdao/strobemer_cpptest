# About this small project

what is strobemer? see https://github.com/ksahlin/strobemers

1. this project implement an c++ version of the strobemer ( W=k+n*w ) with small difference (the window will not shrink at the end of sequence).

* randstrobes supported.
* minstrobes supported.
* switch from s(n, k, w) to s(n, k, w_min, w_max) coming soon ...
* hybirdstrobes coming soon ... 
  
2. there small benchmark were attached. (Ignore them if you don't care)

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

then compile and link it like:

```
g++  -std=c++11 -c strobemer.cpp -o strobemer.o
g++  -std=c++11 example.cpp strobemer.o -o example
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

Results of the "average match of all  kmers/strobemers (%) " for different error rates and different methods:

|  |  0.01  | 0.05 | 0.1 |
| --- | --- | --- |--- |
| Kmer(30) | 74.6 | 22.5 | 4.7 |
| minstrobe(2,15,50) | 70.1 | 17.5 | 3.2 |
| randstrobe(2,15,50) | 70.1 | 17.5 | 3.2 |

## benchmark_SIM-R-snp30

* compare the match number of all kmer/strobemer snp markers.
* assign one snp for each 1000bp ( total 99 snps for 100,000bp because I drop the snp at the sequence end ).
* compare k30, randstrobe(2,15,50) and minstrobe(2,15,50).
* for k30, one snp generate 30 kmer markers.
* for strobemer(2,15,50), each snp generate 65 strobemer markers.

Results of the "average match number of all snp markers" for different error rates and different methods:

|  |  0.01  | 0.05 | 0.1 |
| --- | --- | --- |--- |
| Kmer(30) | 2210 | 665 | 143 |
| minstrobe(2,15,50) | 4511 | 1100 | 208 |
| randstrobe(2,15,50) | 4502 | 1134 | 210 |




## benchmark_SIM-R-snp20

* compare the match number of all kmer/strobemer snp markers.
* assign one snp for each 1000bp ( total 99 snps for 100,000bp because I drop the snp at the sequence end ).
* compare k20, k40, randstrobe(2,10,30) and minstrobe(2,10,30).
* for K20, one snp generate 20 kmer markers.
* for K40, one snp generate 40 kmer markers.
* for strobemer(2,10,30), each snp generate 40 strobemer markers.

Results of the "average match number of all snp markers" for different error rates and different methods:

|  |  0.01  | 0.05 | 0.1 |
| --- | --- | --- |--- |
| Kmer(20) | 1631.5 | 748.93 | 260.72 |
| Kmer(40) | 2682.38 | 540.22 | 62.83 |
| minstrobe(2,10,30) | 3171.38 | 1296.55 | 411.71 |
| randstrobe(2,10,30) | 3164.28 | 1292.72 | 417.33 |

Enjoy ~~
