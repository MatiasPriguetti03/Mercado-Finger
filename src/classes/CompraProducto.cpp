// Clase.h
#include "../../include/classes/CompraProducto.h"

// Constructor
CompraProducto::CompraProducto(Producto* prod, int cant)
    : cant(cant), enviado(false) {
        this->producto = prod;
};

// Getters
int CompraProducto::getCant() {
    return this->cant;
};

bool CompraProducto::getEnvio(){
    return this->enviado;
};

DataProductoCompra CompraProducto::getDataProductoCompra(){
    return DataProductoCompra(this->producto->getCode(), this->producto->getNombre(), this->producto->getPrecio(), this->cant);
};

// Operaciones
void CompraProducto::enviar(){
    this->enviado = true;
};

int CompraProducto::getCodeProd(){
    return this-> producto-> getCode();
}

// Destructor
CompraProducto::~CompraProducto(){};