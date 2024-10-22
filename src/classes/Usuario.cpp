// Clase.h
#include "../../include/classes/Usuario.h"

// Constructor
Usuario::Usuario(string nickname, string contrasenia, DataFecha fechaNacimiento)
    : nickname(nickname), contrasenia(contrasenia), fechaNacimiento(fechaNacimiento) {}

// Getters
string Usuario::getNickname(){
    return this->nickname;         
}

DataFecha Usuario::getFechaNacimiento(){
    return this->fechaNacimiento;
}

DataUsuario* Usuario::getDataInfoUsuario() {
    return new DataUsuario(this->nickname, this->fechaNacimiento);
};

// Operaciones
void Usuario::eliminarRelacionComentario(int id){
    this->comentarios.erase(id);
}

void Usuario::agregarRelacionComentario(Comentario* comentario) {
    int id = comentario->getId();
    this->comentarios.insert(make_pair(id,comentario));
}

vector<DataComentario> Usuario::listarComentarios(){
    vector<DataComentario> comentariosU;
    for (map<int, Comentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it){
        comentariosU.push_back(it->second->getDataComentario());
    }
    return comentariosU;
}

Comentario* Usuario::obtenerComentario(int id){
    return this->comentarios.find(id)->second;
}

// Destructor
Usuario::~Usuario(){}
