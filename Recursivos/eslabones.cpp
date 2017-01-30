//
//  eslabones.cpp
//  
//
//  Created by Pablo Blanco Peris on 30/1/17.
//
//

#include <stdio.h>
#include <iostream>
using namespace std;

int trolls(int fuerza, int eslabones){
    int r;
 
    if(eslabones <= fuerza*2)
        r = 0;
    else{
        
        int eslabonHobbit= eslabones/3;
        int eslabonEnano = eslabones - eslabonHobbit;
        r = 1;
        if(eslabonHobbit > fuerza*2){
            r += trolls(fuerza, eslabonHobbit);
        }
        if(eslabonEnano > fuerza*2){
            r += trolls(fuerza, eslabonEnano);
        }
    }
    return r;
}

bool resuelve(){
    
    int fuerza, eslabones;
    cin >> fuerza;
    cin >> eslabones;
    
    while((fuerza != 0)){
        cout << trolls(fuerza, eslabones) << endl;
        cin >> fuerza;
        cin >> eslabones;
    }
    return false;
}

int main(){
    while(resuelve());
    return 0;
}
