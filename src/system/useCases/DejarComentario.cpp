#include "../../../include/system/Sistema.h"

/* El caso de uso comienza cuando se desea generar un comentario para un producto. Para ello, el Sistema lista los nicknames 
de todos los usuarios y el Administrador selecciona uno. Luego se muestra el listado de todos los productos y el Administrador 
selecciona uno. A continuación, el Sistema pregunta si se quiere realizar un comentario nuevo o responder a un comentario 
existente. En el caso de que sea un comentario nuevo el Sistema pide el texto del comentario, y en caso de que sea una respuesta,
el Sistema lista los comentarios ya realizados para el producto seleccionado y el Administrador selecciona uno y luego ingresa el 
texto de la respuesta. */

void imprimirProductos(vector<DataProducto> prodVector) {
    vector<DataProducto>::iterator dataProdIterator;
    for (dataProdIterator = prodVector.begin(); dataProdIterator != prodVector.end(); ++dataProdIterator) {
        print(dataProdIterator->toString());
    };
};

void imprimirIdUsuarios(set<string> userSet) {
    set<string>::iterator userSetIterator;
    for (userSetIterator = userSet.begin(); userSetIterator != userSet.end(); userSetIterator++) {
        cout << *userSetIterator << endl;
    }
};

void imprimirComentarios(map<int, Comentario *> prodComentarios) {
    map<int, Comentario *>::iterator prodComentariosIterator;

    for (prodComentariosIterator = prodComentarios.begin(); prodComentariosIterator != prodComentarios.end(); ++prodComentariosIterator) {
        Comentario *comentario = prodComentariosIterator->second;
        cout << comentario->getId() << endl;
        cout << comentario->getTexto() << endl;
        cout << endl;
    }
};

void Sistema::dejarComentario() {
    Fabrica *fabrica = Fabrica::getInstancia();
    IUsuario *IUsuario = fabrica->getIUsuario();
    IComentario *IComentario = fabrica->getIComentario();

     print("--------------------- Dejar Comentario ---------------------");
    set<string> userSet = IUsuario->listarUsuarios();
    saltoConsola();

    printSet(userSet);

    string keyUser = getInputString("Escriba el identificador del usuario seleccionado: ");

    if (auto search = userSet.find(keyUser); search != userSet.end()) {

        vector<DataProducto> prodVector = IComentario->seleccionarUsuario(keyUser);

        imprimirProductos(prodVector);

        string idProd = getInputString("Escriba el identificador del producto al que va a dejar comentario: ");
        IComentario->seleccionarProducto(stoi(idProd));

        bool esRespuesta;

        string texto;
        cout << "Ingrese el texto de su comentario: " << endl;
        getline(cin, texto);
        string comentario;
        getline(cin, comentario);

        int opcion;
        cout << endl;
        cout << "Va dejar un comentario como respuesta a otro?" << endl;
        cout << "1. Si, es respuesta a un comentario" << endl;
        cout << "0. No, va a ser un nuevo comentario" << endl;
        opcion = ingresarOpcion(1);
        cout << endl;
        esRespuesta = (opcion == 1);

        FechaSistema *fechaSistema = FechaSistema::getInstance();
        DataFecha test = fechaSistema->getFecha();

        if (esRespuesta) {
            map<int, Comentario *> prodComentarios = IComentario->listarComentarios();
            imprimirComentarios(prodComentarios);

            string idCom = getInputString("Escriba el identificador del comentario al que va a dejar una respuesta: ");

            Comentario *comentarioAResponder = prodComentarios.find(stoi(idCom))->second;
            IComentario->seleccionarComentario(comentarioAResponder->getId());

            IComentario->realizarRespuesta(comentario);
        } else {
            IComentario->nuevoComentario(comentario);
        }
    } else {
        cout << "El usuario no es valido." << endl; 
    }

    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
};