// datatypes
#include "../../include/datatypes/DataPromocion.h"

// Constructor
DataPromocion::DataPromocion(string nickname, string nombre, string descripcion, int descuento, DataFecha fechaVencimiento, vector<DataPromoProducto> productos)
    : nickname(nickname), nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVenc(fechaVencimiento), productos(productos) {}

void DataPromocion :: agregarDataProducto(DataPromoProducto producto){
    this->productos.push_back(DataPromoProducto(producto));
}
//Getters 
string  DataPromocion :: getNickname(){
    return this->nickname;
}
string DataPromocion :: getNombre(){
    return this->nombre;
}
string DataPromocion :: getDescripcion(){
    return this->descripcion;
}
int DataPromocion :: getDescuento(){
    return this->descuento;
}
DataFecha DataPromocion :: getDataFecha(){
    return this->fechaVenc;
}
vector<DataPromoProducto> DataPromocion :: getDataPromoProductos(){ 
    return this->productos;
}

void DataPromocion :: setNickname(string n){
    this->nickname = n;
};

string DataPromocion :: toString(){
    string texto = "    - Vendedor: " + nickname + "\n" +
                   "    - Nombre: " + nombre + "\n" +
                   "    - Descripcion: " + descripcion + "\n" + 
                   "    - Descuento: " + to_string(descuento) + "\n" +
                   "    - Fecha de Vencimiento: " + fechaVenc.toString() + "\n";
    texto += string("----- Productos -----") + "\n";
    for (DataPromoProducto producto : this->productos) {
        texto += producto.toString();
    }
    return texto;
} 

string DataPromocion :: toString2(){
    string texto = "  - Vendedor: " + nickname + "\n" ;

    texto += string("----- Productos -----") + "\n";
        for (DataPromoProducto producto : this->productos) {
        texto += producto.toString();
    }
    return texto;
}


// Destrcutor
DataPromocion::~DataPromocion(){}