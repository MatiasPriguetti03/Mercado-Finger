#ifndef DATACOMPRA
#define DATACOMPRA

// Tipos
#include <vector>
#include <string>
#include <iostream>

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataProductoCompra.h"

using namespace std;

class DataCompra{
    private:
        string nickname;
        DataFecha fecha;
        float totalCompra;
        vector<DataProductoCompra> productos;

    public:
        // Contructor
        DataCompra();
        DataCompra(string nick, DataFecha fecha, int totalCompra, vector<DataProductoCompra> productos);

        //Getters
        string getNickname();
        DataFecha getFecha();
        float getTotalCompra();
        vector<DataProductoCompra> getProductos();

        //Setters
        void setTotalCompra(float total);

        //Operaciones
        void agregarDataProductoCompra(DataProductoCompra dpc);
        string toString();

        // Destructor
        ~DataCompra();
};

#endif