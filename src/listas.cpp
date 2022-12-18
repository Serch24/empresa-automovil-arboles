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

bool Lista::listaVacia(){
    return cabeza == NULL;
}

int Lista::contarVehiculos(){
        pnodoLista aux = cabeza;
        int i = 0;
        while(aux){
                i = i + 1;
                aux = aux->siguiente;
        }
        return i;
}

void Lista::mostrarLista()
{
    //Nodo *aux;
    pnodoLista aux;
    aux = cabeza;

    while(aux)
    {
        cout << "Bastidor: " << aux->valor.Nbastidor << ", Modelo: "<<  aux->valor.modelo << ", color: " << aux->valor.color << ", Concesionario :" << aux->valor.concesionario <<", zona: " << aux->valor.zona << endl;
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
