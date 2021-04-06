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
             buff[i].print();
     }
     delete [] buff;
     return 0;
}
