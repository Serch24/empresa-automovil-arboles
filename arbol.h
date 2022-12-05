#ifndef arbol_H_INCLUDED
#define arbol_H_INCLUDED
#include "automovil.h"
#include <iostream>

using namespace std;

class Arbol{
        private:
           //// Clase local de Lista para Nodo de ArbolBinario:
           class Nodo {
             public:
              // Constructor:
              Nodo(const Automovil dat, Nodo *izq=NULL, Nodo *der=NULL) :
                dato(dat), izquierdo(izq), derecho(der) {}
              // Miembros:
              Automovil dato;
              Nodo *izquierdo;
              Nodo *derecho;
           };

           // Punteros de la lista, para cabeza y nodo actual:
           Nodo *raiz;
           Nodo *actual;
           int contador;
           int altura;

          public:
           // Constructor y destructor básicos:
           Arbol() : raiz(NULL), actual(NULL) {}
           ~Arbol() { Podar(raiz); }
           // Insertar en árbol ordenado:
           void Insertar(const Automovil dat);
           // Borrar un elemento del árbol:
           void Borrar(const Automovil dat);
           // Función de búsqueda:
           bool Buscar(const Automovil dat);
           // Comprobar si el árbol está vacío:
           bool Vacio(Nodo *r) { return r==NULL; }
           // Comprobar si es un nodo hoja:
           bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
           // Contar número de nodos:
           const int NumeroNodos();
           const int AlturaArbol();
           // Calcular altura de un int:
           int Altura(const Automovil dat);
           // Devolver referencia al int del nodo actual:
           Automovil &ValorActual() { return actual->dato; }
           // Moverse al nodo raiz:
           void Raiz() { actual = raiz; }
           // Aplicar una función a cada elemento del árbol:
           void InOrden(void (*func)(Automovil&) , Nodo *nodo=NULL, bool r=true);
           void PreOrden(void (*func)(Automovil&) , Nodo *nodo=NULL, bool r=true);
           void PostOrden(void (*func)(Automovil&) , Nodo *nodo=NULL, bool r=true);
          private:
           // Funciones auxiliares
           void Podar(Nodo* &);
           void auxContador(Nodo*);
           void auxAltura(Nodo*, int);


};

#endif
