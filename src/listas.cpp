#include "listas.h"

using namespace std;

Lista::~Lista()
{
    pnodoArbol aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarNodoAlInicio(int v) {
    pnodoArbol aux;

    if (listaVacia())
    {
        cabeza = new NodoArbol(v, NULL);
        fin = cabeza;
    }else{
            aux = new NodoArbol(v, NULL);
            aux->siguiente = cabeza;
            cabeza = aux;
    }
}

void Lista::insertarNodoAlFinal(int v) {
    pnodoArbol aux;

    if (listaVacia())
    {
        cabeza = new NodoArbol(v, NULL);
        fin=cabeza;
    }
    else
    {
        aux= new NodoArbol(v,NULL);
        fin->siguiente=aux;
        fin=aux;
    }
}

//no entiendo muy bien este m�todo :x
void Lista::insertarNodoIntermedio(int v, int posicion) {
    pnodoArbol aux;

    aux= new NodoArbol(v,NULL);

    if (listaVacia())
    {
        cabeza = aux;
        fin=cabeza;
    }
    else
    {   actual=cabeza;
        while(actual)
        {
            if (actual->valor != posicion){
                    actual = actual->siguiente;
            }else{
                aux->siguiente=actual->siguiente;
                actual->siguiente=aux;

                actual = actual->siguiente; //mueve actual para que salga del while.
            }
        }
    }
}

void Lista::borrarNodoInicio(){

        pnodoArbol sig;
        actual = cabeza;

        if(actual){
                sig = actual->siguiente;
                cabeza = sig;
        }
        delete actual;
}

void Lista::borrarNodoFin(){
        pnodoArbol anterior;
        actual = cabeza;
        if(actual){
                while (actual->siguiente != NULL){
                        anterior=actual;
                        actual=actual->siguiente;
                }
                cout << "Actual : " << actual->valor << endl;
                cout << "Anterior : " << anterior->valor << endl;
                anterior->siguiente = NULL;
                actual->siguiente = NULL;
                fin = anterior;
        }
        delete actual;
}

void Lista::borrarNodo(int v) {
    pnodoArbol anterior;

    actual = cabeza;

    if(actual){
        while ((actual->valor!=v) && (actual->siguiente!=NULL)){
                anterior=actual;
                actual=actual->siguiente;
        }
        if (actual==cabeza){ // Primer elemento
                cabeza = actual->siguiente;
        }else{
                anterior->siguiente = actual->siguiente;
                if (actual==fin)
                {
                    fin=anterior;
                }
            }
        actual->siguiente=NULL;
    }
    delete actual;
}

// Funciona a medias jaja, cuando tiene 3 nodos y le doy a eliminar el nodo 1
// en ese caso funciona, en los dem�s no.
void Lista::borrarNodoPosicion(int posicion){
        actual = cabeza;
        pnodoArbol anterior;
        int i = 0;

        if(cabeza){
                while(i != posicion && actual->siguiente != NULL){
                        anterior = actual;
                        actual = actual->siguiente;
                        i++;
                }

                //Solo hay 1 elemento
                if(cabeza == actual){
                        cabeza = actual->siguiente;
                }else{
                        //si entra aqu� es porque "actual" ha avanzado en el nodo
                }
        }
}

bool Lista::listaVacia(){
    return cabeza == NULL;
}

void Lista::mostrarLista()
{
    //Nodo *aux;
    pnodoArbol aux;
    aux = cabeza;

    while(aux)
    {
        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}

void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void Lista::esPrimero()
{
    actual = cabeza;
}


void Lista::esFinal()
{
    esPrimero();
    if(!listaVacia())
    while(actual->siguiente)
    esSiguiente();
}

bool Lista::esActual()
{
    return actual != NULL;
}

int Lista::valorActual()
{
    return actual->valor;
}
