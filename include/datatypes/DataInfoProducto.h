#ifndef DATAINFOPRODUCTO
#define DATAINFOPRODUCTO

// Tipos
#include <string>
#include <sstream>

// Datatypes
#include "../datatypes/CategoriaProducto.h"

using namespace std;

class DataInfoProducto {
    private:
        int codeProd;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        CategoriaProducto categoria;

    public:
        // Constructor
        DataInfoProducto();
        DataInfoProducto(int codeProd, string nombre, string descripcion, float precio, int stock, CategoriaProducto categoria);

        // Getters
        int getCodeProd();
        string getNombre();
        string getDescripcion();
        int getPrecio();
        CategoriaProducto getCategoria();

        // Operaciones
        string toString();

        // Destructor
        ~DataInfoProducto();
};

#endif