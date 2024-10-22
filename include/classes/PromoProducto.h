#ifndef PROMOPRODUCTO
#define PROMOPRODUCTO

//Forward Declaration
class Producto;

// Clases
#include "Producto.h"

using namespace std;

class PromoProducto {
    private:
        int cantMin;

        // Pseudoatributo
        Producto* producto;
    
    public:
        PromoProducto(Producto* prod, int cant);

        // Getters
        int getCantMin();
        Producto* getProducto(); 

        ~PromoProducto();
};

#endif