// Datatype.h
#include "../../include/datatypes/DataProductoCompra.h"

// Constructor
DataProductoCompra::DataProductoCompra(int codeProd, string nombreProd, float precio, int cant) 
    : codeProd(codeProd), nombreProd(nombreProd), precio(precio), cant(cant) {}

// Getters
int DataProductoCompra::getCode() {
    return this->codeProd;
}

int DataProductoCompra::getCant() {
    return this->cant;
}

string DataProductoCompra :: getNombreProd(){
    return this->nombreProd;
}

float DataProductoCompra::getPrecio() {
    return this->precio;
}

string DataProductoCompra :: toString(){
    return "    - Nombre: " + this->getNombreProd() + "\n" +
           "    - Codigo: " + to_string(this->getCode()) + "\n" +
           "    - Precio: $" + to_string(this->getPrecio()) + "\n" + 
           "    - Cantidad: " + to_string(this->getCant()) + "\n";

}   

// Destructor 
DataProductoCompra::~DataProductoCompra(){}