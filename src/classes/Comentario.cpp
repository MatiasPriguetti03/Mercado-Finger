// Clase.h
#include "../../include/classes/Comentario.h"

// Constructor
Comentario::Comentario(int id, string texto, DataFecha fecha, Usuario* usuario, Producto* producto) 
    : id(id), texto(texto), fecha(fecha), usuario(usuario), producto(producto), comentarioPrevio(NULL) {};

Comentario::Comentario(int id, string texto, DataFecha fecha, Usuario* usuario, Producto* producto, Comentario* comentarioPrevio) 
    : id(id), texto(texto), fecha(fecha), usuario(usuario), producto(producto), comentarioPrevio(comentarioPrevio) {};

// Getters
int Comentario::getId() {
    return this->id;
};
string Comentario::getTexto() {
    return this->texto;
};

Comentario* Comentario::getComentarioPrevio() {
    return this->comentarioPrevio;
};

// Operaciones
DataComentario Comentario::getDataComentario() {
    return DataComentario(this->id, this->texto);
};

void Comentario::eliminarComentario(int id) {
    this->respuestas.erase(id);
};

void Comentario::agregarComentario(Comentario * comentario) {
    this->respuestas.insert(make_pair(comentario->getId(), comentario));
}

// Destructor
Comentario::~Comentario() {
    this->usuario->eliminarRelacionComentario(this->id);
    this->producto->eliminarRelacionComentario(this->id);
    if (this->comentarioPrevio != NULL) {
        this->comentarioPrevio->eliminarComentario(this->id);
    };

    for (const auto &res : this->respuestas) {
        delete res.second;
    };
    this->respuestas.clear();
};