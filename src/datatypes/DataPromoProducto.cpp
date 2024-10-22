// Datatypes
#include "../../include/datatypes/DataPromoProducto.h"

// Contructor
DataPromoProducto::DataPromoProducto(int codeProd, string nombreProd, int cant) 
    : codeProd(codeProd), nombreProd(nombreProd), cant(cant) {};

// Getters
int DataPromoProducto::getCode() {
    return this->codeProd;
}

int DataPromoProducto::getCant() {
    return this->cant;
}

string DataPromoProducto::toString() {
    return  "    - Codigo: " + to_string(codeProd) + "\n" + 
            "    - Nombre: " + nombreProd + "\n" +
            "    - Cantidad: " + to_string(cant) + "\n";
};

// Destructor 
DataPromoProducto::~DataPromoProducto(){}