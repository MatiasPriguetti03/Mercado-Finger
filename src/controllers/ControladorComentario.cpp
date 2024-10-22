// Interfaces
#include "../../include/interfaces/IComentario.h"

// Controladores
#include "../../include/controllers/ControladorComentario.h"

using namespace std;

int ControladorComentario::intDisp = 1;

// Constructor
ControladorComentario::ControladorComentario(){};

ControladorComentario::ControladorComentario(int intDisp, vector<DataComentario *> comentarios) {
    ControladorComentario::intDisp = intDisp;
    this->comentarios = vector<DataComentario *>();
    this->nickMemory = "";
    this->codeProd = 0;
    this->comRespuesta = 0;
};

// Setters
void ControladorComentario::setNickMemory(string nick) {
    this->nickMemory = nick;
};

void ControladorComentario::setCodeProd(int code) {
    if (this->codeProd != 0) {
        this->codeProd = 0;   
    }
    this->codeProd = code;
};

void ControladorComentario::setComentario(int comentario) {
    if (this->comRespuesta != 0) {
        this->comRespuesta = 0;    
    }
    this->comRespuesta = comentario;
};

// Liberar Memoria
void ControladorComentario::liberarMemoria() {
    this->nickMemory = "";
    this->codeProd = 0;
    this->comRespuesta = 0;
};

// Operaciones
vector<DataComentario> ControladorComentario::seleccionarUsuarioYListarComentarios(string nickname) {
// Selecciona un usuario por su nickname y devuelve sus comentarios.

    ControladorUsuario *userController = ControladorUsuario::getInstance();
    Usuario *usuario = userController->obtenerUsuario(nickname);

    this->setNickMemory(nickname);
    vector<DataComentario> comentsUsuario = usuario->listarComentarios();

    return comentsUsuario;
};

void ControladorComentario::eliminarComentario(int id) {
// La funcion recibe el id del comentario a borrar, se lo busca en la coleccion de comentarios
// del vendedor cuyo nickname fue guardado en memoria, y se elimina el comentario y sus respuestas

    ControladorUsuario *userController = ControladorUsuario::getInstance();
    if (this->nickMemory != "") {
        Usuario *user = userController->obtenerUsuario(this->nickMemory);
        Comentario *comment = user->obtenerComentario(id);

        delete comment;
    } else {
        cout << "No se selecciono un usuario";
    }

    this->setNickMemory("");
};

vector<DataProducto> ControladorComentario::seleccionarUsuario(string nickname) {
// La funcion recibe el nickname de un vendedor y devuelve una coleccion de sus productos

    this->setNickMemory(nickname);
    ControladorProducto* prodController = ControladorProducto::getInstance();
    vector<DataProducto> prodVector = prodController->listarProductos();
    return prodVector;
}

void ControladorComentario::seleccionarProducto(int id) {
// La funcion recibe el id de un producto y lo guarda en memoria

    this->setCodeProd(id);
};

void ControladorComentario::seleccionarComentario(int Comentario) {
// La funcion recibe el id de un comentario y lo guarda en memoria

    this->setComentario(Comentario);
};

map<int, Comentario *> ControladorComentario::listarComentarios() {
// La funcion devulve la coleccion de comentarios guardada en memoria

    ControladorProducto *prodController = ControladorProducto::getInstance();
    Producto *prod = prodController->obtenerProducto(this->codeProd);

    return prod->getComentarios();
};

void ControladorComentario::realizarRespuesta(string text) {
// La función recibe el contenido del comentario a realizar, y accediendo a los datos guardados en memoria realiza
// la respuesta a un comentario previamente existente. 
// Finalmente, incrementa el contador de comentarios disponibles y libera la memoria.

    FechaSistema *fechaSistema = FechaSistema::getInstance();
    ControladorProducto *prodController = ControladorProducto::getInstance();
    ControladorUsuario *userController = ControladorUsuario::getInstance();

    Usuario* user = userController->obtenerUsuario(this->nickMemory);
    Producto *prod = prodController->obtenerProducto(this->codeProd);


    Comentario* com = new Comentario(ControladorComentario::intDisp, text, fechaSistema->getFecha(), user, prod, prod->getComentario(this->comRespuesta));

    prod->getComentario(this->comRespuesta)->agregarComentario(com);
    prod->crearRelacionComentario(com);
    user->agregarRelacionComentario(com);

    ++ControladorComentario::intDisp;
    this->liberarMemoria();
};

void ControladorComentario::realizarRespuesta(string text, DataFecha fecha) {

    ControladorProducto *prodController = ControladorProducto::getInstance();
    ControladorUsuario *userController = ControladorUsuario::getInstance();

    Usuario *user = userController->obtenerUsuario(this->nickMemory);
    Producto *prod = prodController->obtenerProducto(this->codeProd);

    Comentario *com = new Comentario(ControladorComentario::intDisp, text, fecha, user, prod, prod->getComentario(this->comRespuesta));

    prod->getComentario(this->comRespuesta)->agregarComentario(com);
    prod->crearRelacionComentario(com);
    user->agregarRelacionComentario(com);


    ++ControladorComentario::intDisp;
    this->liberarMemoria();
};

void ControladorComentario::nuevoComentario(string text) {
// La funcion obtiene el usuario y producto guardados en memoria. Crea un nuevo comentario con esta información y el texto que
// recibe por parametro y actualiza las relaciones correspondientes en el producto y el usuario. Finalmente, incrementa el 
// contador de comentarios disponibles y libera la memoria.

    FechaSistema* fechaSistema = FechaSistema::getInstance();
    ControladorProducto* prodController = ControladorProducto::getInstance();
    ControladorUsuario* userController = ControladorUsuario::getInstance();

    Usuario* user = userController->obtenerUsuario(this->nickMemory);
    Producto* prod = prodController->obtenerProducto(this->codeProd);

    Comentario* com = new Comentario(ControladorComentario::intDisp, text, fechaSistema->getFecha(), user, prod);

    prod->crearRelacionComentario(com);
    user->agregarRelacionComentario(com);

    ++ControladorComentario::intDisp;
    this->liberarMemoria();
};

void ControladorComentario::nuevoComentario(string text, DataFecha fecha) {
    ControladorProducto *prodController = ControladorProducto::getInstance();
    ControladorUsuario *userController = ControladorUsuario::getInstance();

    Usuario* user = userController->obtenerUsuario(this->nickMemory);
    Producto* prod = prodController->obtenerProducto(this->codeProd);

    Comentario* com = new Comentario(ControladorComentario::intDisp, text, fecha, user, prod);

    prod->crearRelacionComentario(com);
    user->agregarRelacionComentario(com);

    ++ControladorComentario::intDisp;
    this->liberarMemoria();
};
