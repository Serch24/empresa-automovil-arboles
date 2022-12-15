#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

#include <iostream>

using namespace std;

struct Automovil
{
        string Nbastidor;
        string modelo;
        string color;
        char zona;
        int concesionario;
};

Automovil leeAutomovil (void);
Automovil dameAutomovilVacio (void);

void generarNAutomoviles(int);
void mostrarAlmacen(void);
void vaciarAlmacen(void);
void ordenar();

char zonaAleatorio();
string bastidorAleatorio();
string modeloAleatorio();
string colorAleatorio();
string concesionarioAleatorio_letra();
int concesionarioAleatorio_numero();
void borrarModelo(string m);

int sacaCocheNS();
Automovil generaAutomovil(string ve);
Automovil generaAutomovil(int);
int generarTamanoPila();
Automovil devolverAuto(int numero);
Automovil devolverAuto(char zona);

#endif
