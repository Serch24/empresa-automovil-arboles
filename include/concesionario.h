#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H

#include <iostream>

#include "listas.h"

using namespace std;

class concesionario
{
    public:
        int numero;
        char zona;
        Lista lista;
        concesionario();
        int concesionarioAleatorio();
        virtual ~concesionario();

};

void aaaa();
#endif // CONCESIONARIO_H
