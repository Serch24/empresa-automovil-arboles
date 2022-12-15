#include "listas.h"

using namespace std;

Lista::~Lista()
{
    pnodoLista aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarNodoAlInicio(Automovil v) {
    pnodoLista aux;

    if (listaVacia())
    {
        cabeza = new NodoLista(v, NULL);
        fin = cabeza;
    }else{
            aux = new NodoLista(v, NULL);
            aux->siguiente = cabeza;
            cabeza = aux;
    }
}

void Lista::insertarNodoAlFinal(Automovil v) {
    pnodoLista aux;

    if (listaVacia())
    {
        cabeza = new NodoLista(v, NULL);
        fin=cabeza;
    }
    else
    {
        aux= new NodoLista(v,NULL);
        fin->siguiente=aux;
        fin=aux;
    }
}

//no entiendo muy bien este método :x
void Lista::insertarNodoIntermedio(Automovil v, int posicion) {
    pnodoLista aux;

    aux= new NodoLista(v,NULL);

    if (listaVacia())
    {
        cabeza = aux;
        fin=cabeza;
    }
    else
    {   actual=cabeza;
        while(actual)
        {
            if (actual->valor.concesionario != posicion){
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

        pnodoLista sig;
        actual = cabeza;

        if(actual){
                sig = actual->siguiente;
                cabeza = sig;
        }
        delete actual;
}

void Lista::borrarNodoFin(){
        pnodoLista anterior;
        actual = cabeza;
        if(actual){
                while (actual->siguiente != NULL){
                        anterior=actual;
                        actual=actual->siguiente;
                }
                cout << "Actual : " << actual->valor.concesionario << endl;
                cout << "Anterior : " << anterior->valor.concesionario << endl;
                anterior->siguiente = NULL;
                actual->siguiente = NULL;
                fin = anterior;
        }
        delete actual;
}

void Lista::borrarNodo(Automovil v) {
    pnodoLista anterior;

    actual = cabeza;

    if(actual){
        while ((actual->valor.concesionario != v.concesionario) && (actual->siguiente!=NULL)){
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
// en ese caso funciona, en los demás no.
void Lista::borrarNodoPosicion(int posicion){
        actual = cabeza;
        pnodoLista anterior;
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
                        //si entra aquí es porque "actual" ha avanzado en el nodo
                }
        }
}

bool Lista::listaVacia(){
    return cabeza == NULL;
}

void Lista::mostrarLista()
{
    //Nodo *aux;
    pnodoLista aux;
    aux = cabeza;

    cout <<  "Mostrando lista..." << endl;
    while(aux)
    {
        cout << "Bastidor: " << aux->valor.Nbastidor << ", Modelo: "<<  aux->valor.modelo << ", Concesionario :" << aux->valor.concesionario << endl;
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

Automovil Lista::valorActual()
{
    return actual->valor;
}
