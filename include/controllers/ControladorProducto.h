#ifndef CONTROLADORPRODUCTO
#define CONTROLADORPRODUCTO

// Tipos
#include <string>
#include <map>
#include <vector>

// Clases
#include "../classes/Producto.h"
#include "../classes/Vendedor.h"

// Interfaces
#include "../interfaces/IProducto.h"

// Datatypes
#include "../datatypes/DataProducto.h"
#include "../datatypes/DataPromoProducto.h"
#include "../datatypes/DataProductoCompra.h"
#include "../datatypes/DataInfoProducto.h"

// Controladores
#include "ControladorUsuario.h"

using namespace std;

class ControladorProducto : public IProducto {
    private:
        // Pseudoatributo
        map<int, Producto*> productos;

        // Clave Primaria
        int clavePrimaria;

        // Memoria
        string* nicknameVendedor;
        DataInfoProducto dataInfoProducto;

        // Singelton
        static ControladorProducto* instancia;

        // Constructor
        ControladorProducto();

        // Destructor
        ~ControladorProducto();

    public:
        // Singelton
        static ControladorProducto* getInstance();

        // Crear
        void crearProducto(string nombre, float precio, int stock, string descripcion, CategoriaProducto categoria);

        // Seleccionar
        void seleccionarVendedor(string nickname);

        // Obtener
        Producto* obtenerProducto(int codeProd);
        DataProducto obtenerDataProducto(int codeProd);
        DataPromoProducto obtenerDataPromoProducto(int codeProd, int cant);
        DataProductoCompra obtenerDataProductoCompra(int codeProd, int cant);
        DataInfoProducto obtenerDataInfoProducto();

        // Mostrar
        DataInfoProducto mostrarProducto(int codeProd);

        // Listar
        vector<DataProducto> listarProductos();
};

#endif