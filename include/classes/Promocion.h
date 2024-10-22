#ifndef PROMOCION
#define PROMOCION

// Tipos
#include <string>
#include <vector>
#include <vector>

// Clases
#include "Producto.h"
#include "PromoProducto.h"

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataCompra.h"
#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataProductoCompra.h"
#include "../datatypes/DataInfoPromo.h"

using namespace std;

class PromoProducto;

class Promocion {
    private:
        string nickname;
        string nombre;
        string descripcion;
        int descuento;
        DataFecha fechaVencimiento;

        //Pseudoatributos
        vector<PromoProducto*> promoProductos;

    public:
        Promocion(string nickname, string nombre, string descripcion, int descuento, DataFecha fechaVencimiento);

        // Getters
        int getDescuento();
        DataPromocion getDataPromocion();
        string getNombre();
        DataInfoPromo getDataInfoPromo();

        // Operaciones
        bool estaVigente(DataFecha fechaActual);
        float aplicarPromocion(vector<DataProductoCompra> productosEnCompra);
        void agregarProducto(Producto* prod, int cant);
        DataInfoProducto obtenerDataInfoProducto();

        ~Promocion();
};

#endif