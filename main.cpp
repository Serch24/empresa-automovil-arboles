#include "arbol.h"
#include "concesionario.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;
Arbol arbolito;

void insertarVehiculosEnLista(int num){
    Automovil coche = devolverAuto(num);
    cout << coche.Nbastidor << endl;
    cout << "Mostrado!" << endl;
    while(coche.Nbastidor != ""){
        arbolito.insertarVehiculosEnListaArbol(num, coche);
        coche = devolverAuto(num);
    }
}

void insertarVehiculosEnLista(char z){
    Automovil coche = devolverAuto(z);
    cout << coche.Nbastidor << endl;
    cout << "Mostrado!" << endl;
    while(coche.Nbastidor != ""){
        arbolito.insertarVehiculosEnListaArbol(z, coche);
        coche = devolverAuto(z);
    }
}

void mostrar(concesionario &a){
        a.lista.mostrarLista();
}

void mostrarMenuPrincipal(){
        string frases[11] = {"Mostrar listado del arbol.", "Generar N cantidad de vehiculos.", "Mostrar datos del almacen.", "Vaciar almacen.",
        "Escribe el modelo a eliminar.", "Llevar a almacen por concesionario.", "Llevar a almacen por zona.", "Mostrar vehiculos por consecionario.",
        "Mostrar vehiculos y concesionarios por zona.", "Borrar un concesionario.", "Salir."};
        for(int i = 0; i < 11; i+=2){
                if(i != 10){
                        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                        cout << setw(60) <<" - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
                        if (i+1 == 9) cout << "| " << i+1 << " |" << setw(37) << frases[i] << setw(3) << "|";
                        else cout << "| " << i+1 << " |" << setw(37) << frases[i] << setw(10) << "|";
                        cout << setw(10) << "| " << i+2 << " |" << setw(37) << frases[i+1] << setw(11) << "|" << endl;
                        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                        cout << setw(60) << " - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
                }else{
                        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
                        cout << "| " << i+1 << " |" << setw(37) << frases[i] << setw(9) << "|" << endl;
                        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
                }
                cout << "" << endl;
        }
}

void generar16Concesionarios(){
        for(int i = 0; i < 16; i++){
                concesionario a;
                arbolito.Insertar(a);
        }
}

int main(){
        char z;
        int opcion, num;
        string entrada;
        srand(time(NULL));
        generar16Concesionarios();
        /* arbolito.InOrden(mostrar); */
        do{
                mostrarMenuPrincipal();
                cout << "Elija una opcion:" << endl;
                cin >> opcion;

                #if defined(__linux__)
                        system("clear");
                #else
                        //system("cls");
                #endif
                switch(opcion){
                        case 1:
                                break;
                        case 2:
                                generarNAutomoviles(10);
                                ordenar();
                                break;
                        case 3:
                                mostrarAlmacen();
                                break;
                        case 4:
                                vaciarAlmacen();
                                break;
                        case 5:
                            cout << "Escribe algo: " << endl;
                            cin >> entrada;
                                borrarModelo(entrada);
                                break;
                        case 6:
                            cout << "Introduce el numero de concesionario: " <<endl;
                            cin >> num;
                            insertarVehiculosEnLista(num);
                                break;
                        case 7:
                            cout << "Introduce el numero de concesionario: " <<endl;
                            cin >> z;
                            insertarVehiculosEnLista(z);
                                break;
                        case 8:
                            cout << "Introduce el numero de concesionario: " <<endl;
                            cin >> num;
                            arbolito.mostrarVehiculosEnListaArbol(num);
                                break;
                        case 9:
                            cout << "Introduce la zona: " <<endl;
                            cin >> z;
                            arbolito.mostrarVehiculosEnListaArbol(z);
                                break;
                        case 10:
                                break;
                        case 11:
                                break;
                }
        }while(opcion != 11);

        return 0;
}


