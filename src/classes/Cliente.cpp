// Clase.h
#include "../../include/classes/Cliente.h"

// Contructor
Cliente::Cliente(string nickname, string contrasenia, DataFecha fecha, string calle, int nroPuerta, string ciudad) 
    : Usuario(nickname, contrasenia, fecha), calle(calle), nroPuerta(nroPuerta), ciudad(ciudad) {}

DataUsuario* Cliente::getDataInfoUsuario() {
    return new DataCliente(this->getNickname(), this->getFechaNacimiento(), this->calle, this->nroPuerta, this->ciudad);
};

// Operaciones

void Cliente::agregarCompra(Compra* compra){
    this->compras.push_back(compra);
}

DataUsuario* Cliente::getExpediente() {
    vector<DataCompra> compras;
    for (Compra* compra : this->compras) {
        compras.push_back(compra->getDataCompra(this->getNickname()));
    };
    return new DataExpedienteCliente(this->getNickname(), this->getFechaNacimiento(), this->calle, this->nroPuerta, this->ciudad, compras);
};

void Cliente::agregarNotificacion(DataPromocion* notificacion) {
    this->notificaciones.push_back(notificacion);
}

vector<DataPromocion*> Cliente::listarNotificaciones(){
    vector<DataPromocion*> listaNotificaciones = this->notificaciones;
    this->notificaciones.clear();
    return listaNotificaciones;
}

vector<DataClienteCompra> Cliente::getVectorClienteCompras(int codeProd){
    vector<DataClienteCompra> vc = vector<DataClienteCompra>();
    for(Compra* compra: this-> compras){
        CompraProducto* cp = compra-> getCompraProducto(codeProd);
        if (cp != NULL){
            bool enviado = cp-> getEnvio();
            if (!enviado){
                DataClienteCompra dcc = DataClienteCompra(this-> getNickname(), compra);
                vc.push_back(dcc);
            }
        }
    }
    return vc;
}

// Destructor
Cliente::~Cliente(){}