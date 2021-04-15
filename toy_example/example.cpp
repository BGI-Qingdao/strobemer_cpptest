#include "../strobemer.h"

int main() {
     char seq[101]="ATGGGCAGAGTTTGACGTAGTCAATGCTTATGAACGAACGCTCCAATATGAATCAGCTCGTGATTTTTGCTGTAAAAATCGTAGCATACTGTTTGATAAA";
     //strobemer::init(3,13,13,20,strobemer_type::minstrobe); // n=3,k=13,w_min=13,w_max=20,type=minstrobe
     //strobemer::init(3,13,13,21,strobemer_type::hybridstrobe); // n=3,k=13,w_min=13,w_max=20,type=hybridstrobe
     strobemer::init(3,13,13,20,strobemer_type::randstrobe);  // n=3,k=13,w_min=13,w_max=20,type=randstrobe
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
