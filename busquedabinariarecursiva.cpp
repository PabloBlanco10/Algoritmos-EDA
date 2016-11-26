//
//  busquedabinariarecursiva.cpp
//  
//
//  Created by Pablo Blanco Peris on 22/11/16.
//
//

#include <stdio.h>

//se supone un vector ordenado.
int buscaBin(int v[], int a, int b, int x){
    int r;
    if(a == b + 1) {
        r = b;
    }
    else{
        int m = (a+b) / 2;
        if(v[m] <= x)
            r = buscaBin(v, m+1, b, x);
        else
            r = buscaBin(v, a, m-1, x);
    }
    return r;
}