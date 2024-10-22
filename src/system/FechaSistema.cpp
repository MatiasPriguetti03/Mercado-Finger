#include "../../include/system/FechaSistema.h"

// Contructor
FechaSistema::FechaSistema() 
    : fecha(DataFecha(0,0,0)) {};
 
// Singelton
FechaSistema* FechaSistema::instancia = NULL;

FechaSistema* FechaSistema::getInstance() {
    if (instancia == NULL) {
        instancia = new FechaSistema();
    }
    return instancia;
};

// Getters
DataFecha FechaSistema::getFecha(){
    return this->fecha;	
};

// Setters
void FechaSistema::setearFechaSistema(DataFecha fechaActual) {
    this->fecha = fechaActual;
};

// Destructor
FechaSistema::~FechaSistema() {};