#include <iostream>

#include "arreglo.h"

using namespace std;

int main() {

    ArregloDinamico<string> arreglo;

    cout << "Insertar cadenas con insertar_inicio() e insertar_final()" << endl;
    arreglo.insertarInicio("cadena_02_al_inicio");
    arreglo.insertarInicio("cadena_01_al_inicio");
    arreglo.insertarFinal("cadena_01_al_final");
    arreglo.insertarFinal("cadena_02_al_final");

    for(size_t i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << endl;
    }    

    cout << endl << "Insertar cadena con insertar() en la posición 2" << endl;
    arreglo.insertar("cadena_01_con_insertar()", 2);

    for(size_t i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << endl;
    }

    cout << endl << "Eliminar con eliminar_inicio(), eliminar_final() y eliminar()" << endl;
    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    arreglo.eliminar(1);

    for(size_t i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << endl;
    }

    return 0;
}