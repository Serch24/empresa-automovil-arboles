#include "automovil.h"
#include "listas_dobles.h"
#include "arbol.h"

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
ListaDoble almacen;
int cantidadCoches = 16;

Automovil dameAutomovilVacio(void){     //coche vacio
    Automovil p;
    p.Nbastidor = "";
    p.modelo="";
    p.color="";
    p.concesionario = 0;
    return p;
}

string bastidorAleatorio(){     //genera bastidor aleatorio
    string numBastidor;
    string letra = "";
    string unaLetra[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string digito = "";
    string unDigito[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int j = 0;
    int t = 0;

    for (j = 0; j < 4; j++){
        int i = 0;

        i = rand() % 25;
        letra += unaLetra[i];
    }
    for (t = 0; t < 3; t++){
        int i = 0;

        i = rand() % 9;
        digito += unDigito[i];
    }
    numBastidor = letra + digito;

    return numBastidor;
}

string modeloAleatorio(){   //genera modelo aleatorio
    int modeloRandom = 0;
    string nuevoModelo[] = {"FIAT", "BMW", "SEAT", "HONDA"};
    modeloRandom = rand() % 4;
    return nuevoModelo[modeloRandom];
}

string  colorAleatorio(){   //genera color aleatorio
    int i = 0;
    string nuevoColor[] = {"ROJO", "NEGRO", "BLANCO", "AZUL", "VERDE", "GRIS"};
    i = rand() % 6;
    return nuevoColor[i];
}

char zonaAleatorio(){
        int random;
        char zonas[] = {'A','B', 'C', 'D'};
        random = rand() % 4;
        return zonas[random];
}

int concesionarioAleatorio_numero(){
        int numRand = 1 + rand() % (16 + 1 - 1); // 5
        return numRand;
}

Automovil generaAutomovil(string ve){    //genera un coche aleatorio
    Automovil v;
    v.color = colorAleatorio();
    v.modelo = ve;
    v.Nbastidor = bastidorAleatorio();
    v.zona = zonaAleatorio();
    v.concesionario= concesionarioAleatorio_numero();
    /* cout << "El modelo es: " << v.modelo  << "y su color es: " << v.color << endl; */
    return v;
 }

void generarNAutomoviles(int cantidad){
        for(int i = 0; i < cantidad; i++){
                Automovil autoM;
                autoM.color = colorAleatorio();
                autoM.modelo = modeloAleatorio();
                autoM.Nbastidor = bastidorAleatorio();
                autoM.zona = zonaAleatorio();
                autoM.concesionario = concesionarioAleatorio_numero();
                almacen.insertarNodo(autoM);
        }
}

void ordenar(){
        almacen.ordenarLista();
}

void mostrarAlmacen(){
        almacen.mostrarLista(0);
}

Automovil devolverAuto(int numero){
    return almacen.sacarVehiculos(numero);
}

void vaciarAlmacen(){
        almacen.vaciar();
}

void borrarModelo(string m){
        almacen.borrarVehiculos(m);
}
