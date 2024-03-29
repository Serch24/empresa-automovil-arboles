#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED

#include <iostream>
#include "automovil.h"

const int ASCENDENTE=0;
const int DESCENDENTE=1;

class Nodo
{
    private:
        Automovil valor;
        Nodo *siguiente;
        Nodo *anterior;
    friend class ListaDoble;
    friend class Automovil;

    public:
        Nodo(Automovil v, Nodo *sig = NULL, Nodo *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef Nodo *pnodo;

class ListaDoble
{
    private:
        pnodo cabeza, fin, actual;

    public:
        ListaDoble() {cabeza=actual=fin=NULL; }
        ~ListaDoble();
        void insertarNodo(Automovil v);
        void ordenarLista();
        void borrarVehiculos(string modelo);
        bool listaVacia();
        void mostrarLista();
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        void vaciar();
        bool esActual();
        int valorActual();
        Automovil sacarVehiculos(int numero);
        Automovil sacarVehiculos(char zona);
};

#endif // LISTAS_DOBLES_H_INCLUDED
