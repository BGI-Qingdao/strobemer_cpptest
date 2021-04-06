#include <iostream>
#include <string>


int main(int argc, char ** argv)
{
    srand(time(NULL));
    if( argc != 2 ) {
        std::cerr<<"Usage : "<<argv[0]<<" k  <input.seq >output.kmer" <<std::endl;
        return -1;
    }
    int k = std::atoi(argv[1]);
    std::string input;
    std:getline(std::cin,input);
    for(int i = 0; i<input.size()-k+1 ; i++ ){
        std::cout<<input.substr(i,k)<<'\n';
    }
    return 0;
}
