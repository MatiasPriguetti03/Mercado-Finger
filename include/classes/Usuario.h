
#ifndef USUARIO
#define USUARIO

// Tipos
#include <string>
#include <map>
#include <vector>

// Clases
#include "Comentario.h"

// Datatype
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataComentario.h"
#include "../datatypes/DataUsuario.h"
#include "../datatypes/DataExpediente.h"

using namespace std;

class Comentario;

class Usuario {
    private:
        string nickname;
        string contrasenia;
        DataFecha fechaNacimiento;
        
        // Pseudoatributos
        map<int, Comentario*> comentarios;

    public:
        Usuario(string nickname, string contrasenia, DataFecha fechaNacimiento);

        // Getters
        virtual string getNickname();
        virtual DataFecha getFechaNacimiento();
        virtual DataUsuario* getDataInfoUsuario();
        virtual DataUsuario* getExpediente() = 0;

        // Operaciones
        void eliminarRelacionComentario(int id);
        void agregarRelacionComentario(Comentario *comentario);
        vector<DataComentario> listarComentarios();
        Comentario* obtenerComentario(int id);

        virtual ~Usuario();
};

#endif