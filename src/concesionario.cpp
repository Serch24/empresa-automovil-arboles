#include "concesionario.h"
#include "automovil.h"
#include "arbol.h"

Arbol arbolito;

concesionario::concesionario()
{
    //ctor
}

concesionario::~concesionario()
{
    //dtor
}

concesionario concesionario::generarConcesionario(void){
    concesionario c;
    c.numero = concesionarioAleatorio_numero();
    c.zona = zonaAleatorio();
    c.lista = Lista();

    cout <<"Numero: "<< c.numero <<"Zona: "<< c.zona << endl;
    return c;
}

void concesionario::generar16concesionarios(){
    for(int i = 0; i < 16; i++){
        arbolito.Insertar(generarConcesionario());
    }
}
