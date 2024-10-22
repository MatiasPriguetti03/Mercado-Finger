// Clase.h
#include "../../include/classes/Producto.h"

// Constructor
Producto::Producto(int code, int stock, float precio, string nombre, string descripcion, CategoriaProducto categoria) : 
    code(code), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {}

//Getters
int Producto::getCode() {
    return this->code;
}

string Producto::getNombre() {
    return this->nombre;
}

int Producto::getStock(){
    return this->stock;
}

float Producto::getPrecio(){
    return this->precio;
}

string Producto::getDescripcion(){
    return this->descripcion;
}

CategoriaProducto Producto::getCategoria(){
    return this->categoria;
}

map<int, Comentario *> Producto::getComentarios() {
    return this->comentarios;
};

Comentario* Producto::getComentario(int id){
    return this->comentarios.find(id)->second;
}

DataProducto Producto::getDataProducto(){
    return DataProducto(this->code, this->nombre); 
}

DataInfoProducto Producto::getInfoProducto(){
    return DataInfoProducto(this->code, this->nombre, this->descripcion, this->precio, this->stock, this->categoria); 
}

// Operaciones
void Producto::modificarStock(int cant){
    this->stock -= cant;
}

void Producto::crearRelacionComentario(Comentario* comentario){
    int id = comentario->getId();
    
    this->comentarios.insert(make_pair(id, comentario));
}

void Producto::eliminarRelacionComentario(int id){
    this->comentarios.erase(id);
}

// Destructor
Producto::~Producto(){}