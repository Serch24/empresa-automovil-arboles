#include "arbol.h"
#include "automovil.h"
#include "concesionario.h"
#include <algorithm>
#include <stdio.h>

// Poda: borrar todos los nodos a partir de uno, incluido
void Arbol::Podar(Nodo* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un concesionario en el árbol ABB
void Arbol::Insertar(const concesionario dat){
	Nodo *padre = NULL;

	actual = raiz;
	// Buscar el int en el árbol, manteniendo un puntero al nodo padre
	while(!Vacio(actual) && dat.numero != actual->dato.numero) {
		padre = actual;
		if(dat.numero > actual->dato.numero) actual = actual->derecho;
		else if(dat.numero < actual->dato.numero) actual = actual->izquierdo;
	}

	// Si se ha encontrado el elemento, regresar sin insertar
	if(!Vacio(actual)) return;
	// Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
	// el nodo raiz
	if(Vacio(padre)){
		raiz = new Nodo(dat);
	}else if(dat.numero < padre->dato.numero){
	       	padre->izquierdo = new Nodo(dat);
	}else if(dat.numero > padre->dato.numero){
	       	padre->derecho = new Nodo(dat);
	}

	//actualizarAltura(raiz);
}

void Arbol::actualizarAltura(Nodo *abb){
	if(Vacio(abb)) return;
	altura = 1 + max(alturaDeNodo(abb->izquierdo), alturaDeNodo(abb->derecho));
	balancear(abb);
	actualizarAltura(abb->izquierdo);
	actualizarAltura(abb->derecho);
}

/*void Arbol::Insertar(concesionario dat, Nodo *abb, bool r){
	if(Vacio(raiz)){
		raiz = new Nodo(dat);
		return;
	}
	if(r) abb = raiz;
	if(Vacio(abb)){
		abb = new Nodo(dat);
		cout << "pasa" << endl;
		return;
	}
	if(dat.numero < abb->dato.numero){
		Insertar(dat, abb->izquierdo, false);
	}else if(dat.numero > abb->dato.numero){
		Insertar(dat, abb->derecho, false);
	}else{
		return;
	}

	raiz = abb;
	//balancear();
}*/

void Arbol::rotacionSimple(Nodo *abb, bool giroIzq){
	Nodo *aux;
	if(giroIzq){
		aux = abb->derecho;
		abb->derecho = aux->izquierdo;
		aux->izquierdo = abb;
	}else{
		aux = abb->izquierdo;
		abb->izquierdo = aux->derecho;
		aux->derecho = abb;
	}
	abb = aux;
}

void Arbol::rotacionDoble(bool giroIzq){
	if(giroIzq){
		rotacionSimple(raiz->derecho, false);
		rotacionSimple(raiz, true);
	}else{
		rotacionSimple(raiz->izquierdo, true);
		rotacionSimple(raiz, false);
	}
}

/*void Arbol::balancear(){
	if(raiz != NULL){
		if((alturaDeNodo(raiz->derecho) - alturaDeNodo(raiz->izquierdo)) == -2){
			if(alturaDeNodo(raiz->izquierdo->izquierdo) >= alturaDeNodo(raiz->izquierdo->derecho)){
				rotacionSimple(raiz, true);
			}else{
				rotacionDoble(true);
			}
		}else{
			if((alturaDeNodo(raiz->derecho) - alturaDeNodo(raiz->izquierdo)) == 2){
				if(alturaDeNodo(raiz->derecho->derecho) >= alturaDeNodo(raiz->derecho->izquierdo)){
					rotacionSimple(raiz, false);
				}else{
					rotacionDoble(false);
				}
			}
		}
	}
}
*/

void Arbol::balancear(Nodo *abb){
	if(Vacio(abb)) return;
	if(alturaDeNodo(abb->izquierdo) - alturaDeNodo(abb->derecho) > 1){
		if(alturaDeNodo(abb->izquierdo->izquierdo) - alturaDeNodo(abb->izquierdo->derecho) >= 0){
			rotacionSimple(abb, false);
		}else{
			rotacionDoble(false);
		}
	}else if(alturaDeNodo(abb->izquierdo) - alturaDeNodo(abb->derecho) < -1){
		if(alturaDeNodo(abb->derecho->izquierdo) - alturaDeNodo(abb->derecho->derecho) <= 0){
			rotacionSimple(abb, true);
		}else{
			rotacionDoble(true);
		}
	}
}

void Arbol::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato.numero) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            /* cout << "\n\t\tBorrado un nodo hoja,"; */
            if(padre) {// Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            }
            else{
                /* cout << " que ademas era raiz."; */
                raiz=NULL;
            }
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            if (actual->derecho==NULL){ //sólo tiene hijo izquierdo.
                /* cout << "\n\t\tBorrado un nodo lista izquierda,"; */
                if (padre){ //Si tiene padre, me lo salto
                        if(padre->izquierdo==actual)
                            padre->izquierdo=actual->izquierdo;
                        else
                            padre->derecho=actual->izquierdo;
                }
                else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz;
                    /* cout << " que ademas era raiz."; */
                    raiz=actual->izquierdo;
                }
                delete actual;
                actual=NULL;
                return;
            }
            else  if (actual->izquierdo==NULL){ //sólo tiene hijo derecho.
                /* cout << "\n\t\tBorrado un nodo lista derecha,"; */
                if (padre){ //Si tiene padre, me lo salto
                        if(padre->izquierdo==actual)
                            padre->izquierdo=actual->derecho;
                        else
                            padre->derecho=actual->derecho;
                }
                else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz;
                    /* cout << " que ademas era raiz."; */
                    raiz=actual->derecho;
                                    }
                delete actual;
                actual=NULL;
                return;
            }
            else{ // Tiene dos hijos. Busco sustituto. Nodo más a la derecha de la rama izquierda
               padre=actual;
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            // Intercambiar valores de nodo a borrar y nodo encontrado y continuar, cerrando el bucle. El nodo encontrado no tiene por qué ser un nodo hoja.
            // cerrando el bucle nos aseguramos de que sólo se eliminan nodos hoja.
                aux = actual->dato.numero;
                actual->dato = nodo->dato;
                nodo->dato.numero = aux;
                actual = nodo;
                /* cout << "\n\t\tHay intercambio."; */
            }
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat> actual->dato.numero) actual = actual->derecho;
         else if(dat< actual->dato.numero) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void Arbol::InOrden(void (*func)(concesionario&), Nodo *nodo, bool r)
{
   if (Vacio(raiz)) return;
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

void Arbol::PreOrden(void (*func)(concesionario&), Nodo *nodo, bool r){
	if (Vacio(raiz)) return;
	if(r) nodo = raiz;
	func(nodo->dato);
	if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
	if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

void Arbol::insertarVehiculosEnListaArbol(int num, Automovil coche){
        actual = raiz;
        // Todavía puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
                if(num == actual->dato.numero){
                        actual->dato.lista.insertarNodoAlInicio(coche);
                        break;
                }
                else if(num > actual->dato.numero) actual = actual->derecho; // Seguir
                else if(num < actual->dato.numero) actual = actual->izquierdo;
        }
}

bool Arbol::insertarVehiculosEnListaArbol(char z, Automovil coche, Nodo *nodo, bool r){
	bool found = false;
	if (Vacio(raiz)) return false;
	if(r) nodo = raiz;
	if(Vacio(nodo)) return false;
	if(nodo->dato.zona == z){
		cout << "Insertando coche... " << coche.Nbastidor << endl;
		nodo->dato.lista.insertarNodoAlInicio(coche);
		return true;
	}
	bool izq = insertarVehiculosEnListaArbol(z, coche, nodo->izquierdo, false);
	if(izq) return true;
	bool der = insertarVehiculosEnListaArbol(z, coche, nodo->derecho, false);
	return der;
}

void Arbol::mostrarVehiculosEnListaArbol(int num, Nodo *nodo, bool r)
{
        actual = raiz;
        // busca el concesionario
         while(!Vacio(actual)) {
                if(num == actual->dato.numero){
                        actual->dato.lista.mostrarLista();
                        break;
                }
                else if(num > actual->dato.numero) actual = actual->derecho; // Seguir
                else if(num < actual->dato.numero) actual = actual->izquierdo;
        }
}

void Arbol::mostrarVehiculosEnListaArbol(char z, Nodo *abb, bool b){
	if(Vacio(raiz)) return;
	if(b) abb = raiz;
	if(abb->izquierdo) mostrarVehiculosEnListaArbol(z, abb->izquierdo, false);
	if(z == abb->dato.zona){
		abb->dato.lista.mostrarLista();
	}
	if(abb->derecho) mostrarVehiculosEnListaArbol(z, abb->derecho, false);
}

// Buscar un valor en el árbol
bool Arbol::Buscar(const int numConcesionario)
{
        actual = raiz;
        while(!Vacio(actual)) {
                if(numConcesionario == actual->dato.numero) return true; // int encontrado
                else if(numConcesionario > actual->dato.numero) actual = actual->derecho; // Seguir
                else if(numConcesionario < actual->dato.numero) actual = actual->izquierdo;
        }
        return false; // No está en árbol
}

bool Arbol::Buscar(char z, Nodo *abb, bool b){
	if(Vacio(raiz)) return false;
	if(b) abb= raiz;
	if(Vacio(abb)) return false;
	//cout << abb->dato.zona << endl;
	return (z == abb->dato.zona) || Buscar(z, abb->izquierdo, false) || Buscar(z, abb->derecho, false);
}

// Calcular la altura del nodo que contiene el int dat
int Arbol::Altura(const concesionario dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.numero == actual->dato.numero) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat.numero > actual->dato.numero) actual = actual->derecho;
         else if(dat.numero < actual->dato.numero) actual = actual->izquierdo;
      }
   }
   return 0; // No está en árbol
}

/*int Arbol::alturaDeNodo(Nodo *a){
	if(!Vacio(a)){
		if(Vacio(a->izquierdo)){
			if(Vacio(a->derecho)){
				return 0;
			}else{
				return 1 + alturaDeNodo(a->derecho);
			}
		}else{
			if(Vacio(a->derecho)){
				return 1 + alturaDeNodo(a->izquierdo);
			}else{
				return 1 + max(alturaDeNodo(a->izquierdo), alturaDeNodo(a->derecho));
			}
		}
	}
	return 0;
}
*/

int Arbol::alturaDeNodo(Nodo *a) {
  if (a == NULL) {
    return 0;
  }
  return 1 + max(alturaDeNodo(a->izquierdo), alturaDeNodo(a->derecho));
}

// Contar el número de nodos
const int Arbol::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void Arbol::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int Arbol::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void Arbol::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}
