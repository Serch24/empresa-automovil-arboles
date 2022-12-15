#include "arbol.h"
#include "automovil.h"
#include "concesionario.h"

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

// Insertar un int en el árbol ABB
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
    if(Vacio(padre)) raiz = new Nodo(dat);
    // Si el int es menor que el que contiene el nodo padre, lo insertamos
    // en la rama izquierda
    else if(dat.numero < padre->dato.numero) padre->izquierdo = new Nodo(dat);
    // Si el int es mayor que el que contiene el nodo padre, lo insertamos
    // en la rama derecha
    else if(dat.numero > padre->dato.numero) padre->derecho = new Nodo(dat);
 }

 void Arbol::InsertarEnLista(Automovil coche){
     actual = raiz;
     cout << raiz->dato.numero << "nuhyhyhuj"<< endl;

 }

/* void Arbol::Borrar(const Automovil dat) */
/* { */
/*    Nodo *padre = NULL; */
/*    Nodo *nodo; */
/*    int aux; */

/*    actual = raiz; */
/*    // Mientras sea posible que el valor esté en el árbol */
/*    while(!Vacio(actual)) { */
/*       if(dat == actual->dato) { // Si el valor está en el nodo actual */
/*          if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos */
/*             cout << "\n\t\tBorrado un nodo hoja,"; */
/*             if(padre) {// Si tiene padre (no es el nodo raiz) */
/*                // Anulamos el puntero que le hace referencia */
/*                if(padre->derecho == actual) padre->derecho = NULL; */
/*                else if(padre->izquierdo == actual) padre->izquierdo = NULL; */
/*             } */
/*             else{ */
/*                 cout << " que ademas era raiz."; */
/*                 raiz=NULL; */
/*             } */
/*             delete actual; // Borrar el nodo */
/*             actual = NULL; */
/*             return; */
/*          } */
/*          else { // Si el valor está en el nodo actual, pero no es hoja */
/*             if (actual->derecho==NULL){ //sólo tiene hijo izquierdo. */
/*                 cout << "\n\t\tBorrado un nodo lista izquierda,"; */
/*                 if (padre){ //Si tiene padre, me lo salto */
/*                         if(padre->izquierdo==actual) */
/*                             padre->izquierdo=actual->izquierdo; */
/*                         else */
/*                             padre->derecho=actual->izquierdo; */
/*                 } */
/*                 else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz; */
/*                     cout << " que ademas era raiz."; */
/*                     raiz=actual->izquierdo; */
/*                 } */
/*                 delete actual; */
/*                 actual=NULL; */
/*                 return; */
/*             } */
/*             else  if (actual->izquierdo==NULL){ //sólo tiene hijo derecho. */
/*                 cout << "\n\t\tBorrado un nodo lista derecha,"; */
/*                 if (padre){ //Si tiene padre, me lo salto */
/*                         if(padre->izquierdo==actual) */
/*                             padre->izquierdo=actual->derecho; */
/*                         else */
/*                             padre->derecho=actual->derecho; */
/*                 } */
/*                 else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz; */
/*                     cout << " que ademas era raiz."; */
/*                     raiz=actual->derecho; */
/*                                     } */
/*                 delete actual; */
/*                 actual=NULL; */
/*                 return; */
/*             } */
/*             else{ // Tiene dos hijos. Busco sustituto. Nodo más a la derecha de la rama izquierda */
/*                padre=actual; */
/*                nodo = actual->izquierdo; */
/*                while(nodo->derecho) { */
/*                   padre = nodo; */
/*                   nodo = nodo->derecho; */
/*                } */
/*             // Intercambiar valores de nodo a borrar y nodo encontrado y continuar, cerrando el bucle. El nodo encontrado no tiene por qué ser un nodo hoja. */
/*             // cerrando el bucle nos aseguramos de que sólo se eliminan nodos hoja. */
/*                 aux = actual->dato; */
/*                 actual->dato = nodo->dato; */
/*                 nodo->dato = aux; */
/*                 actual = nodo; */
/*                 cout << "\n\t\tHay intercambio."; */
/*             } */
/*          } */
/*       } */
/*       else { // Todavía no hemos encontrado el valor, seguir buscándolo */
/*          padre = actual; */
/*          if(dat > actual->dato) actual = actual->derecho; */
/*          else if(dat < actual->dato) actual = actual->izquierdo; */
/*       } */
/*    } */
/* } */


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

void Arbol::insertarVehiculosEnListaArbol(int num, Automovil coche, Nodo *nodo, bool r)
{
    int a = num;
    Automovil b = coche;
   if (Vacio(raiz)) return;
   if(r) nodo = raiz;
   if(nodo->izquierdo){
        if(nodo->dato.numero == num){
            nodo->dato.lista.insertarNodoAlFinal(coche);
        }
        InOrden(a, b, nodo->izquierdo, false);
   }
   if(nodo->derecho){
        if(nodo->dato.numero == num){
            nodo->dato.lista.insertarNodoAlFinal(coche);
        }
        InOrden(num, coche, nodo->derecho, false);
   }
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void Arbol::PreOrden(void (*func)(concesionario&), Nodo *nodo, bool r)
{
   if (Vacio(raiz)) return;
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void Arbol::PostOrden(void (*func)(concesionario&), Nodo *nodo, bool r)
{
   if (Vacio(raiz)) return;
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
}

// Buscar un valor en el árbol
/* bool Arbol::Buscar(const Automovil dat) */
/* { */
/*    actual = raiz; */

/*    // Todavía puede aparecer, ya que quedan nodos por mirar */
/*    while(!Vacio(actual)) { */
/*       if(dat == actual->dato) return true; // int encontrado */
/*       else if(dat > actual->dato) actual = actual->derecho; // Seguir */
/*       else if(dat < actual->dato) actual = actual->izquierdo; */
/*    } */
/*    return false; // No está en árbol */
/* } */

// Calcular la altura del nodo que contiene el int dat
/* int Arbol::Altura(const Automovil dat) */
/* { */
/*    int altura = 0; */
/*    actual = raiz; */

/*    // Todavía puede aparecer, ya que quedan nodos por mirar */
/*    while(!Vacio(actual)) { */
/*       if(dat == actual->dato) return altura; // int encontrado */
/*       else { */
/*          altura++; // Incrementamos la altura, seguimos buscando */
/*          if(dat > actual->dato) actual = actual->derecho; */
/*          else if(dat < actual->dato) actual = actual->izquierdo; */
/*       } */
/*    } */
/*    return -1; // No está en árbol */
/* } */

/* // Contar el número de nodos */
/* const int Arbol::NumeroNodos() */
/* { */
/*    contador = 0; */

/*    auxContador(raiz); // FUnción auxiliar */
/*    return contador; */
/* } */

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
