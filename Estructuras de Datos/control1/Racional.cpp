#include "Racional.h"
#include <cmath>

  //Metodos publicos

  	//**** COMPLETAR

Racional::Racional(long numer, long denom){
    _numer = numer;
    _denom = denom;
}


Racional::suma(Racional arg2){
    long denominador = mcm(_denom, arg2._denom);
    long numerador1 = (denominador/ _denom) * _numer;
    long numerador2 = (denominador/ arg2._denom) * arg2._numer;
    Racional r = Racional(denominador, numerador2+numerador1);
    reduce(r);
    return r;
}

Racional Racional::operator -(const Racional arg2) const {
    long denominador = mcm(_denom, arg2._denom);
    long numerador1 = (denominador/ _denom) * _numer;
    long numerador2 = (denominador/ arg2._denom) * arg2._numer;
//    _numer = numerador1 - numerador2;
//    _denom = denominador;
    Racional r = Racional(numerador1 - numerador2, denominador);
    reduce(r);
    return r;
}

void Racional::operator *=(const Racional arg2) const {
    /////////////////////////////// se actualiza
    _numer *= arg2._numer;
    _denom *= arg2._denom;
    reduce(this);
}

void Racional::divideYActualiza(Racional arg2){
    
    if((arg2._numer == 0) && (arg2._denom == 1)){
        throw EDivisionPorCero();
    }
    else{
        _numer *= arg2._denom;
        _denom *= arg2._numer;
        reduce(this);
    }
}


bool Racional::operator==(const Racional arg2){
    return (_denom == arg2._denom) && (_numer == arg2._numer);
}
 
  
// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

