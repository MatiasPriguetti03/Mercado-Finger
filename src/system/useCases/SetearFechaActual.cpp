// System.h
#include "../../../include/system/Sistema.h"

/* Este caso de uso se utiliza para poder inicializar y modificar la fecha actual que utiliza el sistema. */

void Sistema::setearFechaActual() {
    // Obtener instancia
    FechaSistema* fechaSistema = FechaSistema::getInstance();

    print("---------------------- Fecha del Sistema ----------------------"); 
    saltoConsola();

    // Setear fecha
    DataFecha fechaActual = getInputFecha("Ingresar fecha actual para el sistema (DD/MM/AAAA): ");
    fechaSistema->setearFechaSistema(fechaActual);

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
}