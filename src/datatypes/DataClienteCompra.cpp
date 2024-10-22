// Datatypes.h
#include "../../include/datatypes/DataClienteCompra.h"

// Constructor
DataClienteCompra::DataClienteCompra(){}
DataClienteCompra::DataClienteCompra(string nick, Compra* compra){
    this-> nickname = nick;
    this-> compra = compra;
}

//Getters
string DataClienteCompra::getNickname(){
    return this-> nickname;
}

Compra* DataClienteCompra::getCompra(){
    return this-> compra;
}

// Destructor
DataClienteCompra::~DataClienteCompra(){}