//
// Created by rafael on 13/04/22.
//

struct encomenda{
    int volume;
    int peso;
    int recompensa;
    int duracao;
    int id;
    encomenda(int x1, int x2, int x3, int x4, int i){
        volume = x1;
        peso = x2;
        recompensa = x3;
        id = i;
        duracao = x4;
    }
};