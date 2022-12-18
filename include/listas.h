#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "automovil.h"
#include <iostream>

class NodoLista
 {
    private:
        Automovil valor;
        NodoLista *siguiente;
        int cantidad;
        friend class Lista;

    public:
        NodoLista(Automovil v, NodoLista *sig = NULL)
        {
            valor = v;
            siguiente = sig;
            cantidad = 0;
        }
};
typedef NodoLista *pnodoLista;

class Lista {
    public:
        Lista(){cabeza = actual = fin= NULL;}
        ~Lista();
        void insertarNodoAlInicio(Automovil);
        void insertarNodoAlFinal(Automovil);
        void insertarNodoIntermedio(Automovil, int);
        void borrarNodoInicio();
        void borrarNodoFin();
        void borrarNodoPosicion(int);
        void borrarNodo(Automovil);
        bool listaVacia();
        void mostrarLista();
        int contarVehiculos();
        void esSiguiente();
        void esFinal();
        void esPrimero();
        void esUltimo();
        bool esActual();
        Automovil valorActual();

    private:
        pnodoLista cabeza, fin;
        pnodoLista actual;
};

#endif // LISTAS_H_INCLUDED

