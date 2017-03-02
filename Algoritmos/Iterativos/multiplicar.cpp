//
//  multiplicar.cpp
//  
//
//  Created by Pablo Blanco Peris on 31/1/17.
//
//

#include <stdio.h>
#include <iostream>

using namespace std;

void multiplicar(int v[], int n){
    int mult = 1, max = v[0], primero = 0, segundo = 0, primeroMejor = 0, segundoMejor = 0;
    int numeros = 0, numerosMejor = 0;
    bool ceroAnterior = false;
    
    if((n == 1) && (v[0]%10 != 0)){
        numerosMejor++;
    }
    
    for(int i = 0; i < n; i++){
        
        //si es diferente de 0 y si al multiplicarlo no termina en 0
        if(mult*v[i]%10 != 0){
            mult *= v[i];
            segundo = i;
            numeros++;
            
            if(ceroAnterior){
                primero = i;
                ceroAnterior = false;
            }
            
            if(mult > max){
                max = mult;
                primeroMejor = primero;
                segundoMejor = segundo;
                numerosMejor = numeros;
            }
            
        }
        else{
            mult = 1;
            ceroAnterior = true;
            numeros = 0;
        }
        
    }
    
    if(max % 10 != 0){
        cout << numerosMejor << " -> [" << primeroMejor << "," << segundoMejor << "]" << endl;
    }
    else
        cout << "SIGUE BUSCANDO" << endl;
    
}


bool resuelve(){
    
    int casos, n;
    int v[50000];
    
    cin >> casos;
    
    while(casos > 0){
        cin >> n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i] = a;
        }
        
        multiplicar(v, n);
        casos--;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}