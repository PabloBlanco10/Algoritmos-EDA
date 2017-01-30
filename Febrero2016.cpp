//
//  Febrero2016.cpp
//  
//
//  Created by Pablo Blanco Peris on 18/1/17.
//
//

#include <stdio.h>

//{0 <= n < = long(v) ^ para todo k : 0 <= k < n : v[k] >= 0}
//fun parimpar (int v[], int n) return int p)
//{p = #i,j : 0 <= i < j < n : v[i] % 2 = 0 ^ v[j] % 2 = 1}


//cota n - i
// invariante = 0 <= i <= n ^ contPar = # k : 0 <= k < i : v[k] % 2 = 0 ^ p = # a,b : 0 <= a < b < i :
// v[a] % 2 = 0 ^v[b] % 2 = 1
int parimpar(int v[], int n){
    int p = 0, contPar = 0;
    //recorro hasta el primer par
    //cada vez que encuentre un impar, aumento el numero en impares con el numero de los pares que tenia
    
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0) contPar++;
        else
            p+= contPar;
    }
    return p;
}

//cota = i
// invariante = -1 <= i <= n - 1 ^ contImpares = #k : i < k <= n - 1 _____
// ^ p = # a,b : i < a < b < n : _______
int imparPar(int v[], int n){
    int contImpares = 0, p = 0, i = n - 1;
    
    while(i >= 0){
        if(v[i] % 2 == 1)
            contImpares++;
        else
            p += contImpares;
        i--;
    }
    return p;
    
}


