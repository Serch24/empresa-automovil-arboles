#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

#include <iostream>

using namespace std;

struct Automovil
{
        string Nbastidor;
        string modelo ;
        string color;
        char zona;
        string concesionario;
};

Automovil leeAutomovil (void);
Automovil dameAutomovilVacio (void);

void generarNAutomoviles(int); 
void mostrarAlmacen(void);
void vaciarAlmacen(void);

char zonaAleatorio();
string bastidorAleatorio();
string modeloAleatorio();
string colorAleatorio();
string concesionarioAleatorio_letra();
string concesionarioAleatorio_numero();

int sacaCocheNS();
Automovil generaAutomovil(void);
Automovil generaAutomovil(int);
int generarTamanoPila();

#endif
