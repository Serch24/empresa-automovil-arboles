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
                                }else if(actual->valor.modelo.compare(actual->siguiente->valor.modelo) == 0){
                                        if(actual->valor.color.compare(actual->siguiente->valor.color) > 0){
                                                swap(actual->valor, actual->siguiente->valor);
                                                cambiado = 1;
                                        }
                                }
                                actual = actual->siguiente;
                        }
                        tmp = actual;
                }while(cambiado);
        }

}

void ListaDoble::borrarVehiculos(string modelo){
        if(!listaVacia()){
                actual = cabeza;
                while(actual){
                        pnodo aux;
                        if(actual->valor.modelo == modelo){
                                if(actual == cabeza && fin != actual){
                                    aux = cabeza;
                                    cabeza = cabeza->siguiente;
                                    cabeza->anterior = NULL;
                                    delete aux;
                                }else if(actual == fin && actual != cabeza){
                                    aux = fin;
                                    fin = fin->anterior;
                                    fin->siguiente = NULL;
                                    delete aux;
                                 }else if(actual == fin && cabeza == actual){
                                     cabeza=NULL;
                                     actual=NULL;
                                     fin=NULL;
                                     break;
                                 }else{
                                    aux = actual;
                                    actual->anterior->siguiente = actual->siguiente;
                                    actual->siguiente->anterior = actual->anterior;
                                    delete aux;
                                }
                                actual = actual->siguiente;
                        }else{
                            actual = actual->siguiente;
                        }
                }
        }
}

Automovil ListaDoble::sacarVehiculos(int numero){
        Automovil automov;
        if(!listaVacia()){
                actual = cabeza;
                while(actual){
                        pnodo aux;
                        if(actual->valor.concesionario == numero){
                                if(actual == cabeza && fin != actual){
                                    aux = cabeza;
                                    cabeza = cabeza->siguiente;
                                    cabeza->anterior = NULL;
                                    automov = aux->valor;
                                    delete aux;
                                }else if(actual == fin && actual != cabeza){
                                    aux = fin;
                                    fin = fin->anterior;
                                    fin->siguiente = NULL;
                                    automov = aux->valor;
                                    delete aux;
                                 }else if(actual == fin && cabeza == actual){
                                     automov = actual->valor;
                                     cabeza=NULL;
                                     actual=NULL;
                                     fin=NULL;
                                     break;
                                 }else{
                                    aux = actual;
                                    actual->anterior->siguiente = actual->siguiente;
                                    actual->siguiente->anterior = actual->anterior;
                                    automov = aux->valor;
                                    delete aux;
                                }
                                actual = actual->siguiente;
                                return automov;
                        }else{
                            actual = actual->siguiente;
                        }
                }
        }
        return automov;
}

Automovil ListaDoble::sacarVehiculos(char zona){
        Automovil automov;
        if(!listaVacia()){
                actual = cabeza;
                while(actual){
                        pnodo aux;
                        if(actual->valor.zona == zona){
                                if(actual == cabeza && fin != actual){
                                    aux = cabeza;
                                    automov = aux->valor;
                                    cabeza = cabeza->siguiente;
                                    cabeza->anterior = NULL;
                                    delete aux;
                                }else if(actual == fin && actual != cabeza){
                                    aux = fin;
                                    automov = aux->valor;
                                    fin = fin->anterior;
                                    fin->siguiente = NULL;
                                    delete aux;
                                 }else if(actual == fin && cabeza == actual){
                                     automov = actual->valor;
                                     cabeza=NULL;
                                     actual=NULL;
                                     fin=NULL;
                                     break;
                                 }else{
                                    aux = actual;
                                    automov = aux->valor;
                                    actual->anterior->siguiente = actual->siguiente;
                                    actual->siguiente->anterior = actual->anterior;
                                    delete aux;
                                }
                                break;
                        }else{
                            actual = actual->siguiente;
                        }
                }
        }
        return automov;
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
