// Clase.h
#include "../../include/classes/PromoProducto.h"

// Contructor
PromoProducto::PromoProducto(Producto* prod, int cant)
    : cantMin(cant), producto(prod) {}

// Getters
int PromoProducto::getCantMin(){
    return this-> cantMin;
}

Producto* PromoProducto::getProducto() {
    return this-> producto;
}

// Destructores
PromoProducto::~PromoProducto(){}