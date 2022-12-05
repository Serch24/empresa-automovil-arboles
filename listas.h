#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <iostream>

class Nodo
 {
    private:
        int valor;
        Nodo *siguiente;
        friend class Lista;

    public:
        Nodo(int v, Nodo *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef Nodo *pnodo;

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
        pnodo cabeza, fin;
        pnodo actual;
};

#endif // LISTAS_H_INCLUDED

