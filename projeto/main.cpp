#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "carrinha.cpp"
#include "encomenda.cpp"
#include <algorithm>
bool compareByVol(const carrinha &a, const carrinha &b){
    return a.volMax < b.volMax;
}
bool compareByPeso(const carrinha &a, const carrinha &b){
    return a.pesoMax < b.pesoMax;
}


void estafetas_min(std::vector<carrinha>vec ,std::vector<encomenda>vec2 ){
    /*for (auto arr : vec) {
        std::cout << "volMax: " << arr.volMax << ' '
                  << "pesoMax: " << arr.pesoMax << ' '
                  << "custo: " << arr.custo << ' '
                  << "id: " << arr.id << std::endl;
    }
    for (auto arr : vec2) {
        std::cout << "volume: " << arr.volume << ' '
                  << "peso: " << arr.peso << ' '
                  << "recompensa: " << arr.recompensa << ' '
                  << "duracao: " << arr.duracao << ' '
                  << "id: " << arr.id << std::endl;

                  vec.at(h).volMax
    }*/


    std::sort(vec.begin(), vec.end(), compareByVol);
    for(int i=0; i<vec.size(); i++){
        if(vec2.at(i).volume <= vec.at(i).volMax && vec.at(i).volMax < vec2.at(i))
    }

}

void expresso(std::vector<carrinha>vec ,std::vector<encomenda>vec2 ) {
    int duration[150];
    int i=0;
    for(auto arr : vec2){
        duration[i]=arr.duracao;
        i++;
    }
    int n = sizeof(duration) / sizeof(duration[0]);
    std::sort( duration,duration + n);
    int tempo_medio=0;
    for(auto i:duration){
        tempo_medio+=i;
    }
    tempo_medio/=150;
    std::cout << "tempo medio: " << tempo_medio << std::endl;
}



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


    estafetas_min(vec, vec2);
    expresso(vec, vec2);
    return 0;
}