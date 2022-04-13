#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "carrinha.cpp"
#include "encomenda.cpp"
int main() {
    std::ifstream newfile("carrinhas.txt");
    std::string a;
    std::vector<carrinha> vec;
    int x1,x2,x3;
    int i=0;
    getline(newfile,a);
    while(!newfile.eof()){
        if(i==50){
            break;
        }
        newfile >> x1 >> x2 >> x3 ;
        //std::cout << x1 <<" " << x2 << " "<< x3 << std::endl;
        vec.push_back(carrinha(x1,x2,x3,i));
        i++;
    }
    newfile.close();

    for (auto arr : vec) {
        std::cout << "volMax: " << arr.volMax << ' '
             << "pesoMax: " << arr.pesoMax << ' '
             << "custo: " << arr.custo << ' '
             << "id: " << arr.id << std::endl;
    }

    std::ifstream newfile2("encomendas.txt");
    std::string b;
    std::vector<encomenda> vec2;
    int y1,y2,y3,y4;
    int j=0;
    getline(newfile2,b);
    while(!newfile2.eof()){
        if(j==150){
            break;
        }
        newfile2 >> y1 >> y2 >> y3 >> y4;
        //std::cout << x1 <<" " << x2 << " "<< x3 << std::endl;
        vec2.push_back(encomenda(y1,y2,y3,y4,j));
        j++;
    }
    newfile2.close();

    for (auto arr : vec2) {
        std::cout << "volume: " << arr.volume << ' '
                  << "peso: " << arr.peso << ' '
                  << "recompensa: " << arr.recompensa << ' '
                  << "duracao: " << arr.duracao << ' '
                  << "id: " << arr.id << std::endl;
    }



    return 0;
}
