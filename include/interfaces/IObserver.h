#ifndef IOBSERVER
#define IOBSERVER

#include "../datatypes/DataPromocion.h"

#include <string>

using namespace std;


class IObserver {
    public:
        //Operaciones de Sistema
        virtual void agregarNotificacion(DataPromocion* promo) = 0;
};

#endif