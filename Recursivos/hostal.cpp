//
//  hostal.cpp
//  
//
//  Created by Pablo Blanco Peris on 25/11/16.
//
//

#include <stdio.h>

#include <iostream>
using namespace std;


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


bool resuelve(){
    int n;
    cin >> n;
    int v[1000];
    int potDos = 1;
    
    
    while(n>=0){
      
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            v[j] = aux;
        }
        
        cout <<  hostal(v,n,0,potDos) << endl;
        cin >> n;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}