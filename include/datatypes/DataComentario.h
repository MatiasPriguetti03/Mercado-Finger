#ifndef DATACOMENTARIO 
#define DATACOMENTARIO

// Tipos
#include <string>

using namespace std;

class DataComentario {
    private:
        int id;
        string text;

    public:
        // Constructor
        DataComentario();
        DataComentario(int id, string text);

        // Destructor
        ~DataComentario();

        // Getters
        int getId();
        string getText();

        // Operaciones
        string toString();
};

#endif