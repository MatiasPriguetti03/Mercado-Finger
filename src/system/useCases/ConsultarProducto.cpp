// System.h
#include "../../../include/system/Sistema.h"

void Sistema::consultarProducto(){

    Fabrica* fabrica = Fabrica::getInstancia();
    IProducto*  iProducto = fabrica->getIProducto();

    print("--------------------- Consultar Producto ---------------------");
    saltoConsola();
    print("Listado de los productos del sistema.");
    saltoConsola();

    for(DataProducto dp : iProducto->listarProductos()){
        print(dp.toString());
        saltoConsola();
    };

    print("Seleccion el producto del cual desea saber mas informacion.");
    int code = getInputInt("    Ingresar codigo: ");
    saltoConsola();

    print(iProducto->mostrarProducto(code).toString());
    
    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
}