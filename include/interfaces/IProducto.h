#ifndef IPRODUCTO
#define IPRODUCTO

#include "../datatypes/CategoriaProducto.h"
#include "../datatypes/DataInfoProducto.h"
#include "../datatypes/DataProducto.h"
#include "../classes/Producto.h"

#include <vector>
#include <string>

using namespace std;

class IProducto {
    public:
        // Crear
        virtual void crearProducto(string nombre, float precio, int stock, string descripcion, CategoriaProducto categoria) = 0;

        // Seleccionar
        virtual void seleccionarVendedor(string nickname) = 0;

        // Mostrar
        virtual DataInfoProducto mostrarProducto(int codeProd) = 0;

        // Obtener
        virtual Producto* obtenerProducto(int codeProd) = 0;

        // Listar
        virtual vector<DataProducto> listarProductos() = 0;
        
        virtual DataInfoProducto obtenerDataInfoProducto() = 0;
};

#endif