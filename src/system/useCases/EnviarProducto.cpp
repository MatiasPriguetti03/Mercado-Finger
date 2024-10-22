#include "../../../include/system/Sistema.h"

using namespace std;

void Sistema::enviarProducto(){
    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario*  iUsuario = fabrica-> getIUsuario();

    print("------------------------ Eniviar Producto -------------------------");
    saltoConsola();
    print("Lista de vendedores: ");
    saltoConsola();
    set<string> listaV = iUsuario-> listarVendedores();
    printSet(listaV);
    saltoConsola();
    print("Seleccione un vendedor para ver todos sus productos con envio piendiente: ");
    string nickVendedor = getInputString("    Nickname: ");
    vector<DataProducto> listaP = iUsuario-> listarProductosVendedorNoEnviados(nickVendedor);
    for(DataProducto dp : listaP){
        print(dp.toString());
        saltoConsola();
    };

    print("Seleccione un producto para ver todas sus compras con envio pendiente");
    int code = getInputInt("    Ingresar Codigo: ");
    vector<DataEnvio> listaE = iUsuario-> listarComprasProductoNoEnviado(code);
    int i = 0;
    for (DataEnvio de: listaE){
        cout << i;
        print(de.toString());
        i++;
        saltoConsola();
    }

    int eleccion = getInputInt("Seleccione una compra para hacer el envio: ");
    iUsuario-> marcarEnviado(eleccion);

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
}