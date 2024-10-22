#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

// Clases
#include "Producto.h"

// Datatypes
#include "../datatypes/DataProductoCompra.h"

using namespace std;

class CompraProducto {
    private:
        int cant;
        bool enviado;

        // Pseudoatributo
        Producto* producto;

    public:
        // Constructor
        CompraProducto(Producto* prod,int cant);

        // Getters
        int getCant();
        bool getEnvio();

        // Operaciones
        void enviar(); 
        DataProductoCompra getDataProductoCompra();
        int getCodeProd();

        // Destructor
        ~CompraProducto();
};

#endif