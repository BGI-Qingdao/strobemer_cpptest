#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <map>
#include "../strobemer.h"

int main(int argc , char **argv){
    srand(time(NULL));
    char nucs[4] = { 'A','T','G','C'};
    if( argc != 2 ) {
        std::cerr<<"Usage : "<<argv[0]<<" target.kmer<input.seq" <<std::endl;
        return -1;
    }
    std::string kmer_marker = std::string(argv[1]);
    std::map<std::string,int> markers;
    std::ifstream infs(kmer_marker);
    if(!infs.is_open()){
        std::cerr<<"open file "<<kmer_marker<<" failed"<<'\n';
        return -1;
    }
    std::string kmer;int snp_id;
    while ( ! infs.eof() ){
        infs>>kmer>>snp_id;
        markers[kmer] = snp_id;
    }
    infs.close();
    std::string input;
    std::getline(std::cin,input);
    strobemer::init(2,15,50,strobemer_type::randstrobe);  
    int number = input.size()-strobemer::strobmer_span()+1;
    strobemer * buff = new strobemer[number];
    strobemer::chop_strobemer(input.c_str(),input.size(),buff);
    for( int i = 0 ; i<number;i++){
        if(buff[i].valid)
            if(markers.find(buff[i].to_string()) != markers.end())
                std::cout<<buff[i].to_string()<<'\t'<<markers[buff[i].to_string()]<<'\n';
    }
    delete []buff;
    return 0;
}
