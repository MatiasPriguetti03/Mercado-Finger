#ifndef PRODUCTO
#define PRODUCTO

// Tipos
#include <string>
#include <map>

// Clases
#include "Promocion.h"
#include "Comentario.h"

// Datatypes
#include "../datatypes/DataProducto.h"
#include "../datatypes/DataInfoProducto.h"
#include "../datatypes/CategoriaProducto.h"

class Comentario;

class Producto {
    private:
        int code;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        CategoriaProducto categoria;
    
        //Pseudoatributos
        map<int, Comentario*> comentarios;

    public:
        Producto(int code, int stock, float precio, string nombre, string descripcion, CategoriaProducto categoria);

        // Getters
        int getCode();
        int getStock();
        float getPrecio();
        string getNombre();
        string getDescripcion();
        CategoriaProducto getCategoria();
        map<int, Comentario *> getComentarios();
        Comentario* getComentario(int id);


        //Operaciones
        DataProducto getDataProducto();
        DataInfoProducto getInfoProducto();
        void modificarStock(int cant);
        void crearRelacionComentario(Comentario* comentario);
        void eliminarRelacionComentario(int id);

        ~Producto();
};

#endif