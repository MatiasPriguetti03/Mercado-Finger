#ifndef DATAPRODUCTOCOMPRA
#define DATAPRODUCTOCOMPRA

// Tipos
#include <string>

using namespace std;

class DataProductoCompra {
    private:
        int codeProd;
        string nombreProd;
        float precio;
        int cant;

    public:
        // Constructor
        DataProductoCompra(int codeProd, string nombreProd, float precio, int cant);

        // Getters
        int getCode();
        float getPrecio();   
        int getCant(); 
        string getNombreProd();

        // Operaciones
        string toString();

        // Destructor
        ~DataProductoCompra();    
};

#endif