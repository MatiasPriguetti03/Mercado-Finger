#ifndef CONTROLADORPROMOCION
#define CONTROLADORPROMOCION

// Tipos
#include <string>
#include <vector>

// Interfaces
#include "../interfaces/IPromocion.h"

// Datatypes
#include "../datatypes/DataCompra.h"
#include "../datatypes/DataProducto.h"
#include "../datatypes/DataPromoProducto.h"
#include "../datatypes/DataFecha.h"
#include "../datatypes/DataPromocion.h"
#include "../datatypes/DataInfoPromo.h"


#include "../classes/Vendedor.h"
#include "../classes/Promocion.h"
#include "../system/FechaSistema.h"



// Controladores
#include "ControladorUsuario.h"
#include "ControladorProducto.h"


using namespace std;

class ControladorPromocion : public IPromocion {
    private:
        static ControladorPromocion* instancia;
        ControladorPromocion();
        vector<Promocion*> promocionesGlobales;
        vector<DataInfoPromo> promociones; 
        
        // Pseudo atributos
        

        // Memoria
        DataPromocion*  dataPromocion;
        DataInfoPromo* dataInfoPromo;
       

    public:
        static ControladorPromocion* getInstance();

        void ingresarPromocion(string nombre, string descripcion, int descuento, DataFecha fechaVencimiento);
        void seleccionarVendedor(string nickname);
        vector<DataProducto> mostrarProductos();
        void agregarProducto(int codeProd, int cant);
        void darAltaPromocion(); 
        float aplicarPromociones(vector<DataProductoCompra> productos);
        vector<DataInfoPromo> listarPromociones(); 
        DataPromocion seleccionarYConsultarPromocion(string nombre);
};

#endif