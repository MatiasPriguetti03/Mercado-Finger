// Clase.h
#include "../../include/classes/Vendedor.h"
#include "../../include/system/Operaciones.h"

// Constructor
Vendedor::Vendedor(string nickname, string contrasenia, DataFecha fechaNacimiento, string rut) : Usuario(nickname, contrasenia, fechaNacimiento) {
    this->rut = rut;
    this->productos = map<int, Producto *>();
    this->promociones = vector<Promocion *>();
    this->subcriptores = map<string, IObserver*>();
};

// Destructor
Vendedor::~Vendedor(){

};

// getters
vector<DataProducto *> Vendedor::getProductos() {
    vector<DataProducto*> res;
    map<int, Producto *>::iterator prodIterator;

    for (prodIterator = this->productos.begin(); prodIterator != this->productos.end(); prodIterator++) {
        Producto* producto = prodIterator->second; // Accede al puntero de Producto
        if(producto != nullptr){
            DataProducto dataProd = producto->getDataProducto();
            // Creo el dataProducto en el heap
            DataProducto* dataProdPtr = new DataProducto(dataProd.getCode(),dataProd.getNombre());
            res.push_back(dataProdPtr);
        }
    }
    
    return res;
};

DataUsuario* Vendedor::getDataInfoUsuario() {
    return new DataVendedor(this->getNickname(), this->getFechaNacimiento(), this->rut);
};

DataUsuario* Vendedor::getExpediente() {
    vector<DataInfoProducto> productos;
    for (auto &producto : this->productos) {
        productos.push_back(producto.second->getInfoProducto());
    }
    vector<DataPromocion> promociones;
    for (Promocion* &promocion : this->promociones) {
        promociones.push_back(promocion->getDataPromocion());
    }
    return new DataExpedienteVendedor(this->getNickname(), this->getFechaNacimiento(), this->rut, productos, promociones);
};

// Operaciones

// Devuelve los productos del vendedor
vector<DataProducto> Vendedor::obtenerDataProductos() {
    vector<DataProducto> res;
    for(auto& p: this-> productos){
        res.push_back(p.second ->getDataProducto());
    }
    // map<string, Usuario *>::iterator usuario;
    // ControladorUsuario *userController = ControladorUsuario::getInstancia();
    // map<string, Usuario *> user = userController->getUsuarios();
    // usuario = user.find(nickname);

    // if (usuario != user.end()) {
    //     Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario->second);
    //     if (vendedor) {
    //         return vendedor->getProductos();
    //     } else {
    //         // Si el casteo no es exitoso devuelvo lista vacia
    //         return vector<DataProducto *>();
    //     }
    // } else {
    //     // Si no se encuentra el vendedor devuelvo lista vacia
    return res;
};

void Vendedor::agregarProducto(Producto* prod) {
    this->productos.insert(make_pair(prod->getCode(), prod));
};

// Agrega y asocia una promocion al vendedor
void Vendedor::agregarPromocion(Promocion* promo, vector<DataPromoProducto> prodPromo) {
    this->promociones.push_back(promo);

    vector<DataPromoProducto>::iterator prodPromoIterator;
    map<int, Producto *>::iterator prodVendedorIterator;

    for (prodPromoIterator = prodPromo.begin(); prodPromoIterator != prodPromo.end(); prodPromoIterator++) {
        int codeProd = prodPromoIterator->getCode();
        int cantProd = prodPromoIterator->getCant();

        prodVendedorIterator = this->productos.find(codeProd);

        promo->agregarProducto(prodVendedorIterator->second, cantProd);
    }
};

// Lista todos los vendedores pertenecientes al controlador
vector<string> Vendedor::listarVendedores() {
    // ControladorUsuario *userController = ControladorUsuario::getInstance();
    // return userController->listarVendedores();
    return vector<string>();
};

// Notifica a los suscriptores sobre la creacion de una promo
void Vendedor::notificarPromo(DataPromocion* promo) {
    map<string, IObserver *>::iterator susIterator;

    for (susIterator = this->subcriptores.begin(); susIterator != this->subcriptores.end(); susIterator++) {
        IObserver* suscriptor = susIterator->second;
        suscriptor->agregarNotificacion(promo);
    }
};

// Consulta si un cliente esta suscripto al vendedor
bool Vendedor::estaSubscripto(IObserver *cliente) {
    Usuario *userSuscriptor = dynamic_cast<Usuario *>(cliente);
    string nickSuscriptor = userSuscriptor->getNickname();
    //IObserver *obsSuscriptor = dynamic_cast<IObserver *>(userSuscriptor);

    map<string, IObserver *>::iterator susIterator;
    susIterator = this->subcriptores.find(nickSuscriptor);

    if (susIterator != this->subcriptores.end()) {
        return true;
    }

    return false;
};

// Agrega un suscriptor al vector
void Vendedor::agregarSubscriptor(IObserver *cliente) {
    Usuario* userSuscriptor = dynamic_cast<Usuario*>(cliente);
    string nickSuscriptor = userSuscriptor->getNickname();
    IObserver *obsSuscriptor = dynamic_cast<IObserver *>(userSuscriptor);
    this->subcriptores.insert(pair<string, IObserver *>(nickSuscriptor, obsSuscriptor));
};

// Elimina un suscriptor del vector
void Vendedor::eliminarSubscriptor(string nickname) {
    this->subcriptores.erase(nickname);
}
