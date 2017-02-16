//
//  cerradura.cpp
//  
//
//  Created by Pablo Blanco Peris on 30/1/17.
//
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


int cerradura(int v[], int n){
    int r = 0, arriba, abajo = 0, arribaMejor, abajoMejor = 0;
    
    for(int i = 0; i < n; i++){
        arriba += v[i];
    }
    arribaMejor = arriba;
    if(arribaMejor == 0)
        r = 0;
    else{
        for(int i = 0; i < n; i++){
            arriba -= v[i];
            abajo += v[i];
            if(fabs(arriba - abajo) < fabs(arribaMejor - abajoMejor)){
                r = i+1;
                arribaMejor = arriba;
                abajoMejor = abajo;
            }
        }
    }
    return r;
    
}

bool resuelve(){
    int n;
    int v[1000000];
    cin >> n;
    while(n != 0){
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i] = a;
        }
        cout << cerradura(v, n) << endl;
        cin >> n;
    }
}

int main(){
    while (resuelve());
    return 0;
}