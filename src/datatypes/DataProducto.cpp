// Datatypes.h
#include "../../include/datatypes/DataProducto.h"

// Constructor
DataProducto::DataProducto(int codeProd, string nombreProd) 
    : codeProd(codeProd), nombreProd(nombreProd){}

// Getters
int DataProducto::getCode() {
    return this->codeProd;
};

string DataProducto::getNombre(){
    return this->nombreProd;
};

//Operaciones
string DataProducto::toString(){
return  "    - Codigo: " + to_string(this->codeProd) + "\n" + 
        "    - Nombre: " + this->nombreProd + "\n";
};

// Destructor
DataProducto::~DataProducto(){}
