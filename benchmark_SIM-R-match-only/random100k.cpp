#include <iostream>
#include <ctime>
#include <stdlib.h>

#define LEN 100000
int main(){
    srand(time(NULL));
    char nucs[4]={'A','T','C','G'};
    for(int i=0;i<LEN;i++)
        std::cout<<nucs[random()%4];
    std::cout<<'\n';
    return 0;
}
