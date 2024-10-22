// Datatypes.h
#include "../../include/datatypes/DataComentario.h"

// Constructor
DataComentario::DataComentario(){};
DataComentario::DataComentario(int id, string text)
    : id(id), text(text) {};

// Destructor 
DataComentario::~DataComentario(){}

// Getters
int DataComentario::getId(){
    return this->id;
};
string DataComentario::getText(){
    return this->text;
};

string DataComentario::toString() {
    return "    - Codigo : " + to_string(this->id) + "\n"
           "    - Texto : " + this->text + "\n";
}