// Controlador.h
#include "../../include/controllers/ControladorUsuario.h"

// Contructor
ControladorUsuario :: ControladorUsuario()
    : usuarios(map<string, Usuario*>()) {};

// Singelton
ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario* ControladorUsuario::getInstance(){
    if (instancia == NULL) {
        instancia = new ControladorUsuario();
    }
    return instancia;
};

// Crear
int ControladorUsuario::crearCliente(string nickname, string contrasenia, DataFecha fechaNac, string calle, int numeroPta, string ciudad){
    if (this->usuarios.count(nickname) > 0 ) { return -1; }
    if (contrasenia.length() < 6 ) { return -2; }

    Cliente* cliente = new Cliente(nickname, contrasenia, fechaNac, calle, numeroPta, ciudad);
    this->usuarios.insert(make_pair(nickname, cliente));
    return 0;
}

int ControladorUsuario::crearVendedor(string nickname, string contrasenia, DataFecha fechaNac, string rut) {
    if (this->usuarios.count(nickname) > 0 ) { return -1; }
    if (contrasenia.length() < 6 ) { return -2; }
    if (rut.length() != 12 ) { return -3; }

    Vendedor* vendedor = new Vendedor(nickname, contrasenia, fechaNac, rut);
    this->usuarios.insert(make_pair(nickname, vendedor));
    return 0;
}

// Obtener
Usuario* ControladorUsuario::obtenerUsuario(string nickname){
    auto it = this->usuarios.find(nickname);
    if (it != usuarios.end()) {
        return it->second;
    }
    return nullptr;
}

// Mostrar
DataUsuario* ControladorUsuario::mostrarExpedienteUsuario(string nickname) {
    return this->usuarios.find(nickname)->second->getExpediente();
};

// Listar
set<string> ControladorUsuario::listarUsuarios(){
    set<string> nicknames_usuarios;
    for (auto &usuario : this->usuarios) {
        nicknames_usuarios.insert(usuario.first);
    }
    return nicknames_usuarios;
}

set<string> ControladorUsuario::listarClientes() {
    set<string> nicknames_clientes;
    for (auto &usuario : this->usuarios) {
        Cliente* cliente = dynamic_cast<Cliente*>(usuario.second);
        if (cliente != nullptr) {
            nicknames_clientes.insert(usuario.first);
        }
    }
    return nicknames_clientes;
}

set<string> ControladorUsuario::listarVendedores() {
    set<string> nicknames_vendedores;
    for (auto &usuario : this->usuarios) {
        Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario.second);
        if (vendedor != nullptr) {
            nicknames_vendedores.insert(usuario.first);
        }
    }
    return nicknames_vendedores;
}

vector<DataUsuario*> ControladorUsuario::listarInfoUsuarios() {
    vector<DataUsuario*> dataInfoUsuarios; 
    for (const auto& user : this->usuarios) {
        dataInfoUsuarios.push_back(user.second->getDataInfoUsuario());
    }
    return dataInfoUsuarios;
}

// Suscripciones
void ControladorUsuario::suscribirse(string nickname){
    auto it = usuarios.find(this->nickC);
    if (it != usuarios.find(nickname)) {
        IObserver* suscriptor = dynamic_cast<IObserver*>(it->second);

        auto it = usuarios.find(nickname);
        if (it != usuarios.end()) {
            Vendedor* vendedor = dynamic_cast<Vendedor*>(it->second);
            vendedor->agregarSubscriptor(suscriptor);
            this->nickC = "";
        }
    }
}

set<string> ControladorUsuario::listarSuscripcionesCliente(string nickname) {
    set<string> res;

    this->nickC = nickname;

    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        IObserver* cliente = dynamic_cast<IObserver*>(it->second);
        if (cliente != nullptr) {
            for (auto& usuario : this->usuarios) {
                Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario.second);
                if (vendedor && vendedor->estaSubscripto(cliente)) {
                    res.insert(vendedor->getNickname());
                }
            }
        }
    }

    return res;
}

set<string> ControladorUsuario::listarVendedoresNoSuscritoCliente(string nickname) {
    set<string> res;
    this->nickC = nickname;

    Cliente* c = dynamic_cast<Cliente*>(obtenerUsuario(nickname));

    if (this->usuarios.count(nickname) > 0) {
        for (auto it : usuarios) {
            Vendedor* vendedor = dynamic_cast<Vendedor*>(it.second);
            if (vendedor && !vendedor->estaSubscripto(c)) { 
                res.insert(vendedor->getNickname());
            }
        }
    }
   
    return res;
}

