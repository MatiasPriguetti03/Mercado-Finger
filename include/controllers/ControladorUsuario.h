#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

// Tipos
#include <string>
#include <set>
#include <map>
#include <vector>

// Clases
#include "../classes/Usuario.h"
#include "../classes/Vendedor.h"
#include "../classes/Cliente.h"

// Interfaces
#include "../interfaces/IUsuario.h"

// Datatypes
#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataUsuario.h"
#include "../datatypes/DataClienteCompra.h"
#include "../datatypes/DataExpediente.h"
#include "../datatypes/DataEnvio.h"

using namespace std;

class ControladorUsuario : public IUsuario {
    private:
        // pseudoatributos
        map<string, Usuario*> usuarios;

        // Memoria
        string nickC;
        int codeProdNoEnviado;
        map<int, vector<DataClienteCompra>> mapaProductosNoEnviados;

        // Singleton
        static ControladorUsuario* instancia;

        // Constructor
        ControladorUsuario();

        // Destrcutor 
        ~ControladorUsuario();

    public:
        // Singelton
        static ControladorUsuario* getInstance();

        // Crear
        int crearCliente(string nickname, string contrasenia, DataFecha fechaNac, string calle, int numeroPta, string ciudad);
        int crearVendedor(string nickname, string contrasenia, DataFecha fechaNac, string rut);

        // Obtener
        Usuario* obtenerUsuario(string nickname);
        map<string, Usuario*> getUsuarios();

        // Mostrar
        DataUsuario* mostrarExpedienteUsuario(string nickname);

        // Listar
        set<string> listarUsuarios();
        set<string> listarClientes();
        set<string> listarVendedores();
        vector<DataUsuario*>listarInfoUsuarios();

        // Suscripciones
        void suscribirse(string nickname);
        set<string> listarSuscripcionesCliente(string nickname);
        set<string> listarVendedoresNoSuscritoCliente(string nickname);
        vector<DataPromocion *> listarNotificacionesYEliminar(string nickname);
        void eliminarSuscripcion(string nickname);

        //Enviar Productos
        vector<DataProducto> listarProductosVendedorNoEnviados(string nickname);
        vector<DataEnvio> listarComprasProductoNoEnviado(int codeProd);
        void marcarEnviado(int indice);
};

#endif
