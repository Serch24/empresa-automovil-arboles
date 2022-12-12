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
        concesionario generarConcesionario();
        void generar16concesionarios();

        concesionario();
        virtual ~concesionario();

};

#endif // CONCESIONARIO_H
