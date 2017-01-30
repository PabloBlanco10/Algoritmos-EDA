//
//  sept2015.cpp
//  
//
//  Created by Pablo Blanco Peris on 20/1/17.
//
//

#include <stdio.h>



int jacob(int n){
    int j, j_1, j_2;
    j_2 = 0; j_1 = 1;
    if(n == 0)
        j = 0;
    if(n == 1)
        j = 1;
    for(int i = 2; i <= n; i++){
        int j = j_1 + 2* j_2;
        j_2 = j_1;
        j_1 =j;
    }
    return j;
}


//I = 0 <= i <= n ^
// j =J(i) ^
// jm1 = j(i+1) ^
// jm2 = j(i+2)
//cota = n - i
int jacob(int n){
    int j = 0;
    int jm1 = 1;
    int jm2 = jm1 + 2*j;
    for(int i = 0; i <= n; i++){
        int aux = jm2;
        jm2 = jm2 + 2*jm1;
        j = jm1;
        jm1 = aux;
    }
    return j;
}
