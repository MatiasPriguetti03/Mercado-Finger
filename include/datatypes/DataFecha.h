#ifndef DATAFECHA
#define DATAFECHA

// Tipos
#include <string>

using namespace std;

class DataFecha {
    private:
        int dia;
        int mes;
        int anio;

    public:
        // Constructor
        DataFecha(int dia, int mes, int anio);

        // Getters
        int getDia();
        int getMes();
        int getAnio();

        // Operaciones
        string toString();
        friend bool operator>(DataFecha& fecha1, DataFecha& fecha2);
        friend bool operator<(DataFecha& fecha1, DataFecha& fecha2);

        // Destructor
        ~DataFecha();
};

#endif