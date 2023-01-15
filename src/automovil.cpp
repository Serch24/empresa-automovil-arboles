#include "automovil.h"
#include "listas_dobles.h"
#include "arbol.h"

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
//#include <map>

using namespace std;
ListaDoble almacen;
concesionario conces;

int cantidadCoches = 16;
vector<int> numConsesionarios= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

/*map<string, int> zonas["A"];
zonas["A"] = "hola";
zonas["B"] = {};
zonas["C"] = {};
zonas["D"] = {};*/


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
	int numRand=-1;
	while(numConsesionarios.size() > 0){
		numRand = 1 + rand() % (16 + 1 - 1);
		for(int i=0; i < numConsesionarios.size();i++){
			if(numRand == numConsesionarios[i]){
				numConsesionarios.erase(numConsesionarios.begin() + i);
				return numRand;
			}
		}
	}
        return numRand;
}
/*string asignarZona(){

    for (size_t i = 0; i < zonas.size(); i++){
        string zonaActual = zonas[i];
        if (conces.zona == zonaActual){
            mapa[zonaActual] = conces.numero;
        }
        else{
            mapa[zonaActual]++;
        }
    }
}*/

void generarNAutomoviles(int cantidad){
        for(int i = 0; i < cantidad; i++){
		if(numConsesionarios.size() > 0){
			Automovil autoM;
			autoM.color = colorAleatorio();
			autoM.modelo = modeloAleatorio();
			autoM.Nbastidor = bastidorAleatorio();
            autoM.concesionario = concesionarioAleatorio_numero();
            autoM.zona = zonaAleatorio();

            /*if (arbolito.Buscar(autoM.concesionario)){
                cout <<"LLEGO AQUI" << endl;
                autoM.zona = conces.zona;
            }*/

			almacen.insertarNodo(autoM);
		}else{
			cout << "no hay " << numConsesionarios.size()<< endl;
		}
        }
}

void ordenar(){
        almacen.ordenarLista();
}

void mostrarAlmacen(){
        almacen.mostrarLista();
}

Automovil devolverAuto(int numero){
    return almacen.sacarVehiculos(numero);
}

Automovil devolverAuto(char zona){
    return almacen.sacarVehiculos(zona);
}

void vaciarAlmacen(){
        almacen.vaciar();
	numConsesionarios.clear();
	for(int i = 0; i < 16; i++){
		numConsesionarios.push_back(i+1);
	}
}

void borrarModelo(string m){
        almacen.borrarVehiculos(m);
}
