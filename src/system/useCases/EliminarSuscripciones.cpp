// System.h
#include "../../../include/system/Sistema.h"

/*
El caso de uso comienza cuando un cliente desea eliminar una o más
suscripciones. Para ello, el Administrador indica el nickname de cliente y el
Sistema lista todos los vendedores a los que está suscrito. El Administrador
selecciona uno o varios vendedores y el sistema elimina las correspondientes
suscripciones. 
*/

void Sistema::eliminarSuscripciones() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* controlUsuario = fabrica->getIUsuario();
    
    print("------------------------ Eliminar Suscripciones -------------------------");

    print("Lista de clientes:");
    saltoConsola();
    set<string> lista = controlUsuario-> listarClientes();
    printSet(lista);
    saltoConsola();
    string nickC = getInputString("Ingresar nickname del cliente que quiere eliminar una suscripcion: ");

    saltoConsola();

    int continuarSuscribiendo = 1;
    while (continuarSuscribiendo == 1) {
        set <string> vendedoresNoSuscritos = controlUsuario->listarSuscripcionesCliente(nickC);
        print("Lista de vendedores a los que esta suscrito:");
        saltoConsola();
        printSet(vendedoresNoSuscritos);
        saltoConsola();

        string nickV = getInputString("Ingresar nickname del vendedor al que se quiere desuscribir: ");

        controlUsuario->eliminarSuscripcion(nickV);

        saltoConsola();
        print("Desea desuscribir el cliente a otro vendedor:");
        print("   1 - Si.");
        print("   0 - No.");

        continuarSuscribiendo = getInputInt("");
    }

    saltoConsola();
    print("------------------------  Fin de caso de uso  --------------------------");
};