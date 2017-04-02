#include <iostream>
using namespace std;
#include <string>
#include "lista.h"
#include "pila.h"

bool esVocal(char a){
	return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
}

void colocaLista(Lista<char> &mensaje, Pila<char> &pila, Lista<char>::Iterator it){
	while (!pila.esVacia()){
		mensaje.insertar(pila.cima(), it);
		pila.desapila();
	}
}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	Pila<char> pila = Pila<char>();
	char a;
	int cont = 0;
	bool salir = false;
	Lista<char>::Iterator it = mensaje.begin();
	
	while (!salir){
		a = it.elem();
		if (esVocal(a)){
			colocaLista(mensaje, pila, it);
			it.next();
		}
		else{
			pila.apila(a);
			it = mensaje.eliminar(it);
			if (it == mensaje.end()){
				salir = true;
				if (!pila.esVacia()){
					colocaLista(mensaje, pila, it);
				}
			}
		}
	}
}

// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	Lista<char>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem();
		it.next();
	}
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	//invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();    // Esta operacion debe ser implementada como
	// un nuevo metodo de Lista
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}