vector<DataPromocion *> ControladorUsuario::listarNotificacionesYEliminar(string nickname) {
    vector<DataPromocion *> notificaciones;

    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        Cliente* c = dynamic_cast<Cliente*>(it->second);
        notificaciones = c->listarNotificaciones();
    }

    return notificaciones;
}

vector<DataProducto> ControladorUsuario::listarProductosVendedorNoEnviados(string nickname){
    vector<DataProducto*> productosV;
    vector<DataProducto> res;
    //Obtengo todos los productos del vendedor
    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        Vendedor* vendedor = dynamic_cast<Vendedor*>(it->second);
        productosV = vendedor-> getProductos();
        map<int, vector<DataClienteCompra> > mapa;
        //Para cada uno de los productos del vendedor
        for(DataProducto* dp: productosV){
            //Vector que tendra todas las compras que poseen al producto con envio pendiente
            vector<DataClienteCompra> comprasDeProducto;
            //Recorro todos los usuarios
            for(auto &usuario : this->usuarios){
                Cliente* cliente = dynamic_cast<Cliente*>(usuario.second);
                //Cuando encuentro un cliente
                if (cliente != nullptr) {
                    vector<DataClienteCompra> comprasDeProductoCliente;
                    //Devuelve un vector con todas las compras del cliente que poseen al producto con envio pendiente
                    comprasDeProductoCliente = cliente-> getVectorClienteCompras(dp-> getCode());
                    if (!comprasDeProductoCliente.empty()){
                        //Concateno el vector que recibi a comprasProducto
                        comprasDeProducto.insert(comprasDeProducto.end(), comprasDeProductoCliente.begin(), comprasDeProductoCliente.end());
                    }   
                }
            }
            if (!comprasDeProducto.empty()){
                //Si tengo alguna compra con envio pendiente para el producto, agrego el producto a la rspuesta y el vector con las compras al mapa
                //siendo su clave el codeProd
                res.push_back(*dp);
                mapa.insert(make_pair(dp-> getCode(), comprasDeProducto));
            }
        }
        //Guardo mapa en memoria
        this-> mapaProductosNoEnviados = mapa; //Puede dar problemas
    }else{
        cout << "Nickname invalido";
    }
    return res;   
}

vector<DataEnvio> ControladorUsuario::listarComprasProductoNoEnviado(int codeProd){
    //Guardo CodeProd en memoria
    this-> codeProdNoEnviado = codeProd;
    //Utilizo codeProd para buscar en el mapa en memoria todas las compras pendientes asociadas a ese producto
    vector<DataClienteCompra> comprasP = this-> mapaProductosNoEnviados.find(codeProd)-> second;
    vector<DataEnvio> res;
    for (DataClienteCompra dcc : comprasP){
        string nickCliente = dcc.getNickname();
        DataFecha fechaCompra = dcc.getCompra()-> getFecha();
        DataEnvio de = DataEnvio(nickCliente, fechaCompra);
        res.push_back(de);
    }
    return res;
}

void ControladorUsuario::marcarEnviado(int indice){
    //Accedo al DataClienteCompra obteniendo el vector de producto del mapa, y accediendo a la posicion indice (vector[indice])
    DataClienteCompra dcc = (this-> mapaProductosNoEnviados.find(this-> codeProdNoEnviado)-> second)[indice];
    CompraProducto* cp = dcc.getCompra()-> getCompraProducto(this-> codeProdNoEnviado);
    cp-> enviar();
    //Borro memoria del caso de uso
    this-> codeProdNoEnviado = 0;
    for (auto &it: this-> mapaProductosNoEnviados){
        it.second.clear();
    }
    this-> mapaProductosNoEnviados.clear();
}

void ControladorUsuario::eliminarSuscripcion(string nickname) {
    auto it = usuarios.find(nickname);                                  // Busca el vendedor en la lista de usuarios
    if (it != usuarios.end()) {                                         // Si encuentra al vendedor
        Vendedor* vendedor = dynamic_cast<Vendedor*>(it->second);       // Cast Usuario a Vendedor
        vendedor->eliminarSubscriptor(this->nickC);                     // Eliminar al cliente de los suscriptores del vendedor
        this->nickC = "";                                               // "Libera memoria" asociada al nickname cliente
    }
}