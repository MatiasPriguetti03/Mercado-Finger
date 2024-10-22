#ifndef DATAPRODUCTO
#define DATAPRODUCTO

// Tipos
#include <string>
#include <sstream>

using namespace std;

class DataProducto {
    private:
        int codeProd;
        string nombreProd;

    public:
        // Constructor
        DataProducto(int codeProd, string nombreProd);

        // Getters
        int getCode();
        string getNombre();

        //Operaciones
        string toString();

        // Destructor
        ~DataProducto();
};

#endif