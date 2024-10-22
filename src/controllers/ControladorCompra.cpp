#include "../../include/controllers/ControladorCompra.h"
#include "../../include/controllers/ControladorProducto.h"
#include "../../include/controllers/ControladorPromocion.h"

#include "../../include/classes/Compra.h"
#include "../../include/classes/Cliente.h"



#include "../../include/system/Operaciones.h"

ControladorCompra::ControladorCompra() {};

void ControladorCompra::seleccionarCliente(string nickname){
// La funcion recibe el nickname de un cliente y guarda en memoria una DataCompra con el nickname del vendedor,
// la fecha del sistema, monto total = 0, y coleccion de productos vacia

    FechaSistema* fechaSistema = FechaSistema::getInstance();
    this-> compraActual = new DataCompra(nickname, fechaSistema->getFecha(), 0, vector<DataProductoCompra>());
}

void ControladorCompra::agregarProductoCompra(int codeProd, int cant){
// La funcion agrega un producto e indica su cantidad para el DataCompra guardado en memoria

    ControladorProducto* cProd = ControladorProducto::getInstance();
    DataProductoCompra dpc = cProd->obtenerDataProductoCompra(codeProd, cant);
    this-> compraActual-> agregarDataProductoCompra(dpc);
    this-> compraActual-> setTotalCompra(this-> compraActual-> getTotalCompra() + dpc.getPrecio()*cant);
}

DataCompra* ControladorCompra::mostrarCompra(){
// La funciona aplica todas las promociones que aplican para la compra y setea el total para el DataCompra guardado en memoria
    
    ControladorPromocion* cProm = ControladorPromocion::getInstance();
    
    float totalMontoDesc = cProm-> aplicarPromociones(this-> compraActual-> getProductos());
    
    this-> compraActual-> setTotalCompra(this-> compraActual-> getTotalCompra() - totalMontoDesc);
    return this-> compraActual;
}


void ControladorCompra::confirmarCompra(){
// La funcion obtiene el cliente usando el nickname almacenado en la compra actual,
// y agrega la nueva compra a la lista de compras del cliente. Posteriormente, recorre los productos
// de la compra actual, los agrega a la compra recién creada y actualiza el stock de cada producto.
// Finalmente libera la memoria

    Compra* compra = new Compra(this-> compraActual-> getFecha(), this-> compraActual-> getTotalCompra());
    ControladorUsuario* cUser = ControladorUsuario::getInstance();
    Cliente* cliente =  dynamic_cast<Cliente*>(cUser->obtenerUsuario(this->compraActual-> getNickname()));
    cliente-> agregarCompra(compra);
    ControladorProducto* cProd = ControladorProducto::getInstance();
    for (DataProductoCompra p : this-> compraActual-> getProductos()){
        Producto* prod = cProd-> obtenerProducto(p.getCode());
        compra-> agregarProducto(prod, p.getCant());
        prod->modificarStock(p.getCant());
    }
    this-> compraActual = NULL;
}