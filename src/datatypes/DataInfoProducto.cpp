#include "../../include/datatypes/DataInfoProducto.h"

#include <iostream>
// Constructor
DataInfoProducto::DataInfoProducto(){}
DataInfoProducto::DataInfoProducto(int codeProd, string nombre, string descripcion, float precio, int stock, CategoriaProducto categoria){
    this-> codeProd = codeProd;
    this-> nombre = nombre;
    this-> descripcion = descripcion;
    this-> precio = precio;
    this-> stock = stock;
    this-> categoria = categoria;
}
int DataInfoProducto :: getCodeProd(){
    return this->codeProd;
};
string  DataInfoProducto :: getNombre(){
    return this->nombre;
};
string DataInfoProducto :: getDescripcion(){
    return this->descripcion;
};
int DataInfoProducto :: getPrecio(){
    return this->precio;
};
CategoriaProducto DataInfoProducto :: getCategoria(){
    return this->categoria;
};

string DataInfoProducto::toString(){
    string strCat;
    int cat = this-> categoria;
    if (cat == 0){
        strCat = "Ropa";
    }else if (cat == 1){
        strCat = "Electrodomestico";
    }else{
        strCat = "Otros";
    }
    stringstream ss;
    ss << "Codigo: " << this-> codeProd << "\nNombre: " << this-> nombre << "\nDescripcion: " << this-> descripcion
    << "\nPrecio: " << this-> precio << "\nCategoria: " << strCat;
    return ss.str();
}

// Destructor
DataInfoProducto::~DataInfoProducto() {}