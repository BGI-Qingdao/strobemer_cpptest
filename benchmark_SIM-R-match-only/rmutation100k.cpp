#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <cassert>

#define LEN 100000
int main(int argc , char **argv){
    srand(time(NULL));
    char nucs[4] = { 'A','T','G','C'};
    if( argc != 2 ) {
        std::cerr<<"Usage : "<<argv[0]<<" error_rate*1000 (integer)  <input.10k >output.10" <<std::endl;
        return -1;
    }
    int erate = std::atoi(argv[1]);
    std::string input;
    std:getline(std::cin,input);
    assert(input.size() == LEN);
    for( int i = 0 ; i <LEN ; i++ ) {
        if( random()% 1000<erate ) {
            int mut = random() % 3 ;
            if( mut ==0 ) { //sub 
                while(true){
                    char newc = nucs[random()%4];
                    if( newc != input[i] ){
                        std::cout<<newc;
                        break;
                    }
                }
            } else if ( mut==1) { // ins
                std::cout<<nucs[random()%4];
                i = i -1; // may be insert more than 1, right?
            } else { //del
                continue ;
            }
        }else{
            std::cout<<input[i];
        }
    }
    std::cout<<'\n';
    return 0;
}
