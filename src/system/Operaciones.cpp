#include "../../include/system/Operaciones.h"

using namespace std;

// Output
void print(string texto) {
    cout << texto << endl;
};

void saltoConsola() {
    cout << endl;
}

void printSet(set<string> nicknames){
    for(const string &nickname : nicknames){
        cout << "    -> " << nickname << endl;
    }
};


// Input
string getInputString(string mensaje) {
    cout << mensaje;
    string valor;
    cin >> valor;
    return valor;
};

int getInputInt(string mensaje) {
    cout << mensaje;
    int valor;
    cin >> valor;
    return valor;
};

float getInputFloat(string mensaje) {
    cout << mensaje;
    float valor;
    cin >> valor;
    return float(valor);
};

string getInputOracion(string mensaje) {
    cout << mensaje;
    string oracion;
    getline(cin,oracion);
    string valor;
    getline(cin,valor);
    return valor;
};

DataFecha getInputFecha(string mensaje) {
    cout << mensaje;
    string valor;
    cin >> valor;

    stringstream fechaInput(valor);
    string dia, mes, anio;

    getline(fechaInput, dia, '/');
    getline(fechaInput, mes, '/');
    getline(fechaInput, anio, '/');

    return DataFecha(stoi(dia),stoi(mes),stoi(anio));
};

CategoriaProducto getInputCategoria(){
    cout << "Ingrese a que categoria corresponde su producto:\n 1- Ropa\n 2- Electrodomestico\n 3- Otro\n";
    int valor;
    cin >> valor;
    CategoriaProducto cat;
    if (valor == 1) {
        cat = CategoriaProducto::ropa;
    } else if (valor == 2){
        cat = CategoriaProducto::electrodomestico;
    } else {
        cat = CategoriaProducto::otros;
    }
    return cat;
};