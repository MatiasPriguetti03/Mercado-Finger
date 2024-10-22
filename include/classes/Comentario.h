#ifndef COMENTARIO
#define COMENTARIO

// Tipos#include <iostream>
#include <string>
#include <map>

//Forward Declaration
class Usuario;

// Clases
#include "Producto.h"
#include "Usuario.h"

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataComentario.h"

class Usuario;
class Producto;

using namespace std;

class Comentario {
    private:
        int id;
        string texto;
        DataFecha fecha;

        // Pseudoatributos
        Usuario* usuario;
        Producto* producto;
        Comentario* comentarioPrevio;
        map<int, Comentario*> respuestas;

    public:
        // Constructor
        Comentario(int id, string texto, DataFecha fecha, Usuario* usuario, Producto* producto);
        Comentario(int id, string texto, DataFecha fecha, Usuario* usuario, Producto* producto, Comentario* comentarioPrevio);

        //Getters
        int getId();
        string getTexto();
        Comentario* getComentarioPrevio();

        // Operaciones
        DataComentario getDataComentario();
        void eliminarComentario(int id);
        void agregarComentario(Comentario* comentario);

        // Destructor
        ~Comentario();
};

#endif