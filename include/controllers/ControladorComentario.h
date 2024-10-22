#ifndef CONTROLADORCOMENTARIO
#define CONTROLADORCOMENTARIO

// Tipos
#include <string>
#include <vector>
#include <iostream>

// Datatypes
#include "../datatypes/DataComentario.h"
#include "../datatypes/DataProducto.h"

// Interfaces
#include "../interfaces/IComentario.h"

// Controladores
#include "ControladorUsuario.h"
#include "ControladorProducto.h"
#include "../system/FechaSistema.h"

using namespace std;

class ControladorComentario : public IComentario {
private:

    // pseudoatributos
    vector<DataComentario *> comentarios;

    // memoria
    int comRespuesta;
    string nickMemory;
    int codeProd;

public:
    static int intDisp;

    // Constructor
    ControladorComentario();
    ControladorComentario(int intDisp, vector<DataComentario *> comentarios);

    // Setters
    void setNickMemory(string nickMemory);
    void setCodeProd(int codeProd);
    void setComentario(int comentario);

    // Liberar Memoria
    void liberarMemoria();

    // Operaciones
    vector<DataComentario> seleccionarUsuarioYListarComentarios(string nickname);
    void eliminarComentario(int id);
    vector<DataProducto> seleccionarUsuario(string nickname);
    void seleccionarProducto(int id);
    void seleccionarComentario(int Comentario);
    map<int, Comentario *> listarComentarios();

    void nuevoComentario(string text);
    void nuevoComentario(string text, DataFecha fecha);
    void realizarRespuesta(string text);
    void realizarRespuesta(string text, DataFecha fecha);
};

#endif