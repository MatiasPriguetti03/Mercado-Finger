// Tipos
#include <string>

// Datatypes
#include "../datatypes/DataFecha.h"

using namespace std;

/*******************************************************************************/

#ifndef DATAUSUARIO
#define DATAUSUARIO
class DataUsuario {
    private:
        string nickname;
        DataFecha fechaNac;

    public:
        // Constructor
        DataUsuario(string nickname, DataFecha fechaNac);

        // Getters
        virtual string getNickname();
        virtual DataFecha getFechaNac();

        // Operaciones
        virtual string toString();

        // Destructor
        virtual ~DataUsuario();
};

#endif

/*******************************************************************************/

#ifndef DATACLIENTE
#define DATACLIENTE

class DataCliente : public DataUsuario{
    private:
        string calle;
        int nroPuerta;
        string ciudad;

    public:
        // Constructor
        DataCliente(string nickname, DataFecha fechaNac, string calle, int nroPuerta, string ciudad);

        // Operaciones
        string toString() override; 

        // Destructor
        ~DataCliente();
};

#endif

/*******************************************************************************/

#ifndef DATAVENDEDOR
#define DATAVENDEDOR

class DataVendedor : public DataUsuario {
    private:
        string rut;

    public:
        // Constructor
        DataVendedor(string nickname, DataFecha fechaNac, string rut);

        // Operaciones
        string toString() override; 

        // Destructor
        ~DataVendedor();
};

#endif