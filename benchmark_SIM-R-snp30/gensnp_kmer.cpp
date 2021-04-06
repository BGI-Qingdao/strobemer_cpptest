#include <iostream>
#include <string>

#define LEN 100000
#define SNPDNESITY 1000
int main(int argc, char ** argv)
{
    srand(time(NULL));
    if( argc != 2 ) {
        std::cerr<<"Usage : "<<argv[0]<<" k  <input.seq >output.snp" <<std::endl;
        return -1;
    }
    int k = std::atoi(argv[1]);
    std::string input;
    std:getline(std::cin,input);
    for(int i = SNPDNESITY ; i<LEN ; i+=SNPDNESITY ){
        for( int j = 0 ; j< k; j++ ){
            // print the snp marker and snp_id
            std::cout<<input.substr(i+j,k)<<'\t'<<i/SNPDNESITY<<'\n';
        }
    }
    return 0;
}
