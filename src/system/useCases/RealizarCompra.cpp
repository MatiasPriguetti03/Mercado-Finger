#include "../../../include/system/Sistema.h"

using namespace std;

/*El caso de uso comienza cuando se desea registrar una compra en el sistema. Para ello, el Sistema muestra una lista de los nicknames
de todos los clientes y el Administrador selecciona uno de ellos como el cliente que realizará la compra. Luego, el Sistema muestra los 
datos de todos los productos disponibles. A continuación, el Sistema pregunta al Administrador si desea agregar productos a la compra. 
Si la respuesta es afirmativa, el Administrador ingresa el código del producto junto con la cantidad que desea comprar. Este proceso se 
repite hasta que el Administrador indique que no desea agregar más productos a la compra. Es importante destacar que el Sistema no permite 
que un producto sea agregado a la compra en más de una instancia. Una vez que el Administrador ha finalizado de agregar los productos, el 
Sistema muestra los detalles de la compra, incluyendo el precio total y la fecha, junto con los datos de los productos seleccionados.
Finalmente, después de corroborar los datos de la compra, el Administrador confirma la compra y el Sistema la registra.*/

void printVector4(vector<DataProducto> productos) {
    for (DataProducto &producto : productos) {
        print(producto.toString());
        saltoConsola();
    }
};

void Sistema :: realizarCompra() {

    Fabrica* fabrica = Fabrica::getInstancia();
    ICompra* iCompra = fabrica->getICompra();
    IProducto* iProducto = fabrica->getIProducto();
    IUsuario* iUsuario = fabrica-> getIUsuario();
    

    print("-------------------- Realizar Compra --------------------");
    saltoConsola();

    print("Lista de Clientes:");

    set<string> nicknames = iUsuario->listarClientes();

    printSet(nicknames);
    
    print("Seleccione el cliente que realizara la compra: ");

    string nickname = getInputString("    Ingrese el nickname: ");
    saltoConsola();

    iCompra->seleccionarCliente(nickname);

    vector<DataProducto> productos = iProducto -> listarProductos();

    print("Lista de Productos: ");
    saltoConsola();

    printVector4(productos);
    
    int L = getInputInt("Desea agregar productos a la compra 'Si'(1) o 'No'(0): ");
    saltoConsola();

    while (L == 1){  
        int codeProd = getInputInt("Ingrese el codigo del producto: ");
        saltoConsola();
        int cant = getInputInt("Ingrese la cantidad de productos desea comprar: ");
        saltoConsola();
        iCompra->agregarProductoCompra(codeProd,cant);
        L = getInputInt("Desea agregar mas productos 'Si'(1) o 'No'(0): ");
        saltoConsola();
    };

    DataCompra * compra = iCompra ->mostrarCompra();

    print("Compra: ");

    print(compra->toString());

    iCompra->confirmarCompra();

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};