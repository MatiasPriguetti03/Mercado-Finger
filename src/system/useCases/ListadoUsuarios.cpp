// System.h
#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando se desea consultar la información de todos los usuarios del sistema. Para 
esto, el Sistema lista los nicknames (pseudónimos) de todos los usuarios junto a la fecha de nacimiento. En 
caso de que el usuario sea un cliente, adicionalmente se muestra su dirección y ciudad de residencia, mientras 
que, si se trata de un vendedor, se muestra su código RUT. */

void Sistema::listadoDeUsuarios() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* controlUsuario = fabrica->getIUsuario();

    print("--------------------- Listado de Usuarios ---------------------");
    saltoConsola();
    print("Se lista la infromacion de los usuarios del sistema.");
    saltoConsola();

    for (DataUsuario* usuario : controlUsuario->listarInfoUsuarios()) {
         print(usuario->toString());
    };

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};


