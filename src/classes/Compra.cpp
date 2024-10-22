// Clase.h
#include "../../include/classes/Compra.h"

// Constructor
Compra::Compra(DataFecha fecha, float montoFinal) 
    : fecha(fecha), montoFinal(montoFinal) {};

// Getters
DataFecha Compra::getFecha(){
    return this-> fecha;
}

CompraProducto* Compra::getCompraProducto(int codeProd){
    CompraProducto* res = NULL;
    for (CompraProducto* cp: this-> productos){
        if (cp-> getCodeProd() == codeProd){
            res = cp;
        }
    }
    return res;
}

DataCompra Compra::getDataCompra(string nickname){
    vector<DataProductoCompra> productos;
    for (const auto& compraProd : this->productos){
        productos.push_back(DataProductoCompra(compraProd->getDataProductoCompra()));
    }
    return DataCompra(nickname, this->fecha, this->montoFinal, productos);
}

// Operaciones
void Compra::agregarProducto(Producto* prod, int cant){
    this->productos.push_back(new CompraProducto(prod, cant));
};

// Destructor
Compra::~Compra(){
    for (const auto& compraProd : this->productos){
        delete compraProd;
    }
};