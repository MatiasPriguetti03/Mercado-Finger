#ifndef ICOMENTARIO
#define ICOMENTARIO

#include <vector>
#include <map>
#include <string>

#include "../classes/Comentario.h"
#include "../datatypes/DataComentario.h"
#include "../datatypes/DataProducto.h"

using namespace std;



class IComentario {
    public:
        virtual vector<DataComentario> seleccionarUsuarioYListarComentarios(string nickname) = 0;
        
        virtual void eliminarComentario(int id) = 0;
        virtual vector<DataProducto> seleccionarUsuario(string nickname) = 0;
        virtual void seleccionarProducto(int id) = 0;
        virtual void seleccionarComentario(int Comentario) = 0;
        virtual map<int, Comentario *> listarComentarios() = 0;

        virtual void nuevoComentario(string text) = 0;
        virtual void nuevoComentario(string text, DataFecha fecha) = 0;
        virtual void realizarRespuesta(string text) = 0;
        virtual void realizarRespuesta(string text, DataFecha fecha) = 0;
};

#endif