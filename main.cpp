#include "arbol.h"
#include "concesionario.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
/* Código hecho por María y Serch (◠﹏◠)/
 * UAH - EPS
 * 2022/2023
*/

using namespace std;
Arbol arbolito;

//Insertar por número de concesionario 
void insertarVehiculosEnLista(int num){
        if(arbolito.Buscar(num)){
                Automovil coche = devolverAuto(num);
                while(coche.Nbastidor != ""){
                        //cout << "bastidor: " << coche.Nbastidor << "Zona: " << coche.zona << ", Modelo: " << coche.modelo << endl;
                        arbolito.insertarVehiculosEnListaArbol(num, coche);
                        coche = devolverAuto(num);
                }
		cout << "¡Vehiculos transportados!" << endl;
        }else{
                cout << "no existe el concesionario" << endl;
        }
}

//Insertar por zona
void insertarVehiculosEnLista(char z){
        if(arbolito.Buscar(z)){
                Automovil coche = devolverAuto(z);
                while(coche.Nbastidor != ""){
                        //cout << "bastidor: " << coche.Nbastidor << "Zona: " << coche.zona << ", Modelo: " << coche.modelo << endl;
                        arbolito.insertarVehiculosEnListaArbol(z, coche);
                        coche = devolverAuto(z);
                }
		cout << "¡Vehiculos transportados!" << endl;
        }else{
                cout << "no existe el concesionario" << endl;
        }
}

void mostrar(concesionario &a){
        cout << "Concesionario: " << a.numero << ", zona: " << a.zona << ", Cantidad de vehiculos: " << a.lista.contarVehiculos() << endl; 
}

void mostrarMenuPrincipal(){
        string frases[11] = {"Mostrar listado del arbol.", "Generar N cantidad de vehiculos.", "Mostrar almacen.", "Vaciar almacen.",
"Escribe el modelo a eliminar.", "Llevar a almacen por concesionario.", "Llevar a almacen por zona.", "Mostrar vehiculos por consecionario.",
"Mostrar vehiculos por zona.", "Borrar un concesionario.", "Salir."};
        for(int i = 0; i < 11; i+=2){
                if(i != 10){
                        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                        cout << setw(60) <<" - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
                        if (i+1 == 9) cout << "| " << i+1 << " |" << setw(45) << frases[i] << setw(3) << "|";
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
        int opcion;
        srand(time(NULL));
        generar16Concesionarios();
        do{
                char z;
                int num;
                string entrada;
                mostrarMenuPrincipal();
                cout << "Elija una opcion:" << endl;
                cin >> opcion;

                #if defined(__linux__)
                        system("clear");
                #else
                        system("cls");
                #endif
                switch(opcion){
                        case 1:
                                arbolito.InOrden(mostrar);
                                cout << "Altura del arbol: " << arbolito.AlturaArbol() << endl;
                                cout << "Numero de nodos: " << arbolito.NumeroNodos() << endl;
                                break;
                        case 2:
                            cout << "Introduce el numero de coches a crear: " <<endl;
                            cin >> num;
                                generarNAutomoviles(num);
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
                            cout << "Introduce la zona: " <<endl;
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
                                cout << "Introduce el numero de concesionario a borrar: " <<endl;
                                cin >> num;
                                arbolito.Borrar(num);
                                break;
                }
        }while(opcion != 11);

        return 0;
}



