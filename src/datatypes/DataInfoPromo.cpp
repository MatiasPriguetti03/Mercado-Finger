// datatypes
#include "../../include/datatypes/DataInfoPromo.h"

// Constructor
DataInfoPromo::DataInfoPromo(string nombre, string descripcion, int descuento, DataFecha fechaVencimiento,vector<DataInfoProducto> productos)
    :nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVenc(fechaVencimiento), productos(productos){}


//Getters 

string DataInfoPromo:: getNombre(){
    return this->nombre;
};

string DataInfoPromo :: getDescripcion(){
    return this->descripcion;
};

int DataInfoPromo :: getDescuento(){
    return this->descuento;
};

DataFecha DataInfoPromo :: getDataFecha(){
    return this->fechaVenc;
};

vector<DataInfoProducto> DataInfoPromo :: obtenerDataInfoProducto(){
    return this->productos;
};

void DataInfoPromo :: agregarDataInfoProducto(DataInfoProducto dp){
    this->productos.push_back(DataInfoProducto(dp));
};

string DataInfoPromo :: toString(){
    return "    - Nombre: " + this->nombre + "\n" +
           "    - Descripcion: " + this->descripcion + "\n" +
           "    - Descuento: " + to_string(this->descuento) +  "%\n" +
           "    - Fecha de Vencimiento: " + this->fechaVenc.toString() + "\n";
}

// Destrcutor
DataInfoPromo::~DataInfoPromo(){
};