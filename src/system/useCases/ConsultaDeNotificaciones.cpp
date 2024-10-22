// System.h
#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando un cliente desea consultar las notificaciones recibidas. Para ello, el 
Administrador indica el nickname del cliente y el Sistema lista todas las notificaciones recibidas por 
el cliente correspondiente. Cada notificación contiene el nickname del vendedor, el nombre de la promoción
creada y los productos asociados a la misma. Solo se muestran las notificaciones recibidas desde el momento 
en que el cliente se suscribió o desde su última consulta de notificaciones. Finalmente, el Sistema elimina
todas las notificaciones que haya recibido el cliente hasta este momento.*/

void Sistema::consultaDeNotificaciones() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* controlUsuario = fabrica->getIUsuario();
    
    print("------------------ Consulta de Notificaciones -----------------");
    saltoConsola();
    
    print("Lista de clientes:");
    saltoConsola();
    set<string> lista = controlUsuario-> listarClientes();
    printSet(lista);
    saltoConsola();
    print("Seleccione un cliente al que le desee ver las notificaciones.");
    string nickC = getInputString("    Ingresar nickname: ");
    saltoConsola();

    vector<DataPromocion *> notificaciones = controlUsuario->listarNotificacionesYEliminar(nickC);

    for (DataPromocion* noti : notificaciones) {
        print(noti->toString());
    }

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};
