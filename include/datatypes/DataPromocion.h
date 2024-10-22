#ifndef DATAPROMOCION
#define DATAPROMOCION

// Tipos
#include <vector>
#include <string>

// Datatypes
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataPromoProducto.h"

using namespace std;

class DataPromocion {
    private:
        string nickname;
        string nombre;
        string descripcion;
        int descuento;
        DataFecha fechaVenc;
        vector<DataPromoProducto> productos;

    public:
        // Contructor 
        DataPromocion(string nickname, string nombre, string descripcion, int descuento, DataFecha fechaVencimiento, vector<DataPromoProducto> productos);
        
        //Getters
        string getNickname();
        string getNombre();
        string getDescripcion();
        int getDescuento();
        DataFecha getDataFecha();
        vector<DataPromoProducto> getDataPromoProductos();

        // Setters
        void setNickname(string n);

        // Operaciones
        void agregarDataProducto(DataPromoProducto producto);
        string toString();
        string toString2();

        // Destructor
        ~DataPromocion();
};

#endif