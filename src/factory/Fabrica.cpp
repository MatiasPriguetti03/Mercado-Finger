#include "../../include/factory/Fabrica.h"


Fabrica* Fabrica::instancia = nullptr;

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IComentario* Fabrica::getIComentario() {
    ControladorComentario* controlador = new ControladorComentario();
    return controlador;
}

ICompra* Fabrica::getICompra() {
    ControladorCompra* controlador = new ControladorCompra();
    return controlador;
}


IProducto* Fabrica::getIProducto() {
    return ControladorProducto::getInstance();
}

IPromocion* Fabrica::getIPromocion() {
    return ControladorPromocion::getInstance();
}

IUsuario* Fabrica::getIUsuario() {
    return ControladorUsuario::getInstance();
}
