// System.h
#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando un cliente desea suscribirse para recibir notificaciones relativas a la 
creación de promociones de uno o más vendedores. Para ello, el Administrador indica el nickname del 
cliente y el Sistema devuelve la lista de todos los vendedores a los que no está suscrito dicho cliente. 
Posteriormente, el Administrador indica los vendedores a los que desea suscribir al cliente y el Sistema 
lo agrega a la lista de suscriptores de cada vendedor. */

void Sistema::suscribirseANotificaciones() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* controlUsuario = fabrica->getIUsuario();
    
    print("--------------------- Suscribirse a Notificaciones ----------------------");
    saltoConsola();
    print("Lista de clientes:");
    saltoConsola();
    set<string> lista = controlUsuario-> listarClientes();
    printSet(lista);
    saltoConsola();

    string nickC = getInputString("Ingresar nickname del cliente que quiere hacer una suscripcion: ");
    saltoConsola();


    int continuarSuscribiendo = 1;
    while (continuarSuscribiendo == 1) {
        print("Lista de vendedores a los que no esta suscrito:");
        saltoConsola();
        set <string> vendedoresNoSuscritos = controlUsuario->listarVendedoresNoSuscritoCliente(nickC);
        printSet(vendedoresNoSuscritos);
        saltoConsola();
        
        string nickV = getInputString("Ingresar nickname del vendedor al que se quiere suscribir: ");

        controlUsuario->suscribirse(nickV);
        saltoConsola();
        print("Desea suscribir el cliente a otro vendedor:");
        print("   1 - Si.");
        print("   0 - No.");

        continuarSuscribiendo = getInputInt("");
    }

    saltoConsola();
    print("------------------------ Fin del Caso de Uso -------------------------");
};