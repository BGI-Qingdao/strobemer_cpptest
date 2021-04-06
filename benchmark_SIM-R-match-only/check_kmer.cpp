#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <set>
int main(int argc , char **argv){
    srand(time(NULL));
    char nucs[4] = { 'A','T','G','C'};
    if( argc != 3 ) {
        std::cerr<<"Usage : "<<argv[0]<<" k target.kmer<input.seq" <<std::endl;
        return -1;
    }
    int k = std::atoi(argv[1]);
    std::string kmer_marker = std::string(argv[2]);
    std::set<std::string> markers;
    std::ifstream infs(kmer_marker);
    if(!infs.is_open()){
        std::cerr<<"open file "<<kmer_marker<<" failed"<<'\n';
        return -1;
    }
    std::string kmer;;
    while ( ! infs.eof() ){
        infs>>kmer;
        markers.insert(kmer);
    }
    infs.close();
    std::string input;
    std::getline(std::cin,input);
    int found=0;
    for( int i = 0 ; i<input.size()-k+1;i++){
        std::string kmer = input.substr(i,k);
        if( markers.find(kmer) != markers.end()){
            found++;
        }
    }
    std::cout<<found<<std::endl;
    return 0;
}
