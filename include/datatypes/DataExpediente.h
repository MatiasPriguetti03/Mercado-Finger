// Tipos
#include <string>
#include <vector>

// Datatype
#include "DataUsuario.h"
#include "DataInfoProducto.h"
#include "DataPromocion.h"
#include "DataCompra.h"

/*******************************************************************************/

#ifndef DATAEXPEDIENTECLIENTE
#define DATAEXPEDIENTECLIENTE

class DataExpedienteCliente : public DataCliente {
    private:
        // Pseudoatributos
        vector<DataCompra> compras;

    public:
        // Contructor
        DataExpedienteCliente(string nickname, DataFecha fechaNac, string calle, int nroPuerta, string ciudad, vector<DataCompra> compras);

        // Operaciones
        string toString() override;

        // Destructor
        ~DataExpedienteCliente();
};

#endif

/*******************************************************************************/

#ifndef DATAEXPEDIENTEVENDEDOR
#define DATAEXPEDIENTEVENDEDOR

class DataExpedienteVendedor : public DataVendedor {
    private:
        // Pseudoatributos
        vector<DataInfoProducto> productos;
        vector<DataPromocion> promociones;

    public:
        // Contructor
        DataExpedienteVendedor(string nickname, DataFecha fechaNac, string rut, vector<DataInfoProducto> productos, vector<DataPromocion> promociones);

        // Operaciones
        string toString() override;

        // Destructor
        ~DataExpedienteVendedor();
};

#endif