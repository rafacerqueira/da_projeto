#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "carrinha.h"
int main() {
    std::ifstream newfile("carrinhas.txt");
    std::string a;
    int x1,x2,x3;
    getline(newfile,a);
    while(!newfile.eof()){
        newfile >> x1 >> x2 >> x3 ;
        std::cout << x1 <<" " << x2 << " "<< x3 << std::endl;
    }
    newfile.close();



    return 0;
}
