//
//  EjemploPila.cpp
//
//
//  Created by Pablo Blanco Peris on 7/3/17.
//
//

#include <stdio.h>

template<class T>
class Pila{
    class EPilaVacia();
    
    Pila(){
        _elems = new T[TAM];
        _nelems = 0;
        _tam = TAM;
    }
    
    
    bool esVacia(){
        return _nelems == 0;
;
    }
    
    const T& cima() const{
        if(_nelems == 0)
            throw EPilaVacia();
        else
            return _elems[_nelems - 1];
    }
    
    void apila(const T& elem){
        _elems[_nelems] = elem;
        _nelems++;
        
        if(_nelems == _tam){
            _tam = 2 * _tam;
            T *nuevo = new T[2 * _tam];
            for(int i = 0; i < _nelems; i++){
                nuevo[i] = _elems[i];
            }
            delete[] _elems;
            _elems = nuevo;
        }
    }
    
    void desapila(){
        
        if(_nelems == 0) throw EPilaVacia();
        else {
            _nelems--;
            
        
        }
        
    }
    
    
private:
    
    static int TAM = 100;
    T* _elems;
    int _nelems;
    int _tam;
    
//    class Nodo{
//        T _elem;
//        Nodo* _sig;
//        Nodo(const T& elem){
//            _elem = elem;
//            _sig = NULL;
//        }
//    };
//    Nodo* _cima;
};