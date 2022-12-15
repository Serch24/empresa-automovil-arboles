#include "concesionario.h"
#include "automovil.h"
#include "arbol.h"
#include <vector>

vector<int> numerosDeConcesionarios = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
vector<int> zonaDeConcesionarios = {'A','A','A','A','B','B','B','B','C','C','C','C','D','D','D','D'};


int concesionario::concesionarioAleatorio(){
    while(numerosDeConcesionarios.size() > 0){
        int numRand = 1 + rand() % (16 + 1 - 1);
            for(int i=0; i < numerosDeConcesionarios.size();i++){
                    if(numRand == numerosDeConcesionarios[i]){
                            numerosDeConcesionarios.erase(numerosDeConcesionarios.begin() + i);
                            cout << numRand << endl;
                            return numRand;
                    }
            }
    }
    return 0;
}

char concesionario::zonaAleatorioConcesionario(){
    char tmp = 'Z';
    if(zonaDeConcesionarios.size() > 0){
        int zon = rand() % zonaDeConcesionarios.size();
        tmp = zonaDeConcesionarios[zon];
        zonaDeConcesionarios.erase(zonaDeConcesionarios.begin() + zon);
    }
    return tmp;
}

concesionario::concesionario()
{
    numero = concesionarioAleatorio();
    zona = zonaAleatorioConcesionario();
    lista = Lista();
}

concesionario::~concesionario()
{
    //dtor
}


