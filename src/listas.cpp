#include "listas.h"
#include <iomanip>
#include <string.h>

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

void Lista::ordenarBastidor(){
	pnodoLista aux;
	bool cambiado;
	do{
		cambiado = false;
		actual = cabeza;
		while(actual->siguiente){
			if (strcmp(actual->valor.Nbastidor.c_str(), actual->siguiente->valor.Nbastidor.c_str()) > 0){
				cambiado = true;
				swap(actual->valor, actual->siguiente->valor);
			}
			actual = actual->siguiente;
		}
		aux = actual;
	}while(cambiado);
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
	if(!listaVacia()){
		ordenarBastidor();
		pnodoLista aux = cabeza;
		cout << " | "     <<setw(8) << "modelo"          << " | " << "Bastidor"                       << " | " << setw(7)<< "color"          << " | "  << setw(6) << "zona"          << " | " << "concesionario"<< " |" << endl;
		cout << " ----------------------------------------------------------" << endl;
		while(aux) {
		    cout << " | " << setw(8) << aux->valor.modelo << " | " << aux->valor.Nbastidor << setw(4) << " | " <<setw(7) << aux->valor.color << " | " << setw(6) << aux->valor.zona  << " | " << setw(13) <<aux->valor.concesionario <<  " | "  << endl;
		    cout << "" << endl;
		    aux = aux->siguiente;
		}
	}
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
