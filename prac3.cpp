//
//  prac3.cpp
//  
//
//  Created by Pablo Blanco Peris on 21/10/16.
//
//

#include <iostream>
using namespace std;


bool resuelve();
int miradores(int v[], int n);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    while(resuelve()){
        ;
    }
    
    
    return 0;
}

bool resuelve(){
    int n;
    cin >> n;
    int v[10000];
    
    if(n == 0){
        return false;
        
    }
    
    int j;
    for(int i = 0; i < n; i++){
        cin >> j;
        v[i] = j;
    }
    
    cout << miradores(v, n) << endl;
    
    
    return true;
    
}

int miradores(int v[], int n){
    int miradores = 1;
    int mayor = v[n-1];
    for(int i = n-2; i >= 0; i--){
        if(v[i] > mayor){
            miradores++;
            mayor = v[i];
        }
        
    }
    
    return miradores;
}

// Q = { miradores(v,n) = #w: #para todo x: w <= x < n:
