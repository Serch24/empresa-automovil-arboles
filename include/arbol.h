#ifndef arbol_H_INCLUDED
#define arbol_H_INCLUDED
#include "automovil.h"
#include "concesionario.h"

#include <iostream>

using namespace std;

class Arbol{
        private:
           //// Clase local de Lista para Nodo de ArbolBinario:
           class Nodo {
             public:
              // Constructor:
              Nodo(const concesionario dat, Nodo *izq=NULL, Nodo *der=NULL) :
                dato(dat), izquierdo(izq), derecho(der) {}
              // Miembros:
              concesionario dato;
              Nodo *izquierdo;
              Nodo *derecho;
           };

           // Punteros de la lista, para cabeza y nodo actual:
           Nodo *raiz;
           Nodo *actual;
           int contador;
           int altura;

          public:
           // Constructor y destructor b�sicos:
           Arbol() : raiz(NULL), actual(NULL) {}
           ~Arbol() { Podar(raiz); }
           // Insertar en �rbol ordenado:
           void Insertar(const concesionario dat);
           //void Insertar(concesionario dat, Nodo *abb=NULL, bool=true);
           void InsertarEnLista(Automovil coche);
           // Borrar un elemento del �rbol:
           void Borrar(const int dat);
           // Funci�n de b�squeda:
           bool Buscar(const int numConcesionario);
           bool Buscar(char z, Nodo *abb = NULL, bool b=true);
           // Comprobar si el �rbol est� vac�o:
           bool Vacio(Nodo *r) { return r==NULL; }
           // Comprobar si es un nodo hoja:
           bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
           // Contar n�mero de nodos:
           const int NumeroNodos();
           const int AlturaArbol();
           // Calcular altura de un int:
           int Altura(const concesionario dat);
           // Devolver referencia al int del nodo actual:
           concesionario &ValorActual() { return actual->dato; }
           // Moverse al nodo raiz:
           void Raiz() { actual = raiz; }
           // Aplicar una funci�n a cada elemento del �rbol:
           void InOrden(void (*func)(concesionario&) , Nodo *nodo=NULL, bool r=true);
           void PreOrden(void (*func)(concesionario&) , Nodo *nodo=NULL, bool r=true);
           void PostOrden(void (*func)(concesionario&) , Nodo *nodo=NULL, bool r=true);
           void insertarVehiculosEnListaArbol(int num, Automovil coche);
           bool insertarVehiculosEnListaArbol(char num, Automovil coche, Nodo *nodo=NULL, bool r=true);
           void mostrarVehiculosEnListaArbol(int num, Nodo *nodo=NULL, bool r=true);
           void mostrarVehiculosEnListaArbol(char z, Nodo *abb=NULL,bool r=true);
	   void rotacionSimple(Nodo *abb, bool b);
	   void rotacionDoble(bool b);
	   void balancear(Nodo *abb);
	   int alturaDeNodo(Nodo *nodo);
	   void actualizarAltura(Nodo *abb);

          private:
           // Funciones auxiliares
           void Podar(Nodo* &);
           void auxContador(Nodo*);
           void auxAltura(Nodo*, int);


};

#endif
