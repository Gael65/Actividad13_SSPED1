#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

//Definición
template <class T>
class ArregloDinamico {
private:
    T *arreglo;
    size_t tam;
    size_t contador;
    const static size_t MAX = 5;

    void expandir();
public:
    ArregloDinamico();
    ~ArregloDinamico();

    void insertarFinal(const T& v);
    void insertarInicio(const T& v);
    void insertar(const T& v, size_t p);
    
    size_t size();

    string operator[](size_t p) {
        return arreglo[p];
    }
};

//Implementación
template <class T>
ArregloDinamico<T>::ArregloDinamico() {
    arreglo = new T[MAX];
    contador = 0;
    tam = MAX;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico() {
    delete[] arreglo;
}

template <class T>
void ArregloDinamico<T>::expandir() {
    T *nuevo = new T[tam + MAX];

    for(size_t i = 0; i < contador; i++) {
        nuevo[i] = arreglo[i];
    }

    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

template <class T>
size_t ArregloDinamico<T>::size() {
    return contador;
}

template<class T>
void ArregloDinamico<T>::insertarFinal(const T &v) {
    if(contador == tam) {
        expandir();
    }

    arreglo[contador] = v;
    contador++;
}

template<class T>
void ArregloDinamico<T>::insertarInicio(const T &v) {
    if(contador == tam) {
        expandir();
    }

    for(size_t i = contador; i > 0; i--) {
        arreglo[i] = arreglo[i - 1];
    }  

    arreglo[0] = v;
    contador++; 
}

template<class T>
void ArregloDinamico<T>::insertar(const T& v, size_t p) {
    if(p >= contador) {
        cout << "Posición inválida..." << endl;
        return;
    }

    if(contador == tam) {
        expandir();
    }  

    for(size_t i = contador; i > p; i--) {
        arreglo[i] = arreglo[i - 1];
    }  

    arreglo[p] = v;
    contador++;
}

#endif