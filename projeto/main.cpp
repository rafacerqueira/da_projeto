#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream newfile("carrinhas.txt");
    std::string lines;
    if(newfile.is_open()){
        std::cout << "open" <<std::endl;
    }else {
        std::cout << "not ok" <<std::endl;
    }
    while(std::getline(newfile, lines)){
        std::cout<< lines << std::endl;
    }
    newfile.close();
    return 0;
}
