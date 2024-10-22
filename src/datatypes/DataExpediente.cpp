#include "../../include/datatypes/DataExpediente.h"

/*******************************************************************************/

// Contructor
DataExpedienteCliente::DataExpedienteCliente(string nickname, DataFecha fechaNac, string calle, int nroPuerta, string ciudad, vector<DataCompra> compras) 
    : DataCliente(nickname, fechaNac, calle, nroPuerta, ciudad), compras(compras) {}

// Operaciones
string DataExpedienteCliente::toString() {
    string texto = string("************* EXPEDIENTE USUARIO *************") + "\n";
    texto += DataCliente::toString();
    texto += "\n";
    texto += string("<<<<<<<<<< Compras >>>>>>>>>>") + "\n";

    for (DataCompra& compra : this->compras) {
        texto += string("----- Compra -----") + "\n";
        texto += compra.toString();
        texto += "\n";
    }
    return texto;
}

// Destructor
DataExpedienteCliente::~DataExpedienteCliente() {}

/*******************************************************************************/

// Contructor
DataExpedienteVendedor::DataExpedienteVendedor(string nickname, DataFecha fechaNac, string rut, vector<DataInfoProducto> productos, vector<DataPromocion> promociones)
    : DataVendedor(nickname, fechaNac, rut), productos(productos), promociones(promociones) {}

// Operaciones
string DataExpedienteVendedor::toString() {
    string texto = string("************* EXPEDIENTE USUARIO *************") + "\n";
    texto += DataVendedor::toString();
    texto += "\n";
    
    texto += string("<<<<<<<<<< Productos >>>>>>>>>>") + "\n";
    for (DataInfoProducto& producto : this->productos) {
        texto += producto.toString();
        texto += "\n";
    }
    
    texto += string("<<<<<<<<<< Promociones >>>>>>>>>>") + "\n";
    for (DataPromocion& promocion : this->promociones) {
        texto += string("----- Promocion -----") + "\n";
        texto += promocion.toString();
        texto += "\n";
    }
    return texto;
 }

// Destructor
DataExpedienteVendedor::~DataExpedienteVendedor() {}
