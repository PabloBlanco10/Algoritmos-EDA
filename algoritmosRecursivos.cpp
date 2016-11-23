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

bool resuelve(){
    int n;
    //cout << 13 % 2 << endl << 10 / 10 << endl;
    cin >> n;
    
    while(n>=0){
       // cout <<  binarioADecimal(n) << endl;
        decimalABinario(n);
        cout << endl;
        cin >> n;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}