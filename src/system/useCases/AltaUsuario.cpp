// System.h
#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando se desea dar de alta un usuario en el sistema. El Administrador ingresa 
un nickname, una contraseña (de al menos6 caracteres) y la fecha de nacimiento. En caso de tratarse de un 
cliente, se ingresa su dirección y ciudad de residencia, mientras que, si es un vendedor,se ingresa su 
código RUT (de 12 caracteres). Finalmente, el Sistema da de alta el nuevo usuario con los datos ingresados. 
En caso de que ya exista en el sistema un usuario con el nickname ingresado, el Sistema comunica elerror y 
no se da de alta el usuario.*/

void Sistema::altaDeUsuario() {

    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* controlUsuario = fabrica->getIUsuario();
    
    print("------------------------ Alta Usuario -------------------------");
    saltoConsola();
    
    print("Seleccione el tipo de usuario a ingresar:");
    print("    1 - Ingresar cliente.");
    print("    2 - Ingresar vendedor.");
    saltoConsola();

    int opcion = getInputInt("Opcion : ");
    saltoConsola();

    print("Ingrese los datos del nuevo usuario.");
    string nickname = getInputString("    Ingresar nickname : ");
    string contrasenia = getInputString("    Ingresar contraseña : ");
    DataFecha fechaNac = getInputFecha("    Ingresar fecha de nacimiento (DD/MM/AAAA) : ");

    int error = 1;

    if (opcion == 1) {

        string calle = getInputString("    Ingresar calle : ");
        int nroPuerta = getInputInt("    Ingresar numero de puerta : ");
        string ciudad = getInputString("    Ingresar ciudad : ");
        
        error = controlUsuario->crearCliente(nickname, contrasenia, fechaNac, calle, nroPuerta, ciudad);

    } else if (opcion == 2) {

        string rut = getInputString("    Ingresar rut : ");
        
        error = controlUsuario->crearVendedor(nickname, contrasenia, fechaNac, rut);
    }

    saltoConsola();

    if (error == 0) {
        print("Usuario creado con exito.");
    } else {
        if (error == -1) {
            print("Ya existe un usuario con el nickname ingresado.");
        }
        if (error == -2) {
            print("Contraseña invalida. Debe tener minimo una longitud de 6 caracteres.");
        }
        if (error == -3) {
            print("RUT invalido. Debe tener una longitud de 12 caracteres.");
        } 
    }

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};