#include "arbol.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;

void mostrar(int &a){
        cout << "valor: "  << a << endl;

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

int main(){
        int opcion;
        string entrada;
        srand(time(NULL));
        do{
                mostrarMenuPrincipal();
                cout << "Elija una opcion:" << endl;
                cin >> opcion;

                //system("cls");
                switch(opcion){
                        case 1:
                                break;
                        case 2:
                                generarNAutomoviles(3);
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
                                break;
                        case 7:
                                break;
                        case 8:
                                break;
                        case 9:
                                break;
                        case 10:
                                break;
                        case 11:
                                break;
                }
        }while(opcion != 11);

        return 0;
}
