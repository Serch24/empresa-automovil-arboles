#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "automovil.h"
#include <iostream>

class NodoLista
 {
    private:
        Automovil valor;
        NodoLista *siguiente;
        friend class Lista;

    public:
        NodoLista(Automovil v, NodoLista *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef NodoLista *pnodoLista;

class Lista {
    public:
        Lista(){cabeza = actual = fin= NULL;}
        ~Lista();
        void insertarNodoAlInicio(int);
        void insertarNodoAlFinal(Automovil);
        void insertarNodoIntermedio(int, int);
        void borrarNodoInicio();
        void borrarNodoFin();
        void borrarNodoPosicion(int);
        void borrarNodo(int);
        bool listaVacia();
        void mostrarLista();
        void esSiguiente();
        void esFinal();
        void esPrimero();
        void esUltimo();
        bool esActual();
        int valorActual();

    private:
        pnodoLista cabeza, fin;
        pnodoLista actual;
};

#endif // LISTAS_H_INCLUDED

