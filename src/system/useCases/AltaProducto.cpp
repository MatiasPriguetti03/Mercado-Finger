// System.h
#include "../../../include/system/Sistema.h"

/* El caso de uso ...*/

void Sistema::altaDeProducto() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* iUsuario = fabrica->getIUsuario();
    IProducto* iProducto = fabrica->getIProducto();
    
    print("------------------------ Alta Producto -------------------------");
    saltoConsola();
    print("Listado de los vendedores del sistema.");
    saltoConsola();

    set<string> lista = iUsuario-> listarVendedores();
    printSet(lista);
    saltoConsola();

    print("Seleccione un vendedor para ingresarle un producto.");
    string nickname = getInputString("    Ingresar nickname: ");
    saltoConsola();

    iProducto-> seleccionarVendedor(nickname);

    print("Ingrese los datos del nuevo producto");
    string nombre = getInputString("    Ingresar nombre: ");
    string descripcion = getInputOracion("    Ingresar descripcion: ");
    float precio = getInputFloat("    Ingresar precio: $ ");
    int stock = getInputInt("    Ingresar stock inicial: ");
    CategoriaProducto categoria = getInputCategoria();
    

    iProducto-> crearProducto(nombre, precio, stock, descripcion, categoria);
    
    saltoConsola();
    print("Producto creado con exito.");
    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};