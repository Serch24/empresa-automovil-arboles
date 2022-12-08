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

/* void ListaDoble::insertarNodoIntAntes(Automovil v){ */
/*     pnodo aux; */
/*     int i = 1; */

/*     //Siempre se crea el nodo sin imporar */
/*     //si entra por el else o if :) */
/*     aux = new Nodo(v,NULL,NULL); */
/*     if(listaVacia()) { */
/*         fin=cabeza=aux; */
/*     }else{ */
/*         actual=cabeza; */
/*         while(actual){ */
/*                 cout << "i = " << i << endl; */
/*                 cout << "Cantidad de iteraciones: " << i << endl; */
/*                 // si es mayor que actual entra aquí */
/*                 if(v.modelo.compare(actual->valor.modelo) >= 0){ */
/*                         if((v.modelo.compare(actual->valor.modelo) == 0) && (v.color.compare(actual->valor.color) > 0)){ */
/*                                 aux->anterior = actual; */
/*                                 aux->siguiente = actual; */
/*                                 actual->siguiente = aux; */
/*                                 actual->anterior = aux; */
/*                                 fin = aux; */
/*                                 break; */
/*                         }else if((v.modelo.compare(actual->valor.modelo) == 0) && (v.color.compare(actual->valor.color) < 0)){ */
/*                                 actual->anterior = aux; */
/*                                 actual->siguiente = aux; */
/*                                 aux->siguiente = actual; */
/*                                 aux->anterior = actual; */
/*                                 cabeza = aux; */
/*                                 break; */
/*                         } */
/*                         cout << "Pasa aquí if" << endl; */
/*                         aux->anterior = actual; */
/*                         aux->siguiente = actual; */
/*                         actual->siguiente = aux; */
/*                         actual->anterior = aux; */
/*                         fin = aux; */
/*                         break; */
/*                 }else if(v.modelo.compare(actual->valor.modelo) < 0){ */
/*                         // si es menor que actual entra aquí */
/*                         cout << "Pasa aqui al else " << endl; */
/*                         actual->anterior = aux; */
/*                         actual->siguiente = aux; */
/*                         aux->siguiente = actual; */
/*                         aux->anterior = actual; */
/*                         cabeza = aux; */
/*                         break; */
/*                 } */
/*                 actual = actual->siguiente; */
/*                 i++; */
/*         } */
/*     } */
/* } */


void ListaDoble::insertarNodoIntAntes(Automovil v){

        pnodo aux;
        //Siempre se crea el nodo sin imporar
        //si entra por el else o if :)
        aux = new Nodo(v,NULL,NULL);
        if(listaVacia()) {
                fin=cabeza=aux;
        }else{
                while(actual){
                        // inserta para abajo
                        if(v.modelo.compare(actual->valor.modelo) > 0){
                                /* aux->siguiente=actual; */
                                /* aux->anterior=actual->anterior; */
                                /* actual->anterior->siguiente=aux; */
                                /* actual->anterior=aux; */

                        }else{
                                /* aux->siguiente=actual; */
                                /* aux->anterior=actual->anterior; */
                                /* actual->anterior->siguiente=aux; */
                                /* actual->anterior=aux; */
                                /* actual = actual->siguiente; */
                        }
                        actual = actual->siguiente;
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
            if(aux == fin){
                break;
            }else{
                    aux = aux->siguiente;
            }
        }
    }
    else {
        esUltimo();
        aux = fin;
        cout << " | " << "modelo" << " | " << "Bastidor" << " | " << "color" << " | " << "zona" << " | " << "concesionario" << endl;
        if(aux == fin){
            cout << "" << endl;
            cout << " | " << aux->valor.modelo << setw(5) << " | " << aux->valor.Nbastidor << setw(4) << " | " << aux->valor.color << " | " << aux->valor.zona << setw(7) << " | " << aux->valor.concesionario << setw(12) << " | "  << endl;
        }
        while(aux != cabeza) {
            cout << "" << endl;
            cout << " | " << aux->valor.modelo << setw(5) << " | " << aux->valor.Nbastidor << setw(4) << " | " << aux->valor.color << " | " << aux->valor.zona << setw(7) << " | " << aux->valor.concesionario << setw(12) << " | "  << endl;
            if(aux == fin){
                break;
            }else{
                    aux = aux->siguiente;
            }
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


