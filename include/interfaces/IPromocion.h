#ifndef IPROMOCION
#define IPROMOCION

#include <vector>
#include <string>

#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataProducto.h"
#include "../datatypes/DataCompra.h"
#include "../datatypes/DataInfoPromo.h"
#include "../datatypes/DataInfoProducto.h"
#include "../datatypes/DataPromoProducto.h"

using namespace std;


class IPromocion {
    public:
        //Operaciones de Sistema
        virtual void ingresarPromocion(string nombre, string descripcion, int descuento, DataFecha fechaVencimiento) = 0;
        virtual void seleccionarVendedor(string nickname) = 0;
        virtual vector<DataProducto> mostrarProductos() = 0;
        virtual void agregarProducto(int codeProd, int cant) = 0;
        virtual float aplicarPromociones(vector<DataProductoCompra> compra) = 0;
        virtual void darAltaPromocion() = 0;
        virtual vector<DataInfoPromo> listarPromociones() = 0;
        virtual DataPromocion seleccionarYConsultarPromocion(string nombre) = 0;
};

#endif