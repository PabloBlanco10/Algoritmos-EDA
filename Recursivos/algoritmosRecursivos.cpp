//
//  algoritmosRecursivos.cpp
//  
//
//  Created by Pablo Blanco Peris on 23/11/16.
//
//

#include <stdio.h>
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

////////////////ALGORITMOS RECURSIVOS//////////////////

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

// de decimal a binario
void decimalABinario(int n){
    int r = n % 2;
    
    if(n < 2)
        cout << n;
    else{
        decimalABinario(n/2);
        cout << r;
    }
}

// de binario a decimal
int binarioADecimal(int n){
    int r = n % 10;
    
    if(n < 2)
        r = n;
    else {
        r = (binarioADecimal(n/10) * 2) + r;
    }
    return r;
}

//ejercicio 16 Existe algun v[i] = i

bool dieciseis(int v[], int a, int b){
    int m = (a+b)/2;
    bool r;
    
    if (a > b)
        r = false;
    else{
        if(v[m] == m)
            r = true;
        else if(v[m] < m)
            r = dieciseis(v, m+1, b);
        else
            r = dieciseis(v, a, m-1);
    }
    return r;
}


// t(n):
//        - caso base si n = 0
//        - t (n/2) + c si n > 0
//t(n) pertenece O(log n)
//n = b - a + 1;


//mover n discos de a -> c usando b como auxiliar
void hanoi(int a, int b, int c, int n){
    if(n > 0){
        hanoi(a, c, b, n - 1);
        cout << a << " -> " << b << endl;
        hanoi(b ,a, c, n - 1);
    }
}
//llamada: hanoi(0,1,2,6);

void particion ( int v[], int a, int b, int & p) { // Pre: 0  a  b  longitud(v) 1
    int i, j; int aux;
    i = a+1; j = b;
    while ( i <= j ) {
        if ( (v[i] > v[a]) && (v[j] < v[a]) ) {
            aux = v[i]; v[i] = v[j]; v[j] = aux;
            i = i + 1; j = j - 1;
        }
        else {
            if ( v[i] <= v[a] ) i = i + 1; if ( v[j] >= v[a] ) j = j - 1;
        } }
    p = j;
    aux = v[a]; v[a] = v[p]; v[p] = aux;
}

void quickSort( int v[], int a, int b) {
    // Pre: 0  a  longitud(v) &&  1  b  longitud(v) 1 && a  b+1
    int p;
    if ( a <= b ) {
        particion(v, a, b, p);
        quickSort(v, a, p-1);
        quickSort(v, p+1, b);
    }
    // Post: v está ordenado entre a y b
}

// ejercicio 1
// lo ordeno con algoritmo de mezcla, lo recorro comparando la diferencia,
// y voy actualizando variables
// coste n log n : log n para ordenar y n para recorrer
// no se puede hacer en complejidad orden de n
void ejercicio1(int v[], int n, int i, int &primero, int &segundo, int &distMejor) {
    int dist;
    
    if(i <= n-1){
        dist = v[i] - v[i - 1];
        if(dist < distMejor){
            distMejor = dist;
            primero = v[i - 1];
            segundo = v[i];
        }
        ejercicio1(v, n, i+1, primero, segundo, distMejor);
    }
    
}

// ejercicio 2
// lo ordeno y cojo primero y ultimo
// si se puede hacer en orden de n, lo recorro y cojo el minimo y el maximo
void ejercicio2(int v[], int n, int i, int &primero, int &segundo){
    if(i == 0){
        primero = v[i];
        ejercicio2(v, n, i+1, primero, segundo);
    }
    else if (i == n-1)
        segundo = v[i];
    else
        ejercicio2(v, n, i+1, primero, segundo);
}


// ejercicio 7 dosfibonacci
// dosFib(10, r, s) ----- r = fib(10) --- s = fib(11)
// caso base = dosFib(0, 0, 1)



//ejercicio 17
int hostal(int v[], int n, int i, int &potDos){
    int m = (n / 2)-1;
    int r=0;
    
    if(i <= m){
        int aux = potDos * 2;
        r = v[i]*potDos + hostal(v,n,i+1, aux);
    }
    else if((i > m) && (i < n)){
        int aux = potDos / 2;
        r = v[i]*aux + hostal(v,n,i+1, aux);
    }
    return r;
    
}


//ejercicio 18
int complementario(int n){
    
    int r;
    if(n > 9){
        int digito = n%10;
        r = complementario(n/10) * 10 + (9 - digito);
    }
    else r = 9 - n;
    return r;
}
// Q = { r = 10 elevado a digitos(n) - 1 - n}

bool resuelve(){
    int n;
    //cout << 13 % 2 << endl << 10 / 10 << endl;
    cin >> n;
    int v[1000];
    int dist, distMejor, primero, segundo, potDos = 1;
    
    
    while(n>=0){
       // cout <<  binarioADecimal(n) << endl;
//        decimalABinario(n);
//        cout << endl;
//        cin >> n;
        cout << 146720 % 10;
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            v[j] = aux;
        }
        
        cout <<  hostal(v,n,0,potDos) << endl;
//        quickSort(v,0,n-1);
//        primero = v[0];
//        segundo = v[1];
//        distMejor = segundo - primero;
//        //ejercicio1(v, n, 1, primero, segundo, distMejor);
//        ejercicio2(v, n, 0, primero, segundo);
//        cout << "La mayor distancia es de: " << distMejor
//        << "   -    " << primero << " - " << segundo << endl;
//
//        if(dieciseis(v,n,0))
//            cout << "si" << endl;
//        else
//            cout << "no" << endl;
        
        cin >> n;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}