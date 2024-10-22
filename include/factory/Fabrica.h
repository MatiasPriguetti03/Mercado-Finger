#ifndef FABRICA
#define FABRICA

#include <string>

#include "../../include/interfaces/IUsuario.h"
#include "../../include/interfaces/IProducto.h"
#include "../../include/interfaces/ICompra.h"
#include "../../include/interfaces/IPromocion.h"
#include "../../include/interfaces/IComentario.h"

#include "../../include/controllers/ControladorUsuario.h"
#include "../../include/controllers/ControladorProducto.h"
#include "../../include/controllers/ControladorCompra.h"
#include "../../include/controllers/ControladorPromocion.h"
#include "../../include/controllers/ControladorComentario.h"

using namespace std;

// Singleton
class Fabrica {

private:
    Fabrica() {};

    static Fabrica* instancia;

     ~Fabrica() {}
public:

    // Getters

    // Operaciones de Clase
    static Fabrica* getInstancia();

    // Controladores
    IUsuario* getIUsuario();
    IProducto* getIProducto();
    ICompra* getICompra();
    IPromocion* getIPromocion();
    IComentario* getIComentario();
};

#endif 