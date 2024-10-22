#ifndef IUSUARIO
#define IUSUARIO

// Tipos
#include <string>
#include <set>

// Clases
#include "../classes/Usuario.h"

// Datatypes
#include "../datatypes/DataEnvio.h"
#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataUsuario.h"

using namespace std;

class IUsuario {
    public:
        // Crear
        virtual int crearCliente(string nickname, string contrasenia, DataFecha fechaNac, string calle, int numeroPta, string ciudad) = 0;
        virtual int crearVendedor(string nickname, string contrasenia, DataFecha fechaNac, string rut) = 0;

        // Mostrar 
        virtual DataUsuario* mostrarExpedienteUsuario(string nickname) = 0;

        // Listar
        virtual set<string> listarUsuarios() = 0;
        virtual set<string> listarClientes() = 0;
        virtual set<string> listarVendedores() = 0;
        virtual vector<DataUsuario*>listarInfoUsuarios() = 0;
        
        // Suscripciones 
        virtual void suscribirse(string nickname) = 0;
        virtual set<string> listarSuscripcionesCliente(string nickname) = 0;
        virtual set<string> listarVendedoresNoSuscritoCliente(string nickname) = 0;
        virtual vector<DataPromocion *> listarNotificacionesYEliminar(string nickname) = 0;
        virtual void eliminarSuscripcion(string nickname) = 0;

        //EnviarProductos
        virtual vector<DataProducto> listarProductosVendedorNoEnviados(string nickname) = 0;
        virtual vector<DataEnvio> listarComprasProductoNoEnviado(int codeProd) = 0;
        virtual void marcarEnviado(int indice) = 0;
};

#endif