#include "../../../include/system/Sistema.h"

/*El caso de uso comienza cuando se desea obtener la información de todas las promociones vigentes en 
el sistema. Para ello, el Sistema lista todos los datos de las promociones disponibles. Luego, si el 
Administrador lo desea, puede seleccionar una promoción ingresando su nombre, permitiendo al Sistema 
devolver los datos de los productos que pertenecen a la promoción junto con la información de su vendedor.*/

void printVector10(vector<DataInfoPromo> listadoPromo) {
    for (DataInfoPromo promocion : listadoPromo) {
        print(promocion.toString());
        saltoConsola(); 
    }
};


void Sistema :: consultarPromocion(){
    Fabrica* fabrica = Fabrica::getInstancia();
    IPromocion* iPromocion = fabrica->getIPromocion();
   
    print("-------------------- Consultar Promocion --------------------");
    saltoConsola();

    print("Lista de promociones vigentes: ");
    vector<DataInfoPromo> listadoPromo = iPromocion->listarPromociones();
    printVector10(listadoPromo);
    

    int L = getInputInt("Desea saber mas sobre la promocion? 'Si'(1) o 'No'(0): ");

    if (L == 1){
        string nombre = getInputOracion("Escriba el nombre de la Promocion: ");
        DataPromocion productos = iPromocion->seleccionarYConsultarPromocion(nombre);
        saltoConsola();
        print(productos.toString());
    }

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};