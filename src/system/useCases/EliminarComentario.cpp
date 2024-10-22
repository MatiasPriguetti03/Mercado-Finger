#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando se desea eliminar un comentario. Para ello, el Sistema lista los nicknames 
de todos los usuarios y el Administrador selecciona uno. Luego, el Sistema lista todos los comentarios dejados
por el usuario seleccionado y el Administrador selecciona uno. Finalmente, el Sistema elimina el comentario 
seleccionado, así como todas sus respuestas si las hubiera, en cascada.*/

void Sistema::eliminarComentario(){

    Fabrica *fabrica = Fabrica::getInstancia();
    IUsuario *userController = fabrica->getIUsuario();
    IComentario *comentController = fabrica->getIComentario();

    print("--------------------- Eliminar Comentario ---------------------");
    saltoConsola();
    print("Listado de los usuarios del sistema.");
    saltoConsola();

    set<string> userSet = userController->listarUsuarios();
    set<string>::iterator userSetIterator;

    printSet(userController->listarUsuarios());
    saltoConsola();

    print("Seleccione un usuario al cual desea eliminarle un comentario.");
    string nickUser = getInputString("    Ingresar nickname: ");
    saltoConsola();
    
    if (auto search = userSet.find(nickUser); search != userSet.end()) {
        vector<DataComentario> comentarios = comentController->seleccionarUsuarioYListarComentarios(nickUser);
        vector<DataComentario>::iterator dataComentarioIterator;

        for(dataComentarioIterator = comentarios.begin(); dataComentarioIterator != comentarios.end(); ++dataComentarioIterator){
            print(dataComentarioIterator->toString());
            saltoConsola();
        };
        
        int idComentario = getInputInt("Escriba el identificador del comentario a eliminar: ");

        comentController->eliminarComentario(idComentario);
    } else {
        cout << "El usuario no es valido" << endl;
    }

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};