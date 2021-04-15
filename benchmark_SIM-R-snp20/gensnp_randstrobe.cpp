#include <iostream>
#include <string>
#include <cassert>
#include "../strobemer.h"

#define LEN 100000
#define SNPDENSITY 1000

int main(int argc, char ** argv)
{
    srand(time(NULL));
    std::string input;
    std::getline(std::cin,input);
    assert(input.size() == LEN);
    strobemer::init(2,10,10,30,strobemer_type::randstrobe);  
    int number = input.size()-strobemer::strobmer_span()+1;
    strobemer * buff = new strobemer[number];
    strobemer::chop_strobemer(input.c_str(),input.size(),buff);
    for(int i = SNPDENSITY ; i< input.size() ; i+=SNPDENSITY ) {
        for( int j = 0 ; j < strobemer::strobmer_span() ; j++ )
            if(buff[i+j].valid) {
                std::cout<<buff[i+j].to_string()<<'\t'<<i/SNPDENSITY<<'\n';
            } else {
                std::cerr<<"N found in ["<<i+j<<", "<<i+j+strobemer::strobmer_span()<<")"<<std::endl;
            }
    }
    delete []buff;
    return 0;
}
