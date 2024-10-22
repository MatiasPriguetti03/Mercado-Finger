#include "../../include/system/Sistema.h"

#include <sstream>

// Constructor
Sistema::Sistema(){};

Sistema* Sistema::instancia;

Sistema* Sistema::getInstance(){
    if (instancia != NULL) {
        return instancia;
    } else {
        instancia = new Sistema();
        return instancia;
    }
};

// Destructor
Sistema::~Sistema(){};

// Operaciones de Consola
bool Sistema::deseaRealizarOtraOperacion(){
    int opcion;
    cout << endl;
    cout << "Desea realizar otra operacion?" << endl;
    cout << "    0. No" << endl;
    cout << "    1. Si" << endl;
    opcion = ingresarOpcion(1);
    cout << endl;
    return opcion == 1;
};

int Sistema::ingresarOpcion(int cantOpciones){
    int opcion = getInputInt("Ingrese una opcion: ");

    if (opcion >= 0 && opcion <= cantOpciones) {
        cout << endl;
        return opcion;
    } else {
        cout << "Debe ingresar una opcion valida" << endl;
        return ingresarOpcion(cantOpciones);
    }
};

void Sistema::imprimirMenu() {
    cout << "Menu de opciones:" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Listado de usuarios" << endl;
    cout << "3. Alta de producto" << endl;
    cout << "4. Consultar producto" << endl;
    cout << "5. Crear promocion" << endl;
    cout << "6. Consultar promocion" << endl;
    cout << "7. Realizar compra" << endl;
    cout << "8. Dejar comentario" << endl;
    cout << "9. Eliminar comentario" << endl;
    cout << "10. Enviar producto" << endl;
    cout << "11. Expediente de usuario" << endl;
    cout << "12. Suscribirse a notificaciones" << endl;
    cout << "13. Consulta de notificaciones" << endl;
    cout << "14. Eliminar suscripciones" << endl;
    cout << "15. Cargar Datos" << endl;
    cout << "16. Setear Fecha" << endl;
    cout << "0. Salir" << endl;
}

void Sistema::limpiarConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
};