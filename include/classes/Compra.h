#ifndef COMPRA
#define COMPRA

// Tipos
#include <string>
#include <vector>

// Clases
#include "Producto.h"
#include "CompraProducto.h"

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataCompra.h"

using namespace std;

class Compra {
    private:
        DataFecha fecha;
        float montoFinal;

        // Pseudoatributos
        vector<CompraProducto*> productos;

    public:
        // Contructor
        Compra(DataFecha fecha, float montoFinal);

        // Getters
        DataFecha getFecha();
        CompraProducto* getCompraProducto(int codeProd);
        DataCompra getDataCompra(string nickname);

        // Operaciones
        void agregarProducto(Producto* prod, int cant);

        // Destructor
        ~Compra();
};

#endif