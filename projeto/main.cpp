#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include "carrinha.cpp"
#include "encomenda.cpp"
#include "ocupado.cpp"

bool compareByVol(const carrinha &a, const carrinha &b){
    return a.volMax > b.volMax;
}
bool compareByCusto(const carrinha &a, const carrinha &b){
    return a.custo < b.custo;
}

void lucro(std::vector<carrinha>vec ,std::vector<encomenda>vec2){
    std::vector<ocupado> feito;
    std::sort(vec.begin(), vec.end(), compareByCusto);
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec2.size(); j++){
            if(vec2.at(j).volume <= vec.at(i).volMax && vec2.at(j).peso <= vec.at(i).pesoMax){
                feito.push_back(ocupado(vec2.at(j).id, vec.at(i).id));
                vec.at(i).pesoMax -= vec2.at(j).peso;
                vec.at(i).volMax -= vec2.at(j).volume;
                vec2.at(j).peso = INT_MAX;
                vec2.at(j).volume = INT_MAX;

            }
        }
    }
    for(auto arr: feito){
        std::cout << "id carrinha: " << arr.id_carrinha
        << "id encomenda: " << arr.id_encomenda << std::endl;
    }
    int receita = 0;
    int custo_total = 0;
    int last_id = feito.at(0).id_carrinha;
    for(int i=0; i<feito.size(); i++){
        if(last_id!=feito.at(i).id_carrinha){
            custo_total+=vec.at(feito.at(i).id_carrinha).custo;
            receita+=vec2.at(feito.at(i).id_encomenda).recompensa;
            last_id = feito.at(i).id_carrinha;
        }
    }
    int resultado = receita- custo_total;
    std::cout << "lucro maximo do dia: " << resultado << std::endl;


}



void estafetas_min(std::vector<carrinha>vec ,std::vector<encomenda>vec2){
    std::vector<ocupado> feito;
    std::sort(vec.begin(), vec.end(), compareByVol);
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec2.size(); j++){
            if(vec2.at(j).volume <= vec.at(i).volMax && vec2.at(j).peso <= vec.at(i).pesoMax){
                feito.push_back(ocupado(vec2.at(j).id, vec.at(i).id)); //encomenda id, carrinha id
                vec.at(i).pesoMax -= vec2.at(j).peso;
                vec.at(i).volMax -= vec2.at(j).volume;
                vec2.at(j).peso = INT_MAX;
                vec2.at(j).volume = INT_MAX;
            }
        }
    }

    std::sort(vec.begin(), vec.end(), compareByVol);

    int resultado = 1;
    int last_id = feito.at(0).id_carrinha;
    for(int i=0; i<feito.size(); i++){
        if(feito.at(i).id_carrinha!=last_id){
            resultado++;
            last_id = feito.at(i).id_carrinha;
        }
    }
    std::cout << "numero minimo de estafetas: " << resultado << std::endl;
}

void expresso(std::vector<carrinha>vec ,std::vector<encomenda>vec2 ) {
    int duration[450];
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
        if(j==450){
            break;
        }
        newfile2 >> y1 >> y2 >> y3 >> y4;
        //std::cout << x1 <<" " << x2 << " "<< x3 << std::endl;
        vec2.push_back(encomenda(y1,y2,y3,y4,j));
        j++;
    }
    newfile2.close();


    estafetas_min(vec, vec2);
    lucro(vec, vec2);
    expresso(vec, vec2);

    return 0;
}