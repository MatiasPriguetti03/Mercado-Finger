
#ifndef OPERACIONES
#define OPERACIONES

#include <string>
#include <set>
#include <iostream>
#include <sstream>

#include "../datatypes/CategoriaProducto.h"
#include "../datatypes/DataFecha.h"

using namespace std;

// Output
void print(string texto);

void saltoConsola();

void printSet(set<string> nicknames);


// Input
string getInputString(string mensaje);

int getInputInt(string mensaje);

float getInputFloat(string mensaje);

string getInputOracion(string mensaje);

DataFecha getInputFecha(string mensaje);

CategoriaProducto getInputCategoria();

bool confirmacion (int L);


#endif