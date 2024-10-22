#ifndef DATAPROMOPRODUCTO
#define DATAPROMOPRODUCTO

// Tipos
#include <string>

using namespace std;

class DataPromoProducto {
    private:
        int codeProd;
        string nombreProd;
        int cant;

    public:
        // Constructor
        DataPromoProducto(int codeProd, string nombreProd, int cant);

        // Getters
        int getCode();
        int getCant();

        // Operaciones
        string toString();

        // Destructor
        ~DataPromoProducto();
};

#endif