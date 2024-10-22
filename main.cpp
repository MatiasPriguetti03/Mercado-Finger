#include "include/system/Sistema.h"


#include <string>
#include <iostream>

using namespace std;

int main(){

    bool quiereContinuar = true;
    Sistema* sistema = Sistema::getInstance();
    print("Bienvenido a MercadoFinger");
    saltoConsola();
    do
    {
        sistema -> imprimirMenu();
        int opcion = sistema->ingresarOpcion(16);
        switch (opcion)
        {
        case 1:
            sistema->altaDeUsuario();
            break;
        case 2:
            sistema->listadoDeUsuarios();
            break;
        case 3:
            sistema->altaDeProducto();
            break;
        case 4:
            sistema->consultarProducto();
            break;
        case 5:
            sistema->crearPromocion();
            break;
        case 6:
            sistema->consultarPromocion();
            break;
        case 7:
            sistema->realizarCompra();
           break;
        case 8:
            sistema->dejarComentario();
            break;
        case 9:
            sistema->eliminarComentario();
            break;
        case 10:
            sistema->enviarProducto();
            break;
        case 11:
            sistema->expedienteDeUsuario();
            break;
        case 12:
            sistema->suscribirseANotificaciones();
            break;
        case 13:
            sistema->consultaDeNotificaciones();
            break;
        case 14:
            sistema->eliminarSuscripciones();
            break;
        case 15:
            sistema->cargarDatos();
            break;
        case 16:
            sistema->setearFechaActual();
            break;
        case 0:
            quiereContinuar = false;
            break;
        }
        if (opcion != 0)
        {
            quiereContinuar = sistema->deseaRealizarOtraOperacion();
        }

        sistema->limpiarConsola();

    } while (quiereContinuar);
};
