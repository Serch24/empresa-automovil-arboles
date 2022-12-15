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

// Insertar un int en el �rbol ABB
void Arbol::Insertar(const concesionario dat){
    Nodo *padre = NULL;

    actual = raiz;
    // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
    while(!Vacio(actual) && dat.numero != actual->dato.numero) {
       padre = actual;
       if(dat.numero > actual->dato.numero) actual = actual->derecho;
       else if(dat.numero < actual->dato.numero) actual = actual->izquierdo;
    }

    // Si se ha encontrado el elemento, regresar sin insertar
    if(!Vacio(actual)) return;
    // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
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
/*    // Mientras sea posible que el valor est� en el �rbol */
/*    while(!Vacio(actual)) { */
/*       if(dat == actual->dato) { // Si el valor est� en el nodo actual */
/*          if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos */
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
/*          else { // Si el valor est� en el nodo actual, pero no es hoja */
/*             if (actual->derecho==NULL){ //s�lo tiene hijo izquierdo. */
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
/*             else  if (actual->izquierdo==NULL){ //s�lo tiene hijo derecho. */
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
/*             else{ // Tiene dos hijos. Busco sustituto. Nodo m�s a la derecha de la rama izquierda */
/*                padre=actual; */
/*                nodo = actual->izquierdo; */
/*                while(nodo->derecho) { */
/*                   padre = nodo; */
/*                   nodo = nodo->derecho; */
/*                } */
/*             // Intercambiar valores de nodo a borrar y nodo encontrado y continuar, cerrando el bucle. El nodo encontrado no tiene por qu� ser un nodo hoja. */
/*             // cerrando el bucle nos aseguramos de que s�lo se eliminan nodos hoja. */
/*                 aux = actual->dato; */
/*                 actual->dato = nodo->dato; */
/*                 nodo->dato = aux; */
/*                 actual = nodo; */
/*                 cout << "\n\t\tHay intercambio."; */
/*             } */
/*          } */
/*       } */
/*       else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo */
/*          padre = actual; */
/*          if(dat > actual->dato) actual = actual->derecho; */
/*          else if(dat < actual->dato) actual = actual->izquierdo; */
/*       } */
/*    } */
/* } */


// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
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

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
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

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
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

// Buscar un valor en el �rbol
/* bool Arbol::Buscar(const Automovil dat) */
/* { */
/*    actual = raiz; */

/*    // Todav�a puede aparecer, ya que quedan nodos por mirar */
/*    while(!Vacio(actual)) { */
/*       if(dat == actual->dato) return true; // int encontrado */
/*       else if(dat > actual->dato) actual = actual->derecho; // Seguir */
/*       else if(dat < actual->dato) actual = actual->izquierdo; */
/*    } */
/*    return false; // No est� en �rbol */
/* } */

// Calcular la altura del nodo que contiene el int dat
/* int Arbol::Altura(const Automovil dat) */
/* { */
/*    int altura = 0; */
/*    actual = raiz; */

/*    // Todav�a puede aparecer, ya que quedan nodos por mirar */
/*    while(!Vacio(actual)) { */
/*       if(dat == actual->dato) return altura; // int encontrado */
/*       else { */
/*          altura++; // Incrementamos la altura, seguimos buscando */
/*          if(dat > actual->dato) actual = actual->derecho; */
/*          else if(dat < actual->dato) actual = actual->izquierdo; */
/*       } */
/*    } */
/*    return -1; // No est� en �rbol */
/* } */

/* // Contar el n�mero de nodos */
/* const int Arbol::NumeroNodos() */
/* { */
/*    contador = 0; */

/*    auxContador(raiz); // FUnci�n auxiliar */
/*    return contador; */
/* } */

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void Arbol::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int Arbol::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funci�n auxiliar
   return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
void Arbol::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // �rbol, actualizamos la altura actual del �rbol
   if(EsHoja(nodo) && a > altura) altura = a;
}
