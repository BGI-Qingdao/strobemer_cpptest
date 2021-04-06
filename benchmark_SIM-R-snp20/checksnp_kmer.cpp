#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <map>
int main(int argc , char **argv){
    srand(time(NULL));
    char nucs[4] = { 'A','T','G','C'};
    if( argc != 3 ) {
        std::cerr<<"Usage : "<<argv[0]<<" k target.kmer<input.seq" <<std::endl;
        return -1;
    }
    int k = std::atoi(argv[1]);
    std::string kmer_marker = std::string(argv[2]);
    std::map<std::string,int> markers;
    std::ifstream infs(kmer_marker);
    if(!infs.is_open()){
        std::cerr<<"open file "<<kmer_marker<<" failed"<<'\n';
        return -1;
    }
    std::string kmer;int snp_id;
    while ( ! infs.eof() ){
        infs>>kmer>>snp_id;
        markers[kmer]=snp_id;
    }
    infs.close();
    std::string input;
    std::getline(std::cin,input);
    for( int i = 0 ; i<input.size()-k+1;i++){
        std::string kmer = input.substr(i,k);
        if( markers.find(kmer) != markers.end()){
            std::cout<<kmer<<'\t'<< markers[kmer]<<'\n';
        }
    }
    return 0;
}
