// Datatypes.h
#include "../../include/datatypes/DataCompra.h"

// Constructor
DataCompra::DataCompra(string nick, DataFecha fecha, int totalCompra, vector<DataProductoCompra> productos) 
    : nickname(nick), fecha(fecha), totalCompra(totalCompra),  productos(productos) {}

//Getters
string DataCompra::getNickname(){
    return this-> nickname;
}

DataFecha DataCompra::getFecha(){
    return this-> fecha;
}

float DataCompra::getTotalCompra(){
    return this-> totalCompra;
}

vector<DataProductoCompra> DataCompra::getProductos(){
    return this-> productos;
}

//Setters
void DataCompra::setTotalCompra(float total){
    this-> totalCompra = total;
}

//Operaciones
void DataCompra::agregarDataProductoCompra(DataProductoCompra dpc){
    this-> productos.push_back(dpc);
}

//toString
string DataCompra :: toString(){
    string texto = "    - Usuario: " + this->getNickname() + "\n" + 
                   "    - Fecha: " + this->fecha.toString() + "\n" +
                   "    - Monto final: $" + to_string(this->totalCompra) + "\n";
    texto += "\n";
    texto += "+ Productos:\n";
    for (DataProductoCompra producto : this->productos) {
        texto += producto.toString();
        texto += "\n";
    }
    return  texto;
};

// Destructor
DataCompra::~DataCompra(){}
