// Datatypes.h
#include "../../include/datatypes/DataEnvio.h"

// Constructor
DataEnvio::DataEnvio(string nickC, DataFecha fechaCompra)
: nicknameCliente(nickC), fechaCompra(fechaCompra) {}

// Getters
string DataEnvio::getNicknameCliente() {
    return this-> nicknameCliente;
};

DataFecha DataEnvio::getFechaCompra(){
    return this-> fechaCompra;
};

//Operaciones
string DataEnvio::toString(){
return  "    - Nickname Cliente: " + (this-> nicknameCliente) + "\n" + 
        "    - Fecha de la Compra: " + this-> fechaCompra.toString() + "\n";
};

// Destructor
DataEnvio::~DataEnvio(){}