#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "carrinha.h"

int main() {
    std::ifstream newfile("carrinhas.txt");
    std::string a;
    std::vector<carrinha> vec;
    int x1,x2,x3;
    int i=0;
    getline(newfile,a);
    while(!newfile.eof()){
        newfile >> x1 >> x2 >> x3 ;
        std::cout << x1 <<" " << x2 << " "<< x3 << std::endl;
        vec.push_back(carrinha(x1,x2,x3,i));
        i++;
    }
    newfile.close();



    return 0;
}
