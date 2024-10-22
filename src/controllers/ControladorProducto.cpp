// Controlador.h
#include "../../include/controllers/ControladorProducto.h"

// Contructor
ControladorProducto::ControladorProducto() {
        this-> clavePrimaria = 0;
        this-> nicknameVendedor = NULL;
        this-> productos = map<int, Producto*> ();
}

// Singelton
ControladorProducto* ControladorProducto::instancia = NULL;

ControladorProducto* ControladorProducto::getInstance() {
    if (instancia == NULL) {
        instancia = new ControladorProducto();
    }
    return instancia;
};

// Crear
void ControladorProducto::crearProducto(string nombre, float precio, int stock, string descripcion, CategoriaProducto categoria) {
    this->clavePrimaria ++;
    Producto* producto = new Producto(this->clavePrimaria, stock, precio, nombre, descripcion, categoria);
    this->productos.insert(make_pair(this->clavePrimaria, producto));
    ControladorUsuario* controlUser = ControladorUsuario::getInstance();
    Vendedor* vendedor =  dynamic_cast<Vendedor*>(controlUser->obtenerUsuario(*this->nicknameVendedor));
    vendedor->agregarProducto(producto);
    //this->dataInfoProducto = DataInfoProducto(producto->getCode(), nombre, descripcion, precio, stock, categoria);
    delete this->nicknameVendedor;
};

// Seleccionar
void ControladorProducto::seleccionarVendedor(string nickname) {
    this->nicknameVendedor = new string(nickname);
};

// Obtener
Producto* ControladorProducto::obtenerProducto(int codeProd) {
    Producto* res = NULL;
    if (this->productos.find(codeProd) != this->productos.end()){
        res = this->productos.find(codeProd)->second;
    }
    return res;
};



DataProducto ControladorProducto::obtenerDataProducto(int codeProd) {
    return this->productos.find(codeProd)->second->getDataProducto();
};

DataPromoProducto ControladorProducto::obtenerDataPromoProducto(int codeProd, int cant) {
    DataProducto dp = this->productos.find(codeProd)->second->getDataProducto();
    return DataPromoProducto(dp.getCode(), dp.getNombre(), cant);
};

DataProductoCompra ControladorProducto::obtenerDataProductoCompra(int codeProd, int cant) {
    DataProducto dp = this->productos.find(codeProd)->second->getDataProducto();
    return DataProductoCompra(dp.getCode(), dp.getNombre(), this->productos.find(codeProd)->second->getPrecio(), cant);
};

// Mostrar
DataInfoProducto ControladorProducto::mostrarProducto(int codeProd) {
    return this->productos.find(codeProd)->second->getInfoProducto();
};

// Listar
vector<DataProducto> ControladorProducto::listarProductos() {
    vector<DataProducto> dataProductos;
    for (map<int,Producto*>::iterator prod = this->productos.begin(); prod != this->productos.end(); ++prod) {
        dataProductos.push_back(prod->second->getDataProducto());
    }
    return dataProductos;
};

DataInfoProducto ControladorProducto :: obtenerDataInfoProducto(){//falta
    DataInfoProducto producto = this->dataInfoProducto;
    return producto;
};

// Destructor
//ControladorProducto::~ControladorProducto() {};