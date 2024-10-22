#ifndef CONTROLADORCOMPRA
#define CONTROLADORCOMPRA

// Tipos
#include <string>
#include <vector>

// Clases
#include "../classes/CompraProducto.h"

// Interfaces
#include "../interfaces/ICompra.h"

#include "ControladorPromocion.h"

// Datatypes
#include "../datatypes/DataCompra.h"
#include "../datatypes/DataProducto.h"

#include "../system/FechaSistema.h"

using namespace std;

class ControladorCompra : public ICompra {
    private:
        DataCompra* compraActual;
        // pseudoatributos
        set<CompraProducto*> ProductosCompra;
        vector<DataProductoCompra> ProdsConPrecio;
    public:
        // Constructor
        ControladorCompra();

        // Operaciones
        void seleccionarCliente(string nickname);
        void agregarProductoCompra(int codeProd, int cant);
        DataCompra * mostrarCompra();
        void confirmarCompra();
};

#endif