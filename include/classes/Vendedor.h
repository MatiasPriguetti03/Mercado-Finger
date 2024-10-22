#ifndef VENDEDOR
#define VENDEDOR

// Tipos
#include <vector>
#include <string>
#include <map>

// Clases
#include "Usuario.h"
#include "Producto.h"
#include "Promocion.h"

// Interfaces
#include "../interfaces/IObserver.h"

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataProducto.h"
#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataPromoProducto.h"
#include "../datatypes/DataUsuario.h"

// Controlador
#include "../../include/controllers/ControladorUsuario.h"

using namespace std;

class Vendedor : public Usuario
{
private:
    string rut;

    // Pseudoatributo
    map<int, Producto *> productos;
    vector<Promocion *> promociones;
    map<string, IObserver *> subcriptores;

public:
    // Constructor
    Vendedor(string nickname, string contrasenia, DataFecha fechaNacimiento, string rut);

    // Destructor
    ~Vendedor();

    // Getters
    vector<DataProducto *> getProductos();
    DataUsuario* getDataInfoUsuario() override;
    DataUsuario*  getExpediente() override;

    // Operaciones
    vector<DataProducto> obtenerDataProductos();
    void agregarPromocion(Promocion *promo, vector<DataPromoProducto> prodPromo);
    void agregarProducto(Producto* prod);
    vector<string> listarVendedores();
    void notificarPromo(DataPromocion* promo);
    bool estaSubscripto(IObserver *cliente);
    void agregarSubscriptor(IObserver *cliente);
    void eliminarSubscriptor(string nickname);


};

#endif