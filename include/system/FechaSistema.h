#ifndef FECHASISTEMA
#define FECHASISTEMA

#include "../../include/datatypes/DataFecha.h"

class FechaSistema {
    private:
        DataFecha fecha;

        // Singelton
        static FechaSistema* instancia;

        // Contructor
        FechaSistema();

        // Destructor
        ~FechaSistema();
            
    public:
        // Singelton
        static FechaSistema* getInstance();

        // Getters
        DataFecha getFecha();

        // Setters
        void setearFechaSistema(DataFecha fechaActual); 
};

#endif