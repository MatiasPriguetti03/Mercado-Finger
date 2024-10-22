#include "../../include/controllers/ControladorPromocion.h"
#include "../../include/system/Operaciones.h"

ControladorPromocion* ControladorPromocion::instancia = NULL;

ControladorPromocion* ControladorPromocion::getInstance(){
    if (instancia == NULL){
        return instancia = new ControladorPromocion();
    }
    return instancia;    
};

//Constructor
ControladorPromocion :: ControladorPromocion()
    : promocionesGlobales(vector<Promocion*>()), dataPromocion(NULL){};


// Operaciones
void ControladorPromocion :: ingresarPromocion(string nombre, string descripcion, int descuento, DataFecha fechaVencimiento) {
    this->dataPromocion = new DataPromocion("", nombre, descripcion, descuento, fechaVencimiento, vector<DataPromoProducto> ());
    this->dataInfoPromo = new DataInfoPromo(nombre, descripcion, descuento, fechaVencimiento, vector<DataInfoProducto> ());
};

void ControladorPromocion :: seleccionarVendedor(string nickname){
    this->dataPromocion->setNickname(nickname);
};

//Mostrar Productos//
vector<DataProducto> ControladorPromocion :: mostrarProductos(){
    ControladorUsuario* CUser = ControladorUsuario::getInstance();
    Vendedor* vendedor =  dynamic_cast<Vendedor*>(CUser->obtenerUsuario(this->dataPromocion->getNickname()));
    return vendedor->obtenerDataProductos();
    
};


//Agregar Producto//
void ControladorPromocion :: agregarProducto(int codeProd, int cant){
    ControladorProducto* CProd = ControladorProducto ::getInstance();
    DataPromoProducto dp = CProd->obtenerDataPromoProducto(codeProd, cant);
    this->dataPromocion->agregarDataProducto(dp);
    DataInfoProducto dip = CProd->obtenerDataInfoProducto();
    this->dataInfoPromo->agregarDataInfoProducto(dip);
};

//Aplicar//
float ControladorPromocion :: aplicarPromociones(vector<DataProductoCompra> productos){
    FechaSistema* fechaSistema = FechaSistema::getInstance();
    float totalConDescuentos = 0; 
    for (vector<Promocion*>::iterator it = promocionesGlobales.begin(); it != promocionesGlobales.end(); ++it){      
        if ((*it)->estaVigente(fechaSistema->getFecha())){
            totalConDescuentos += (*it)->aplicarPromocion(productos);
        }       
    }
    return totalConDescuentos;  
};
    
//Dar de Alta//
void ControladorPromocion :: darAltaPromocion(){
    Promocion* promocion = new Promocion(this->dataPromocion->getNickname(), this->dataPromocion->getNombre(),this->dataPromocion->getDescripcion(), this->dataPromocion->getDescuento(),this->dataPromocion->getDataFecha());  
    ControladorUsuario* CUser = ControladorUsuario::getInstance(); 
    Vendedor* vendedor =  dynamic_cast<Vendedor*>(CUser->obtenerUsuario(this->dataPromocion->getNickname()));   
    vendedor->agregarPromocion(promocion,this->dataPromocion->getDataPromoProductos());  
    

    this->promocionesGlobales.push_back(promocion); 
    vendedor->notificarPromo(this->dataPromocion);
    this->promociones.push_back(*this->dataInfoPromo);
    this->dataPromocion = NULL;
    this->dataInfoPromo = NULL;
};

//Listar Promociones//
vector<DataInfoPromo> ControladorPromocion :: listarPromociones(){ 
    FechaSistema* fechaSistema = FechaSistema::getInstance();
    vector<DataInfoPromo> promocionesVigentes;
    for (vector<Promocion*>::iterator it = promocionesGlobales.begin(); it != promocionesGlobales.end(); ++it){
        if ((*it)->estaVigente(fechaSistema->getFecha())){
            promocionesVigentes.push_back((*it)->getDataInfoPromo());
        }
    }
    return promocionesVigentes;
};

//Seleccionar y Consultar Promocion//
DataPromocion ControladorPromocion :: seleccionarYConsultarPromocion(string nombre){
    vector<Promocion*> :: iterator it = promocionesGlobales.begin();
    for (; it != promocionesGlobales.end(); ++it){
        if ((*it)->getNombre() == nombre){
            break;
        }
    }  
    DataPromocion dataPromo =  (*it)->getDataPromocion(); 
    return dataPromo;
};
