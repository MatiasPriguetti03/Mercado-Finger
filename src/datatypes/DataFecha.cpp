// Datatype.h
#include "../../include/datatypes/DataFecha.h"

// Constructor
DataFecha::DataFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio){}

// Getters
int DataFecha::getDia() {
    return this->dia;
}

int DataFecha::getMes() {
    return this->mes;
}

int DataFecha::getAnio() {
    return this->anio;
}

// Operaciones
string DataFecha::toString() {
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio) ;
}

bool operator>(DataFecha& fecha1, DataFecha& fecha2) {
    if (fecha1.getAnio() > fecha2.getAnio()) {
        return true;
    } else if (fecha1.getAnio() == fecha2.getAnio()) {
        if (fecha1.getMes() > fecha2.getMes()) {
            return true;
        } else if (fecha1.getMes() == fecha2.getMes()) {
            if (fecha1.getDia() >= fecha2.getDia()) {
                return true;
            }
        }
    }
    return false;
}

bool operator<(DataFecha& fecha1, DataFecha& fecha2) {
    if (fecha1.getAnio() < fecha2.getAnio()) {
        return true;
    } else if (fecha1.getAnio() == fecha2.getAnio()) {
        if (fecha1.getMes() < fecha2.getMes()) {
            return true;
        } else if (fecha1.getMes() == fecha2.getMes()) {
            if (fecha1.getDia() < fecha2.getDia()) {
                return true;
            }
        }
    }
    return false;
}

// Destructor
DataFecha::~DataFecha() {}
