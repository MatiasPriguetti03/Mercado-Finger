#ifndef DATAENVIO
#define DATAENVIO

// Tipos
#include <string>

//Datatypes
#include "./DataFecha.h"

using namespace std;

class DataEnvio {
    private:
        string nicknameCliente;
        DataFecha fechaCompra;

    public:
        // Constructor
        DataEnvio(string nickC, DataFecha fechaCompra);

        // Getters
        string getNicknameCliente();
        DataFecha getFechaCompra();

        //Operaciones
        string toString();

        // Destructor
        ~DataEnvio();
};

#endif