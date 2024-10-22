// System.h
#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando se quiere obtener información de un usuario. Para eso, el Sistema lista 
los nicknames de todos los usuarios y el Administrador selecciona uno. A continuación, el Sistema lista 
información básica del usuario. Además, si es vendedor lista todos los productos que tiene a la venta y sus 
promociones vigentes, mientras que si es un cliente, lista todas las compras que ha realizado, incluyendo 
información sobre los productos de cada una.*/

void Sistema::expedienteDeUsuario() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* controlUsuario = fabrica->getIUsuario();
    
    print("-------------------- Expediente de Usuario --------------------");
    saltoConsola();
    print("Listado de los nickname de los usuarios del sistema.");
    saltoConsola();

    printSet(controlUsuario->listarUsuarios());
    saltoConsola();

    print("Seleccione usuario al que le desea ver el expediente.");
    string nickname = getInputString("    Ingrese el nickname :");
    saltoConsola();

    print(controlUsuario->mostrarExpedienteUsuario(nickname)->toString());

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};