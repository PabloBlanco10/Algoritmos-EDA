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

bool dieciseis(int v[], int n, int i){
    bool r;
    
    if(v[i] == i)
        return true;
    else if (i < n - 1){
        i++;
        r = dieciseis(v, n, i);
    }
    else if(i >= n)
        return false;
    return r;
}


// ejercicio 1
// lo ordeno con algoritmo de mezcla, lo recorro comparando la diferencia,
// y voy actualizando variables
// coste n log n : log n para ordenar y n para recorrer
// no se puede hacer en complejidad orden de n


// ejercicio 2
// lo ordeno y cojo primero y ultimo
// si se puede hacer en orden de n, lo recorro y cojo el minimo y el maximo


// ejercicio 7 dosfibonacci
// dosFib(10, r, s) ----- r = fib(10) --- s = fib(11)
// caso base = dosFib(0, 0, 1)



bool resuelve(){
    int n;
    //cout << 13 % 2 << endl << 10 / 10 << endl;
    cin >> n;
    int v[1000];
    
    
    while(n>=0){
       // cout <<  binarioADecimal(n) << endl;
//        decimalABinario(n);
//        cout << endl;
//        cin >> n;
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            v[j] = aux;
        }
        
        if(dieciseis(v,n,0))
            cout << "si" << endl;
        else
            cout << "no" << endl;
        
        cin >> n;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}