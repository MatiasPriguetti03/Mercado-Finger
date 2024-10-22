#ifndef ICOMPRA
#define ICOMPRA

#include <set>
#include <string>

#include "../datatypes/DataCompra.h"

using namespace std;


class ICompra {
    public:
        //Operaciones de Sistema
        virtual void seleccionarCliente(string nickname) = 0;
        virtual void agregarProductoCompra(int codeProd, int cant) = 0;
        virtual DataCompra * mostrarCompra() = 0; 
        virtual void confirmarCompra() = 0; 
};

#endif