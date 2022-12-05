#include "listas_dobles.h"
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

void ListaDoble::insertarNodo(Automovil v, char c)
{
    pnodo aux;
    char tipoInsercion;
    tipoInsercion=c;

    if(listaVacia()) { // Si la lista está vacía
        aux = new Nodo(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserción por el final
        aux= new Nodo(v,NULL,NULL);
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new Nodo(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}

void ListaDoble::insertarNodoIntAntes(Automovil v)
{
    pnodo aux;

    if(listaVacia()) { // Si la lista está vacía
        aux = new Nodo(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else   //Inserción antes del nodo
    {   actual=cabeza;
        while(actual)
        {
                // falta cambiar esto porque no funciona la condición D:
            if (v.modelo.compare(actual->valor.modelo) <= 0)
            { 
                    actual = actual->siguiente;
            }
            else
            {
                aux= new Nodo(v,NULL,NULL);
                aux->siguiente=actual;
                aux->anterior=actual->anterior;
                actual->anterior->siguiente=aux;
                actual->anterior=aux;
                actual = actual->siguiente; //mueve actual para que salga del while.
           }
        }
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

void ListaDoble::mostrarLista (int orden)
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
    cout << endl;
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


