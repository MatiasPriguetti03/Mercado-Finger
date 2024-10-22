#ifndef DATAINFOPROMO
#define DATAINFOPROMO

// Tipos
#include <vector>
#include <string>

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataInfoProducto.h"

using namespace std;

class DataInfoPromo {
    private:
       
        string nombre;
        string descripcion;
        int descuento;
        DataFecha fechaVenc;
        vector<DataInfoProducto> productos;
        

    public:
        // Contructor
        DataInfoPromo(string nombre, string descripcion, int descuento, DataFecha fechaVencimiento, vector<DataInfoProducto> productos);
        
        //Getters
        string getNombre();
        string getDescripcion();
        int getDescuento();
        DataFecha getDataFecha();
        vector<DataInfoProducto> obtenerDataInfoProducto();

        //Setters
        void setNickname(string n);
       
        // Operaciones
        string toString();
        void agregarDataInfoProducto(DataInfoProducto dp);

        // Destructor
        ~DataInfoPromo();
};

#endif