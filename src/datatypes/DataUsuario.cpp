
// Datatypes.h
#include "../../include/datatypes/DataUsuario.h"

// Constructor
DataUsuario::DataUsuario(string nickname, DataFecha fechaNac) 
    : nickname(nickname), fechaNac(fechaNac){};

// Operaciones
string DataUsuario::getNickname() {
    return this->nickname;
};

DataFecha DataUsuario::getFechaNac() {
    return this->fechaNac;
};


string DataUsuario::toString() {
    return "";
};

// Destructor
DataUsuario::~DataUsuario() {};

/*******************************************************************************/

// Constructor
DataCliente::DataCliente(string nickname, DataFecha fechaNac, string calle, int nroPuerta, string ciudad)
    : DataUsuario(nickname, fechaNac), calle(calle), nroPuerta(nroPuerta), ciudad(ciudad)  {};

// Operaciones
string DataCliente::toString() {
    return  string("----- Cliente -----") + "\n" + 
            "    - Nickname: " + this->getNickname() + "\n" + 
            "    - Fecha de nacimiento: " + this->getFechaNac().toString() + "\n" +
            "    - Calle: " + this->calle + "\n" + 
            "    - Nro de puerta: " + to_string(this->nroPuerta) + "\n" +
            "    - Ciudad: " + this->ciudad + "\n";
};

// Destructor
DataCliente::~DataCliente() {};


/*******************************************************************************/

// Constructor
DataVendedor::DataVendedor(string nickname, DataFecha fechaNac, string rut) 
    : DataUsuario(nickname, fechaNac), rut(rut)  {};

// Operaciones
string DataVendedor::toString() {
    return  string("----- Vendedor -----") + "\n" +
            "    - Nickname: " + this->getNickname() + "\n" + 
            "    - Fecha de nacimiento: " + this->getFechaNac().toString() + "\n" +
            "    - RUT: " + this->rut + "\n";
};

// Destructor
DataVendedor::~DataVendedor() {};


