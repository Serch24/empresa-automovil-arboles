#include "listas_dobles.h"
#include "automovil.h"
#include <iomanip>

using namespace std;

ListaDoble::~ListaDoble()
{
    pnodo aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
        fin=NULL;
}

void ListaDoble::vaciar(){
    pnodo aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
        fin=NULL;
}

void ListaDoble::insertarNodo(Automovil v)
{
    pnodo aux;

    if(listaVacia()) { // Si la lista está vacía
        aux = new Nodo(v,NULL,NULL);
        fin=cabeza=aux;
    }else{
        aux= new Nodo(v, NULL, NULL);
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
}

void ListaDoble::ordenarLista(){
        int cambiado;
        pnodo tmp = NULL;
        if(cabeza != NULL){
                do{
                        cambiado = 0;
                        actual = cabeza;

                        while(actual->siguiente != tmp){
                                if(actual->valor.modelo.compare(actual->siguiente->valor.modelo) > 0){
                                        swap(actual->valor, actual->siguiente->valor);
                                        cambiado = 1;
                                }
                                actual = actual->siguiente;
                        }
                        tmp = actual;
                }while(cambiado);
        }
        
}

void ListaDoble::borrarNodo(Automovil v,char c)
{
    char tipoBorrado;
    tipoBorrado=c;

    if(tipoBorrado=='f') {//Eliminación por el final
        pnodo aux=NULL;
        if((cabeza==fin)) { //Sólo hay elemento
            aux=fin;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=fin;
            fin=fin->anterior;
            aux->anterior=NULL;  //añado yo según transparencias
            fin->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminación por el Principio
        pnodo aux=NULL;
        if((cabeza==fin)) {//Sólo hay elemento
            aux=cabeza;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;  //añado yo según transparencias
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}

void ListaDoble::mostrarLista(int orden)
{
    pnodo aux;

    if (orden == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        cout << " | " << "modelo" << " | " << "Bastidor" << " | " << "color" << " | " << "zona" << " | " << "concesionario" << endl;
        while(aux) {
            cout << "" << endl;
            cout << " | " << aux->valor.modelo << setw(5) << " | " << aux->valor.Nbastidor << setw(4) << " | " << aux->valor.color << " | " << aux->valor.zona << setw(7) << " | " << aux->valor.concesionario << setw(12) << " | "  << endl;
            aux = aux->siguiente;
        }
    }
    else {
        esUltimo();
        aux = fin;
        cout << " | " << "modelo" << " | " << "Bastidor" << " | " << "color" << " | " << "zona" << " | " << "concesionario" << endl;
        while(aux) {
            cout << "" << endl;
            cout << " | " << aux->valor.modelo << setw(5) << " | " << aux->valor.Nbastidor << setw(4) << " | " << aux->valor.color << " | " << aux->valor.zona << setw(7) << " | " << aux->valor.concesionario << setw(12) << " | "  << endl;
            aux = aux->anterior;
        }
    }
}

bool ListaDoble::listaVacia()
{
    return cabeza == NULL;
}

void ListaDoble::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void ListaDoble::esAnterior()
{
    if(actual) actual = actual->anterior;
}

void ListaDoble::esPrimero()
{
    actual=cabeza;
}

void ListaDoble::esUltimo()
{
    actual=fin;
}

bool ListaDoble::esActual()
{
    return actual != NULL;
}

/* int ListaDoble::valorActual() */
/* { */
/*     if (!listaVacia()) return actual->valor.modelo; */
/*      else return 0; */
/* } */


