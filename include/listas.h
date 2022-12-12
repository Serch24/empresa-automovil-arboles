#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <iostream>

class NodoArbol
 {
    private:
        int valor;
        NodoArbol *siguiente;
        friend class Lista;

    public:
        NodoArbol(int v, NodoArbol *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef NodoArbol *pnodoArbol;

class Lista {
    public:
        Lista(){cabeza = actual = fin= NULL;}
        ~Lista();
        void insertarNodoAlInicio(int);
        void insertarNodoAlFinal(int);
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
        pnodoArbol cabeza, fin;
        pnodoArbol actual;
};

#endif // LISTAS_H_INCLUDED

