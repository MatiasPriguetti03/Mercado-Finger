#ifndef SISTEMA
#define SISTEMA

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "../controllers/ControladorComentario.h"
#include "../controllers/ControladorCompra.h"
#include "../controllers/ControladorProducto.h"
#include "../controllers/ControladorPromocion.h"
#include "../controllers/ControladorUsuario.h"

#include "../factory/Fabrica.h"

#include "Operaciones.h"
#include "FechaSistema.h"

using namespace std;

class Sistema {
private:
    static Sistema* instancia;
    Sistema();
public:
    // Constructor
    // Sistema();
    static Sistema *getInstance();
    // Destructor
    ~Sistema();

    // Operaciones de Consola
    bool deseaRealizarOtraOperacion();
    int ingresarOpcion(int num);
    void limpiarConsola();
    void imprimirMenu();

    // Operaciones del Sistema
    void altaDeUsuario();
    void listadoDeUsuarios();
    void altaDeProducto();
    void consultarProducto();
    void crearPromocion();
    void consultarPromocion();
    void realizarCompra();
    void dejarComentario();
    void eliminarComentario();
    void enviarProducto();
    void expedienteDeUsuario();
    void suscribirseANotificaciones();
    void consultaDeNotificaciones();
    void eliminarSuscripciones();
    void cargarDatos();
    void setearFechaActual();
};

#endif