#ifndef CLIENTE
#define CLIENTE

// Tipos
#include <string>
#include <vector>

// Clases
#include "Usuario.h"
#include "Compra.h"

// Interfaces
#include "../interfaces/IObserver.h"

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataComentario.h"
#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataClienteCompra.h"


using namespace std;

class Cliente : public Usuario, public IObserver {
    private:
        std::string calle;
        int nroPuerta;
        string ciudad;
        vector<DataPromocion*> notificaciones;

        // Pseudoatributo
        vector<Compra*> compras;

    public:
        Cliente(string nickname, string contrasenia, DataFecha fecha, string calle, int nroPuerta, string ciudad); 

        DataUsuario* getDataInfoUsuario() override; 
        DataUsuario* getExpediente() override;

        // Operaciones
        void agregarCompra(Compra* compra);
        void agregarNotificacion(DataPromocion* notificacion) override;
        vector<DataPromocion*> listarNotificaciones();
        vector<DataClienteCompra> getVectorClienteCompras(int codeProd);

        ~Cliente();
};

#endif