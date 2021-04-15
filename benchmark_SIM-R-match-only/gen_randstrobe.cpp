#include <iostream>
#include <string>
#include "../strobemer.h"

int main(int argc, char ** argv)
{
    srand(time(NULL));
    std::string input;
    std:getline(std::cin,input);
    strobemer::init(2,15,15,50,strobemer_type::randstrobe);
    int number = input.size()-strobemer::strobmer_span()+1;
    strobemer * buff = new strobemer[number];
    strobemer::chop_strobemer(input.c_str(),input.size(),buff);
    for(int i = 0 ; i< number ; i++ ){
        if(buff[i].valid)
            buff[i].print();
        else {
            std::cerr<<"N found in ["<<i<<", "<<i+strobemer::strobmer_span()<<")"<<std::endl;
        }
    }
    delete []buff;
    return 0;
}
