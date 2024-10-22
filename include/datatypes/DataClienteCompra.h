#ifndef DATACLIENTECOMPRA
#define DATACLIENTECOMPRA

// Tipos
#include <iostream>
#include <vector>
#include <string>

// Clases
#include "../classes/Compra.h"

using namespace std;

class DataClienteCompra{
    private:
        string nickname;
        Compra* compra;

    public:
        DataClienteCompra();
        DataClienteCompra(string nick, Compra* compra);

        //Getters
        string getNickname();
        Compra* getCompra();

        //Setters
        

        ~DataClienteCompra();
};

#endif