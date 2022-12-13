#include "concesionario.h"
#include "automovil.h"
#include "arbol.h"

concesionario::concesionario()
{
    numero = concesionarioAleatorio_numero();
    zona = zonaAleatorio();
    lista = Lista();
}

concesionario::~concesionario()
{
    //dtor
}
