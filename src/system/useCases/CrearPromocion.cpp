#include "../../../include/system/Sistema.h"

using namespace std;

/*El caso de uso comienza cuando se desea dar de alta una promoción en el sistema. Para ello, el Administrador 
ingresa los datos de la promoción, luego, el Sistema lista el nickname de todos vendedores y el Administrador 
selecciona uno, que será quien ofrezca la promoción. Luego, el Sistema lista el código y el nombre de todos los 
productos disponibles asociados al vendedor seleccionado, para que el Administrador seleccione los productos
que compondrán la promoción. Es importante destacar que el sistema no permite que un producto esté incluido en dos 
promociones vigentes simultáneamente. Para cada producto seleccionado, el usuario especifica la cantidad mínima que 
debe ser adquirida para aplicar la promoción. Una vez que el Administrador termina, el Sistema da de alta la nueva 
promoción con los datos ingresados.*/

void printVector(vector<DataProducto> productos) {
    for (DataProducto producto : productos) {
        print(producto.toString());
        saltoConsola();
    }
};


void Sistema :: crearPromocion(){

    Fabrica* fabrica = Fabrica::getInstancia();
    IPromocion* iPromocion = fabrica->getIPromocion();
    IUsuario* iUsuario = fabrica->getIUsuario();

    print("-------------------- Crear Promocion --------------------");
    saltoConsola();

    print("Ingrese los datos para la nueva promocion.");
    string nombre = getInputString("    Ingresar nombre: ");
    string descripcion = getInputOracion("    Ingresar descripcion: "); //string descripcion = getInputString("Ingrese la descripcion: ");
    int descuento = getInputInt("    Ingresar descuento: ");
    DataFecha fecha = getInputFecha("Ingresar fecha de vencimiento (DD/MM/AAAA): ");
    saltoConsola();

    iPromocion->ingresarPromocion(nombre,descripcion,descuento,fecha);

    print("Listado de vendedores del sistema: ");
    set<string> nicknames = iUsuario -> listarVendedores();
    printSet(nicknames);
    saltoConsola();
    string nickname = getInputString("A continuacion escriba el nombre del vendedor que desea hacer la promocion: ");

    iPromocion -> seleccionarVendedor(nickname);
    vector<DataProducto> productosDeV = iPromocion -> mostrarProductos();
    
    saltoConsola();
    printVector(productosDeV);

    int L = 1;
    while (L == 1){
        int codeProd = getInputInt("Ingrese el codigo del producto: ");
        saltoConsola();
        int cant = getInputInt("Ingrese la cantidad de productos que se deben comprar para aplicar la promocion: ");
        saltoConsola();
        iPromocion ->agregarProducto(codeProd,cant);
        L = getInputInt("Desea agregar mas productos 'Si'(1) o 'No'(0): ");
    };


    iPromocion -> darAltaPromocion();

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};