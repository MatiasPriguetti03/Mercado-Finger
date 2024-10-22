// Clase.h
#include "../../include/classes/Promocion.h"

// Constructor
Promocion::Promocion(string nickname, string nombre, string descripcion, int descuento, DataFecha fechaVencimiento) 
    : nickname(nickname), nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVencimiento(fechaVencimiento), promoProductos() {}


// Getters
int Promocion :: getDescuento(){
    return this->descuento;
}
string Promocion :: getNombre(){
    return this->nombre;
}

DataPromocion Promocion::getDataPromocion() {
    vector<DataPromoProducto> productos;
    for (const auto& promoProd : this->promoProductos) {
        int codeProd = promoProd->getProducto()->getCode();
        string nombre = promoProd->getProducto()->getNombre();
        int cantMin = promoProd->getCantMin();
        
        productos.push_back(DataPromoProducto(codeProd, nombre, cantMin));
    }

    DataPromocion dataPromo(this->nickname, this->nombre, this->descripcion, this->descuento, this->fechaVencimiento, productos);
    return dataPromo;
}

DataInfoProducto Promocion :: obtenerDataInfoProducto(){
    DataInfoProducto NOIMPLEMENTADO(1,"","",1,1,otros);
    return NOIMPLEMENTADO;
}

DataInfoPromo Promocion :: getDataInfoPromo(){
    vector<DataInfoProducto> productos;
    for (const auto& promoProd : this->promoProductos) {
        int codeProd = promoProd->getProducto()->getCode();
        string nombre = promoProd->getProducto()->getNombre();
        string descripcion = promoProd->getProducto()->getDescripcion();
        int precio = promoProd->getProducto()->getPrecio();
        int stock = promoProd->getProducto()->getStock();
        CategoriaProducto categoria = promoProd->getProducto()->getCategoria(); 
        productos.push_back(DataInfoProducto(codeProd, nombre, descripcion, precio, stock,  categoria));
    }

    DataInfoPromo dataInfoPromo(this->nombre, this->descripcion, this->descuento, this->fechaVencimiento, productos);
    return dataInfoPromo;
}

// Operaciones
bool Promocion::estaVigente(DataFecha fechaActual) {
    return fechaActual < this->fechaVencimiento;
}

float Promocion::aplicarPromocion(vector<DataProductoCompra> productosEnCompra) {
    float total = 0.0f;
    int descuento = this->getDescuento();
    int cantProductosPromo = 0;
    int cantProductosAplicanPromo = 0;

    for (PromoProducto* promoProd : this->promoProductos) {
        int cantidadMinima = promoProd->getCantMin();
        Producto* producto = promoProd->getProducto();
        int codeProductoEnPromo = producto->getCode();
        cantProductosPromo = cantProductosPromo + 1;
        
        for (DataProductoCompra productoCompra : productosEnCompra) {
            int codeProductoCompra = productoCompra.getCode();
            int cantidadComprada = productoCompra.getCant();

            if ((codeProductoCompra == codeProductoEnPromo) && (cantidadComprada >= cantidadMinima)) {
                cantProductosAplicanPromo = cantProductosAplicanPromo + 1;
                total += ((productoCompra.getPrecio() * descuento / 100) * cantidadComprada);
            }
        }
    }

    if (cantProductosPromo == cantProductosAplicanPromo) {
        return total;
    } else {
        return 0;
    }
}


void Promocion :: agregarProducto(Producto* prod, int cant) {
    PromoProducto* promo_prod = new PromoProducto(prod, cant);
    this->promoProductos.push_back(promo_prod);
}

// Destructor
Promocion::~Promocion() {}